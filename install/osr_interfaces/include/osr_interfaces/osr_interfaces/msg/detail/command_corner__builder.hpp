// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from osr_interfaces:msg/CommandCorner.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "osr_interfaces/msg/command_corner.hpp"


#ifndef OSR_INTERFACES__MSG__DETAIL__COMMAND_CORNER__BUILDER_HPP_
#define OSR_INTERFACES__MSG__DETAIL__COMMAND_CORNER__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "osr_interfaces/msg/detail/command_corner__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace osr_interfaces
{

namespace msg
{

namespace builder
{

class Init_CommandCorner_right_back_pos
{
public:
  explicit Init_CommandCorner_right_back_pos(::osr_interfaces::msg::CommandCorner & msg)
  : msg_(msg)
  {}
  ::osr_interfaces::msg::CommandCorner right_back_pos(::osr_interfaces::msg::CommandCorner::_right_back_pos_type arg)
  {
    msg_.right_back_pos = std::move(arg);
    return std::move(msg_);
  }

private:
  ::osr_interfaces::msg::CommandCorner msg_;
};

class Init_CommandCorner_right_front_pos
{
public:
  explicit Init_CommandCorner_right_front_pos(::osr_interfaces::msg::CommandCorner & msg)
  : msg_(msg)
  {}
  Init_CommandCorner_right_back_pos right_front_pos(::osr_interfaces::msg::CommandCorner::_right_front_pos_type arg)
  {
    msg_.right_front_pos = std::move(arg);
    return Init_CommandCorner_right_back_pos(msg_);
  }

private:
  ::osr_interfaces::msg::CommandCorner msg_;
};

class Init_CommandCorner_left_back_pos
{
public:
  explicit Init_CommandCorner_left_back_pos(::osr_interfaces::msg::CommandCorner & msg)
  : msg_(msg)
  {}
  Init_CommandCorner_right_front_pos left_back_pos(::osr_interfaces::msg::CommandCorner::_left_back_pos_type arg)
  {
    msg_.left_back_pos = std::move(arg);
    return Init_CommandCorner_right_front_pos(msg_);
  }

private:
  ::osr_interfaces::msg::CommandCorner msg_;
};

class Init_CommandCorner_left_front_pos
{
public:
  Init_CommandCorner_left_front_pos()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_CommandCorner_left_back_pos left_front_pos(::osr_interfaces::msg::CommandCorner::_left_front_pos_type arg)
  {
    msg_.left_front_pos = std::move(arg);
    return Init_CommandCorner_left_back_pos(msg_);
  }

private:
  ::osr_interfaces::msg::CommandCorner msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::osr_interfaces::msg::CommandCorner>()
{
  return osr_interfaces::msg::builder::Init_CommandCorner_left_front_pos();
}

}  // namespace osr_interfaces

#endif  // OSR_INTERFACES__MSG__DETAIL__COMMAND_CORNER__BUILDER_HPP_
