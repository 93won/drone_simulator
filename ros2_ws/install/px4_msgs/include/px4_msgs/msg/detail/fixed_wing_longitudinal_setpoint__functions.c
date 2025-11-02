// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from px4_msgs:msg/FixedWingLongitudinalSetpoint.idl
// generated code does not contain a copyright notice
#include "px4_msgs/msg/detail/fixed_wing_longitudinal_setpoint__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


bool
px4_msgs__msg__FixedWingLongitudinalSetpoint__init(px4_msgs__msg__FixedWingLongitudinalSetpoint * msg)
{
  if (!msg) {
    return false;
  }
  // timestamp
  // altitude
  // height_rate
  // equivalent_airspeed
  // pitch_direct
  // throttle_direct
  return true;
}

void
px4_msgs__msg__FixedWingLongitudinalSetpoint__fini(px4_msgs__msg__FixedWingLongitudinalSetpoint * msg)
{
  if (!msg) {
    return;
  }
  // timestamp
  // altitude
  // height_rate
  // equivalent_airspeed
  // pitch_direct
  // throttle_direct
}

bool
px4_msgs__msg__FixedWingLongitudinalSetpoint__are_equal(const px4_msgs__msg__FixedWingLongitudinalSetpoint * lhs, const px4_msgs__msg__FixedWingLongitudinalSetpoint * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // timestamp
  if (lhs->timestamp != rhs->timestamp) {
    return false;
  }
  // altitude
  if (lhs->altitude != rhs->altitude) {
    return false;
  }
  // height_rate
  if (lhs->height_rate != rhs->height_rate) {
    return false;
  }
  // equivalent_airspeed
  if (lhs->equivalent_airspeed != rhs->equivalent_airspeed) {
    return false;
  }
  // pitch_direct
  if (lhs->pitch_direct != rhs->pitch_direct) {
    return false;
  }
  // throttle_direct
  if (lhs->throttle_direct != rhs->throttle_direct) {
    return false;
  }
  return true;
}

bool
px4_msgs__msg__FixedWingLongitudinalSetpoint__copy(
  const px4_msgs__msg__FixedWingLongitudinalSetpoint * input,
  px4_msgs__msg__FixedWingLongitudinalSetpoint * output)
{
  if (!input || !output) {
    return false;
  }
  // timestamp
  output->timestamp = input->timestamp;
  // altitude
  output->altitude = input->altitude;
  // height_rate
  output->height_rate = input->height_rate;
  // equivalent_airspeed
  output->equivalent_airspeed = input->equivalent_airspeed;
  // pitch_direct
  output->pitch_direct = input->pitch_direct;
  // throttle_direct
  output->throttle_direct = input->throttle_direct;
  return true;
}

px4_msgs__msg__FixedWingLongitudinalSetpoint *
px4_msgs__msg__FixedWingLongitudinalSetpoint__create()
{
  px4_msgs__msg__FixedWingLongitudinalSetpoint * msg = (px4_msgs__msg__FixedWingLongitudinalSetpoint *)malloc(sizeof(px4_msgs__msg__FixedWingLongitudinalSetpoint));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(px4_msgs__msg__FixedWingLongitudinalSetpoint));
  bool success = px4_msgs__msg__FixedWingLongitudinalSetpoint__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
px4_msgs__msg__FixedWingLongitudinalSetpoint__destroy(px4_msgs__msg__FixedWingLongitudinalSetpoint * msg)
{
  if (msg) {
    px4_msgs__msg__FixedWingLongitudinalSetpoint__fini(msg);
  }
  free(msg);
}


bool
px4_msgs__msg__FixedWingLongitudinalSetpoint__Sequence__init(px4_msgs__msg__FixedWingLongitudinalSetpoint__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  px4_msgs__msg__FixedWingLongitudinalSetpoint * data = NULL;
  if (size) {
    data = (px4_msgs__msg__FixedWingLongitudinalSetpoint *)calloc(size, sizeof(px4_msgs__msg__FixedWingLongitudinalSetpoint));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = px4_msgs__msg__FixedWingLongitudinalSetpoint__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        px4_msgs__msg__FixedWingLongitudinalSetpoint__fini(&data[i - 1]);
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
px4_msgs__msg__FixedWingLongitudinalSetpoint__Sequence__fini(px4_msgs__msg__FixedWingLongitudinalSetpoint__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      px4_msgs__msg__FixedWingLongitudinalSetpoint__fini(&array->data[i]);
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

px4_msgs__msg__FixedWingLongitudinalSetpoint__Sequence *
px4_msgs__msg__FixedWingLongitudinalSetpoint__Sequence__create(size_t size)
{
  px4_msgs__msg__FixedWingLongitudinalSetpoint__Sequence * array = (px4_msgs__msg__FixedWingLongitudinalSetpoint__Sequence *)malloc(sizeof(px4_msgs__msg__FixedWingLongitudinalSetpoint__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = px4_msgs__msg__FixedWingLongitudinalSetpoint__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
px4_msgs__msg__FixedWingLongitudinalSetpoint__Sequence__destroy(px4_msgs__msg__FixedWingLongitudinalSetpoint__Sequence * array)
{
  if (array) {
    px4_msgs__msg__FixedWingLongitudinalSetpoint__Sequence__fini(array);
  }
  free(array);
}

bool
px4_msgs__msg__FixedWingLongitudinalSetpoint__Sequence__are_equal(const px4_msgs__msg__FixedWingLongitudinalSetpoint__Sequence * lhs, const px4_msgs__msg__FixedWingLongitudinalSetpoint__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!px4_msgs__msg__FixedWingLongitudinalSetpoint__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
px4_msgs__msg__FixedWingLongitudinalSetpoint__Sequence__copy(
  const px4_msgs__msg__FixedWingLongitudinalSetpoint__Sequence * input,
  px4_msgs__msg__FixedWingLongitudinalSetpoint__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(px4_msgs__msg__FixedWingLongitudinalSetpoint);
    px4_msgs__msg__FixedWingLongitudinalSetpoint * data =
      (px4_msgs__msg__FixedWingLongitudinalSetpoint *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!px4_msgs__msg__FixedWingLongitudinalSetpoint__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          px4_msgs__msg__FixedWingLongitudinalSetpoint__fini(&data[i]);
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
    if (!px4_msgs__msg__FixedWingLongitudinalSetpoint__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
