// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from px4_msgs:msg/RoverSpeedStatus.idl
// generated code does not contain a copyright notice

#ifndef PX4_MSGS__MSG__DETAIL__ROVER_SPEED_STATUS__STRUCT_H_
#define PX4_MSGS__MSG__DETAIL__ROVER_SPEED_STATUS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in msg/RoverSpeedStatus in the package px4_msgs.
typedef struct px4_msgs__msg__RoverSpeedStatus
{
  uint64_t timestamp;
  float measured_speed_body_x;
  float adjusted_speed_body_x_setpoint;
  float pid_throttle_body_x_integral;
  float measured_speed_body_y;
  float adjusted_speed_body_y_setpoint;
  float pid_throttle_body_y_integral;
} px4_msgs__msg__RoverSpeedStatus;

// Struct for a sequence of px4_msgs__msg__RoverSpeedStatus.
typedef struct px4_msgs__msg__RoverSpeedStatus__Sequence
{
  px4_msgs__msg__RoverSpeedStatus * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} px4_msgs__msg__RoverSpeedStatus__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // PX4_MSGS__MSG__DETAIL__ROVER_SPEED_STATUS__STRUCT_H_
