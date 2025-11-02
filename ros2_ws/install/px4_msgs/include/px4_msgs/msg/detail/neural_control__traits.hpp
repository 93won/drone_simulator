// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from px4_msgs:msg/NeuralControl.idl
// generated code does not contain a copyright notice

#ifndef PX4_MSGS__MSG__DETAIL__NEURAL_CONTROL__TRAITS_HPP_
#define PX4_MSGS__MSG__DETAIL__NEURAL_CONTROL__TRAITS_HPP_

#include "px4_msgs/msg/detail/neural_control__struct.hpp"
#include <stdint.h>
#include <rosidl_runtime_cpp/traits.hpp>
#include <sstream>
#include <string>
#include <type_traits>

namespace rosidl_generator_traits
{

inline void to_yaml(
  const px4_msgs::msg::NeuralControl & msg,
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

  // member: observation
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.observation.size() == 0) {
      out << "observation: []\n";
    } else {
      out << "observation:\n";
      for (auto item : msg.observation) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: network_output
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.network_output.size() == 0) {
      out << "network_output: []\n";
    } else {
      out << "network_output:\n";
      for (auto item : msg.network_output) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: controller_time
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "controller_time: ";
    value_to_yaml(msg.controller_time, out);
    out << "\n";
  }

  // member: inference_time
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "inference_time: ";
    value_to_yaml(msg.inference_time, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const px4_msgs::msg::NeuralControl & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

template<>
inline const char * data_type<px4_msgs::msg::NeuralControl>()
{
  return "px4_msgs::msg::NeuralControl";
}

template<>
inline const char * name<px4_msgs::msg::NeuralControl>()
{
  return "px4_msgs/msg/NeuralControl";
}

template<>
struct has_fixed_size<px4_msgs::msg::NeuralControl>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<px4_msgs::msg::NeuralControl>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<px4_msgs::msg::NeuralControl>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // PX4_MSGS__MSG__DETAIL__NEURAL_CONTROL__TRAITS_HPP_
