// generated from rosidl_typesupport_fastrtps_c/resource/idl__rosidl_typesupport_fastrtps_c.h.em
// with input from osr_interfaces:msg/Status.idl
// generated code does not contain a copyright notice
#ifndef OSR_INTERFACES__MSG__DETAIL__STATUS__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
#define OSR_INTERFACES__MSG__DETAIL__STATUS__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_


#include <stddef.h>
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "osr_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "osr_interfaces/msg/detail/status__struct.h"
#include "fastcdr/Cdr.h"

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_osr_interfaces
bool cdr_serialize_osr_interfaces__msg__Status(
  const osr_interfaces__msg__Status * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_osr_interfaces
bool cdr_deserialize_osr_interfaces__msg__Status(
  eprosima::fastcdr::Cdr &,
  osr_interfaces__msg__Status * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_osr_interfaces
size_t get_serialized_size_osr_interfaces__msg__Status(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_osr_interfaces
size_t max_serialized_size_osr_interfaces__msg__Status(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_osr_interfaces
bool cdr_serialize_key_osr_interfaces__msg__Status(
  const osr_interfaces__msg__Status * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_osr_interfaces
size_t get_serialized_size_key_osr_interfaces__msg__Status(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_osr_interfaces
size_t max_serialized_size_key_osr_interfaces__msg__Status(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_osr_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, osr_interfaces, msg, Status)();

#ifdef __cplusplus
}
#endif

#endif  // OSR_INTERFACES__MSG__DETAIL__STATUS__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
