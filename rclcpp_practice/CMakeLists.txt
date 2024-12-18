cmake_minimum_required(VERSION 3.8)
project(rclcpp_practice)

# Default to C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_components REQUIRED)
find_package(std_msgs REQUIRED)
find_package(rosbag2_interfaces REQUIRED)

add_library(${PROJECT_NAME} SHARED
  src/rclcpp_practice/sample_component1.cpp
  src/rclcpp_practice/sample_component2.cpp
  src/rclcpp_practice/sample_service_client.cpp
  src/rclcpp_practice/sample_service_server.cpp
  src/rclcpp_practice/sample_parameter.cpp
)
rclcpp_components_register_node(${PROJECT_NAME}
  PLUGIN "rclcpp_practice::SampleComponent1"
  EXECUTABLE sample_component1_node
)
rclcpp_components_register_node(${PROJECT_NAME}
  PLUGIN "rclcpp_practice::SampleComponent2"
  EXECUTABLE sample_component2_node
)
rclcpp_components_register_node(${PROJECT_NAME}
  PLUGIN "rclcpp_practice::SampleServiceClient"
  EXECUTABLE sample_service_client_node
)
rclcpp_components_register_node(${PROJECT_NAME}
  PLUGIN "rclcpp_practice::SampleServiceServer"
  EXECUTABLE sample_service_server_node
)
rclcpp_components_register_node(${PROJECT_NAME}
  PLUGIN "rclcpp_practice::SampleParameter"
  EXECUTABLE sample_parameter_node
)
#rclcpp_components_register_nodes(${PROJECT_NAME}
 #"rclcpp_practice::SampleComponent1"
 #"rclcpp_practice::SampleComponent2"
#)
target_include_directories(${PROJECT_NAME}
  PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)
ament_target_dependencies(${PROJECT_NAME}
  rclcpp
  rclcpp_components
  std_msgs
  rosbag2_interfaces
)

add_executable(manual_load_composition
  src/manual_load_composition.cpp
)
target_include_directories(manual_load_composition
  PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)
target_link_libraries(manual_load_composition
  ${PROJECT_NAME}
)
ament_target_dependencies(manual_load_composition
  rclcpp
  rclcpp_components
  std_msgs
)

ament_export_targets(export_${PROJECT_NAME})
install(TARGETS
  ${PROJECT_NAME}
  EXPORT export_${PROJECT_NAME}
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin
  INCLUDES DESTINATION include
)

install(TARGETS
  manual_load_composition
  DESTINATION lib/${PROJECT_NAME}
)

install(DIRECTORY
  launch
  config
  DESTINATION share/${PROJECT_NAME}
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
