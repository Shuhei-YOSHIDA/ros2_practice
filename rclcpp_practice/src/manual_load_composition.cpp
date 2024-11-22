/**
 * @file manual_load_composition.cpp
 * @brief Components are loaded statically into executor's node.
 */

#include <rclcpp/executors/single_threaded_executor.hpp>
#include <rclcpp/rclcpp.hpp>
#include <rclcpp_practice/sample_component1.hpp>
#include <rclcpp_practice/sample_component2.hpp>

int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);

  rclcpp::executors::SingleThreadedExecutor exec;
  rclcpp::NodeOptions options;

  // SampleComponents1/2 has same named parameters.
  auto sc1 = std::make_shared<rclcpp_practice::SampleComponent1>(options);
  exec.add_node(sc1);
  auto sc2 = std::make_shared<rclcpp_practice::SampleComponent2>(options);
  exec.add_node(sc2);

  exec.spin();
  rclcpp::shutdown();

  return 0;
}
