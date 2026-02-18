// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from osr_interfaces:msg/CommandDrive.idl
// generated code does not contain a copyright notice
#include "osr_interfaces/msg/detail/command_drive__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <cstddef>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "osr_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "osr_interfaces/msg/detail/command_drive__struct.h"
#include "osr_interfaces/msg/detail/command_drive__functions.h"
#include "fastcdr/Cdr.h"

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

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif


// forward declare type support functions


using _CommandDrive__ros_msg_type = osr_interfaces__msg__CommandDrive;


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_osr_interfaces
bool cdr_serialize_osr_interfaces__msg__CommandDrive(
  const osr_interfaces__msg__CommandDrive * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: left_front_vel
  {
    cdr << ros_message->left_front_vel;
  }

  // Field name: left_middle_vel
  {
    cdr << ros_message->left_middle_vel;
  }

  // Field name: left_back_vel
  {
    cdr << ros_message->left_back_vel;
  }

  // Field name: right_front_vel
  {
    cdr << ros_message->right_front_vel;
  }

  // Field name: right_middle_vel
  {
    cdr << ros_message->right_middle_vel;
  }

  // Field name: right_back_vel
  {
    cdr << ros_message->right_back_vel;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_osr_interfaces
bool cdr_deserialize_osr_interfaces__msg__CommandDrive(
  eprosima::fastcdr::Cdr & cdr,
  osr_interfaces__msg__CommandDrive * ros_message)
{
  // Field name: left_front_vel
  {
    cdr >> ros_message->left_front_vel;
  }

  // Field name: left_middle_vel
  {
    cdr >> ros_message->left_middle_vel;
  }

  // Field name: left_back_vel
  {
    cdr >> ros_message->left_back_vel;
  }

  // Field name: right_front_vel
  {
    cdr >> ros_message->right_front_vel;
  }

  // Field name: right_middle_vel
  {
    cdr >> ros_message->right_middle_vel;
  }

  // Field name: right_back_vel
  {
    cdr >> ros_message->right_back_vel;
  }

  return true;
}  // NOLINT(readability/fn_size)


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_osr_interfaces
size_t get_serialized_size_osr_interfaces__msg__CommandDrive(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _CommandDrive__ros_msg_type * ros_message = static_cast<const _CommandDrive__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: left_front_vel
  {
    size_t item_size = sizeof(ros_message->left_front_vel);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: left_middle_vel
  {
    size_t item_size = sizeof(ros_message->left_middle_vel);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: left_back_vel
  {
    size_t item_size = sizeof(ros_message->left_back_vel);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: right_front_vel
  {
    size_t item_size = sizeof(ros_message->right_front_vel);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: right_middle_vel
  {
    size_t item_size = sizeof(ros_message->right_middle_vel);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: right_back_vel
  {
    size_t item_size = sizeof(ros_message->right_back_vel);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_osr_interfaces
size_t max_serialized_size_osr_interfaces__msg__CommandDrive(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // Field name: left_front_vel
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: left_middle_vel
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: left_back_vel
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: right_front_vel
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: right_middle_vel
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: right_back_vel
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }


  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = osr_interfaces__msg__CommandDrive;
    is_plain =
      (
      offsetof(DataType, right_back_vel) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_osr_interfaces
bool cdr_serialize_key_osr_interfaces__msg__CommandDrive(
  const osr_interfaces__msg__CommandDrive * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: left_front_vel
  {
    cdr << ros_message->left_front_vel;
  }

  // Field name: left_middle_vel
  {
    cdr << ros_message->left_middle_vel;
  }

  // Field name: left_back_vel
  {
    cdr << ros_message->left_back_vel;
  }

  // Field name: right_front_vel
  {
    cdr << ros_message->right_front_vel;
  }

  // Field name: right_middle_vel
  {
    cdr << ros_message->right_middle_vel;
  }

  // Field name: right_back_vel
  {
    cdr << ros_message->right_back_vel;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_osr_interfaces
size_t get_serialized_size_key_osr_interfaces__msg__CommandDrive(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _CommandDrive__ros_msg_type * ros_message = static_cast<const _CommandDrive__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: left_front_vel
  {
    size_t item_size = sizeof(ros_message->left_front_vel);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: left_middle_vel
  {
    size_t item_size = sizeof(ros_message->left_middle_vel);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: left_back_vel
  {
    size_t item_size = sizeof(ros_message->left_back_vel);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: right_front_vel
  {
    size_t item_size = sizeof(ros_message->right_front_vel);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: right_middle_vel
  {
    size_t item_size = sizeof(ros_message->right_middle_vel);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: right_back_vel
  {
    size_t item_size = sizeof(ros_message->right_back_vel);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_osr_interfaces
size_t max_serialized_size_key_osr_interfaces__msg__CommandDrive(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;
  // Field name: left_front_vel
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: left_middle_vel
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: left_back_vel
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: right_front_vel
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: right_middle_vel
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: right_back_vel
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = osr_interfaces__msg__CommandDrive;
    is_plain =
      (
      offsetof(DataType, right_back_vel) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}


static bool _CommandDrive__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const osr_interfaces__msg__CommandDrive * ros_message = static_cast<const osr_interfaces__msg__CommandDrive *>(untyped_ros_message);
  (void)ros_message;
  return cdr_serialize_osr_interfaces__msg__CommandDrive(ros_message, cdr);
}

static bool _CommandDrive__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  osr_interfaces__msg__CommandDrive * ros_message = static_cast<osr_interfaces__msg__CommandDrive *>(untyped_ros_message);
  (void)ros_message;
  return cdr_deserialize_osr_interfaces__msg__CommandDrive(cdr, ros_message);
}

static uint32_t _CommandDrive__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_osr_interfaces__msg__CommandDrive(
      untyped_ros_message, 0));
}

static size_t _CommandDrive__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_osr_interfaces__msg__CommandDrive(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_CommandDrive = {
  "osr_interfaces::msg",
  "CommandDrive",
  _CommandDrive__cdr_serialize,
  _CommandDrive__cdr_deserialize,
  _CommandDrive__get_serialized_size,
  _CommandDrive__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _CommandDrive__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_CommandDrive,
  get_message_typesupport_handle_function,
  &osr_interfaces__msg__CommandDrive__get_type_hash,
  &osr_interfaces__msg__CommandDrive__get_type_description,
  &osr_interfaces__msg__CommandDrive__get_type_description_sources,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, osr_interfaces, msg, CommandDrive)() {
  return &_CommandDrive__type_support;
}

#if defined(__cplusplus)
}
#endif
