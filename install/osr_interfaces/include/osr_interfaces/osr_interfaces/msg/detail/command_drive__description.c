// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from osr_interfaces:msg/CommandDrive.idl
// generated code does not contain a copyright notice

#include "osr_interfaces/msg/detail/command_drive__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_osr_interfaces
const rosidl_type_hash_t *
osr_interfaces__msg__CommandDrive__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x3e, 0x4d, 0x6a, 0xd2, 0x70, 0x8b, 0x95, 0x27,
      0x1e, 0xea, 0x22, 0x68, 0x10, 0x52, 0xe8, 0x14,
      0xab, 0x20, 0x4e, 0x4b, 0x3b, 0xf1, 0xf3, 0x90,
      0x79, 0x6f, 0x61, 0x69, 0xc0, 0x54, 0xe4, 0xce,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char osr_interfaces__msg__CommandDrive__TYPE_NAME[] = "osr_interfaces/msg/CommandDrive";

// Define type names, field names, and default values
static char osr_interfaces__msg__CommandDrive__FIELD_NAME__left_front_vel[] = "left_front_vel";
static char osr_interfaces__msg__CommandDrive__FIELD_NAME__left_middle_vel[] = "left_middle_vel";
static char osr_interfaces__msg__CommandDrive__FIELD_NAME__left_back_vel[] = "left_back_vel";
static char osr_interfaces__msg__CommandDrive__FIELD_NAME__right_front_vel[] = "right_front_vel";
static char osr_interfaces__msg__CommandDrive__FIELD_NAME__right_middle_vel[] = "right_middle_vel";
static char osr_interfaces__msg__CommandDrive__FIELD_NAME__right_back_vel[] = "right_back_vel";

static rosidl_runtime_c__type_description__Field osr_interfaces__msg__CommandDrive__FIELDS[] = {
  {
    {osr_interfaces__msg__CommandDrive__FIELD_NAME__left_front_vel, 14, 14},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {osr_interfaces__msg__CommandDrive__FIELD_NAME__left_middle_vel, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {osr_interfaces__msg__CommandDrive__FIELD_NAME__left_back_vel, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {osr_interfaces__msg__CommandDrive__FIELD_NAME__right_front_vel, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {osr_interfaces__msg__CommandDrive__FIELD_NAME__right_middle_vel, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {osr_interfaces__msg__CommandDrive__FIELD_NAME__right_back_vel, 14, 14},
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
osr_interfaces__msg__CommandDrive__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {osr_interfaces__msg__CommandDrive__TYPE_NAME, 31, 31},
      {osr_interfaces__msg__CommandDrive__FIELDS, 6, 6},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "# drive motors, velocity in rad/s\n"
  "float64 left_front_vel\n"
  "float64 left_middle_vel\n"
  "float64 left_back_vel\n"
  "float64 right_front_vel\n"
  "float64 right_middle_vel\n"
  "float64 right_back_vel";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
osr_interfaces__msg__CommandDrive__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {osr_interfaces__msg__CommandDrive__TYPE_NAME, 31, 31},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 174, 174},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
osr_interfaces__msg__CommandDrive__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *osr_interfaces__msg__CommandDrive__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
