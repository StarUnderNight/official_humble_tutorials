# 使用colcon构建包

## 1. 构建工作空间

```bash
colcon build --symlink-install
```

## 2. colcon_cd命令
快速跳转到指定的包
```bash
colcon_cd some_ros_package
```

需要将下面的内容写入.bashrc才能启用这个功能
```bash
echo "source /usr/share/colcon_cd/function/colcon_cd.sh" >> ~/.bashrc
echo "export _colcon_cd_root=/opt/ros/humble/" >> ~/.bashrc
```

## 3. colcon命令的tab补全
安装`colcon-argcomplete` 
