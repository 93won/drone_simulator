// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from px4_msgs:msg/FixedWingLongitudinalSetpoint.idl
// generated code does not contain a copyright notice

#ifndef PX4_MSGS__MSG__DETAIL__FIXED_WING_LONGITUDINAL_SETPOINT__TRAITS_HPP_
#define PX4_MSGS__MSG__DETAIL__FIXED_WING_LONGITUDINAL_SETPOINT__TRAITS_HPP_

#include "px4_msgs/msg/detail/fixed_wing_longitudinal_setpoint__struct.hpp"
#include <stdint.h>
#include <rosidl_runtime_cpp/traits.hpp>
#include <sstream>
#include <string>
#include <type_traits>

namespace rosidl_generator_traits
{

inline void to_yaml(
  const px4_msgs::msg::FixedWingLongitudinalSetpoint & msg,
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

  // member: altitude
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "altitude: ";
    value_to_yaml(msg.altitude, out);
    out << "\n";
  }

  // member: height_rate
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "height_rate: ";
    value_to_yaml(msg.height_rate, out);
    out << "\n";
  }

  // member: equivalent_airspeed
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "equivalent_airspeed: ";
    value_to_yaml(msg.equivalent_airspeed, out);
    out << "\n";
  }

  // member: pitch_direct
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pitch_direct: ";
    value_to_yaml(msg.pitch_direct, out);
    out << "\n";
  }

  // member: throttle_direct
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "throttle_direct: ";
    value_to_yaml(msg.throttle_direct, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const px4_msgs::msg::FixedWingLongitudinalSetpoint & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

template<>
inline const char * data_type<px4_msgs::msg::FixedWingLongitudinalSetpoint>()
{
  return "px4_msgs::msg::FixedWingLongitudinalSetpoint";
}

template<>
inline const char * name<px4_msgs::msg::FixedWingLongitudinalSetpoint>()
{
  return "px4_msgs/msg/FixedWingLongitudinalSetpoint";
}

template<>
struct has_fixed_size<px4_msgs::msg::FixedWingLongitudinalSetpoint>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<px4_msgs::msg::FixedWingLongitudinalSetpoint>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<px4_msgs::msg::FixedWingLongitudinalSetpoint>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // PX4_MSGS__MSG__DETAIL__FIXED_WING_LONGITUDINAL_SETPOINT__TRAITS_HPP_
