// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from osr_interfaces:msg/Status.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "osr_interfaces/msg/status.h"


#ifndef OSR_INTERFACES__MSG__DETAIL__STATUS__STRUCT_H_
#define OSR_INTERFACES__MSG__DETAIL__STATUS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'error_status'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/Status in the package osr_interfaces.
/**
  * voltage level being read into the RoboClaws, in Volts
 */
typedef struct osr_interfaces__msg__Status
{
  float battery;
  /// status of an error being present on each RoboClaw. Stringified hex
  rosidl_runtime_c__String error_status[3];
  /// Temperature of the motor controllers expressed in Celsius
  float temp[3];
  /// Sensed current from the motor controllers in Ampere
  float current[6];
} osr_interfaces__msg__Status;

// Struct for a sequence of osr_interfaces__msg__Status.
typedef struct osr_interfaces__msg__Status__Sequence
{
  osr_interfaces__msg__Status * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} osr_interfaces__msg__Status__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // OSR_INTERFACES__MSG__DETAIL__STATUS__STRUCT_H_
