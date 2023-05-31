- 没有增加计数的话，就会导致shared_ptr管理的对象被析构两次
- 实现一个智能指针类， 记住： 每次为智能指针开辟内存时，也开辟了一个用于引用计数的内存， 析构时一起析构，注意构造函数有两种，一种是给裸指针， 一种是给别的智能指针对象，前者是会重新开辟内存块的，可能会析构两次
```
template <typename T>
class SharedPtr {
public:
    SharedPtr(T* ptr) : ptr_(ptr), refCount_(new int(1)) {}

    SharedPtr(const SharedPtr& other) : ptr_(other.ptr_), refCount_(other.refCount_) {
        ++(*refCount_);
    }

    ~SharedPtr() {
        if (--(*refCount_) == 0) {
            delete ptr_;
            delete refCount_;
        }
    }

    SharedPtr& operator=(const SharedPtr& other) {
        if (this != &other) {
            if (--(*refCount_) == 0) {
                delete ptr_;
                delete refCount_;
            }
            ptr_ = other.ptr_;
            refCount_ = other.refCount_;
            ++(*refCount_);
        }
        return *this;
    }

    T& operator*() const {
        return *ptr_;
    }

    T* operator->() const {
        return ptr_;
    }

private:
    T* ptr_;
    int* refCount_;
};

```

- 为何会出现这种使用场合
    -  因为在异步调用中，存在一个保活机制，异步函数执行的时间点我们是无法确定的，然而异步函数可能会使用到异步调用之前就存在的变量。为了保证该变量在异步函数执期间一直有效，我们可以传递一个指向自身的share_ptr给异步函数，这样在异步函数执行期间share_ptr所管理的对象就不会析构，所使用的变量也会一直有效了（保活）
