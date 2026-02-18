// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from osr_interfaces:msg/CommandCorner.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "osr_interfaces/msg/command_corner.h"


#ifndef OSR_INTERFACES__MSG__DETAIL__COMMAND_CORNER__STRUCT_H_
#define OSR_INTERFACES__MSG__DETAIL__COMMAND_CORNER__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

/// Struct defined in msg/CommandCorner in the package osr_interfaces.
/**
  * corner motors, position in rad around the vertical z-axis, with zero indicating the position where the wheels are straight
 */
typedef struct osr_interfaces__msg__CommandCorner
{
  double left_front_pos;
  double left_back_pos;
  double right_front_pos;
  double right_back_pos;
} osr_interfaces__msg__CommandCorner;

// Struct for a sequence of osr_interfaces__msg__CommandCorner.
typedef struct osr_interfaces__msg__CommandCorner__Sequence
{
  osr_interfaces__msg__CommandCorner * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} osr_interfaces__msg__CommandCorner__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // OSR_INTERFACES__MSG__DETAIL__COMMAND_CORNER__STRUCT_H_
