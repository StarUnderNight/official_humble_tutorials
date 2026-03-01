# turtlesim、ros2以及rqt的使用
## 1. turtlesim
1）安装turtlesim
```bash
sudo apt update
sudo apt install ros-humble-turtlesim
```
2）查看功能包包含的可执行程序
```bash
$ ros2 pkg executables turtlesim
turtlesim draw_square
turtlesim mimic
turtlesim turtle_teleop_key
turtlesim turtlesim_node
```
3）启动乌龟
启动后会出现一个弹窗，里面有一只乌龟
```bash
ros2 run turtlesim turtlesim_node
```
4）控制乌龟
新开一个终端，运行命令，然后通过键盘箭头控制乌龟运动
```bash
ros2 run turtlesim turtle_teleop_key
```

## 2. rqt
1）安装rqt
```bash
sudo apt update
sudo apt install '~nros-humble-rqt*'
```
2）使用rqt
终端运行rqt
```bash
rqt
```
详细操作点击链接[rqt操作](https://docs.ros.org/en/humble/Tutorials/Beginner-CLI-Tools/Introducing-Turtlesim/Introducing-Turtlesim.html)



