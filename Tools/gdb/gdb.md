# [gdb](https://www.sourceware.org/gdb/)

## tutorials
- https://sourceware.org/gdb/current/onlinedocs/gdb.pdf


## attach
```
sudo gdb attach pid
```

### attach 之后的命令
- info threads
    - 查看线程信息
- bt
    - 查看堆栈信息
- thread id
    - 切换到具体的线程id，一般切换到具体的线程后再执行bt等操作。

## 查看core文件

coredump文件生成

```
ulimit -a   看系统对core文件的大小设置
ulimit -c unlimited 
```

之后再
`ulimit -a`

`cat /proc/sys/kernel/core_pattern` 

`echo /root/world_model/logs/core-%p-%t > /proc/sys/kernel/core_pattern` 
这个文件中是生成的core文件的路经； 
程序崩溃了的话就会在该路经下生成core文件；

或者：
`echo /root/.cores_cyber/core-%p-%t > /proc/sys/kernel/core_pattern` 

然后：
`gdb 可执行文件 core文件`
注意：
cmakelists中必须要有 -g 选项  以及debug模式
例子

```
// --------------
// worldmodel

gdb /integration/bin/mainboard -d /integration/conf/pnc/etc/worldmodel/dag/worldmodel.dag -core /root/world_model/logs/core-1151264-1670488711

// --------------
// visualizer_ros
gdb mainboard -d /root/visualizer_ros/cyber_component/dag/rosdebug_cyber_component.dag -core /root/.cores_cyber/core-1849144-1675399919
```



然后：
`bt 查看堆栈`

如何关闭coredump文件的生成
`ulimit -S -c 0`
参考：
http://c.biancheng.net/view/8174.html

断点调试
vscode调试worldmodel代码 
基于vscode + clangd

- https://blog.csdn.net/m0_54206076/article/details/123836683  这个写的比较好
- cmakelists中加入
# for debug

```
set(CMAKE_CXX_FLAGS

        # "${CMAKE_CXX_FLAGS} -std=c++17 -pipe -O3 -Wall -Wextra  -Wfatal-errors -fopenmp -Wunused-parameter -Wunused-function -fPIC -pthread -Wl,--copy-dt-needed-entries"

​        "${CMAKE_CXX_FLAGS} -std=c++17 -pipe -O -Wall -g  -Wfatal-errors -fopenmp  -fPIC -pthread "
)
SET(CMAKE_BUILD_TYPE "Debug")
SET(CMAKE_C_FLAGS_DEBUG "$ENV{CFLAGS} -O0 -Wall -g -ggdb")
SET(CMAKE_C_FLAGS_RELEASE "$ENV{CFLAGS} -O3 -Wall")
SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CFLAGS} -O0 -Wall -g -ggdb")
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CFLAGS} -O0 -Wall")
```








- launch.json

  ```
  - // launch.json
    {
      "version": "0.2.0",
      "configurations": [
          {
              "name": "clangd-debug-wm",
              "type": "lldb",
              "request": "launch",
              "program": "/integration/bin/mainboard",
              "args": [
                  "-d",
                  "/integration/conf/pnc/etc/worldmodel/dag/worldmodel.dag"
              ],
              // "cwd": "${workspaceFolder}/world_model",
              "sourceLanguages": [
                  "C++"
              ],
              "stopOnEntry": false,
              "preRunCommands": [],
              "preLaunchTask": "run_wm_env",
              "env": {
                  "HHH": "0",
                  "GLOG_minloglevel": "1",
                  "GLOG_alsologtostderr": "1",
                  "GLOG_log_dir": "/root/world_model/logs",
                  "LD_LIBRARY_PATH": "/integration/lib/:/opt/ros/noetic/lib/",
                  "PATH": "$PATH:/integration/bin",
                  "CYBER_PATH": "/integration",
                  "CYBER_IP": "127.0.0.1",
                  "TERMINFO": "/usr/share/terminfo",
                  "TERM": "xterm-basic",
              },
          }
      ]
    }
  - tasks.json
    {
      "tasks": [
          {
              "type": "shell",
              "label": "echo_cwd",
              "command": "echo",
              "args": [
                  "${cwd}"
              ],
              "options": {},
              "problemMatcher": [],
              // "group": {
              //     "kind": "build",
              //     "isDefault": true
              // },
              "detail": "Generated task by Debugger"
          },
          {
              "type": "shell",
              "label": "wm_debug_env",
              "command": "source",
              "args": [
                  "/root/.vscode/run_wm.sh"
              ]
          },
          {
              "label": "echo_env",
              "type": "shell",
              "command": "bash ${workspaceFolder}/environment"
              //,
              // "presentation": {
              //  "reveal": "silent",
              //  "focus": false
              // }
          },
          {
              "type": "shell",
              "label": "run_wm_env",
              "command": "source",
              "args": [
                  "/root/.vscode/run_wm.sh"
              ]
          }
      ],
      // "version": "2.0.0"
    }
  ```

  

直接cmd中用gdb
参考：
- GDB调试中 如何在so共享库中打断点、保存断点以及加载断点_globbo的博客-CSDN博客_gdb调试so打不了断点
- 


lldb






博客
https://casatwy.com/shi-yong-lldbdiao-shi-cheng-xu.html

官方教程
Tutorial — The LLDB Debugger


https://blog.csdn.net/weixin_41795487/article/details/124970916


https://github.com/vadimcn/vscode-lldb/blob/v1.7.0/MANUAL.md

