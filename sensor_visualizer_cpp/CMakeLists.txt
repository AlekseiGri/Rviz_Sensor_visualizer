
cmake_minimum_required(VERSION 2.8.3)
project(sensor_visualizer_cpp)

## Find catkin and any catkin packages
find_package(catkin REQUIRED COMPONENTS 
    roscpp
    std_msgs
    visualization_msgs
)


## Declare a catkin package
catkin_package()

## Build talker and listener
include_directories(include ${catkin_INCLUDE_DIRS})

install(DIRECTORY config/
 DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}/config
 )

add_executable(sensor_publisher src/sensor_publisher.cpp)
target_link_libraries(sensor_publisher ${catkin_LIBRARIES})

add_executable(rviz_marker_publisher src/rviz_marker_publisher.cpp)
target_link_libraries(rviz_marker_publisher ${catkin_LIBRARIES})
