// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from osr_interfaces:msg/Status.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "osr_interfaces/msg/status.hpp"


#ifndef OSR_INTERFACES__MSG__DETAIL__STATUS__BUILDER_HPP_
#define OSR_INTERFACES__MSG__DETAIL__STATUS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "osr_interfaces/msg/detail/status__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace osr_interfaces
{

namespace msg
{

namespace builder
{

class Init_Status_current
{
public:
  explicit Init_Status_current(::osr_interfaces::msg::Status & msg)
  : msg_(msg)
  {}
  ::osr_interfaces::msg::Status current(::osr_interfaces::msg::Status::_current_type arg)
  {
    msg_.current = std::move(arg);
    return std::move(msg_);
  }

private:
  ::osr_interfaces::msg::Status msg_;
};

class Init_Status_temp
{
public:
  explicit Init_Status_temp(::osr_interfaces::msg::Status & msg)
  : msg_(msg)
  {}
  Init_Status_current temp(::osr_interfaces::msg::Status::_temp_type arg)
  {
    msg_.temp = std::move(arg);
    return Init_Status_current(msg_);
  }

private:
  ::osr_interfaces::msg::Status msg_;
};

class Init_Status_error_status
{
public:
  explicit Init_Status_error_status(::osr_interfaces::msg::Status & msg)
  : msg_(msg)
  {}
  Init_Status_temp error_status(::osr_interfaces::msg::Status::_error_status_type arg)
  {
    msg_.error_status = std::move(arg);
    return Init_Status_temp(msg_);
  }

private:
  ::osr_interfaces::msg::Status msg_;
};

class Init_Status_battery
{
public:
  Init_Status_battery()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Status_error_status battery(::osr_interfaces::msg::Status::_battery_type arg)
  {
    msg_.battery = std::move(arg);
    return Init_Status_error_status(msg_);
  }

private:
  ::osr_interfaces::msg::Status msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::osr_interfaces::msg::Status>()
{
  return osr_interfaces::msg::builder::Init_Status_battery();
}

}  // namespace osr_interfaces

#endif  // OSR_INTERFACES__MSG__DETAIL__STATUS__BUILDER_HPP_
