// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from px4_msgs:msg/FixedWingLateralGuidanceStatus.idl
// generated code does not contain a copyright notice

#ifndef PX4_MSGS__MSG__DETAIL__FIXED_WING_LATERAL_GUIDANCE_STATUS__TRAITS_HPP_
#define PX4_MSGS__MSG__DETAIL__FIXED_WING_LATERAL_GUIDANCE_STATUS__TRAITS_HPP_

#include "px4_msgs/msg/detail/fixed_wing_lateral_guidance_status__struct.hpp"
#include <stdint.h>
#include <rosidl_runtime_cpp/traits.hpp>
#include <sstream>
#include <string>
#include <type_traits>

namespace rosidl_generator_traits
{

inline void to_yaml(
  const px4_msgs::msg::FixedWingLateralGuidanceStatus & msg,
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

  // member: course_setpoint
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "course_setpoint: ";
    value_to_yaml(msg.course_setpoint, out);
    out << "\n";
  }

  // member: lateral_acceleration_ff
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "lateral_acceleration_ff: ";
    value_to_yaml(msg.lateral_acceleration_ff, out);
    out << "\n";
  }

  // member: bearing_feas
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "bearing_feas: ";
    value_to_yaml(msg.bearing_feas, out);
    out << "\n";
  }

  // member: bearing_feas_on_track
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "bearing_feas_on_track: ";
    value_to_yaml(msg.bearing_feas_on_track, out);
    out << "\n";
  }

  // member: signed_track_error
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "signed_track_error: ";
    value_to_yaml(msg.signed_track_error, out);
    out << "\n";
  }

  // member: track_error_bound
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "track_error_bound: ";
    value_to_yaml(msg.track_error_bound, out);
    out << "\n";
  }

  // member: adapted_period
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "adapted_period: ";
    value_to_yaml(msg.adapted_period, out);
    out << "\n";
  }

  // member: wind_est_valid
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "wind_est_valid: ";
    value_to_yaml(msg.wind_est_valid, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const px4_msgs::msg::FixedWingLateralGuidanceStatus & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

template<>
inline const char * data_type<px4_msgs::msg::FixedWingLateralGuidanceStatus>()
{
  return "px4_msgs::msg::FixedWingLateralGuidanceStatus";
}

template<>
inline const char * name<px4_msgs::msg::FixedWingLateralGuidanceStatus>()
{
  return "px4_msgs/msg/FixedWingLateralGuidanceStatus";
}

template<>
struct has_fixed_size<px4_msgs::msg::FixedWingLateralGuidanceStatus>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<px4_msgs::msg::FixedWingLateralGuidanceStatus>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<px4_msgs::msg::FixedWingLateralGuidanceStatus>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // PX4_MSGS__MSG__DETAIL__FIXED_WING_LATERAL_GUIDANCE_STATUS__TRAITS_HPP_
