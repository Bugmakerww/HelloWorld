# QG训练营移动组第二周周记：
2023年3月28日

## 生活随记

### 感想

通过逐步探究学习《第一行代码》，已经从上周的照抄代码懵懵懂懂到了现在的基本理解代码含义，可以根据自己的理解修改书中代码实现不同的效果。但一些具体的格式仍不是很清晰，比如xml中的<    />等。

### 3.27

队列写的半夜2点，前面的函数都测试得不错，而对于泛型的函数具体如何实现确是摸不着头脑。查了博客，修修补补，又出现了奇怪的BUG。但由于对这方面的知识认知比较浅，我挑了很久也没有完全弄好。最后发现原来训练营的文件里给了泛型实现的一些代码以及UI的实现，我只能把原来的函数代码移植过去继续实现。太晚了，先睡觉。

### 3.28

LQueue给出的源文件有一些，需要修改后才能使用。如没有加;

没有定义addData而是定义成了add_data，以及length未定义等。

修改后可以运行，但是测试时发现LengthQueue函数出现异常，发现其return类型是Status的。而前面为修改**”警告	1	warning C4020: “LengthLQueue”: 实参太多	“**把第二个参数length去掉了，采用return Q->length一条语句的方式完成函数，而返回值按要求是Status的，所以是需要用*length指针来接长度的，但头文件对于函数的声明是

/**
*  @name        : int LengthLQueue(LQueue *Q)
*    @description : 确定队列长度
*    @param         Q 队列指针Q
*    @return         : 成功-TRUE; 失败-FALSE
*  @notice      : None
*/
int LengthLQueue(LQueue *Q);



只有一个参数，由此推测是头文件制作的疏漏，少给了第二个参数，添加或问题得以解决。



如果没有头文件和源文件的提供，恐怕很难短时间内完成。

#### memcpy函数语法

博客上看到的函数，去查了具体介绍如下：



函数原型
void *memcpy(void *destin, void *source, unsigned n);
参数
destin-- 指向用于存储复制内容的目标数组，类型强制转换为 void* 指针。
source-- 指向要复制的数据源，类型强制转换为 void* 指针。
n-- 要被复制的字节数。
返回值
该函数返回一个指向目标存储区destin的指针。
功能
从源source所指的内存地址的起始位置开始拷贝n个字节到目标destin所指的内存地址的起始位置中。

## 一周总结

### 学习进度

首先这周有许多活动占据了学习时间，如周三的班委述职的准备，包括PPT的制作，也有防诈宣传主题班会，还有周五下午的信息安全专业宣讲会明明说是16：30到18：00的，结果弄到了18：40。加上周六下午还有选修，以及利用一些时间把前两周的高数线代进度跟上，导致这周的Android学习进度慢了。

这周我先把书的大致内容看了一遍，确认重点章节，再从第二章后面开始看，目前学到第六章（一些内容有跳过）。虽然很多内容看得行云流水，但为了保证知识的牢固性选择了将代码和用法截取出来做成笔记加深印象，方便日后查找复习，这也导致了进度的拖拉。



## 存在问题

1. 数据结构不够熟练，每个项目都得花半天才能做好

2. Android学习进度缓慢，需要加快

## 下周规划

从下周开始，需要加快Android学习进度，因此我会视情况适当选择跳过一些笔记的记录。



***



## 部分笔记

# Android

## 3.2 常用控件的使用方法

### 3.2.1 TextView

#### 文字对齐方式

![image-20230326003247291](C:/Users/86137/AppData/Roaming/Typora/typora-user-images/image-20230326003247291.png)



#### 字体大小和颜色

![image-20230326003541340](C:/Users/86137/AppData/Roaming/Typora/typora-user-images/image-20230326003541340.png)



### 3.2.2 Button

#### 代码

```
<Button
    android:id="@+id/button"
    android:layout_width="match_parent"
    android:layout_height="wrap_content"
    android:text="Button"
    android:textAllCaps="false"/>//使“Button”不会转为全大写
```



#### 注册监听器的两种方式

##### 匿名内部类

![image-20230326003915447](C:/Users/86137/AppData/Roaming/Typora/typora-user-images/image-20230326003915447.png)



##### 实现接口

```
public class MainActivity extends AppCompatActivity implements View.OnClickListener{

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        Button button=(Button)findViewById(R.id.button);
        button.setOnClickListener(this);
    }

    @Override
    public void onClick(View v) {
        switch (v.getId()){
            case button:
                //此处添加逻辑
                break;
            default:
                break;
        }
    }
}
```



### 3.2.3 EditText

```
<EditText
    android:id="@+id/edit_text"
    android:layout_width="match_parent"
    android:layout_height="wrap_content"
    android:hint="Type something here"//提示语句
    android:maxLines="2"//指定最大行数为2
    />
```



### 3.2.4 ImageView

#### 用法

![image-20230326012259141](C:/Users/86137/AppData/Roaming/Typora/typora-user-images/image-20230326012259141.png)



#### 动态更改图片

![image-20230326012529595](C:/Users/86137/AppData/Roaming/Typora/typora-user-images/image-20230326012529595.png)



### 3.2.5 ProgressBar

进度条，表示加载数据



#### 代码

```
<ProgressBar
    android:id="@+id/progress_bar"
    android:layout_width="match_parent"
    android:layout_height="wrap_content"
    style="?android:attr/progressBarStyleHorizontal"//水平进度条
    android:max="100"
    />
```

#### 显示与隐藏

![image-20230327002750375](C:/Users/86137/AppData/Roaming/Typora/typora-user-images/image-20230327002750375.png)



#### 进度条加载

```
public void onClick(View v) {
    switch (v.getId()){
        case R.id.button:
            //此处添加逻辑
            int progress=progressBar.getProgress();
            progress=progress+10;//每次点击加10
            progressBar.setProgress(progress);
            break;
        default:
            break;
    }
}
```





### 3.2.6 AlertDialog

![image-20230327003023742](C:/Users/86137/AppData/Roaming/Typora/typora-user-images/image-20230327003023742.png)



### 3.2.7 ProgressDialog

![image-20230327003119726](C:/Users/86137/AppData/Roaming/Typora/typora-user-images/image-20230327003119726.png)



注意，如果在**setCancelable()中传入了false**，表示 ProgressDialog是不能通过Back键取消掉的，这时就一定要在代码中做好控制，当数据加载完成后必须要调用ProgressDialog的**dismiss()**方法来关闭对话框，否则ProgressDialog将会一直存在。



