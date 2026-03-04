cmake_minimum_required(VERSION 3.14)
project("ros_ws")

include("/opt/ros/cmake/colcon.cmake")

message(STATUS "AMENT_PREFIX_PATH=$ENV{AMENT_PREFIX_PATH}")
message(STATUS "CMAKE_PREFIX_PATH=$ENV{CMAKE_PREFIX_PATH}")
message(STATUS "ROS_DISTRO=$ENV{ROS_DISTRO}")


# only for clion highlighting and analysis
colcon_add_subdirectories(
        BUILD_BASE "${PROJECT_SOURCE_DIR}/build"
        BASE_PATHS "${PROJECT_SOURCE_DIR}/src/"
        --packages-select cpp_pubsub cpp_srvcli
)
