/**
 * @file sample_component1.cpp
 */

#include "rclcpp_practice/sample_component1.hpp"

using namespace std::chrono_literals;

namespace rclcpp_practice
{

SampleComponent1::SampleComponent1(const rclcpp::NodeOptions& options)
    : Node("sample_component1", options)
{
   _str_pub = this->create_publisher<std_msgs::msg::String>("str_data", 10);
   _timer = this->create_wall_timer(1s, std::bind(&SampleComponent1::timer_cb, this));
}

void SampleComponent1::timer_cb()
{
  auto msg = std_msgs::msg::String();
  msg.data = "Hello, world! from sample_components1 : " + std::to_string(_count);
  RCLCPP_INFO(this->get_logger(), "Publishing : '%s'", msg.data.c_str());
  _count++;
  _str_pub->publish(msg);
}

} // namespace rclcpp_practice
