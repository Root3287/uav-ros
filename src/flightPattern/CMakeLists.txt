cmake_minimum_required(VERSION 3.0.2)
project(flightPattern)

find_package(catkin REQUIRED COMPONENTS
  mavros
  roscpp
  mavros_msgs
  std_msgs
  message_generation
)

add_message_files(
  FILES
  Trajectory.msg
)

generate_messages(
  DEPENDENCIES
  geometry_msgs
  flightPattern
)

catkin_package(
  CATKIN_DEPENDS 
  message_runtime
)

include_directories(include ${catkin_INCLUDE_DIRS})

add_executable(flightPatternTest src/flightPatternTest.cpp src/flightPatterns.cpp)
target_link_libraries(flightPatternTest ${catkin_LIBRARIES})
add_dependencies(flightPatternTest ${catkin_EXPORTED_TARGETS})