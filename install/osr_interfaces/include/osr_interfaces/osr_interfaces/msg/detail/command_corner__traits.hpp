// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from osr_interfaces:msg/CommandCorner.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "osr_interfaces/msg/command_corner.hpp"


#ifndef OSR_INTERFACES__MSG__DETAIL__COMMAND_CORNER__TRAITS_HPP_
#define OSR_INTERFACES__MSG__DETAIL__COMMAND_CORNER__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "osr_interfaces/msg/detail/command_corner__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace osr_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const CommandCorner & msg,
  std::ostream & out)
{
  out << "{";
  // member: left_front_pos
  {
    out << "left_front_pos: ";
    rosidl_generator_traits::value_to_yaml(msg.left_front_pos, out);
    out << ", ";
  }

  // member: left_back_pos
  {
    out << "left_back_pos: ";
    rosidl_generator_traits::value_to_yaml(msg.left_back_pos, out);
    out << ", ";
  }

  // member: right_front_pos
  {
    out << "right_front_pos: ";
    rosidl_generator_traits::value_to_yaml(msg.right_front_pos, out);
    out << ", ";
  }

  // member: right_back_pos
  {
    out << "right_back_pos: ";
    rosidl_generator_traits::value_to_yaml(msg.right_back_pos, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const CommandCorner & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: left_front_pos
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "left_front_pos: ";
    rosidl_generator_traits::value_to_yaml(msg.left_front_pos, out);
    out << "\n";
  }

  // member: left_back_pos
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "left_back_pos: ";
    rosidl_generator_traits::value_to_yaml(msg.left_back_pos, out);
    out << "\n";
  }

  // member: right_front_pos
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "right_front_pos: ";
    rosidl_generator_traits::value_to_yaml(msg.right_front_pos, out);
    out << "\n";
  }

  // member: right_back_pos
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "right_back_pos: ";
    rosidl_generator_traits::value_to_yaml(msg.right_back_pos, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const CommandCorner & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace osr_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use osr_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const osr_interfaces::msg::CommandCorner & msg,
  std::ostream & out, size_t indentation = 0)
{
  osr_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use osr_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const osr_interfaces::msg::CommandCorner & msg)
{
  return osr_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<osr_interfaces::msg::CommandCorner>()
{
  return "osr_interfaces::msg::CommandCorner";
}

template<>
inline const char * name<osr_interfaces::msg::CommandCorner>()
{
  return "osr_interfaces/msg/CommandCorner";
}

template<>
struct has_fixed_size<osr_interfaces::msg::CommandCorner>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<osr_interfaces::msg::CommandCorner>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<osr_interfaces::msg::CommandCorner>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // OSR_INTERFACES__MSG__DETAIL__COMMAND_CORNER__TRAITS_HPP_
