/**
 * @file sample_service_client.hpp
 * @brief Example to call service in ROS2 node to check Seek service of "ros2 bag play"
 */

#include <rclcpp/client.hpp>
#include <rclcpp/rclcpp.hpp>
#include <rosbag2_interfaces/srv/seek.hpp>

#ifndef INCLUDE_RCLCPP_PRACTICE_SAMPLE_SERVICE_CLIENT_HPP
#define INCLUDE_RCLCPP_PRACTICE_SAMPLE_SERVICE_CLIENT_HPP

namespace rclcpp_practice
{

class SampleServiceClient : public rclcpp::Node
{
public:
  SampleServiceClient(const rclcpp::NodeOptions& options=rclcpp::NodeOptions());

private:
  rclcpp::TimerBase::SharedPtr _timer;
  rclcpp::Client<rosbag2_interfaces::srv::Seek>::SharedPtr _client;

  void timer_cb();


};

} // namespace rclcpp_practice


#endif /* ifndef INCLUDE_RCLCPP_PRACTICE_SAMPLE_SERVICE_CLIENT_HPP */
