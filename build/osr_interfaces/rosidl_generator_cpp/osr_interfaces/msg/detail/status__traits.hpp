// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from osr_interfaces:msg/Status.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "osr_interfaces/msg/status.hpp"


#ifndef OSR_INTERFACES__MSG__DETAIL__STATUS__TRAITS_HPP_
#define OSR_INTERFACES__MSG__DETAIL__STATUS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "osr_interfaces/msg/detail/status__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace osr_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const Status & msg,
  std::ostream & out)
{
  out << "{";
  // member: battery
  {
    out << "battery: ";
    rosidl_generator_traits::value_to_yaml(msg.battery, out);
    out << ", ";
  }

  // member: error_status
  {
    if (msg.error_status.size() == 0) {
      out << "error_status: []";
    } else {
      out << "error_status: [";
      size_t pending_items = msg.error_status.size();
      for (auto item : msg.error_status) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: temp
  {
    if (msg.temp.size() == 0) {
      out << "temp: []";
    } else {
      out << "temp: [";
      size_t pending_items = msg.temp.size();
      for (auto item : msg.temp) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: current
  {
    if (msg.current.size() == 0) {
      out << "current: []";
    } else {
      out << "current: [";
      size_t pending_items = msg.current.size();
      for (auto item : msg.current) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Status & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: battery
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "battery: ";
    rosidl_generator_traits::value_to_yaml(msg.battery, out);
    out << "\n";
  }

  // member: error_status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.error_status.size() == 0) {
      out << "error_status: []\n";
    } else {
      out << "error_status:\n";
      for (auto item : msg.error_status) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: temp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.temp.size() == 0) {
      out << "temp: []\n";
    } else {
      out << "temp:\n";
      for (auto item : msg.temp) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: current
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.current.size() == 0) {
      out << "current: []\n";
    } else {
      out << "current:\n";
      for (auto item : msg.current) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Status & msg, bool use_flow_style = false)
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
  const osr_interfaces::msg::Status & msg,
  std::ostream & out, size_t indentation = 0)
{
  osr_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use osr_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const osr_interfaces::msg::Status & msg)
{
  return osr_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<osr_interfaces::msg::Status>()
{
  return "osr_interfaces::msg::Status";
}

template<>
inline const char * name<osr_interfaces::msg::Status>()
{
  return "osr_interfaces/msg/Status";
}

template<>
struct has_fixed_size<osr_interfaces::msg::Status>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<osr_interfaces::msg::Status>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<osr_interfaces::msg::Status>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // OSR_INTERFACES__MSG__DETAIL__STATUS__TRAITS_HPP_
