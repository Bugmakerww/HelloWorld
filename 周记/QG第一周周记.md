# QG训练营移动组第一周周记：
2023年3月19日

## 生活随记

### 数据结构-链表

1. 创建Status InitList(LinkedList *L)函数时，由于是直接复制头文件过去，没有仔细理解LNode和LinkedList的区别，导致出现如下错误

   ![image-20230319091031333](C:\Users\86137\AppData\Roaming\Typora\typora-user-images\image-20230319091031333.png)

**Error:表达式必须包含指向结构或联合的指针类型**

解决方法：调转回去看头文件，发现typedef定义了LNode相当于LinkedList，因此把Status InitList(LinkedList *L)的\*去掉即可

3.18



补充（3.19）

```c
Status InitList(LinkedList L){
    L = (LinkedList*)malloc(sizeof(LNode));
    if (L == NULL){
        printf("创建失败！\n");
        return ERROR;
    }
    L->next = NULL;
    printf("创建成功\n");
    return SUCCESS;
}
```

经过资料查找，我发现自己对初始化链表理解有误，以上是我原先的代码

而实际上我找到的资料是通过一个LinkedList*型指针指向LinkedList型指针来创建，这也就解释得通Status InitList(LinkedList *L)为什么带\*了



2. 看不懂void TraverseList(LinkedList L, void(*visit)(ElemType e))的第二个参数，查了发现visit用于指向具体函数，初步大致了解其功能，并无深究，看得懂就行



3. 一直出现为声明标识符，可是明明定义了的...   

   或许是编译器的问题

   ![](C:\Users\86137\Pictures\Screenshots\QQ图片20230320015727.png)



### Android

#### 1.3

Activity是 Android系统提供的一个活动基类，我们项目中所有的活动都必须继承它或者它的子类才能拥有活动的特性（AppCompatActivity 是 Activity的子类)。



HelloWorldActivity中有一个onCreate()方法,这个方法是一个活动被创建时必定要执行的方法



#### res目录

所有以drawable开头的文件夹都是用来放图片的，所有以mipmap开头的文件夹都是用来放应用图标的，所有以values开头的文件夹都是用来放字符串、样式、颜色等配置的，layout文件夹是用来放布局文件的



![image-20230317163535018](file://C:\Users\86137\AppData\Roaming\Typora\typora-user-images\image-20230317163535018.png?lastModify=1679248491)



#### 引用资源

在代码中通过R.string.hello_world可以获得该字符串的引用。

在XML中通过@string/hello_world可以获得该字符串的引用。





#### 日志

##### 自定义过滤器

![image-20230317174815176](file://C:\Users\86137\AppData\Roaming\Typora\typora-user-images\image-20230317174815176.png?lastModify=1679248491)





##### 日志级别控制及关键字过滤

![image-20230317175357922](file://C:\Users\86137\AppData\Roaming\Typora\typora-user-images\image-20230317175357922.png?lastModify=1679248491)



其中关键字支持正则表达式



#### id定义和引用

在XML中引用一个id：**@id/id_name**

在XML中定义一个id：**@+id/id_name**





#### 快捷键

![image-20230317173716137](file://C:\Users\86137\AppData\Roaming\Typora\typora-user-images\image-20230317173716137.png?lastModify=1679248491)



#### Toast

Toast是Android系统提供的一种非常好的提醒方式,在程序中可以使用它将一些短小的信息通知给用户，这些信息会在一段时间后自动消失，并且不会占用任何屏幕空间

#### 2.2

##### 一些概念

![image-20230319161945954](file://C:\Users\86137\AppData\Roaming\Typora\typora-user-images\image-20230319161945954.png?lastModify=1679248491)

<item   android:id   android:title



#### 随记

这周四弄Android，遇到很多困难。

首先是Android的虚拟机。刚开始按照书本的操作一步步进行，没有意外，直到弄了虚拟机开始，显示以下错误

![img](file://C:\Users\86137\Pictures\Screenshots\QQ%E5%9B%BE%E7%89%8720230320001201.png?lastModify=1679248491)



可能是电脑CPU不支持，抑或者是其他原因，那天查了很久博客，各种方法都实了个遍，依旧无法运行虚拟机

![img](file://C:\Users\86137\Pictures\Screenshots\QQ%E5%9B%BE%E7%89%8720230320001222.png?lastModify=1679248491)



最后无奈第二天装了个夜神模拟器

![img](file://C:\Users\86137\Pictures\Screenshots\%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE%202023-03-20%20001359.png?lastModify=1679248491)



周五晚上开始Android的学习，学到后面又想着接实机，发现无法连接到实机，又只能用模拟器了（/(ㄒoㄒ)/~~）



![img](file://C:\Users\86137\Pictures\Screenshots\QQ%E5%9B%BE%E7%89%8720230320001231.png?lastModify=1679248491)



#### 一些感想

截至周日晚，学到了50页左右，由于周六一天都在搞活动导致进度慢了许多。感受是很多都是照着书本敲，结合讲解大致理解代码含义，但由于缺乏系统的学习和充足的经验，许多概念性和方法性知识过一遍就忘了，难以形成系统的框架和结构，仍需好好琢磨参悟



git弄了好久，时间紧，其他事占用时间多，有点草率...





## 一周总结

学习了链表的各种操作，加深了对数据结构的理解

（尽管效果不尽如人意）



学习了Android的一些知识

## 存在问题

因为经验不足以及其他因素，无法完成对链表的测试。今后慢慢加深学习和理解，争取克服困难

## 下周规划

1. 进一步完善数据结构的学习
2. 进一步学习Android
