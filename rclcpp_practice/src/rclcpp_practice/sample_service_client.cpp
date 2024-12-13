/**
 * @file sample_service_client.cpp
 */

#include "rclcpp_practice/sample_service_client.hpp"
#include <rclcpp_components/register_node_macro.hpp>

using namespace std::chrono_literals;

namespace rclcpp_practice
{

SampleServiceClient::SampleServiceClient(const rclcpp::NodeOptions& options)
  : Node("sample_service_client", options)
{
   _timer = this->create_wall_timer(10s, std::bind(&SampleServiceClient::timer_cb, this));
   _client = this->create_client<rosbag2_interfaces::srv::Seek>(
           "/rosbag2_player/seek");
}

void SampleServiceClient::timer_cb()
{
  RCLCPP_INFO(this->get_logger(), "timer cb!");

  while(!_client->wait_for_service(1s))
  {
    if(!rclcpp::ok())
    {
      RCLCPP_INFO(this->get_logger(), "Interupted");
      return;
    }
    RCLCPP_INFO(this->get_logger(), "Waiting for service...");
  }

  auto request = std::make_shared<rosbag2_interfaces::srv::Seek::Request>();
  // If time is out of range of rosbag file, node of "ros2 bag play" will crash
  request->time.sec = 1732412500; // test value for 20241124_AM rosbag data

  auto response_cb =
    [this](rclcpp::Client<rosbag2_interfaces::srv::Seek>::SharedFuture future){
      std::string res = future.get()->success ? "success" : "fail";
      RCLCPP_INFO(this->get_logger(), "res: %s", res.c_str());
    };
  auto future_res = _client->async_send_request(request, response_cb);
}

RCLCPP_COMPONENTS_REGISTER_NODE(rclcpp_practice::SampleServiceClient)

} // namespace rclcpp_practice
