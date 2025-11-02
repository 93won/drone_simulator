// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from px4_msgs:msg/RoverSpeedSetpoint.idl
// generated code does not contain a copyright notice
#include "px4_msgs/msg/detail/rover_speed_setpoint__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


bool
px4_msgs__msg__RoverSpeedSetpoint__init(px4_msgs__msg__RoverSpeedSetpoint * msg)
{
  if (!msg) {
    return false;
  }
  // timestamp
  // speed_body_x
  // speed_body_y
  return true;
}

void
px4_msgs__msg__RoverSpeedSetpoint__fini(px4_msgs__msg__RoverSpeedSetpoint * msg)
{
  if (!msg) {
    return;
  }
  // timestamp
  // speed_body_x
  // speed_body_y
}

bool
px4_msgs__msg__RoverSpeedSetpoint__are_equal(const px4_msgs__msg__RoverSpeedSetpoint * lhs, const px4_msgs__msg__RoverSpeedSetpoint * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // timestamp
  if (lhs->timestamp != rhs->timestamp) {
    return false;
  }
  // speed_body_x
  if (lhs->speed_body_x != rhs->speed_body_x) {
    return false;
  }
  // speed_body_y
  if (lhs->speed_body_y != rhs->speed_body_y) {
    return false;
  }
  return true;
}

bool
px4_msgs__msg__RoverSpeedSetpoint__copy(
  const px4_msgs__msg__RoverSpeedSetpoint * input,
  px4_msgs__msg__RoverSpeedSetpoint * output)
{
  if (!input || !output) {
    return false;
  }
  // timestamp
  output->timestamp = input->timestamp;
  // speed_body_x
  output->speed_body_x = input->speed_body_x;
  // speed_body_y
  output->speed_body_y = input->speed_body_y;
  return true;
}

px4_msgs__msg__RoverSpeedSetpoint *
px4_msgs__msg__RoverSpeedSetpoint__create()
{
  px4_msgs__msg__RoverSpeedSetpoint * msg = (px4_msgs__msg__RoverSpeedSetpoint *)malloc(sizeof(px4_msgs__msg__RoverSpeedSetpoint));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(px4_msgs__msg__RoverSpeedSetpoint));
  bool success = px4_msgs__msg__RoverSpeedSetpoint__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
px4_msgs__msg__RoverSpeedSetpoint__destroy(px4_msgs__msg__RoverSpeedSetpoint * msg)
{
  if (msg) {
    px4_msgs__msg__RoverSpeedSetpoint__fini(msg);
  }
  free(msg);
}


bool
px4_msgs__msg__RoverSpeedSetpoint__Sequence__init(px4_msgs__msg__RoverSpeedSetpoint__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  px4_msgs__msg__RoverSpeedSetpoint * data = NULL;
  if (size) {
    data = (px4_msgs__msg__RoverSpeedSetpoint *)calloc(size, sizeof(px4_msgs__msg__RoverSpeedSetpoint));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = px4_msgs__msg__RoverSpeedSetpoint__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        px4_msgs__msg__RoverSpeedSetpoint__fini(&data[i - 1]);
      }
      free(data);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
px4_msgs__msg__RoverSpeedSetpoint__Sequence__fini(px4_msgs__msg__RoverSpeedSetpoint__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      px4_msgs__msg__RoverSpeedSetpoint__fini(&array->data[i]);
    }
    free(array->data);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

px4_msgs__msg__RoverSpeedSetpoint__Sequence *
px4_msgs__msg__RoverSpeedSetpoint__Sequence__create(size_t size)
{
  px4_msgs__msg__RoverSpeedSetpoint__Sequence * array = (px4_msgs__msg__RoverSpeedSetpoint__Sequence *)malloc(sizeof(px4_msgs__msg__RoverSpeedSetpoint__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = px4_msgs__msg__RoverSpeedSetpoint__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
px4_msgs__msg__RoverSpeedSetpoint__Sequence__destroy(px4_msgs__msg__RoverSpeedSetpoint__Sequence * array)
{
  if (array) {
    px4_msgs__msg__RoverSpeedSetpoint__Sequence__fini(array);
  }
  free(array);
}

bool
px4_msgs__msg__RoverSpeedSetpoint__Sequence__are_equal(const px4_msgs__msg__RoverSpeedSetpoint__Sequence * lhs, const px4_msgs__msg__RoverSpeedSetpoint__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!px4_msgs__msg__RoverSpeedSetpoint__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
px4_msgs__msg__RoverSpeedSetpoint__Sequence__copy(
  const px4_msgs__msg__RoverSpeedSetpoint__Sequence * input,
  px4_msgs__msg__RoverSpeedSetpoint__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(px4_msgs__msg__RoverSpeedSetpoint);
    px4_msgs__msg__RoverSpeedSetpoint * data =
      (px4_msgs__msg__RoverSpeedSetpoint *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!px4_msgs__msg__RoverSpeedSetpoint__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          px4_msgs__msg__RoverSpeedSetpoint__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!px4_msgs__msg__RoverSpeedSetpoint__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
