// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from px4_msgs:msg/LongitudinalControlConfiguration.idl
// generated code does not contain a copyright notice

#ifndef PX4_MSGS__MSG__DETAIL__LONGITUDINAL_CONTROL_CONFIGURATION__TRAITS_HPP_
#define PX4_MSGS__MSG__DETAIL__LONGITUDINAL_CONTROL_CONFIGURATION__TRAITS_HPP_

#include "px4_msgs/msg/detail/longitudinal_control_configuration__struct.hpp"
#include <stdint.h>
#include <rosidl_runtime_cpp/traits.hpp>
#include <sstream>
#include <string>
#include <type_traits>

namespace rosidl_generator_traits
{

inline void to_yaml(
  const px4_msgs::msg::LongitudinalControlConfiguration & msg,
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

  // member: pitch_min
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pitch_min: ";
    value_to_yaml(msg.pitch_min, out);
    out << "\n";
  }

  // member: pitch_max
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pitch_max: ";
    value_to_yaml(msg.pitch_max, out);
    out << "\n";
  }

  // member: throttle_min
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "throttle_min: ";
    value_to_yaml(msg.throttle_min, out);
    out << "\n";
  }

  // member: throttle_max
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "throttle_max: ";
    value_to_yaml(msg.throttle_max, out);
    out << "\n";
  }

  // member: climb_rate_target
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "climb_rate_target: ";
    value_to_yaml(msg.climb_rate_target, out);
    out << "\n";
  }

  // member: sink_rate_target
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "sink_rate_target: ";
    value_to_yaml(msg.sink_rate_target, out);
    out << "\n";
  }

  // member: speed_weight
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "speed_weight: ";
    value_to_yaml(msg.speed_weight, out);
    out << "\n";
  }

  // member: enforce_low_height_condition
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "enforce_low_height_condition: ";
    value_to_yaml(msg.enforce_low_height_condition, out);
    out << "\n";
  }

  // member: disable_underspeed_protection
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "disable_underspeed_protection: ";
    value_to_yaml(msg.disable_underspeed_protection, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const px4_msgs::msg::LongitudinalControlConfiguration & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

template<>
inline const char * data_type<px4_msgs::msg::LongitudinalControlConfiguration>()
{
  return "px4_msgs::msg::LongitudinalControlConfiguration";
}

template<>
inline const char * name<px4_msgs::msg::LongitudinalControlConfiguration>()
{
  return "px4_msgs/msg/LongitudinalControlConfiguration";
}

template<>
struct has_fixed_size<px4_msgs::msg::LongitudinalControlConfiguration>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<px4_msgs::msg::LongitudinalControlConfiguration>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<px4_msgs::msg::LongitudinalControlConfiguration>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // PX4_MSGS__MSG__DETAIL__LONGITUDINAL_CONTROL_CONFIGURATION__TRAITS_HPP_
