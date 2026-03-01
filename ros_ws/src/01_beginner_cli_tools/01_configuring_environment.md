# 配置ros环境

## 1. 终端刷新ros环境
打开终端，输入如下命令，将ros相关环境以及命令加入系统
```bash
source /opt/ros/humble/setup.bash
```
输入以上命令后才可以使用ros相关的命令和环境

可以将以上命令写入`.bashrc` 中，这样每次打开终端会自动执行这个命令

## 2. 查看ros环境变量
```bash
printenv | grep -i ROS
```

## 3. ros域名id
域名id等环境变量也可以设置
```bash
export ROS_DOMAIN_ID=<your_domain_id>
```
