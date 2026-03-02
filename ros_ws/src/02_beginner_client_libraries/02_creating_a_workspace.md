# 创建工作空间

## 1. 创建一个新的目录
```bash
mkdir -p ~/ros2_ws/src
cd ~/ros2_ws/src
```
## 2. 在src下创建若干功能包
src下创建若干功能包，可以在网上下载，也可以自己创建

官方是在ros2_ws/src下使用该命令
```bash
git clone https://github.com/ros/ros_tutorials.git -b humble
```

## 3. 解析功能包依赖
你下载或者自己创建的功能包可能需要一些依赖，这些依赖还没有下载，
则在与src同级的终端中，使用如下命令，去安装依赖。
```bash
rosdep install -i --from-path src --rosdistro humble -y
```