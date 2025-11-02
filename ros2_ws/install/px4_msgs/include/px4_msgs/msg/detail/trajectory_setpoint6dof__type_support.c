// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from px4_msgs:msg/TrajectorySetpoint6dof.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "px4_msgs/msg/detail/trajectory_setpoint6dof__rosidl_typesupport_introspection_c.h"
#include "px4_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "px4_msgs/msg/detail/trajectory_setpoint6dof__functions.h"
#include "px4_msgs/msg/detail/trajectory_setpoint6dof__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void TrajectorySetpoint6dof__rosidl_typesupport_introspection_c__TrajectorySetpoint6dof_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  px4_msgs__msg__TrajectorySetpoint6dof__init(message_memory);
}

void TrajectorySetpoint6dof__rosidl_typesupport_introspection_c__TrajectorySetpoint6dof_fini_function(void * message_memory)
{
  px4_msgs__msg__TrajectorySetpoint6dof__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember TrajectorySetpoint6dof__rosidl_typesupport_introspection_c__TrajectorySetpoint6dof_message_member_array[7] = {
  {
    "timestamp",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT64,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(px4_msgs__msg__TrajectorySetpoint6dof, timestamp),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "position",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    3,  // array size
    false,  // is upper bound
    offsetof(px4_msgs__msg__TrajectorySetpoint6dof, position),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "velocity",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    3,  // array size
    false,  // is upper bound
    offsetof(px4_msgs__msg__TrajectorySetpoint6dof, velocity),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "acceleration",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    3,  // array size
    false,  // is upper bound
    offsetof(px4_msgs__msg__TrajectorySetpoint6dof, acceleration),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "jerk",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    3,  // array size
    false,  // is upper bound
    offsetof(px4_msgs__msg__TrajectorySetpoint6dof, jerk),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "quaternion",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    4,  // array size
    false,  // is upper bound
    offsetof(px4_msgs__msg__TrajectorySetpoint6dof, quaternion),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "angular_velocity",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    3,  // array size
    false,  // is upper bound
    offsetof(px4_msgs__msg__TrajectorySetpoint6dof, angular_velocity),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers TrajectorySetpoint6dof__rosidl_typesupport_introspection_c__TrajectorySetpoint6dof_message_members = {
  "px4_msgs__msg",  // message namespace
  "TrajectorySetpoint6dof",  // message name
  7,  // number of fields
  sizeof(px4_msgs__msg__TrajectorySetpoint6dof),
  TrajectorySetpoint6dof__rosidl_typesupport_introspection_c__TrajectorySetpoint6dof_message_member_array,  // message members
  TrajectorySetpoint6dof__rosidl_typesupport_introspection_c__TrajectorySetpoint6dof_init_function,  // function to initialize message memory (memory has to be allocated)
  TrajectorySetpoint6dof__rosidl_typesupport_introspection_c__TrajectorySetpoint6dof_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t TrajectorySetpoint6dof__rosidl_typesupport_introspection_c__TrajectorySetpoint6dof_message_type_support_handle = {
  0,
  &TrajectorySetpoint6dof__rosidl_typesupport_introspection_c__TrajectorySetpoint6dof_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_px4_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, px4_msgs, msg, TrajectorySetpoint6dof)() {
  if (!TrajectorySetpoint6dof__rosidl_typesupport_introspection_c__TrajectorySetpoint6dof_message_type_support_handle.typesupport_identifier) {
    TrajectorySetpoint6dof__rosidl_typesupport_introspection_c__TrajectorySetpoint6dof_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &TrajectorySetpoint6dof__rosidl_typesupport_introspection_c__TrajectorySetpoint6dof_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
