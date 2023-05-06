# ROS1
- 初始化一个节点， 且不注册ctrl-c响应函数[ref](http://wiki.ros.org/roscpp/Overview/Initialization%20and%20Shutdown)
``` C++
static int a = 0;
ros::init(a, NULL, "rosnode_wm_cpp_debug_by_" + std::to_string(getpid()),
              ros::init_options::NoSigintHandler);
```