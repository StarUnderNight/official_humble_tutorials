#!/bin/bash

# 先加载系统ROS
source /opt/ros/humble/setup.bash

# 再加载你的workspace
source /home/h/ws/clion-ws/official_humble_tutorials/build_ws/install/setup.bash

# 最后执行传入命令（非常重要）
exec "$@"