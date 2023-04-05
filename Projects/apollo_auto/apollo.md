# 1

## Basic Steps

1.下载apollo源码并进入apollo目录
git clone <https://github.com/ApolloAuto/apollo.git>

2.安装docker
sudo docker/setup_host/install_docker.sh

3.启动docker
sudo docker/script/dev_start.sh

4.进入docker环境
sudo docker/script/dev_into.sh

5.在docker中编译apollo源码
sudo ./apollo.sh build

6.启动 Dreamview
sudo script/bootstrap.sh
若正常启动，打开 <http://localhost:8888> 可以看到效果

7.下载演示包
python docs/demo_guide/record_helper.py demo_3.5.record

8.运行演示包
cyber_recorder play -f docs/demo_guide/demo_3.5.record --loop
若提示 cyber_recorder:command not found
则执行 source cyber/setup.bash 将cyber_record添加到环境变量中

原文链接：<https://blog.csdn.net/haizixinzhu/article/details/124239322>

# 2 Cuda版本

11.1

<https://developer.nvidia.com/cuda-11.1.1-download-archive?target_os=Linux&target_arch=x86_64&target_distro=Ubuntu&target_version=2004&target_type=deblocal>

（本地不好编译 在docker中不用考虑自己安装cuda）

# 3 Bazel

最后编译的命令本质上就是：

```shell
bazel build //modules/... //cyber/... -//modules/drivers/canbus/can_client/esd/...
```

后面的省略号就是指的是这个文件夹下面的所有目标，包括子文件夹

``` shell
bazel build //modules/... 
```
