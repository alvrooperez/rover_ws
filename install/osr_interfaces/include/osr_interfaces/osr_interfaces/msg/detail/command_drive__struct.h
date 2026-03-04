// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from osr_interfaces:msg/CommandDrive.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "osr_interfaces/msg/command_drive.h"


#ifndef OSR_INTERFACES__MSG__DETAIL__COMMAND_DRIVE__STRUCT_H_
#define OSR_INTERFACES__MSG__DETAIL__COMMAND_DRIVE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

/// Struct defined in msg/CommandDrive in the package osr_interfaces.
/**
  * drive motors, velocity in rad/s
 */
typedef struct osr_interfaces__msg__CommandDrive
{
  double left_front_vel;
  double left_middle_vel;
  double left_back_vel;
  double right_front_vel;
  double right_middle_vel;
  double right_back_vel;
} osr_interfaces__msg__CommandDrive;

// Struct for a sequence of osr_interfaces__msg__CommandDrive.
typedef struct osr_interfaces__msg__CommandDrive__Sequence
{
  osr_interfaces__msg__CommandDrive * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} osr_interfaces__msg__CommandDrive__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // OSR_INTERFACES__MSG__DETAIL__COMMAND_DRIVE__STRUCT_H_
