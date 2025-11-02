// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from px4_msgs:msg/DronecanNodeStatus.idl
// generated code does not contain a copyright notice

#ifndef PX4_MSGS__MSG__DETAIL__DRONECAN_NODE_STATUS__STRUCT_H_
#define PX4_MSGS__MSG__DETAIL__DRONECAN_NODE_STATUS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'HEALTH_OK'.
enum
{
  px4_msgs__msg__DronecanNodeStatus__HEALTH_OK = 0
};

/// Constant 'HEALTH_WARNING'.
enum
{
  px4_msgs__msg__DronecanNodeStatus__HEALTH_WARNING = 1
};

/// Constant 'HEALTH_ERROR'.
enum
{
  px4_msgs__msg__DronecanNodeStatus__HEALTH_ERROR = 2
};

/// Constant 'HEALTH_CRITICAL'.
enum
{
  px4_msgs__msg__DronecanNodeStatus__HEALTH_CRITICAL = 3
};

/// Constant 'MODE_OPERATIONAL'.
enum
{
  px4_msgs__msg__DronecanNodeStatus__MODE_OPERATIONAL = 0
};

/// Constant 'MODE_INITIALIZATION'.
enum
{
  px4_msgs__msg__DronecanNodeStatus__MODE_INITIALIZATION = 1
};

/// Constant 'MODE_MAINTENANCE'.
enum
{
  px4_msgs__msg__DronecanNodeStatus__MODE_MAINTENANCE = 2
};

/// Constant 'MODE_SOFTWARE_UPDATE'.
enum
{
  px4_msgs__msg__DronecanNodeStatus__MODE_SOFTWARE_UPDATE = 3
};

/// Constant 'MODE_OFFLINE'.
enum
{
  px4_msgs__msg__DronecanNodeStatus__MODE_OFFLINE = 7
};

// Struct defined in msg/DronecanNodeStatus in the package px4_msgs.
typedef struct px4_msgs__msg__DronecanNodeStatus
{
  uint64_t timestamp;
  uint16_t node_id;
  uint32_t uptime_sec;
  uint8_t health;
  uint8_t mode;
  uint8_t sub_mode;
  uint16_t vendor_specific_status_code;
} px4_msgs__msg__DronecanNodeStatus;

// Struct for a sequence of px4_msgs__msg__DronecanNodeStatus.
typedef struct px4_msgs__msg__DronecanNodeStatus__Sequence
{
  px4_msgs__msg__DronecanNodeStatus * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} px4_msgs__msg__DronecanNodeStatus__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // PX4_MSGS__MSG__DETAIL__DRONECAN_NODE_STATUS__STRUCT_H_
