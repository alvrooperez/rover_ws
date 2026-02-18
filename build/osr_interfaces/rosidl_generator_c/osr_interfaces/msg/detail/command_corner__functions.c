// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from osr_interfaces:msg/CommandCorner.idl
// generated code does not contain a copyright notice
#include "osr_interfaces/msg/detail/command_corner__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
osr_interfaces__msg__CommandCorner__init(osr_interfaces__msg__CommandCorner * msg)
{
  if (!msg) {
    return false;
  }
  // left_front_pos
  // left_back_pos
  // right_front_pos
  // right_back_pos
  return true;
}

void
osr_interfaces__msg__CommandCorner__fini(osr_interfaces__msg__CommandCorner * msg)
{
  if (!msg) {
    return;
  }
  // left_front_pos
  // left_back_pos
  // right_front_pos
  // right_back_pos
}

bool
osr_interfaces__msg__CommandCorner__are_equal(const osr_interfaces__msg__CommandCorner * lhs, const osr_interfaces__msg__CommandCorner * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // left_front_pos
  if (lhs->left_front_pos != rhs->left_front_pos) {
    return false;
  }
  // left_back_pos
  if (lhs->left_back_pos != rhs->left_back_pos) {
    return false;
  }
  // right_front_pos
  if (lhs->right_front_pos != rhs->right_front_pos) {
    return false;
  }
  // right_back_pos
  if (lhs->right_back_pos != rhs->right_back_pos) {
    return false;
  }
  return true;
}

bool
osr_interfaces__msg__CommandCorner__copy(
  const osr_interfaces__msg__CommandCorner * input,
  osr_interfaces__msg__CommandCorner * output)
{
  if (!input || !output) {
    return false;
  }
  // left_front_pos
  output->left_front_pos = input->left_front_pos;
  // left_back_pos
  output->left_back_pos = input->left_back_pos;
  // right_front_pos
  output->right_front_pos = input->right_front_pos;
  // right_back_pos
  output->right_back_pos = input->right_back_pos;
  return true;
}

osr_interfaces__msg__CommandCorner *
osr_interfaces__msg__CommandCorner__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  osr_interfaces__msg__CommandCorner * msg = (osr_interfaces__msg__CommandCorner *)allocator.allocate(sizeof(osr_interfaces__msg__CommandCorner), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(osr_interfaces__msg__CommandCorner));
  bool success = osr_interfaces__msg__CommandCorner__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
osr_interfaces__msg__CommandCorner__destroy(osr_interfaces__msg__CommandCorner * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    osr_interfaces__msg__CommandCorner__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
osr_interfaces__msg__CommandCorner__Sequence__init(osr_interfaces__msg__CommandCorner__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  osr_interfaces__msg__CommandCorner * data = NULL;

  if (size) {
    data = (osr_interfaces__msg__CommandCorner *)allocator.zero_allocate(size, sizeof(osr_interfaces__msg__CommandCorner), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = osr_interfaces__msg__CommandCorner__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        osr_interfaces__msg__CommandCorner__fini(&data[i - 1]);
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
osr_interfaces__msg__CommandCorner__Sequence__fini(osr_interfaces__msg__CommandCorner__Sequence * array)
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
      osr_interfaces__msg__CommandCorner__fini(&array->data[i]);
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

osr_interfaces__msg__CommandCorner__Sequence *
osr_interfaces__msg__CommandCorner__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  osr_interfaces__msg__CommandCorner__Sequence * array = (osr_interfaces__msg__CommandCorner__Sequence *)allocator.allocate(sizeof(osr_interfaces__msg__CommandCorner__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = osr_interfaces__msg__CommandCorner__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
osr_interfaces__msg__CommandCorner__Sequence__destroy(osr_interfaces__msg__CommandCorner__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    osr_interfaces__msg__CommandCorner__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
osr_interfaces__msg__CommandCorner__Sequence__are_equal(const osr_interfaces__msg__CommandCorner__Sequence * lhs, const osr_interfaces__msg__CommandCorner__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!osr_interfaces__msg__CommandCorner__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
osr_interfaces__msg__CommandCorner__Sequence__copy(
  const osr_interfaces__msg__CommandCorner__Sequence * input,
  osr_interfaces__msg__CommandCorner__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(osr_interfaces__msg__CommandCorner);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    osr_interfaces__msg__CommandCorner * data =
      (osr_interfaces__msg__CommandCorner *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!osr_interfaces__msg__CommandCorner__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          osr_interfaces__msg__CommandCorner__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!osr_interfaces__msg__CommandCorner__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
