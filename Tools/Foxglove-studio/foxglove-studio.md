# Foxglove-studio连接wm-docker
## docker内外：
在docker内外的.bashrc中加入以下两行：
```
export ROS_MASTER_URI=http://$(hostname --ip-address):11311
export ROS_HOSTNAME=$(hostname --ip-address)
```
## docker外部执行以下操作
1. 安装本地foxglove-studio
https://foxglove.dev/download
2. 安装bridge
https://foxglove.dev/docs/studio/connection/using-foxglove-bridge
3. 运行bridge
rosrun foxglove_bridge foxglove_bridge
4. 打开foxglove-studio，连接到ros1

![image-20230423153151921](image/image-20230423153151921.png)

![image-20230423153204117](image/image-20230423153204117.png)

![image-20230423153217393](image/image-20230423153217393.png)

## 效果

![image-20230423153244067](image/image-20230423153244067.png)