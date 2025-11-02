// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from px4_msgs:msg/NeuralControl.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "px4_msgs/msg/detail/neural_control__rosidl_typesupport_introspection_c.h"
#include "px4_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "px4_msgs/msg/detail/neural_control__functions.h"
#include "px4_msgs/msg/detail/neural_control__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void NeuralControl__rosidl_typesupport_introspection_c__NeuralControl_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  px4_msgs__msg__NeuralControl__init(message_memory);
}

void NeuralControl__rosidl_typesupport_introspection_c__NeuralControl_fini_function(void * message_memory)
{
  px4_msgs__msg__NeuralControl__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember NeuralControl__rosidl_typesupport_introspection_c__NeuralControl_message_member_array[5] = {
  {
    "timestamp",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT64,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(px4_msgs__msg__NeuralControl, timestamp),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "observation",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    15,  // array size
    false,  // is upper bound
    offsetof(px4_msgs__msg__NeuralControl, observation),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "network_output",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    4,  // array size
    false,  // is upper bound
    offsetof(px4_msgs__msg__NeuralControl, network_output),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "controller_time",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(px4_msgs__msg__NeuralControl, controller_time),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "inference_time",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(px4_msgs__msg__NeuralControl, inference_time),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers NeuralControl__rosidl_typesupport_introspection_c__NeuralControl_message_members = {
  "px4_msgs__msg",  // message namespace
  "NeuralControl",  // message name
  5,  // number of fields
  sizeof(px4_msgs__msg__NeuralControl),
  NeuralControl__rosidl_typesupport_introspection_c__NeuralControl_message_member_array,  // message members
  NeuralControl__rosidl_typesupport_introspection_c__NeuralControl_init_function,  // function to initialize message memory (memory has to be allocated)
  NeuralControl__rosidl_typesupport_introspection_c__NeuralControl_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t NeuralControl__rosidl_typesupport_introspection_c__NeuralControl_message_type_support_handle = {
  0,
  &NeuralControl__rosidl_typesupport_introspection_c__NeuralControl_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_px4_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, px4_msgs, msg, NeuralControl)() {
  if (!NeuralControl__rosidl_typesupport_introspection_c__NeuralControl_message_type_support_handle.typesupport_identifier) {
    NeuralControl__rosidl_typesupport_introspection_c__NeuralControl_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &NeuralControl__rosidl_typesupport_introspection_c__NeuralControl_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
