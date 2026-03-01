# 记录和回放数据
1）记录数据
```bash
ros2 bag record <topic_name>

# 记录多个话题
ros2 bag record -o subset /turtle1/cmd_vel /turtle1/pose
```

2）查看bag包信息
```bash
ros2 bag info <bag_file_name>
```

3）回放
```bash
ros2 bag play subset
```