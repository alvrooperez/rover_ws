// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from osr_interfaces:msg/CommandDrive.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "osr_interfaces/msg/command_drive.hpp"


#ifndef OSR_INTERFACES__MSG__DETAIL__COMMAND_DRIVE__BUILDER_HPP_
#define OSR_INTERFACES__MSG__DETAIL__COMMAND_DRIVE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "osr_interfaces/msg/detail/command_drive__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace osr_interfaces
{

namespace msg
{

namespace builder
{

class Init_CommandDrive_right_back_vel
{
public:
  explicit Init_CommandDrive_right_back_vel(::osr_interfaces::msg::CommandDrive & msg)
  : msg_(msg)
  {}
  ::osr_interfaces::msg::CommandDrive right_back_vel(::osr_interfaces::msg::CommandDrive::_right_back_vel_type arg)
  {
    msg_.right_back_vel = std::move(arg);
    return std::move(msg_);
  }

private:
  ::osr_interfaces::msg::CommandDrive msg_;
};

class Init_CommandDrive_right_middle_vel
{
public:
  explicit Init_CommandDrive_right_middle_vel(::osr_interfaces::msg::CommandDrive & msg)
  : msg_(msg)
  {}
  Init_CommandDrive_right_back_vel right_middle_vel(::osr_interfaces::msg::CommandDrive::_right_middle_vel_type arg)
  {
    msg_.right_middle_vel = std::move(arg);
    return Init_CommandDrive_right_back_vel(msg_);
  }

private:
  ::osr_interfaces::msg::CommandDrive msg_;
};

class Init_CommandDrive_right_front_vel
{
public:
  explicit Init_CommandDrive_right_front_vel(::osr_interfaces::msg::CommandDrive & msg)
  : msg_(msg)
  {}
  Init_CommandDrive_right_middle_vel right_front_vel(::osr_interfaces::msg::CommandDrive::_right_front_vel_type arg)
  {
    msg_.right_front_vel = std::move(arg);
    return Init_CommandDrive_right_middle_vel(msg_);
  }

private:
  ::osr_interfaces::msg::CommandDrive msg_;
};

class Init_CommandDrive_left_back_vel
{
public:
  explicit Init_CommandDrive_left_back_vel(::osr_interfaces::msg::CommandDrive & msg)
  : msg_(msg)
  {}
  Init_CommandDrive_right_front_vel left_back_vel(::osr_interfaces::msg::CommandDrive::_left_back_vel_type arg)
  {
    msg_.left_back_vel = std::move(arg);
    return Init_CommandDrive_right_front_vel(msg_);
  }

private:
  ::osr_interfaces::msg::CommandDrive msg_;
};

class Init_CommandDrive_left_middle_vel
{
public:
  explicit Init_CommandDrive_left_middle_vel(::osr_interfaces::msg::CommandDrive & msg)
  : msg_(msg)
  {}
  Init_CommandDrive_left_back_vel left_middle_vel(::osr_interfaces::msg::CommandDrive::_left_middle_vel_type arg)
  {
    msg_.left_middle_vel = std::move(arg);
    return Init_CommandDrive_left_back_vel(msg_);
  }

private:
  ::osr_interfaces::msg::CommandDrive msg_;
};

class Init_CommandDrive_left_front_vel
{
public:
  Init_CommandDrive_left_front_vel()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_CommandDrive_left_middle_vel left_front_vel(::osr_interfaces::msg::CommandDrive::_left_front_vel_type arg)
  {
    msg_.left_front_vel = std::move(arg);
    return Init_CommandDrive_left_middle_vel(msg_);
  }

private:
  ::osr_interfaces::msg::CommandDrive msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::osr_interfaces::msg::CommandDrive>()
{
  return osr_interfaces::msg::builder::Init_CommandDrive_left_front_vel();
}

}  // namespace osr_interfaces

#endif  // OSR_INTERFACES__MSG__DETAIL__COMMAND_DRIVE__BUILDER_HPP_
