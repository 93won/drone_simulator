// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from px4_msgs:msg/FixedWingLateralSetpoint.idl
// generated code does not contain a copyright notice

#ifndef PX4_MSGS__MSG__DETAIL__FIXED_WING_LATERAL_SETPOINT__STRUCT_H_
#define PX4_MSGS__MSG__DETAIL__FIXED_WING_LATERAL_SETPOINT__STRUCT_H_

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
  px4_msgs__msg__FixedWingLateralSetpoint__MESSAGE_VERSION = 0ul
};

// Struct defined in msg/FixedWingLateralSetpoint in the package px4_msgs.
typedef struct px4_msgs__msg__FixedWingLateralSetpoint
{
  uint64_t timestamp;
  float course;
  float airspeed_direction;
  float lateral_acceleration;
} px4_msgs__msg__FixedWingLateralSetpoint;

// Struct for a sequence of px4_msgs__msg__FixedWingLateralSetpoint.
typedef struct px4_msgs__msg__FixedWingLateralSetpoint__Sequence
{
  px4_msgs__msg__FixedWingLateralSetpoint * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} px4_msgs__msg__FixedWingLateralSetpoint__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // PX4_MSGS__MSG__DETAIL__FIXED_WING_LATERAL_SETPOINT__STRUCT_H_
