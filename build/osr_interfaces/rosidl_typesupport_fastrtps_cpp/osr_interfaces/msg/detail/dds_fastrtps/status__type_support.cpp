// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from osr_interfaces:msg/Status.idl
// generated code does not contain a copyright notice
#include "osr_interfaces/msg/detail/status__rosidl_typesupport_fastrtps_cpp.hpp"
#include "osr_interfaces/msg/detail/status__functions.h"
#include "osr_interfaces/msg/detail/status__struct.hpp"

#include <cstddef>
#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

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
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: battery
  cdr << ros_message.battery;

  // Member: error_status
  {
    cdr << ros_message.error_status;
  }

  // Member: temp
  {
    cdr << ros_message.temp;
  }

  // Member: current
  {
    cdr << ros_message.current;
  }

  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_osr_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  osr_interfaces::msg::Status & ros_message)
{
  // Member: battery
  cdr >> ros_message.battery;

  // Member: error_status
  {
    cdr >> ros_message.error_status;
  }

  // Member: temp
  {
    cdr >> ros_message.temp;
  }

  // Member: current
  {
    cdr >> ros_message.current;
  }

  return true;
}  // NOLINT(readability/fn_size)


size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_osr_interfaces
get_serialized_size(
  const osr_interfaces::msg::Status & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: battery
  {
    size_t item_size = sizeof(ros_message.battery);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: error_status
  {
    size_t array_size = 3;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        (ros_message.error_status[index].size() + 1);
    }
  }

  // Member: temp
  {
    size_t array_size = 3;
    size_t item_size = sizeof(ros_message.temp[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: current
  {
    size_t array_size = 6;
    size_t item_size = sizeof(ros_message.current[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}


size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_osr_interfaces
max_serialized_size_Status(
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

  // Member: battery
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // Member: error_status
  {
    size_t array_size = 3;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }
  // Member: temp
  {
    size_t array_size = 3;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // Member: current
  {
    size_t array_size = 6;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = osr_interfaces::msg::Status;
    is_plain =
      (
      offsetof(DataType, current) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_osr_interfaces
cdr_serialize_key(
  const osr_interfaces::msg::Status & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: battery
  cdr << ros_message.battery;

  // Member: error_status
  {
    cdr << ros_message.error_status;
  }

  // Member: temp
  {
    cdr << ros_message.temp;
  }

  // Member: current
  {
    cdr << ros_message.current;
  }

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_osr_interfaces
get_serialized_size_key(
  const osr_interfaces::msg::Status & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: battery
  {
    size_t item_size = sizeof(ros_message.battery);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: error_status
  {
    size_t array_size = 3;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        (ros_message.error_status[index].size() + 1);
    }
  }

  // Member: temp
  {
    size_t array_size = 3;
    size_t item_size = sizeof(ros_message.temp[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: current
  {
    size_t array_size = 6;
    size_t item_size = sizeof(ros_message.current[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_osr_interfaces
max_serialized_size_key_Status(
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

  // Member: battery
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: error_status
  {
    size_t array_size = 3;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Member: temp
  {
    size_t array_size = 3;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: current
  {
    size_t array_size = 6;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = osr_interfaces::msg::Status;
    is_plain =
      (
      offsetof(DataType, current) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}


static bool _Status__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const osr_interfaces::msg::Status *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _Status__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<osr_interfaces::msg::Status *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _Status__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const osr_interfaces::msg::Status *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _Status__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_Status(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _Status__callbacks = {
  "osr_interfaces::msg",
  "Status",
  _Status__cdr_serialize,
  _Status__cdr_deserialize,
  _Status__get_serialized_size,
  _Status__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _Status__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_Status__callbacks,
  get_message_typesupport_handle_function,
  &osr_interfaces__msg__Status__get_type_hash,
  &osr_interfaces__msg__Status__get_type_description,
  &osr_interfaces__msg__Status__get_type_description_sources,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace osr_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_osr_interfaces
const rosidl_message_type_support_t *
get_message_type_support_handle<osr_interfaces::msg::Status>()
{
  return &osr_interfaces::msg::typesupport_fastrtps_cpp::_Status__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, osr_interfaces, msg, Status)() {
  return &osr_interfaces::msg::typesupport_fastrtps_cpp::_Status__handle;
}

#ifdef __cplusplus
}
#endif
