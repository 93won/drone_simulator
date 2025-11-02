// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from px4_msgs:msg/FixedWingLateralGuidanceStatus.idl
// generated code does not contain a copyright notice

#ifndef PX4_MSGS__MSG__DETAIL__FIXED_WING_LATERAL_GUIDANCE_STATUS__STRUCT_H_
#define PX4_MSGS__MSG__DETAIL__FIXED_WING_LATERAL_GUIDANCE_STATUS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in msg/FixedWingLateralGuidanceStatus in the package px4_msgs.
typedef struct px4_msgs__msg__FixedWingLateralGuidanceStatus
{
  uint64_t timestamp;
  float course_setpoint;
  float lateral_acceleration_ff;
  float bearing_feas;
  float bearing_feas_on_track;
  float signed_track_error;
  float track_error_bound;
  float adapted_period;
  uint8_t wind_est_valid;
} px4_msgs__msg__FixedWingLateralGuidanceStatus;

// Struct for a sequence of px4_msgs__msg__FixedWingLateralGuidanceStatus.
typedef struct px4_msgs__msg__FixedWingLateralGuidanceStatus__Sequence
{
  px4_msgs__msg__FixedWingLateralGuidanceStatus * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} px4_msgs__msg__FixedWingLateralGuidanceStatus__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // PX4_MSGS__MSG__DETAIL__FIXED_WING_LATERAL_GUIDANCE_STATUS__STRUCT_H_
