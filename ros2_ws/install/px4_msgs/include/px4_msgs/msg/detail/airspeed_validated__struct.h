// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from px4_msgs:msg/AirspeedValidated.idl
// generated code does not contain a copyright notice

#ifndef PX4_MSGS__MSG__DETAIL__AIRSPEED_VALIDATED__STRUCT_H_
#define PX4_MSGS__MSG__DETAIL__AIRSPEED_VALIDATED__STRUCT_H_

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
  px4_msgs__msg__AirspeedValidated__MESSAGE_VERSION = 1ul
};

/// Constant 'SOURCE_DISABLED'.
enum
{
  px4_msgs__msg__AirspeedValidated__SOURCE_DISABLED = -1
};

/// Constant 'SOURCE_GROUND_MINUS_WIND'.
enum
{
  px4_msgs__msg__AirspeedValidated__SOURCE_GROUND_MINUS_WIND = 0
};

/// Constant 'SOURCE_SENSOR_1'.
enum
{
  px4_msgs__msg__AirspeedValidated__SOURCE_SENSOR_1 = 1
};

/// Constant 'SOURCE_SENSOR_2'.
enum
{
  px4_msgs__msg__AirspeedValidated__SOURCE_SENSOR_2 = 2
};

/// Constant 'SOURCE_SENSOR_3'.
enum
{
  px4_msgs__msg__AirspeedValidated__SOURCE_SENSOR_3 = 3
};

/// Constant 'SOURCE_SYNTHETIC'.
enum
{
  px4_msgs__msg__AirspeedValidated__SOURCE_SYNTHETIC = 4
};

// Struct defined in msg/AirspeedValidated in the package px4_msgs.
typedef struct px4_msgs__msg__AirspeedValidated
{
  uint64_t timestamp;
  float indicated_airspeed_m_s;
  float calibrated_airspeed_m_s;
  float true_airspeed_m_s;
  int8_t airspeed_source;
  float calibrated_ground_minus_wind_m_s;
  float calibraded_airspeed_synth_m_s;
  float airspeed_derivative_filtered;
  float throttle_filtered;
  float pitch_filtered;
} px4_msgs__msg__AirspeedValidated;

// Struct for a sequence of px4_msgs__msg__AirspeedValidated.
typedef struct px4_msgs__msg__AirspeedValidated__Sequence
{
  px4_msgs__msg__AirspeedValidated * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} px4_msgs__msg__AirspeedValidated__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // PX4_MSGS__MSG__DETAIL__AIRSPEED_VALIDATED__STRUCT_H_
