// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from px4_msgs:msg/SensorGnssStatus.idl
// generated code does not contain a copyright notice
#include "px4_msgs/msg/detail/sensor_gnss_status__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


bool
px4_msgs__msg__SensorGnssStatus__init(px4_msgs__msg__SensorGnssStatus * msg)
{
  if (!msg) {
    return false;
  }
  // timestamp
  // device_id
  // quality_available
  // quality_corrections
  // quality_receiver
  // quality_gnss_signals
  // quality_post_processing
  return true;
}

void
px4_msgs__msg__SensorGnssStatus__fini(px4_msgs__msg__SensorGnssStatus * msg)
{
  if (!msg) {
    return;
  }
  // timestamp
  // device_id
  // quality_available
  // quality_corrections
  // quality_receiver
  // quality_gnss_signals
  // quality_post_processing
}

bool
px4_msgs__msg__SensorGnssStatus__are_equal(const px4_msgs__msg__SensorGnssStatus * lhs, const px4_msgs__msg__SensorGnssStatus * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // timestamp
  if (lhs->timestamp != rhs->timestamp) {
    return false;
  }
  // device_id
  if (lhs->device_id != rhs->device_id) {
    return false;
  }
  // quality_available
  if (lhs->quality_available != rhs->quality_available) {
    return false;
  }
  // quality_corrections
  if (lhs->quality_corrections != rhs->quality_corrections) {
    return false;
  }
  // quality_receiver
  if (lhs->quality_receiver != rhs->quality_receiver) {
    return false;
  }
  // quality_gnss_signals
  if (lhs->quality_gnss_signals != rhs->quality_gnss_signals) {
    return false;
  }
  // quality_post_processing
  if (lhs->quality_post_processing != rhs->quality_post_processing) {
    return false;
  }
  return true;
}

bool
px4_msgs__msg__SensorGnssStatus__copy(
  const px4_msgs__msg__SensorGnssStatus * input,
  px4_msgs__msg__SensorGnssStatus * output)
{
  if (!input || !output) {
    return false;
  }
  // timestamp
  output->timestamp = input->timestamp;
  // device_id
  output->device_id = input->device_id;
  // quality_available
  output->quality_available = input->quality_available;
  // quality_corrections
  output->quality_corrections = input->quality_corrections;
  // quality_receiver
  output->quality_receiver = input->quality_receiver;
  // quality_gnss_signals
  output->quality_gnss_signals = input->quality_gnss_signals;
  // quality_post_processing
  output->quality_post_processing = input->quality_post_processing;
  return true;
}

px4_msgs__msg__SensorGnssStatus *
px4_msgs__msg__SensorGnssStatus__create()
{
  px4_msgs__msg__SensorGnssStatus * msg = (px4_msgs__msg__SensorGnssStatus *)malloc(sizeof(px4_msgs__msg__SensorGnssStatus));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(px4_msgs__msg__SensorGnssStatus));
  bool success = px4_msgs__msg__SensorGnssStatus__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
px4_msgs__msg__SensorGnssStatus__destroy(px4_msgs__msg__SensorGnssStatus * msg)
{
  if (msg) {
    px4_msgs__msg__SensorGnssStatus__fini(msg);
  }
  free(msg);
}


bool
px4_msgs__msg__SensorGnssStatus__Sequence__init(px4_msgs__msg__SensorGnssStatus__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  px4_msgs__msg__SensorGnssStatus * data = NULL;
  if (size) {
    data = (px4_msgs__msg__SensorGnssStatus *)calloc(size, sizeof(px4_msgs__msg__SensorGnssStatus));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = px4_msgs__msg__SensorGnssStatus__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        px4_msgs__msg__SensorGnssStatus__fini(&data[i - 1]);
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
px4_msgs__msg__SensorGnssStatus__Sequence__fini(px4_msgs__msg__SensorGnssStatus__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      px4_msgs__msg__SensorGnssStatus__fini(&array->data[i]);
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

px4_msgs__msg__SensorGnssStatus__Sequence *
px4_msgs__msg__SensorGnssStatus__Sequence__create(size_t size)
{
  px4_msgs__msg__SensorGnssStatus__Sequence * array = (px4_msgs__msg__SensorGnssStatus__Sequence *)malloc(sizeof(px4_msgs__msg__SensorGnssStatus__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = px4_msgs__msg__SensorGnssStatus__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
px4_msgs__msg__SensorGnssStatus__Sequence__destroy(px4_msgs__msg__SensorGnssStatus__Sequence * array)
{
  if (array) {
    px4_msgs__msg__SensorGnssStatus__Sequence__fini(array);
  }
  free(array);
}

bool
px4_msgs__msg__SensorGnssStatus__Sequence__are_equal(const px4_msgs__msg__SensorGnssStatus__Sequence * lhs, const px4_msgs__msg__SensorGnssStatus__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!px4_msgs__msg__SensorGnssStatus__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
px4_msgs__msg__SensorGnssStatus__Sequence__copy(
  const px4_msgs__msg__SensorGnssStatus__Sequence * input,
  px4_msgs__msg__SensorGnssStatus__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(px4_msgs__msg__SensorGnssStatus);
    px4_msgs__msg__SensorGnssStatus * data =
      (px4_msgs__msg__SensorGnssStatus *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!px4_msgs__msg__SensorGnssStatus__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          px4_msgs__msg__SensorGnssStatus__fini(&data[i]);
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
    if (!px4_msgs__msg__SensorGnssStatus__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
