// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from osr_interfaces:msg/CommandDrive.idl
// generated code does not contain a copyright notice
#include "osr_interfaces/msg/detail/command_drive__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
osr_interfaces__msg__CommandDrive__init(osr_interfaces__msg__CommandDrive * msg)
{
  if (!msg) {
    return false;
  }
  // left_front_vel
  // left_middle_vel
  // left_back_vel
  // right_front_vel
  // right_middle_vel
  // right_back_vel
  return true;
}

void
osr_interfaces__msg__CommandDrive__fini(osr_interfaces__msg__CommandDrive * msg)
{
  if (!msg) {
    return;
  }
  // left_front_vel
  // left_middle_vel
  // left_back_vel
  // right_front_vel
  // right_middle_vel
  // right_back_vel
}

bool
osr_interfaces__msg__CommandDrive__are_equal(const osr_interfaces__msg__CommandDrive * lhs, const osr_interfaces__msg__CommandDrive * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // left_front_vel
  if (lhs->left_front_vel != rhs->left_front_vel) {
    return false;
  }
  // left_middle_vel
  if (lhs->left_middle_vel != rhs->left_middle_vel) {
    return false;
  }
  // left_back_vel
  if (lhs->left_back_vel != rhs->left_back_vel) {
    return false;
  }
  // right_front_vel
  if (lhs->right_front_vel != rhs->right_front_vel) {
    return false;
  }
  // right_middle_vel
  if (lhs->right_middle_vel != rhs->right_middle_vel) {
    return false;
  }
  // right_back_vel
  if (lhs->right_back_vel != rhs->right_back_vel) {
    return false;
  }
  return true;
}

bool
osr_interfaces__msg__CommandDrive__copy(
  const osr_interfaces__msg__CommandDrive * input,
  osr_interfaces__msg__CommandDrive * output)
{
  if (!input || !output) {
    return false;
  }
  // left_front_vel
  output->left_front_vel = input->left_front_vel;
  // left_middle_vel
  output->left_middle_vel = input->left_middle_vel;
  // left_back_vel
  output->left_back_vel = input->left_back_vel;
  // right_front_vel
  output->right_front_vel = input->right_front_vel;
  // right_middle_vel
  output->right_middle_vel = input->right_middle_vel;
  // right_back_vel
  output->right_back_vel = input->right_back_vel;
  return true;
}

osr_interfaces__msg__CommandDrive *
osr_interfaces__msg__CommandDrive__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  osr_interfaces__msg__CommandDrive * msg = (osr_interfaces__msg__CommandDrive *)allocator.allocate(sizeof(osr_interfaces__msg__CommandDrive), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(osr_interfaces__msg__CommandDrive));
  bool success = osr_interfaces__msg__CommandDrive__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
osr_interfaces__msg__CommandDrive__destroy(osr_interfaces__msg__CommandDrive * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    osr_interfaces__msg__CommandDrive__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
osr_interfaces__msg__CommandDrive__Sequence__init(osr_interfaces__msg__CommandDrive__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  osr_interfaces__msg__CommandDrive * data = NULL;

  if (size) {
    data = (osr_interfaces__msg__CommandDrive *)allocator.zero_allocate(size, sizeof(osr_interfaces__msg__CommandDrive), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = osr_interfaces__msg__CommandDrive__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        osr_interfaces__msg__CommandDrive__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
osr_interfaces__msg__CommandDrive__Sequence__fini(osr_interfaces__msg__CommandDrive__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      osr_interfaces__msg__CommandDrive__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

osr_interfaces__msg__CommandDrive__Sequence *
osr_interfaces__msg__CommandDrive__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  osr_interfaces__msg__CommandDrive__Sequence * array = (osr_interfaces__msg__CommandDrive__Sequence *)allocator.allocate(sizeof(osr_interfaces__msg__CommandDrive__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = osr_interfaces__msg__CommandDrive__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
osr_interfaces__msg__CommandDrive__Sequence__destroy(osr_interfaces__msg__CommandDrive__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    osr_interfaces__msg__CommandDrive__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
osr_interfaces__msg__CommandDrive__Sequence__are_equal(const osr_interfaces__msg__CommandDrive__Sequence * lhs, const osr_interfaces__msg__CommandDrive__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!osr_interfaces__msg__CommandDrive__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
osr_interfaces__msg__CommandDrive__Sequence__copy(
  const osr_interfaces__msg__CommandDrive__Sequence * input,
  osr_interfaces__msg__CommandDrive__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(osr_interfaces__msg__CommandDrive);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    osr_interfaces__msg__CommandDrive * data =
      (osr_interfaces__msg__CommandDrive *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!osr_interfaces__msg__CommandDrive__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          osr_interfaces__msg__CommandDrive__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!osr_interfaces__msg__CommandDrive__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
