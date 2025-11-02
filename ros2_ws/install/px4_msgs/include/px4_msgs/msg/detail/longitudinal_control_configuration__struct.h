// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from px4_msgs:msg/LongitudinalControlConfiguration.idl
// generated code does not contain a copyright notice

#ifndef PX4_MSGS__MSG__DETAIL__LONGITUDINAL_CONTROL_CONFIGURATION__STRUCT_H_
#define PX4_MSGS__MSG__DETAIL__LONGITUDINAL_CONTROL_CONFIGURATION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'MESSAGE_VERSION'.
enum
{
  px4_msgs__msg__LongitudinalControlConfiguration__MESSAGE_VERSION = 0ul
};

// Struct defined in msg/LongitudinalControlConfiguration in the package px4_msgs.
typedef struct px4_msgs__msg__LongitudinalControlConfiguration
{
  uint64_t timestamp;
  float pitch_min;
  float pitch_max;
  float throttle_min;
  float throttle_max;
  float climb_rate_target;
  float sink_rate_target;
  float speed_weight;
  bool enforce_low_height_condition;
  bool disable_underspeed_protection;
} px4_msgs__msg__LongitudinalControlConfiguration;

// Struct for a sequence of px4_msgs__msg__LongitudinalControlConfiguration.
typedef struct px4_msgs__msg__LongitudinalControlConfiguration__Sequence
{
  px4_msgs__msg__LongitudinalControlConfiguration * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} px4_msgs__msg__LongitudinalControlConfiguration__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // PX4_MSGS__MSG__DETAIL__LONGITUDINAL_CONTROL_CONFIGURATION__STRUCT_H_
