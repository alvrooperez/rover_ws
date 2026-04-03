#include <chrono>
#include <memory>
#include <cmath> // Añadido para funciones trigonométricas y matemáticas

#include <rclcpp/rclcpp.hpp>
#include <trajectory_msgs/msg/joint_trajectory.hpp>
#include <trajectory_msgs/msg/joint_trajectory_point.hpp>
#include <std_msgs/msg/float64_multi_array.hpp>
#include <geometry_msgs/msg/twist.hpp>

#include <sensor_msgs/msg/imu.hpp>
#include <sensor_msgs/msg/joint_state.hpp>
#include <nav_msgs/msg/odometry.hpp>

// JAZZY: Actualizado a .hpp y añadidas librerías de matriz explícitas
#include <tf2_geometry_msgs/tf2_geometry_msgs.hpp>
#include <tf2/LinearMath/Quaternion.h>
#include <tf2/LinearMath/Matrix3x3.h> 
#include <tf2_ros/transform_listener.h>
#include <tf2_ros/transform_broadcaster.h>

using std::placeholders::_1;

class Controller : public rclcpp::Node {

private:

    rclcpp::Publisher<std_msgs::msg::Float64MultiArray>::SharedPtr motor_wheel_pub;
    rclcpp::Publisher<trajectory_msgs::msg::JointTrajectory>::SharedPtr servo_pub;
    rclcpp::Publisher<nav_msgs::msg::Odometry>::SharedPtr odom_pub;

    rclcpp::Subscription<geometry_msgs::msg::Twist>::SharedPtr sub;
    rclcpp::Subscription<sensor_msgs::msg::JointState>::SharedPtr joint_sub;
    rclcpp::Subscription<sensor_msgs::msg::Imu>::SharedPtr imu_sub;

    // JAZZY: Declaración segura del broadcaster de TF
    std::unique_ptr<tf2_ros::TransformBroadcaster> tf_broadcaster_;

    double angle_data;

    #define ROVER_WHEEL_RADIUS 0.075

    #define d1 0.177 // Distance from the center to the front-left wheel along the x-axis
    #define d2 0.310 // Distance from the center to the front-left wheel along the y-axis
    #define d3 0.274 // Distance from the center to the front-rear wheels along the y-axis
    #define d4 0.253 // Distance from the center to the center wheel along the x-axis

    double servo_theta = 0;
    double theta = 0;
    double l = 0; // linear, angular turning radius

    double theta_front_closest;
    double theta_front_farthest;
    rclcpp::Time last_time;
    
    double angular_velocity_center, vel_middle_closest, vel_corner_closest, vel_corner_farthest, vel_middle_farthest;
    double ang_vel_middle_closest, ang_vel_corner_closest, ang_vel_corner_farthest, ang_vel_middle_farthest;
    double start_time, time, pre_time;

    geometry_msgs::msg::Twist pri_velocity;

    double fl_vel, fr_vel, ml_vel, mr_vel, rl_vel, rr_vel;
    double current_dl, dl, pre_dl;
    double x_postion, y_postion;

    double FL_data, FR_data, ML_data, MR_data, RL_data, RR_data;
    double FR_servo_data, FL_servo_data, RR_servo_data, RL_servo_data;

    bool delay_ = true;

    double dt;
    double test1;
    double test = 0;
    nav_msgs::msg::Odometry odom_msg;

public:
    Controller() : Node("controller") {
        motor_wheel_pub = this->create_publisher<std_msgs::msg::Float64MultiArray>("/wheel_controller/commands", 1);
        servo_pub = this->create_publisher<trajectory_msgs::msg::JointTrajectory>("/servo_controller/joint_trajectory", 1);

        sub = this->create_subscription<geometry_msgs::msg::Twist>(
            "cmd_vel", 1, std::bind(&Controller::msgCallback, this, std::placeholders::_1));

        joint_sub = this->create_subscription<sensor_msgs::msg::JointState>(
            "joint_states", 1, std::bind(&Controller::jointStateCallback, this, std::placeholders::_1));

        // JAZZY: Asegúrate de que el topic del IMU es el mismo que pusimos en el URDF ("imu")
        imu_sub = this->create_subscription<sensor_msgs::msg::Imu>(
            "imu", 1, std::bind(&Controller::imuCallback, this, std::placeholders::_1));

        odom_pub = this->create_publisher<nav_msgs::msg::Odometry>("osr/odom", 10);

        // Inicializar el broadcaster de TF de forma segura
        tf_broadcaster_ = std::make_unique<tf2_ros::TransformBroadcaster>(this);
    }

    void jointStateCallback(const sensor_msgs::msg::JointState::SharedPtr msg) {
        fl_vel = msg->position[5];
        fr_vel = msg->position[7];
        ml_vel = msg->position[2];
        mr_vel = msg->position[3];
        rl_vel = msg->position[8];
        rr_vel = msg->position[9];

        Odometry(theta);
    }

    void Odometry(double angle)
    {
        current_dl = (fl_vel + fr_vel + ml_vel + mr_vel + rl_vel + rr_vel) * ROVER_WHEEL_RADIUS / 6;
        dl = current_dl - pre_dl;

        pre_dl = current_dl;

        x_postion += dl * cos(theta);
        y_postion += dl * sin(theta);

        odom_msg.header.stamp = this->get_clock()->now();
        odom_msg.header.frame_id = "odom";

        odom_msg.pose.pose.position.x = x_postion;
        odom_msg.pose.pose.position.y = y_postion;

        tf2::Quaternion quaternion;
        quaternion.setRPY(0, 0, angle);

        odom_msg.pose.pose.orientation.x = quaternion.x();
        odom_msg.pose.pose.orientation.y = quaternion.y();
        odom_msg.pose.pose.orientation.z = quaternion.z();
        odom_msg.pose.pose.orientation.w = quaternion.w();

        geometry_msgs::msg::TransformStamped transformStamped;
        transformStamped.header.stamp = this->get_clock()->now();
        transformStamped.header.frame_id = "odom";
        transformStamped.child_frame_id = "base_footprint";

        transformStamped.transform.translation.x = x_postion;
        transformStamped.transform.translation.y = y_postion;
        transformStamped.transform.translation.z = 0.0;

        transformStamped.transform.rotation = odom_msg.pose.pose.orientation;
        
        // Usar el broadcaster de la clase
        tf_broadcaster_->sendTransform(transformStamped);

        odom_pub->publish(odom_msg);
    }

    void imuCallback(const sensor_msgs::msg::Imu::SharedPtr msg) {
        tf2::Quaternion quaternion;
        tf2::fromMsg(msg->orientation, quaternion);

        double roll, pitch, yaw;
        tf2::Matrix3x3 m(quaternion);
        m.getRPY(roll, pitch, yaw);
        theta = yaw;
    }

    void msgCallback(const geometry_msgs::msg::Twist::SharedPtr msg) {

        if((pri_velocity.linear.x == msg->linear.x) && (pri_velocity.angular.z == msg->angular.z)) return;

        if(delay_)
        {
            delay_ = false;

            if (msg->angular.z == 0 && msg->linear.x != 0) { 
                go_straight(msg);
                publishVelocity();
                publishAngles();
            }
            else if((msg->angular.z != 0)&&(msg->linear.x == 0)) 
            {
                FL_servo_data = -atan(d3/d1);
                FR_servo_data = atan(d3/d1);
                RL_servo_data = atan(d2/d1);
                RR_servo_data = -atan(d2/d1);

                rotate_in_place(msg);
                publishAngles();                
                publishVelocity();
            }
            else if((msg->angular.z != 0)&&(msg->linear.x != 0)) 
            {
                twist_to_turning_radius(msg);
                calculate_servo_angle(l);
                calculate_drive_velocity(msg->linear.x, l);
                publishAngles();
                publishVelocity();
            }
            else if((msg->angular.z == 0)&&(msg->linear.x == 0))
            {
                stop();
                publishAngles();
                publishVelocity();
            }

            delay_ = true;
        }

        pri_velocity.linear.x = msg->linear.x;
        pri_velocity.angular.z = msg->angular.z;
    }

    void calculate_servo_angle(double l)
    {
        theta_front_closest = atan2(d3, std::abs(l) - d1);
        theta_front_farthest = atan2(d3, std::abs(l) + d1);

        if(l > 0)
        {
            FL_servo_data = theta_front_closest;
            FR_servo_data = theta_front_closest;
            RL_servo_data = -theta_front_closest;
            RR_servo_data = -theta_front_closest;
        }
        else
        {
            FL_servo_data = -theta_front_closest;
            FR_servo_data = -theta_front_closest;
            RL_servo_data = theta_front_closest;
            RR_servo_data = theta_front_closest;
        }
    }

    void calculate_drive_velocity(float velocity, double l)
    {
        angular_velocity_center = velocity / std::abs(l);

        vel_middle_closest = (std::abs(l) - d4) * angular_velocity_center;
        vel_corner_closest = std::hypot(std::abs(l) - d1, d3) * angular_velocity_center;
        vel_corner_farthest = std::hypot(std::abs(l) + d1, d3) * angular_velocity_center;
        vel_middle_farthest = (std::abs(l) + d4) * angular_velocity_center;

        ang_vel_middle_closest = vel_middle_closest / ROVER_WHEEL_RADIUS;
        ang_vel_corner_closest = vel_corner_closest / ROVER_WHEEL_RADIUS;
        ang_vel_corner_farthest = vel_corner_farthest / ROVER_WHEEL_RADIUS;
        ang_vel_middle_farthest = vel_middle_farthest / ROVER_WHEEL_RADIUS;

        if (l > 0)  
        {
            FL_data = float(ang_vel_corner_closest);
            RL_data = float(ang_vel_corner_closest);

            ML_data = float(ang_vel_middle_closest);
            FR_data = float(ang_vel_corner_farthest);

            RR_data = float(ang_vel_corner_farthest);
            MR_data = float(ang_vel_middle_farthest);
        }
        else        
        {
            FL_data = float(ang_vel_corner_farthest);
            RL_data = float(ang_vel_corner_farthest);

            ML_data = float(ang_vel_middle_farthest);
            FR_data = float(ang_vel_corner_closest);

            RR_data = float(ang_vel_corner_closest);
            MR_data = float(ang_vel_middle_closest);
        }
    }

    void stop()
    {
        FL_data = 0; RL_data = 0;
        ML_data = 0; FR_data = 0;
        RR_data = 0; MR_data = 0;
        FL_servo_data = 0; FR_servo_data = 0;
        RL_servo_data = 0; RR_servo_data = 0;
    }

    void go_straight(const geometry_msgs::msg::Twist::SharedPtr msg) {
        double velocity_data = msg->linear.x / ROVER_WHEEL_RADIUS;

        FL_data = velocity_data; FR_data = velocity_data;
        ML_data = velocity_data; MR_data = velocity_data;
        RL_data = velocity_data; RR_data = velocity_data;
        FL_servo_data = 0; FR_servo_data = 0;
        RL_servo_data = 0; RR_servo_data = 0;
    }

    void twist_to_turning_radius(const geometry_msgs::msg::Twist::SharedPtr msg)
    {
        l = msg->linear.x / msg->angular.z;
    }

    void rotate_in_place(const geometry_msgs::msg::Twist::SharedPtr& msg)
    {
        FL_data = -float(sqrt(d1*d1+d3*d3) * msg->angular.z / ROVER_WHEEL_RADIUS);
        RL_data = -float(sqrt(d1*d1+d2*d2) * msg->angular.z / ROVER_WHEEL_RADIUS);

        ML_data = -float(d4 * msg->angular.z / ROVER_WHEEL_RADIUS);
        FR_data = float(sqrt(d1*d1+d3*d3) * msg->angular.z / ROVER_WHEEL_RADIUS);

        RR_data = float(d4 * msg->angular.z / ROVER_WHEEL_RADIUS);
        MR_data = float(sqrt(d1*d1+d2*d2) * msg->angular.z / ROVER_WHEEL_RADIUS);
    }

    void publishVelocity() {
        std_msgs::msg::Float64MultiArray wheel;
        wheel.data = {ML_data, MR_data, FL_data, FR_data, RL_data, RR_data};
        motor_wheel_pub->publish(wheel);
    }

    void publishAngles()
    {
        auto servo = trajectory_msgs::msg::JointTrajectory();
        servo.joint_names = {"front_wheel_joint_R", "front_wheel_joint_L", "rear_wheel_joint_R", "rear_wheel_joint_L"};

        auto point = trajectory_msgs::msg::JointTrajectoryPoint();
        point.positions = {FR_servo_data, FL_servo_data, RR_servo_data, RL_servo_data};
        point.velocities = {0.0, 0.0, 0.0, 0.0};
        
        // JAZZY: Asignación explícita para evitar errores de tipo Duration
        point.time_from_start.sec = 0;
        point.time_from_start.nanosec = 200000000; // 0.2 segundos

        servo.points.push_back(point);
        servo_pub->publish(servo);
    }
};

int main(int argc, char* argv[]) {
    rclcpp::init(argc, argv);
    auto node = std::make_shared<Controller>();

    auto rate = std::chrono::milliseconds(300);

    while (rclcpp::ok()) {
        rclcpp::spin_some(node);
        std::this_thread::sleep_for(rate);
    }
    rclcpp::shutdown();
    return 0;
}