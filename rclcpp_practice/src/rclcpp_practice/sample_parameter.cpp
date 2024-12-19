/**
 * @file sample_parameter.cpp
 */

#include "rclcpp_practice/sample_parameter.hpp"
#include <rclcpp_components/register_node_macro.hpp>

using namespace std::chrono_literals;

namespace rclcpp_practice
{

SampleParameter::SampleParameter(const rclcpp::NodeOptions& options)
  : Node("sample_parameter", options)
{
  RCLCPP_INFO(this->get_logger(), "Start SampleParameter");
  this->declare_parameter("test_param1", "data_test_param1");
  this->declare_parameter("test_param2", "data_test_param2");
  this->declare_parameter("namespace_example.test_param3", "data_test_param3");
  this->declare_parameter("namespace_example.test_param4", "data_test_param4");
  this->declare_parameter("test_param5", std::vector<double>({1.0, 2.0, 3.0}));


 //_timer = this->create_wall_timer(10s, std::bind(&SampleParameter::timer_cb, this));
}

//void SampleParameter::timer_cb()
//{
  //RCLCPP_INFO(this->get_logger(), "timer cb!");
//}

RCLCPP_COMPONENTS_REGISTER_NODE(rclcpp_practice::SampleParameter)

} // namespace rclcpp_practice
