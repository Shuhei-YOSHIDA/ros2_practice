/**
 * @file sample_service_server.cpp
 */

#include "rclcpp_practice/sample_service_server.hpp"
#include <rclcpp_components/register_node_macro.hpp>

using namespace std::chrono_literals;
using namespace std::placeholders;

namespace rclcpp_practice
{

SampleServiceServer::SampleServiceServer(const rclcpp::NodeOptions& options)
  : Node("sample_service_server", options)
{
  // Fake service to imitate "ros2 bag player"
  _srvr = this->create_service<rosbag2_interfaces::srv::Seek>(
      "/rosbag2_player/seek",
      std::bind(&SampleServiceServer::serviceCb, this, _1, _2));

}

void SampleServiceServer::serviceCb(
  const rosbag2_interfaces::srv::Seek::Request::SharedPtr request,
  const rosbag2_interfaces::srv::Seek::Response::SharedPtr response)
{
  RCLCPP_INFO(this->get_logger(), "ServiceServer is called, req is : %d", request->time.sec);
  response->success = true;
}

RCLCPP_COMPONENTS_REGISTER_NODE(rclcpp_practice::SampleServiceServer)

} // namespace rclcpp_practice
