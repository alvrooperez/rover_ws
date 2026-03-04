// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from osr_interfaces:msg/CommandCorner.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "osr_interfaces/msg/command_corner.hpp"


#ifndef OSR_INTERFACES__MSG__DETAIL__COMMAND_CORNER__STRUCT_HPP_
#define OSR_INTERFACES__MSG__DETAIL__COMMAND_CORNER__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__osr_interfaces__msg__CommandCorner __attribute__((deprecated))
#else
# define DEPRECATED__osr_interfaces__msg__CommandCorner __declspec(deprecated)
#endif

namespace osr_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct CommandCorner_
{
  using Type = CommandCorner_<ContainerAllocator>;

  explicit CommandCorner_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->left_front_pos = 0.0;
      this->left_back_pos = 0.0;
      this->right_front_pos = 0.0;
      this->right_back_pos = 0.0;
    }
  }

  explicit CommandCorner_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->left_front_pos = 0.0;
      this->left_back_pos = 0.0;
      this->right_front_pos = 0.0;
      this->right_back_pos = 0.0;
    }
  }

  // field types and members
  using _left_front_pos_type =
    double;
  _left_front_pos_type left_front_pos;
  using _left_back_pos_type =
    double;
  _left_back_pos_type left_back_pos;
  using _right_front_pos_type =
    double;
  _right_front_pos_type right_front_pos;
  using _right_back_pos_type =
    double;
  _right_back_pos_type right_back_pos;

  // setters for named parameter idiom
  Type & set__left_front_pos(
    const double & _arg)
  {
    this->left_front_pos = _arg;
    return *this;
  }
  Type & set__left_back_pos(
    const double & _arg)
  {
    this->left_back_pos = _arg;
    return *this;
  }
  Type & set__right_front_pos(
    const double & _arg)
  {
    this->right_front_pos = _arg;
    return *this;
  }
  Type & set__right_back_pos(
    const double & _arg)
  {
    this->right_back_pos = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    osr_interfaces::msg::CommandCorner_<ContainerAllocator> *;
  using ConstRawPtr =
    const osr_interfaces::msg::CommandCorner_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<osr_interfaces::msg::CommandCorner_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<osr_interfaces::msg::CommandCorner_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      osr_interfaces::msg::CommandCorner_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<osr_interfaces::msg::CommandCorner_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      osr_interfaces::msg::CommandCorner_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<osr_interfaces::msg::CommandCorner_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<osr_interfaces::msg::CommandCorner_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<osr_interfaces::msg::CommandCorner_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__osr_interfaces__msg__CommandCorner
    std::shared_ptr<osr_interfaces::msg::CommandCorner_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__osr_interfaces__msg__CommandCorner
    std::shared_ptr<osr_interfaces::msg::CommandCorner_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const CommandCorner_ & other) const
  {
    if (this->left_front_pos != other.left_front_pos) {
      return false;
    }
    if (this->left_back_pos != other.left_back_pos) {
      return false;
    }
    if (this->right_front_pos != other.right_front_pos) {
      return false;
    }
    if (this->right_back_pos != other.right_back_pos) {
      return false;
    }
    return true;
  }
  bool operator!=(const CommandCorner_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct CommandCorner_

// alias to use template instance with default allocator
using CommandCorner =
  osr_interfaces::msg::CommandCorner_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace osr_interfaces

#endif  // OSR_INTERFACES__MSG__DETAIL__COMMAND_CORNER__STRUCT_HPP_
