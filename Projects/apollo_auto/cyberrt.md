# Cyber 

- Component和TimerComponent的区别是什么？

- getopt_long
    - 解析命令行选项
- 把互斥锁放在一个函数中
    - ```
    std::recursive_mutex& GetLibPathSharedLibMutex() {
  static std::recursive_mutex m;
  return m;
} // 把锁放在一个函数中
    ```
- cyber是怎么动态载入类的？
    - 