// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from osr_interfaces:msg/CommandCorner.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "osr_interfaces/msg/detail/command_corner__functions.h"
#include "osr_interfaces/msg/detail/command_corner__struct.hpp"
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

void CommandCorner_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) osr_interfaces::msg::CommandCorner(_init);
}

void CommandCorner_fini_function(void * message_memory)
{
  auto typed_message = static_cast<osr_interfaces::msg::CommandCorner *>(message_memory);
  typed_message->~CommandCorner();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember CommandCorner_message_member_array[4] = {
  {
    "left_front_pos",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(osr_interfaces::msg::CommandCorner, left_front_pos),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "left_back_pos",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(osr_interfaces::msg::CommandCorner, left_back_pos),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "right_front_pos",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(osr_interfaces::msg::CommandCorner, right_front_pos),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "right_back_pos",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(osr_interfaces::msg::CommandCorner, right_back_pos),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers CommandCorner_message_members = {
  "osr_interfaces::msg",  // message namespace
  "CommandCorner",  // message name
  4,  // number of fields
  sizeof(osr_interfaces::msg::CommandCorner),
  false,  // has_any_key_member_
  CommandCorner_message_member_array,  // message members
  CommandCorner_init_function,  // function to initialize message memory (memory has to be allocated)
  CommandCorner_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t CommandCorner_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &CommandCorner_message_members,
  get_message_typesupport_handle_function,
  &osr_interfaces__msg__CommandCorner__get_type_hash,
  &osr_interfaces__msg__CommandCorner__get_type_description,
  &osr_interfaces__msg__CommandCorner__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace osr_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<osr_interfaces::msg::CommandCorner>()
{
  return &::osr_interfaces::msg::rosidl_typesupport_introspection_cpp::CommandCorner_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, osr_interfaces, msg, CommandCorner)() {
  return &::osr_interfaces::msg::rosidl_typesupport_introspection_cpp::CommandCorner_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
