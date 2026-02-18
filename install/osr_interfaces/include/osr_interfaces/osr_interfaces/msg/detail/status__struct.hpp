// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from osr_interfaces:msg/Status.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "osr_interfaces/msg/status.hpp"


#ifndef OSR_INTERFACES__MSG__DETAIL__STATUS__STRUCT_HPP_
#define OSR_INTERFACES__MSG__DETAIL__STATUS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__osr_interfaces__msg__Status __attribute__((deprecated))
#else
# define DEPRECATED__osr_interfaces__msg__Status __declspec(deprecated)
#endif

namespace osr_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Status_
{
  using Type = Status_<ContainerAllocator>;

  explicit Status_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->battery = 0.0f;
      std::fill<typename std::array<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, 3>::iterator, std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>(this->error_status.begin(), this->error_status.end(), "");
      std::fill<typename std::array<float, 3>::iterator, float>(this->temp.begin(), this->temp.end(), 0.0f);
      std::fill<typename std::array<float, 6>::iterator, float>(this->current.begin(), this->current.end(), 0.0f);
    }
  }

  explicit Status_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : error_status(_alloc),
    temp(_alloc),
    current(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->battery = 0.0f;
      std::fill<typename std::array<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, 3>::iterator, std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>(this->error_status.begin(), this->error_status.end(), "");
      std::fill<typename std::array<float, 3>::iterator, float>(this->temp.begin(), this->temp.end(), 0.0f);
      std::fill<typename std::array<float, 6>::iterator, float>(this->current.begin(), this->current.end(), 0.0f);
    }
  }

  // field types and members
  using _battery_type =
    float;
  _battery_type battery;
  using _error_status_type =
    std::array<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, 3>;
  _error_status_type error_status;
  using _temp_type =
    std::array<float, 3>;
  _temp_type temp;
  using _current_type =
    std::array<float, 6>;
  _current_type current;

  // setters for named parameter idiom
  Type & set__battery(
    const float & _arg)
  {
    this->battery = _arg;
    return *this;
  }
  Type & set__error_status(
    const std::array<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, 3> & _arg)
  {
    this->error_status = _arg;
    return *this;
  }
  Type & set__temp(
    const std::array<float, 3> & _arg)
  {
    this->temp = _arg;
    return *this;
  }
  Type & set__current(
    const std::array<float, 6> & _arg)
  {
    this->current = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    osr_interfaces::msg::Status_<ContainerAllocator> *;
  using ConstRawPtr =
    const osr_interfaces::msg::Status_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<osr_interfaces::msg::Status_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<osr_interfaces::msg::Status_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      osr_interfaces::msg::Status_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<osr_interfaces::msg::Status_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      osr_interfaces::msg::Status_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<osr_interfaces::msg::Status_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<osr_interfaces::msg::Status_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<osr_interfaces::msg::Status_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__osr_interfaces__msg__Status
    std::shared_ptr<osr_interfaces::msg::Status_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__osr_interfaces__msg__Status
    std::shared_ptr<osr_interfaces::msg::Status_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Status_ & other) const
  {
    if (this->battery != other.battery) {
      return false;
    }
    if (this->error_status != other.error_status) {
      return false;
    }
    if (this->temp != other.temp) {
      return false;
    }
    if (this->current != other.current) {
      return false;
    }
    return true;
  }
  bool operator!=(const Status_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Status_

// alias to use template instance with default allocator
using Status =
  osr_interfaces::msg::Status_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace osr_interfaces

#endif  // OSR_INTERFACES__MSG__DETAIL__STATUS__STRUCT_HPP_
