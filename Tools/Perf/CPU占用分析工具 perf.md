## perf

- 安装

  ```
  sudo apt-get install linux-tools-common
  sudo apt-get install linux-tools-generic
  sudo apt-get install linux-cloud-tools-generic
  sudo apt-get install linux-tools-"$(uname -r)"
  sudo apt-get install linux-cloud-tools-"$(uname -r)"
  ```

- [perf-让CPU消耗无处遁形](https://cloud.tencent.com/developer/article/1655528)

- ```
  perf record --freq 99 --call-graph dwarf /integration/bin/mainboard -d /integration/conf/pnc/etc/worldmodel/dag/worldmodel.dag
  
  Cmakelist -g 模式
  ```

## SpeedScope

- [使用SpeedScope作性能分析](https://sundy-li.github.io/posts/%E4%BD%BF%E7%94%A8speedscope%E4%BD%9C%E6%80%A7%E8%83%BD%E5%88%86%E6%9E%90/)
- ```
  perf script -i perf.data > profile.linux-perf.txt
  ```

- 拖拽到 `https://www.speedscope.app/` 中打开，中间需要选一下线程

