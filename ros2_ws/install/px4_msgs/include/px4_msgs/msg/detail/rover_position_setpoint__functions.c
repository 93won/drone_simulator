// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from px4_msgs:msg/RoverPositionSetpoint.idl
// generated code does not contain a copyright notice
#include "px4_msgs/msg/detail/rover_position_setpoint__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


bool
px4_msgs__msg__RoverPositionSetpoint__init(px4_msgs__msg__RoverPositionSetpoint * msg)
{
  if (!msg) {
    return false;
  }
  // timestamp
  // position_ned
  // start_ned
  // cruising_speed
  // arrival_speed
  // yaw
  return true;
}

void
px4_msgs__msg__RoverPositionSetpoint__fini(px4_msgs__msg__RoverPositionSetpoint * msg)
{
  if (!msg) {
    return;
  }
  // timestamp
  // position_ned
  // start_ned
  // cruising_speed
  // arrival_speed
  // yaw
}

bool
px4_msgs__msg__RoverPositionSetpoint__are_equal(const px4_msgs__msg__RoverPositionSetpoint * lhs, const px4_msgs__msg__RoverPositionSetpoint * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // timestamp
  if (lhs->timestamp != rhs->timestamp) {
    return false;
  }
  // position_ned
  for (size_t i = 0; i < 2; ++i) {
    if (lhs->position_ned[i] != rhs->position_ned[i]) {
      return false;
    }
  }
  // start_ned
  for (size_t i = 0; i < 2; ++i) {
    if (lhs->start_ned[i] != rhs->start_ned[i]) {
      return false;
    }
  }
  // cruising_speed
  if (lhs->cruising_speed != rhs->cruising_speed) {
    return false;
  }
  // arrival_speed
  if (lhs->arrival_speed != rhs->arrival_speed) {
    return false;
  }
  // yaw
  if (lhs->yaw != rhs->yaw) {
    return false;
  }
  return true;
}

bool
px4_msgs__msg__RoverPositionSetpoint__copy(
  const px4_msgs__msg__RoverPositionSetpoint * input,
  px4_msgs__msg__RoverPositionSetpoint * output)
{
  if (!input || !output) {
    return false;
  }
  // timestamp
  output->timestamp = input->timestamp;
  // position_ned
  for (size_t i = 0; i < 2; ++i) {
    output->position_ned[i] = input->position_ned[i];
  }
  // start_ned
  for (size_t i = 0; i < 2; ++i) {
    output->start_ned[i] = input->start_ned[i];
  }
  // cruising_speed
  output->cruising_speed = input->cruising_speed;
  // arrival_speed
  output->arrival_speed = input->arrival_speed;
  // yaw
  output->yaw = input->yaw;
  return true;
}

px4_msgs__msg__RoverPositionSetpoint *
px4_msgs__msg__RoverPositionSetpoint__create()
{
  px4_msgs__msg__RoverPositionSetpoint * msg = (px4_msgs__msg__RoverPositionSetpoint *)malloc(sizeof(px4_msgs__msg__RoverPositionSetpoint));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(px4_msgs__msg__RoverPositionSetpoint));
  bool success = px4_msgs__msg__RoverPositionSetpoint__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
px4_msgs__msg__RoverPositionSetpoint__destroy(px4_msgs__msg__RoverPositionSetpoint * msg)
{
  if (msg) {
    px4_msgs__msg__RoverPositionSetpoint__fini(msg);
  }
  free(msg);
}


bool
px4_msgs__msg__RoverPositionSetpoint__Sequence__init(px4_msgs__msg__RoverPositionSetpoint__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  px4_msgs__msg__RoverPositionSetpoint * data = NULL;
  if (size) {
    data = (px4_msgs__msg__RoverPositionSetpoint *)calloc(size, sizeof(px4_msgs__msg__RoverPositionSetpoint));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = px4_msgs__msg__RoverPositionSetpoint__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        px4_msgs__msg__RoverPositionSetpoint__fini(&data[i - 1]);
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
px4_msgs__msg__RoverPositionSetpoint__Sequence__fini(px4_msgs__msg__RoverPositionSetpoint__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      px4_msgs__msg__RoverPositionSetpoint__fini(&array->data[i]);
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

px4_msgs__msg__RoverPositionSetpoint__Sequence *
px4_msgs__msg__RoverPositionSetpoint__Sequence__create(size_t size)
{
  px4_msgs__msg__RoverPositionSetpoint__Sequence * array = (px4_msgs__msg__RoverPositionSetpoint__Sequence *)malloc(sizeof(px4_msgs__msg__RoverPositionSetpoint__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = px4_msgs__msg__RoverPositionSetpoint__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
px4_msgs__msg__RoverPositionSetpoint__Sequence__destroy(px4_msgs__msg__RoverPositionSetpoint__Sequence * array)
{
  if (array) {
    px4_msgs__msg__RoverPositionSetpoint__Sequence__fini(array);
  }
  free(array);
}

bool
px4_msgs__msg__RoverPositionSetpoint__Sequence__are_equal(const px4_msgs__msg__RoverPositionSetpoint__Sequence * lhs, const px4_msgs__msg__RoverPositionSetpoint__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!px4_msgs__msg__RoverPositionSetpoint__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
px4_msgs__msg__RoverPositionSetpoint__Sequence__copy(
  const px4_msgs__msg__RoverPositionSetpoint__Sequence * input,
  px4_msgs__msg__RoverPositionSetpoint__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(px4_msgs__msg__RoverPositionSetpoint);
    px4_msgs__msg__RoverPositionSetpoint * data =
      (px4_msgs__msg__RoverPositionSetpoint *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!px4_msgs__msg__RoverPositionSetpoint__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          px4_msgs__msg__RoverPositionSetpoint__fini(&data[i]);
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
    if (!px4_msgs__msg__RoverPositionSetpoint__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
