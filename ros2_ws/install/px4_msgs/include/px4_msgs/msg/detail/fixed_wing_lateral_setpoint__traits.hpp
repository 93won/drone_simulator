// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from px4_msgs:msg/FixedWingLateralSetpoint.idl
// generated code does not contain a copyright notice

#ifndef PX4_MSGS__MSG__DETAIL__FIXED_WING_LATERAL_SETPOINT__TRAITS_HPP_
#define PX4_MSGS__MSG__DETAIL__FIXED_WING_LATERAL_SETPOINT__TRAITS_HPP_

#include "px4_msgs/msg/detail/fixed_wing_lateral_setpoint__struct.hpp"
#include <stdint.h>
#include <rosidl_runtime_cpp/traits.hpp>
#include <sstream>
#include <string>
#include <type_traits>

namespace rosidl_generator_traits
{

inline void to_yaml(
  const px4_msgs::msg::FixedWingLateralSetpoint & msg,
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

  // member: course
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "course: ";
    value_to_yaml(msg.course, out);
    out << "\n";
  }

  // member: airspeed_direction
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "airspeed_direction: ";
    value_to_yaml(msg.airspeed_direction, out);
    out << "\n";
  }

  // member: lateral_acceleration
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "lateral_acceleration: ";
    value_to_yaml(msg.lateral_acceleration, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const px4_msgs::msg::FixedWingLateralSetpoint & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

template<>
inline const char * data_type<px4_msgs::msg::FixedWingLateralSetpoint>()
{
  return "px4_msgs::msg::FixedWingLateralSetpoint";
}

template<>
inline const char * name<px4_msgs::msg::FixedWingLateralSetpoint>()
{
  return "px4_msgs/msg/FixedWingLateralSetpoint";
}

template<>
struct has_fixed_size<px4_msgs::msg::FixedWingLateralSetpoint>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<px4_msgs::msg::FixedWingLateralSetpoint>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<px4_msgs::msg::FixedWingLateralSetpoint>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // PX4_MSGS__MSG__DETAIL__FIXED_WING_LATERAL_SETPOINT__TRAITS_HPP_
