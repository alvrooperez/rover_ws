// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from osr_interfaces:msg/Status.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "osr_interfaces/msg/detail/status__rosidl_typesupport_introspection_c.h"
#include "osr_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "osr_interfaces/msg/detail/status__functions.h"
#include "osr_interfaces/msg/detail/status__struct.h"


// Include directives for member types
// Member `error_status`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void osr_interfaces__msg__Status__rosidl_typesupport_introspection_c__Status_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  osr_interfaces__msg__Status__init(message_memory);
}

void osr_interfaces__msg__Status__rosidl_typesupport_introspection_c__Status_fini_function(void * message_memory)
{
  osr_interfaces__msg__Status__fini(message_memory);
}

size_t osr_interfaces__msg__Status__rosidl_typesupport_introspection_c__size_function__Status__error_status(
  const void * untyped_member)
{
  (void)untyped_member;
  return 3;
}

const void * osr_interfaces__msg__Status__rosidl_typesupport_introspection_c__get_const_function__Status__error_status(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__String * member =
    (const rosidl_runtime_c__String *)(untyped_member);
  return &member[index];
}

void * osr_interfaces__msg__Status__rosidl_typesupport_introspection_c__get_function__Status__error_status(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__String * member =
    (rosidl_runtime_c__String *)(untyped_member);
  return &member[index];
}

void osr_interfaces__msg__Status__rosidl_typesupport_introspection_c__fetch_function__Status__error_status(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const rosidl_runtime_c__String * item =
    ((const rosidl_runtime_c__String *)
    osr_interfaces__msg__Status__rosidl_typesupport_introspection_c__get_const_function__Status__error_status(untyped_member, index));
  rosidl_runtime_c__String * value =
    (rosidl_runtime_c__String *)(untyped_value);
  *value = *item;
}

void osr_interfaces__msg__Status__rosidl_typesupport_introspection_c__assign_function__Status__error_status(
  void * untyped_member, size_t index, const void * untyped_value)
{
  rosidl_runtime_c__String * item =
    ((rosidl_runtime_c__String *)
    osr_interfaces__msg__Status__rosidl_typesupport_introspection_c__get_function__Status__error_status(untyped_member, index));
  const rosidl_runtime_c__String * value =
    (const rosidl_runtime_c__String *)(untyped_value);
  *item = *value;
}

size_t osr_interfaces__msg__Status__rosidl_typesupport_introspection_c__size_function__Status__temp(
  const void * untyped_member)
{
  (void)untyped_member;
  return 3;
}

const void * osr_interfaces__msg__Status__rosidl_typesupport_introspection_c__get_const_function__Status__temp(
  const void * untyped_member, size_t index)
{
  const float * member =
    (const float *)(untyped_member);
  return &member[index];
}

void * osr_interfaces__msg__Status__rosidl_typesupport_introspection_c__get_function__Status__temp(
  void * untyped_member, size_t index)
{
  float * member =
    (float *)(untyped_member);
  return &member[index];
}

void osr_interfaces__msg__Status__rosidl_typesupport_introspection_c__fetch_function__Status__temp(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    osr_interfaces__msg__Status__rosidl_typesupport_introspection_c__get_const_function__Status__temp(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void osr_interfaces__msg__Status__rosidl_typesupport_introspection_c__assign_function__Status__temp(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    osr_interfaces__msg__Status__rosidl_typesupport_introspection_c__get_function__Status__temp(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

size_t osr_interfaces__msg__Status__rosidl_typesupport_introspection_c__size_function__Status__current(
  const void * untyped_member)
{
  (void)untyped_member;
  return 6;
}

const void * osr_interfaces__msg__Status__rosidl_typesupport_introspection_c__get_const_function__Status__current(
  const void * untyped_member, size_t index)
{
  const float * member =
    (const float *)(untyped_member);
  return &member[index];
}

void * osr_interfaces__msg__Status__rosidl_typesupport_introspection_c__get_function__Status__current(
  void * untyped_member, size_t index)
{
  float * member =
    (float *)(untyped_member);
  return &member[index];
}

void osr_interfaces__msg__Status__rosidl_typesupport_introspection_c__fetch_function__Status__current(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    osr_interfaces__msg__Status__rosidl_typesupport_introspection_c__get_const_function__Status__current(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void osr_interfaces__msg__Status__rosidl_typesupport_introspection_c__assign_function__Status__current(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    osr_interfaces__msg__Status__rosidl_typesupport_introspection_c__get_function__Status__current(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

static rosidl_typesupport_introspection_c__MessageMember osr_interfaces__msg__Status__rosidl_typesupport_introspection_c__Status_message_member_array[4] = {
  {
    "battery",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(osr_interfaces__msg__Status, battery),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "error_status",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    true,  // is array
    3,  // array size
    false,  // is upper bound
    offsetof(osr_interfaces__msg__Status, error_status),  // bytes offset in struct
    NULL,  // default value
    osr_interfaces__msg__Status__rosidl_typesupport_introspection_c__size_function__Status__error_status,  // size() function pointer
    osr_interfaces__msg__Status__rosidl_typesupport_introspection_c__get_const_function__Status__error_status,  // get_const(index) function pointer
    osr_interfaces__msg__Status__rosidl_typesupport_introspection_c__get_function__Status__error_status,  // get(index) function pointer
    osr_interfaces__msg__Status__rosidl_typesupport_introspection_c__fetch_function__Status__error_status,  // fetch(index, &value) function pointer
    osr_interfaces__msg__Status__rosidl_typesupport_introspection_c__assign_function__Status__error_status,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "temp",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    true,  // is array
    3,  // array size
    false,  // is upper bound
    offsetof(osr_interfaces__msg__Status, temp),  // bytes offset in struct
    NULL,  // default value
    osr_interfaces__msg__Status__rosidl_typesupport_introspection_c__size_function__Status__temp,  // size() function pointer
    osr_interfaces__msg__Status__rosidl_typesupport_introspection_c__get_const_function__Status__temp,  // get_const(index) function pointer
    osr_interfaces__msg__Status__rosidl_typesupport_introspection_c__get_function__Status__temp,  // get(index) function pointer
    osr_interfaces__msg__Status__rosidl_typesupport_introspection_c__fetch_function__Status__temp,  // fetch(index, &value) function pointer
    osr_interfaces__msg__Status__rosidl_typesupport_introspection_c__assign_function__Status__temp,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "current",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    true,  // is array
    6,  // array size
    false,  // is upper bound
    offsetof(osr_interfaces__msg__Status, current),  // bytes offset in struct
    NULL,  // default value
    osr_interfaces__msg__Status__rosidl_typesupport_introspection_c__size_function__Status__current,  // size() function pointer
    osr_interfaces__msg__Status__rosidl_typesupport_introspection_c__get_const_function__Status__current,  // get_const(index) function pointer
    osr_interfaces__msg__Status__rosidl_typesupport_introspection_c__get_function__Status__current,  // get(index) function pointer
    osr_interfaces__msg__Status__rosidl_typesupport_introspection_c__fetch_function__Status__current,  // fetch(index, &value) function pointer
    osr_interfaces__msg__Status__rosidl_typesupport_introspection_c__assign_function__Status__current,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers osr_interfaces__msg__Status__rosidl_typesupport_introspection_c__Status_message_members = {
  "osr_interfaces__msg",  // message namespace
  "Status",  // message name
  4,  // number of fields
  sizeof(osr_interfaces__msg__Status),
  false,  // has_any_key_member_
  osr_interfaces__msg__Status__rosidl_typesupport_introspection_c__Status_message_member_array,  // message members
  osr_interfaces__msg__Status__rosidl_typesupport_introspection_c__Status_init_function,  // function to initialize message memory (memory has to be allocated)
  osr_interfaces__msg__Status__rosidl_typesupport_introspection_c__Status_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t osr_interfaces__msg__Status__rosidl_typesupport_introspection_c__Status_message_type_support_handle = {
  0,
  &osr_interfaces__msg__Status__rosidl_typesupport_introspection_c__Status_message_members,
  get_message_typesupport_handle_function,
  &osr_interfaces__msg__Status__get_type_hash,
  &osr_interfaces__msg__Status__get_type_description,
  &osr_interfaces__msg__Status__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_osr_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, osr_interfaces, msg, Status)() {
  if (!osr_interfaces__msg__Status__rosidl_typesupport_introspection_c__Status_message_type_support_handle.typesupport_identifier) {
    osr_interfaces__msg__Status__rosidl_typesupport_introspection_c__Status_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &osr_interfaces__msg__Status__rosidl_typesupport_introspection_c__Status_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
