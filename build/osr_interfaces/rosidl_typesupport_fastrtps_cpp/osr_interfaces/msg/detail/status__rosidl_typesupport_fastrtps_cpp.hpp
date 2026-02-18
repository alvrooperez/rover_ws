// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from osr_interfaces:msg/Status.idl
// generated code does not contain a copyright notice

#ifndef OSR_INTERFACES__MSG__DETAIL__STATUS__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define OSR_INTERFACES__MSG__DETAIL__STATUS__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include <cstddef>
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "osr_interfaces/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "osr_interfaces/msg/detail/status__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

#include "fastcdr/Cdr.h"

namespace osr_interfaces
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_osr_interfaces
cdr_serialize(
  const osr_interfaces::msg::Status & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_osr_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  osr_interfaces::msg::Status & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_osr_interfaces
get_serialized_size(
  const osr_interfaces::msg::Status & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_osr_interfaces
max_serialized_size_Status(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_osr_interfaces
cdr_serialize_key(
  const osr_interfaces::msg::Status & ros_message,
  eprosima::fastcdr::Cdr &);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_osr_interfaces
get_serialized_size_key(
  const osr_interfaces::msg::Status & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_osr_interfaces
max_serialized_size_key_Status(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace osr_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_osr_interfaces
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, osr_interfaces, msg, Status)();

#ifdef __cplusplus
}
#endif

#endif  // OSR_INTERFACES__MSG__DETAIL__STATUS__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
