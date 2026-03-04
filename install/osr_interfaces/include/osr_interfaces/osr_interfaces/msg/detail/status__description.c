// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from osr_interfaces:msg/Status.idl
// generated code does not contain a copyright notice

#include "osr_interfaces/msg/detail/status__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_osr_interfaces
const rosidl_type_hash_t *
osr_interfaces__msg__Status__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x9e, 0x1a, 0x0c, 0xd0, 0xff, 0x05, 0x23, 0x0b,
      0xcc, 0xf9, 0xda, 0x4c, 0x99, 0x41, 0x70, 0x35,
      0x92, 0x97, 0x68, 0xc8, 0x36, 0x63, 0xe5, 0xdb,
      0x90, 0xb3, 0x9f, 0xfa, 0x66, 0x19, 0xbb, 0x92,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char osr_interfaces__msg__Status__TYPE_NAME[] = "osr_interfaces/msg/Status";

// Define type names, field names, and default values
static char osr_interfaces__msg__Status__FIELD_NAME__battery[] = "battery";
static char osr_interfaces__msg__Status__FIELD_NAME__error_status[] = "error_status";
static char osr_interfaces__msg__Status__FIELD_NAME__temp[] = "temp";
static char osr_interfaces__msg__Status__FIELD_NAME__current[] = "current";

static rosidl_runtime_c__type_description__Field osr_interfaces__msg__Status__FIELDS[] = {
  {
    {osr_interfaces__msg__Status__FIELD_NAME__battery, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {osr_interfaces__msg__Status__FIELD_NAME__error_status, 12, 12},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING_ARRAY,
      3,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {osr_interfaces__msg__Status__FIELD_NAME__temp, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT_ARRAY,
      3,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {osr_interfaces__msg__Status__FIELD_NAME__current, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT_ARRAY,
      6,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
osr_interfaces__msg__Status__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {osr_interfaces__msg__Status__TYPE_NAME, 25, 25},
      {osr_interfaces__msg__Status__FIELDS, 4, 4},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "# voltage level being read into the RoboClaws, in Volts\n"
  "float32 battery\n"
  "# status of an error being present on each RoboClaw. Stringified hex\n"
  "string[3] error_status\n"
  "# Temperature of the motor controllers expressed in Celsius\n"
  "float32[3] temp\n"
  "# Sensed current from the motor controllers in Ampere\n"
  "float32[6] current";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
osr_interfaces__msg__Status__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {osr_interfaces__msg__Status__TYPE_NAME, 25, 25},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 313, 313},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
osr_interfaces__msg__Status__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *osr_interfaces__msg__Status__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
