launch.json文件

``` json
{
    "version": "0.2.0",
    "configurations": [
        {
            "name": "g++ mainboard",
            "type": "cppdbg",
            "request": "launch",
            // "preLaunchTask": "Run",
            "program": "/integration/bin/mainboard",
            "args": ["-d","/integration/conf/pnc/etc/worldmodel/dag/worldmodel.dag"],
            "stopAtEntry": false,
            "cwd": "/root",
            "environment": [{"name": "LD_LIBRARY_PATH", "value": "/opt/ros/noetic/lib/:/integration/lib:$LD_LIBRARY_PATH"},
                            {"name": "PATH","value": "$PATH:/integration/bin"},
                            {"name": "CYBER_PATH","value": "/integration"},
                            {"name": "CYBER_IP","value": "127.0.0.1"},
                            {"name": "TERMINFO","value": "/usr/share/terminfo"},
                            {"name": "TERM","value": "xterm-basic"},
                            {"name": "GLOG_log_dir","value": "./logs/"},
                            {"name": "GLOG_minloglevel","value": "0"},
                            {"name": "GLOG_v","value": "5"},
                            {"name": "DISPLAY","value": ":0"},],
            "externalConsole": false,
            "MIMode": "gdb",
            "setupCommands": [
                {
                    "description": "为 gdb 启用整齐打印",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                }
            ],
            "miDebuggerPath": "/usr/bin/gdb"
        }
    ]
}
```
