/**
 * @file sample_component2.cpp
 */

#ifndef INCLUDE_RCLCPP_PRACTICE_SAMPLE_COMPONENT2_HPP
#define INCLUDE_RCLCPP_PRACTICE_SAMPLE_COMPONENT2_HPP

#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>

namespace rclcpp_practice
{

class SampleComponent2 : public rclcpp::Node
{
public:
  SampleComponent2(const rclcpp::NodeOptions& options=rclcpp::NodeOptions());

private:
  rclcpp::Subscription<std_msgs::msg::String>::SharedPtr _str_sub;
  void str_cb(const std_msgs::msg::String::SharedPtr msg);

};

} // namespace rclcpp_practice


#endif /* ifndef RCLCPP_PRACTICE_SAMPLE_COMPONENT2_HPP */
