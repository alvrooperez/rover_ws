// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from osr_interfaces:msg/CommandCorner.idl
// generated code does not contain a copyright notice

#include "osr_interfaces/msg/detail/command_corner__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_osr_interfaces
const rosidl_type_hash_t *
osr_interfaces__msg__CommandCorner__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x83, 0x6d, 0x00, 0x14, 0x13, 0xab, 0xf2, 0x6d,
      0x5b, 0xf6, 0xe9, 0xa6, 0x43, 0xbc, 0xa8, 0x00,
      0xfd, 0x4b, 0x36, 0xa8, 0x9b, 0x03, 0x58, 0x1b,
      0x48, 0x48, 0x9d, 0xef, 0xc4, 0x27, 0x38, 0x2b,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char osr_interfaces__msg__CommandCorner__TYPE_NAME[] = "osr_interfaces/msg/CommandCorner";

// Define type names, field names, and default values
static char osr_interfaces__msg__CommandCorner__FIELD_NAME__left_front_pos[] = "left_front_pos";
static char osr_interfaces__msg__CommandCorner__FIELD_NAME__left_back_pos[] = "left_back_pos";
static char osr_interfaces__msg__CommandCorner__FIELD_NAME__right_front_pos[] = "right_front_pos";
static char osr_interfaces__msg__CommandCorner__FIELD_NAME__right_back_pos[] = "right_back_pos";

static rosidl_runtime_c__type_description__Field osr_interfaces__msg__CommandCorner__FIELDS[] = {
  {
    {osr_interfaces__msg__CommandCorner__FIELD_NAME__left_front_pos, 14, 14},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {osr_interfaces__msg__CommandCorner__FIELD_NAME__left_back_pos, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {osr_interfaces__msg__CommandCorner__FIELD_NAME__right_front_pos, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {osr_interfaces__msg__CommandCorner__FIELD_NAME__right_back_pos, 14, 14},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
osr_interfaces__msg__CommandCorner__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {osr_interfaces__msg__CommandCorner__TYPE_NAME, 32, 32},
      {osr_interfaces__msg__CommandCorner__FIELDS, 4, 4},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "# corner motors, position in rad around the vertical z-axis, with zero indicating the position where the wheels are straight\n"
  "float64 left_front_pos\n"
  "float64 left_back_pos\n"
  "float64 right_front_pos\n"
  "float64 right_back_pos";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
osr_interfaces__msg__CommandCorner__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {osr_interfaces__msg__CommandCorner__TYPE_NAME, 32, 32},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 216, 216},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
osr_interfaces__msg__CommandCorner__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *osr_interfaces__msg__CommandCorner__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
