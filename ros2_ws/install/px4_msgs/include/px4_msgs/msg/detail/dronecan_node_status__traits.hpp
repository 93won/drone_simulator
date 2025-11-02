// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from px4_msgs:msg/DronecanNodeStatus.idl
// generated code does not contain a copyright notice

#ifndef PX4_MSGS__MSG__DETAIL__DRONECAN_NODE_STATUS__TRAITS_HPP_
#define PX4_MSGS__MSG__DETAIL__DRONECAN_NODE_STATUS__TRAITS_HPP_

#include "px4_msgs/msg/detail/dronecan_node_status__struct.hpp"
#include <stdint.h>
#include <rosidl_runtime_cpp/traits.hpp>
#include <sstream>
#include <string>
#include <type_traits>

namespace rosidl_generator_traits
{

inline void to_yaml(
  const px4_msgs::msg::DronecanNodeStatus & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: timestamp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "timestamp: ";
    value_to_yaml(msg.timestamp, out);
    out << "\n";
  }

  // member: node_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "node_id: ";
    value_to_yaml(msg.node_id, out);
    out << "\n";
  }

  // member: uptime_sec
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "uptime_sec: ";
    value_to_yaml(msg.uptime_sec, out);
    out << "\n";
  }

  // member: health
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "health: ";
    value_to_yaml(msg.health, out);
    out << "\n";
  }

  // member: mode
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "mode: ";
    value_to_yaml(msg.mode, out);
    out << "\n";
  }

  // member: sub_mode
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "sub_mode: ";
    value_to_yaml(msg.sub_mode, out);
    out << "\n";
  }

  // member: vendor_specific_status_code
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "vendor_specific_status_code: ";
    value_to_yaml(msg.vendor_specific_status_code, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const px4_msgs::msg::DronecanNodeStatus & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

template<>
inline const char * data_type<px4_msgs::msg::DronecanNodeStatus>()
{
  return "px4_msgs::msg::DronecanNodeStatus";
}

template<>
inline const char * name<px4_msgs::msg::DronecanNodeStatus>()
{
  return "px4_msgs/msg/DronecanNodeStatus";
}

template<>
struct has_fixed_size<px4_msgs::msg::DronecanNodeStatus>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<px4_msgs::msg::DronecanNodeStatus>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<px4_msgs::msg::DronecanNodeStatus>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // PX4_MSGS__MSG__DETAIL__DRONECAN_NODE_STATUS__TRAITS_HPP_
