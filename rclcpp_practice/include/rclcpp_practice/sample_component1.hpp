/**
 * @file sample_component1.cpp
 */

#ifndef INCLUDE_RCLCPP_PRACTICE_SAMPLE_COMPONENT1_HPP
#define INCLUDE_RCLCPP_PRACTICE_SAMPLE_COMPONENT1_HPP

#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>

namespace rclcpp_practice
{

class SampleComponent1 : public rclcpp::Node
{
public:
  SampleComponent1(const rclcpp::NodeOptions& options=rclcpp::NodeOptions());

private:
  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr _str_pub;
  rclcpp::TimerBase::SharedPtr _timer;

  void timer_cb();

  size_t _count = 0;

};

} // namespace rclcpp_practice


#endif /* ifndef RCLCPP_PRACTICE_SAMPLE_COMPONENT1_HPP */
