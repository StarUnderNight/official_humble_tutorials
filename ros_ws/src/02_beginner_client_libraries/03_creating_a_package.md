# 创建功能包
## 1. 创建功能包
进入src目录，`cd ~/ros2_ws/src` 
```bash
ros2 pkg create --build-type ament_cmake --license Apache-2.0 <package_name>

# --node-name参数会创建一个简单的Hello World类型的可执行程序
ros2 pkg create --build-type ament_cmake --license Apache-2.0 --node-name my_node my_package
```