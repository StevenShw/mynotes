
- 定义了析构函数， 要禁用一些构造函数

```c++
class NonCopyable
{
public:
    NonCopyable() = default;
    virtual ~NonCopyable() = default;
    NonCopyable(NonCopyable const&) = delete;
    NonCopyable& operator =(NonCopyable const&) = delete;
    NonCopyable(NonCopyable&&) = delete;
    NonCopyable& operator=(NonCopyable&&) = delete;
};


```

- so文件的四个区

  ![image-20230425155029028](image/image-20230425155029028.png)

## tips
- 在C++中，如果基类的析构函数被声明为virtual，那么子类的析构函数会自动继承virtual属性，无需再次声明为virtual。实际上，子类的析构函数会被自动视为virtual，即使没有显式地声明为virtual。
这个特性确保在使用基类指针或引用删除子类对象时，能够正确调用子类的析构函数。这种行为被称为多态析构函数。

- C++中子类重写父类的虚函数能改变其访问权限吗
  - 答案是：可以的！没问题！试了两个最极端的情况：
  - 父类的虚函数（或纯虚函数）是private，子类可以重写成public并且之后可以被外面访问