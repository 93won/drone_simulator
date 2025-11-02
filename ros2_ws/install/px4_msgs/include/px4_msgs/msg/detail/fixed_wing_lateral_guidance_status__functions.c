// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from px4_msgs:msg/FixedWingLateralGuidanceStatus.idl
// generated code does not contain a copyright notice
#include "px4_msgs/msg/detail/fixed_wing_lateral_guidance_status__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


bool
px4_msgs__msg__FixedWingLateralGuidanceStatus__init(px4_msgs__msg__FixedWingLateralGuidanceStatus * msg)
{
  if (!msg) {
    return false;
  }
  // timestamp
  // course_setpoint
  // lateral_acceleration_ff
  // bearing_feas
  // bearing_feas_on_track
  // signed_track_error
  // track_error_bound
  // adapted_period
  // wind_est_valid
  return true;
}

void
px4_msgs__msg__FixedWingLateralGuidanceStatus__fini(px4_msgs__msg__FixedWingLateralGuidanceStatus * msg)
{
  if (!msg) {
    return;
  }
  // timestamp
  // course_setpoint
  // lateral_acceleration_ff
  // bearing_feas
  // bearing_feas_on_track
  // signed_track_error
  // track_error_bound
  // adapted_period
  // wind_est_valid
}

bool
px4_msgs__msg__FixedWingLateralGuidanceStatus__are_equal(const px4_msgs__msg__FixedWingLateralGuidanceStatus * lhs, const px4_msgs__msg__FixedWingLateralGuidanceStatus * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // timestamp
  if (lhs->timestamp != rhs->timestamp) {
    return false;
  }
  // course_setpoint
  if (lhs->course_setpoint != rhs->course_setpoint) {
    return false;
  }
  // lateral_acceleration_ff
  if (lhs->lateral_acceleration_ff != rhs->lateral_acceleration_ff) {
    return false;
  }
  // bearing_feas
  if (lhs->bearing_feas != rhs->bearing_feas) {
    return false;
  }
  // bearing_feas_on_track
  if (lhs->bearing_feas_on_track != rhs->bearing_feas_on_track) {
    return false;
  }
  // signed_track_error
  if (lhs->signed_track_error != rhs->signed_track_error) {
    return false;
  }
  // track_error_bound
  if (lhs->track_error_bound != rhs->track_error_bound) {
    return false;
  }
  // adapted_period
  if (lhs->adapted_period != rhs->adapted_period) {
    return false;
  }
  // wind_est_valid
  if (lhs->wind_est_valid != rhs->wind_est_valid) {
    return false;
  }
  return true;
}

bool
px4_msgs__msg__FixedWingLateralGuidanceStatus__copy(
  const px4_msgs__msg__FixedWingLateralGuidanceStatus * input,
  px4_msgs__msg__FixedWingLateralGuidanceStatus * output)
{
  if (!input || !output) {
    return false;
  }
  // timestamp
  output->timestamp = input->timestamp;
  // course_setpoint
  output->course_setpoint = input->course_setpoint;
  // lateral_acceleration_ff
  output->lateral_acceleration_ff = input->lateral_acceleration_ff;
  // bearing_feas
  output->bearing_feas = input->bearing_feas;
  // bearing_feas_on_track
  output->bearing_feas_on_track = input->bearing_feas_on_track;
  // signed_track_error
  output->signed_track_error = input->signed_track_error;
  // track_error_bound
  output->track_error_bound = input->track_error_bound;
  // adapted_period
  output->adapted_period = input->adapted_period;
  // wind_est_valid
  output->wind_est_valid = input->wind_est_valid;
  return true;
}

px4_msgs__msg__FixedWingLateralGuidanceStatus *
px4_msgs__msg__FixedWingLateralGuidanceStatus__create()
{
  px4_msgs__msg__FixedWingLateralGuidanceStatus * msg = (px4_msgs__msg__FixedWingLateralGuidanceStatus *)malloc(sizeof(px4_msgs__msg__FixedWingLateralGuidanceStatus));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(px4_msgs__msg__FixedWingLateralGuidanceStatus));
  bool success = px4_msgs__msg__FixedWingLateralGuidanceStatus__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
px4_msgs__msg__FixedWingLateralGuidanceStatus__destroy(px4_msgs__msg__FixedWingLateralGuidanceStatus * msg)
{
  if (msg) {
    px4_msgs__msg__FixedWingLateralGuidanceStatus__fini(msg);
  }
  free(msg);
}


bool
px4_msgs__msg__FixedWingLateralGuidanceStatus__Sequence__init(px4_msgs__msg__FixedWingLateralGuidanceStatus__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  px4_msgs__msg__FixedWingLateralGuidanceStatus * data = NULL;
  if (size) {
    data = (px4_msgs__msg__FixedWingLateralGuidanceStatus *)calloc(size, sizeof(px4_msgs__msg__FixedWingLateralGuidanceStatus));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = px4_msgs__msg__FixedWingLateralGuidanceStatus__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        px4_msgs__msg__FixedWingLateralGuidanceStatus__fini(&data[i - 1]);
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
px4_msgs__msg__FixedWingLateralGuidanceStatus__Sequence__fini(px4_msgs__msg__FixedWingLateralGuidanceStatus__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      px4_msgs__msg__FixedWingLateralGuidanceStatus__fini(&array->data[i]);
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

px4_msgs__msg__FixedWingLateralGuidanceStatus__Sequence *
px4_msgs__msg__FixedWingLateralGuidanceStatus__Sequence__create(size_t size)
{
  px4_msgs__msg__FixedWingLateralGuidanceStatus__Sequence * array = (px4_msgs__msg__FixedWingLateralGuidanceStatus__Sequence *)malloc(sizeof(px4_msgs__msg__FixedWingLateralGuidanceStatus__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = px4_msgs__msg__FixedWingLateralGuidanceStatus__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
px4_msgs__msg__FixedWingLateralGuidanceStatus__Sequence__destroy(px4_msgs__msg__FixedWingLateralGuidanceStatus__Sequence * array)
{
  if (array) {
    px4_msgs__msg__FixedWingLateralGuidanceStatus__Sequence__fini(array);
  }
  free(array);
}

bool
px4_msgs__msg__FixedWingLateralGuidanceStatus__Sequence__are_equal(const px4_msgs__msg__FixedWingLateralGuidanceStatus__Sequence * lhs, const px4_msgs__msg__FixedWingLateralGuidanceStatus__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!px4_msgs__msg__FixedWingLateralGuidanceStatus__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
px4_msgs__msg__FixedWingLateralGuidanceStatus__Sequence__copy(
  const px4_msgs__msg__FixedWingLateralGuidanceStatus__Sequence * input,
  px4_msgs__msg__FixedWingLateralGuidanceStatus__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(px4_msgs__msg__FixedWingLateralGuidanceStatus);
    px4_msgs__msg__FixedWingLateralGuidanceStatus * data =
      (px4_msgs__msg__FixedWingLateralGuidanceStatus *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!px4_msgs__msg__FixedWingLateralGuidanceStatus__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          px4_msgs__msg__FixedWingLateralGuidanceStatus__fini(&data[i]);
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
    if (!px4_msgs__msg__FixedWingLateralGuidanceStatus__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
