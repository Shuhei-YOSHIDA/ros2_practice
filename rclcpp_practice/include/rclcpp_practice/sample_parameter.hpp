/**
 * @file sample_parameter.hpp
 */

#ifndef INCLUDE_RCLCPP_PRACTICE_SAMPLE_PARAMETER_HPP
#define INCLUDE_RCLCPP_PRACTICE_SAMPLE_PARAMETER_HPP

#include <rclcpp/rclcpp.hpp>
namespace rclcpp_practice
{

class SampleParameter : public rclcpp::Node
{
public:
  SampleParameter(const rclcpp::NodeOptions& options=rclcpp::NodeOptions());

private:
  //rclcpp::TimerBase::SharedPtr _timer;
  //void timer_cb();
};

} // namespace rclcpp_practice

#endif /* ifndef INCLUDE_RCLCPP_PRACTICE_SAMPLE_PARAMETER_HPP */
