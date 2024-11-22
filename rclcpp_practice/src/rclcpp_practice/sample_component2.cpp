/**
 * @file sample_component2.cpp
 */

#include "rclcpp_practice/sample_component2.hpp"
#include <rclcpp_components/register_node_macro.hpp>

using std::placeholders::_1;

namespace rclcpp_practice
{

SampleComponent2::SampleComponent2(const rclcpp::NodeOptions& options)
    : Node("sample_component2", options)
{
  _str_sub = this->create_subscription<std_msgs::msg::String>(
          "str_data", 10, std::bind(&SampleComponent2::str_cb, this, _1));

   _same_name_param = this->declare_parameter("same_name_param", _same_name_param);
   _component2_unique_param = this->declare_parameter("component2_unique_param", _component2_unique_param);

   RCLCPP_INFO(this->get_logger(), "same_name_param is %s", _same_name_param.c_str());
   RCLCPP_INFO(this->get_logger(), "component2_unique_param is %s", _component2_unique_param.c_str());

}

void SampleComponent2::str_cb(const std_msgs::msg::String::SharedPtr msg)
{
  RCLCPP_INFO(this->get_logger(), "I heard: '%s'", msg->data.c_str());
}

RCLCPP_COMPONENTS_REGISTER_NODE(rclcpp_practice::SampleComponent2)

} // namespace rclcpp_practice
