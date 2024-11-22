/**
 * @file sample_component2.cpp
 */

#include "rclcpp_practice/sample_component2.hpp"

using std::placeholders::_1;

namespace rclcpp_practice
{

SampleComponent2::SampleComponent2(const rclcpp::NodeOptions& options)
    : Node("sample_component2", options)
{
  _str_sub = this->create_subscription<std_msgs::msg::String>(
          "str_data", 10, std::bind(&SampleComponent2::str_cb, this, _1));
}

void SampleComponent2::str_cb(const std_msgs::msg::String::SharedPtr msg)
{
  RCLCPP_INFO(this->get_logger(), "I heard: '%s'", msg->data.c_str());
}

} // namespace rclcpp_practice
