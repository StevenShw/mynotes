# algorithms

- CSK

- 算法分类
  - 经典算法：
    - MOSSE 
      - <https://blog.csdn.net/qq_22905795/article/details/97272882>
      
      - ![image-20230413145652986](image/image-20230413145652986.png)
      
        ![image-20230413145630199](image/image-20230413145630199.png)
      
      - 是基础算法
      
      - 相关性滤波操作：两个信号卷积结果数值越大越相关 MOSSE applies this idea to train a ﬁlter ht , which could obtain the response map gt when the object image ft and the ﬁlter ht are under correlation ﬁltering operation. The highest value in the response map gt indicates the center of the object
      
    - discriminative correlation ﬁlter（相关滤波器） based trackers.
        * The discriminative correlation ﬁlter based trackers view tracking as a classiﬁcation problem
        
    - kernel correlation ﬁlter based trackers. 
        * the kernel correlation ﬁlter based trackers view tracking as a ridge regression problem.
    
  - 基于学习 

QA：
- 图像的卷积是什么？
  （下面图像中的相关性计算公式有错误的）

![image-20230414104340934](image/image-20230414104340934.png)

![image-20230414104350711](image/image-20230414104350711.png)

![image-20230414104633171](image/image-20230414104633171.png)

- 为什么二维矩阵能做傅里叶变换

![image-20230414110258143](image/image-20230414110258143.png)

- https://www.zhihu.com/tardis/zm/art/54946461?source_id=1005