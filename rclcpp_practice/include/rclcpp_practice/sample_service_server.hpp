/**
 * @file sample_service_server.hpp
 */

#include <rclcpp/client.hpp>
#include <rclcpp/rclcpp.hpp>
#include <rosbag2_interfaces/srv/seek.hpp>

#ifndef INCLUDE_RCLCPP_PRACTICE_SAMPLE_SERVICE_SERVER_HPP
#define INCLUDE_RCLCPP_PRACTICE_SAMPLE_SERVICE_SERVER_HPP

namespace rclcpp_practice
{

class SampleServiceServer : public rclcpp::Node
{
public:
  SampleServiceServer(const rclcpp::NodeOptions& options=rclcpp::NodeOptions());

private:
  rclcpp::Service<rosbag2_interfaces::srv::Seek>::SharedPtr _srvr;
  void serviceCb(
    const rosbag2_interfaces::srv::Seek::Request::SharedPtr request,
    const rosbag2_interfaces::srv::Seek::Response::SharedPtr response);

};

} // namespace rclcpp_practice


#endif /* ifndef INCLUDE_RCLCPP_PRACTICE_SAMPLE_SERVICE_SERVER_HPP */
