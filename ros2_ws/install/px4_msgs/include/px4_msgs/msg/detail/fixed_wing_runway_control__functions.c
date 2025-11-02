// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from px4_msgs:msg/FixedWingRunwayControl.idl
// generated code does not contain a copyright notice
#include "px4_msgs/msg/detail/fixed_wing_runway_control__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


bool
px4_msgs__msg__FixedWingRunwayControl__init(px4_msgs__msg__FixedWingRunwayControl * msg)
{
  if (!msg) {
    return false;
  }
  // timestamp
  // wheel_steering_enabled
  // wheel_steering_nudging_rate
  return true;
}

void
px4_msgs__msg__FixedWingRunwayControl__fini(px4_msgs__msg__FixedWingRunwayControl * msg)
{
  if (!msg) {
    return;
  }
  // timestamp
  // wheel_steering_enabled
  // wheel_steering_nudging_rate
}

bool
px4_msgs__msg__FixedWingRunwayControl__are_equal(const px4_msgs__msg__FixedWingRunwayControl * lhs, const px4_msgs__msg__FixedWingRunwayControl * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // timestamp
  if (lhs->timestamp != rhs->timestamp) {
    return false;
  }
  // wheel_steering_enabled
  if (lhs->wheel_steering_enabled != rhs->wheel_steering_enabled) {
    return false;
  }
  // wheel_steering_nudging_rate
  if (lhs->wheel_steering_nudging_rate != rhs->wheel_steering_nudging_rate) {
    return false;
  }
  return true;
}

bool
px4_msgs__msg__FixedWingRunwayControl__copy(
  const px4_msgs__msg__FixedWingRunwayControl * input,
  px4_msgs__msg__FixedWingRunwayControl * output)
{
  if (!input || !output) {
    return false;
  }
  // timestamp
  output->timestamp = input->timestamp;
  // wheel_steering_enabled
  output->wheel_steering_enabled = input->wheel_steering_enabled;
  // wheel_steering_nudging_rate
  output->wheel_steering_nudging_rate = input->wheel_steering_nudging_rate;
  return true;
}

px4_msgs__msg__FixedWingRunwayControl *
px4_msgs__msg__FixedWingRunwayControl__create()
{
  px4_msgs__msg__FixedWingRunwayControl * msg = (px4_msgs__msg__FixedWingRunwayControl *)malloc(sizeof(px4_msgs__msg__FixedWingRunwayControl));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(px4_msgs__msg__FixedWingRunwayControl));
  bool success = px4_msgs__msg__FixedWingRunwayControl__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
px4_msgs__msg__FixedWingRunwayControl__destroy(px4_msgs__msg__FixedWingRunwayControl * msg)
{
  if (msg) {
    px4_msgs__msg__FixedWingRunwayControl__fini(msg);
  }
  free(msg);
}


bool
px4_msgs__msg__FixedWingRunwayControl__Sequence__init(px4_msgs__msg__FixedWingRunwayControl__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  px4_msgs__msg__FixedWingRunwayControl * data = NULL;
  if (size) {
    data = (px4_msgs__msg__FixedWingRunwayControl *)calloc(size, sizeof(px4_msgs__msg__FixedWingRunwayControl));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = px4_msgs__msg__FixedWingRunwayControl__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        px4_msgs__msg__FixedWingRunwayControl__fini(&data[i - 1]);
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
px4_msgs__msg__FixedWingRunwayControl__Sequence__fini(px4_msgs__msg__FixedWingRunwayControl__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      px4_msgs__msg__FixedWingRunwayControl__fini(&array->data[i]);
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

px4_msgs__msg__FixedWingRunwayControl__Sequence *
px4_msgs__msg__FixedWingRunwayControl__Sequence__create(size_t size)
{
  px4_msgs__msg__FixedWingRunwayControl__Sequence * array = (px4_msgs__msg__FixedWingRunwayControl__Sequence *)malloc(sizeof(px4_msgs__msg__FixedWingRunwayControl__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = px4_msgs__msg__FixedWingRunwayControl__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
px4_msgs__msg__FixedWingRunwayControl__Sequence__destroy(px4_msgs__msg__FixedWingRunwayControl__Sequence * array)
{
  if (array) {
    px4_msgs__msg__FixedWingRunwayControl__Sequence__fini(array);
  }
  free(array);
}

bool
px4_msgs__msg__FixedWingRunwayControl__Sequence__are_equal(const px4_msgs__msg__FixedWingRunwayControl__Sequence * lhs, const px4_msgs__msg__FixedWingRunwayControl__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!px4_msgs__msg__FixedWingRunwayControl__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
px4_msgs__msg__FixedWingRunwayControl__Sequence__copy(
  const px4_msgs__msg__FixedWingRunwayControl__Sequence * input,
  px4_msgs__msg__FixedWingRunwayControl__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(px4_msgs__msg__FixedWingRunwayControl);
    px4_msgs__msg__FixedWingRunwayControl * data =
      (px4_msgs__msg__FixedWingRunwayControl *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!px4_msgs__msg__FixedWingRunwayControl__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          px4_msgs__msg__FixedWingRunwayControl__fini(&data[i]);
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
    if (!px4_msgs__msg__FixedWingRunwayControl__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
