// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from osr_interfaces:msg/Status.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "osr_interfaces/msg/detail/status__functions.h"
#include "osr_interfaces/msg/detail/status__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace osr_interfaces
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void Status_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) osr_interfaces::msg::Status(_init);
}

void Status_fini_function(void * message_memory)
{
  auto typed_message = static_cast<osr_interfaces::msg::Status *>(message_memory);
  typed_message->~Status();
}

size_t size_function__Status__error_status(const void * untyped_member)
{
  (void)untyped_member;
  return 3;
}

const void * get_const_function__Status__error_status(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<std::string, 3> *>(untyped_member);
  return &member[index];
}

void * get_function__Status__error_status(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<std::string, 3> *>(untyped_member);
  return &member[index];
}

void fetch_function__Status__error_status(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const std::string *>(
    get_const_function__Status__error_status(untyped_member, index));
  auto & value = *reinterpret_cast<std::string *>(untyped_value);
  value = item;
}

void assign_function__Status__error_status(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<std::string *>(
    get_function__Status__error_status(untyped_member, index));
  const auto & value = *reinterpret_cast<const std::string *>(untyped_value);
  item = value;
}

size_t size_function__Status__temp(const void * untyped_member)
{
  (void)untyped_member;
  return 3;
}

const void * get_const_function__Status__temp(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<float, 3> *>(untyped_member);
  return &member[index];
}

void * get_function__Status__temp(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<float, 3> *>(untyped_member);
  return &member[index];
}

void fetch_function__Status__temp(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const float *>(
    get_const_function__Status__temp(untyped_member, index));
  auto & value = *reinterpret_cast<float *>(untyped_value);
  value = item;
}

void assign_function__Status__temp(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<float *>(
    get_function__Status__temp(untyped_member, index));
  const auto & value = *reinterpret_cast<const float *>(untyped_value);
  item = value;
}

size_t size_function__Status__current(const void * untyped_member)
{
  (void)untyped_member;
  return 6;
}

const void * get_const_function__Status__current(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<float, 6> *>(untyped_member);
  return &member[index];
}

void * get_function__Status__current(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<float, 6> *>(untyped_member);
  return &member[index];
}

void fetch_function__Status__current(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const float *>(
    get_const_function__Status__current(untyped_member, index));
  auto & value = *reinterpret_cast<float *>(untyped_value);
  value = item;
}

void assign_function__Status__current(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<float *>(
    get_function__Status__current(untyped_member, index));
  const auto & value = *reinterpret_cast<const float *>(untyped_value);
  item = value;
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember Status_message_member_array[4] = {
  {
    "battery",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(osr_interfaces::msg::Status, battery),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "error_status",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    true,  // is array
    3,  // array size
    false,  // is upper bound
    offsetof(osr_interfaces::msg::Status, error_status),  // bytes offset in struct
    nullptr,  // default value
    size_function__Status__error_status,  // size() function pointer
    get_const_function__Status__error_status,  // get_const(index) function pointer
    get_function__Status__error_status,  // get(index) function pointer
    fetch_function__Status__error_status,  // fetch(index, &value) function pointer
    assign_function__Status__error_status,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "temp",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    true,  // is array
    3,  // array size
    false,  // is upper bound
    offsetof(osr_interfaces::msg::Status, temp),  // bytes offset in struct
    nullptr,  // default value
    size_function__Status__temp,  // size() function pointer
    get_const_function__Status__temp,  // get_const(index) function pointer
    get_function__Status__temp,  // get(index) function pointer
    fetch_function__Status__temp,  // fetch(index, &value) function pointer
    assign_function__Status__temp,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "current",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    true,  // is array
    6,  // array size
    false,  // is upper bound
    offsetof(osr_interfaces::msg::Status, current),  // bytes offset in struct
    nullptr,  // default value
    size_function__Status__current,  // size() function pointer
    get_const_function__Status__current,  // get_const(index) function pointer
    get_function__Status__current,  // get(index) function pointer
    fetch_function__Status__current,  // fetch(index, &value) function pointer
    assign_function__Status__current,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers Status_message_members = {
  "osr_interfaces::msg",  // message namespace
  "Status",  // message name
  4,  // number of fields
  sizeof(osr_interfaces::msg::Status),
  false,  // has_any_key_member_
  Status_message_member_array,  // message members
  Status_init_function,  // function to initialize message memory (memory has to be allocated)
  Status_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t Status_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &Status_message_members,
  get_message_typesupport_handle_function,
  &osr_interfaces__msg__Status__get_type_hash,
  &osr_interfaces__msg__Status__get_type_description,
  &osr_interfaces__msg__Status__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace osr_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<osr_interfaces::msg::Status>()
{
  return &::osr_interfaces::msg::rosidl_typesupport_introspection_cpp::Status_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, osr_interfaces, msg, Status)() {
  return &::osr_interfaces::msg::rosidl_typesupport_introspection_cpp::Status_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
