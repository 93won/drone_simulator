// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from px4_msgs:msg/RoverPositionSetpoint.idl
// generated code does not contain a copyright notice

#ifndef PX4_MSGS__MSG__DETAIL__ROVER_POSITION_SETPOINT__TRAITS_HPP_
#define PX4_MSGS__MSG__DETAIL__ROVER_POSITION_SETPOINT__TRAITS_HPP_

#include "px4_msgs/msg/detail/rover_position_setpoint__struct.hpp"
#include <stdint.h>
#include <rosidl_runtime_cpp/traits.hpp>
#include <sstream>
#include <string>
#include <type_traits>

namespace rosidl_generator_traits
{

inline void to_yaml(
  const px4_msgs::msg::RoverPositionSetpoint & msg,
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

  // member: position_ned
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.position_ned.size() == 0) {
      out << "position_ned: []\n";
    } else {
      out << "position_ned:\n";
      for (auto item : msg.position_ned) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: start_ned
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.start_ned.size() == 0) {
      out << "start_ned: []\n";
    } else {
      out << "start_ned:\n";
      for (auto item : msg.start_ned) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: cruising_speed
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "cruising_speed: ";
    value_to_yaml(msg.cruising_speed, out);
    out << "\n";
  }

  // member: arrival_speed
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "arrival_speed: ";
    value_to_yaml(msg.arrival_speed, out);
    out << "\n";
  }

  // member: yaw
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "yaw: ";
    value_to_yaml(msg.yaw, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const px4_msgs::msg::RoverPositionSetpoint & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

template<>
inline const char * data_type<px4_msgs::msg::RoverPositionSetpoint>()
{
  return "px4_msgs::msg::RoverPositionSetpoint";
}

template<>
inline const char * name<px4_msgs::msg::RoverPositionSetpoint>()
{
  return "px4_msgs/msg/RoverPositionSetpoint";
}

template<>
struct has_fixed_size<px4_msgs::msg::RoverPositionSetpoint>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<px4_msgs::msg::RoverPositionSetpoint>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<px4_msgs::msg::RoverPositionSetpoint>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // PX4_MSGS__MSG__DETAIL__ROVER_POSITION_SETPOINT__TRAITS_HPP_
