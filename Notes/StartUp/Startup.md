@import "my-style.less"

# 第二章：开始学习C++ {ignore=true}
---
## 本章学习内容： {ignore=true}
[TOC]
---

### 2.1 创建C++程序

#### 2.1.1 第一个cpp程序

myfirst.cpp
```cpp {.line-numbers}
// myfirst.cpp -- display a message
#include <iostream>                 // a preprocessor directive
int main()                          // function header
{                                   // start of function body
    using namespace std;            // make definitions visible
    // message
    cout << "Come up and C++ me some time.";
    // start a new line
    cout << endl;
    // more output
    cout << "You won't regret it!" << endl;
    // terminate main()
    return 0;
}
```

代码完成后使用g++进行编译。首先`Terminal` :fa-arrow-right: `New Terminal` 打开一个终端。查看目前终端所在的所在路径。

@import "./pics/1.png"

如图，目前所在的文件是`StartUp`中，也是`MyFirst.cpp`所在的的文件夹；若不是，需使用指令`cd`，将路径切换到`.cpp`文件所在的路径。
例：
@import "./pics/2.png"

然后再运行`g++`的指令编译刚才的代码：
```cdm
g++ -g .\MyFirst.cpp -o MyFirst  
```
此时，左侧的目录就可以看到刚刚创建的一个叫`MyFirst.exe`的执行文件。
直接在Terimial中输入`.\MyFirst.exe`我们运行这个文件，结果如下：
@import "./pics/3.png"

至此，我们的第一个C++程序完成。

### 2.2 C++ 程序的一般格式
#### 2.2.1 一般格式
去掉修饰后，一个基本的程序如下：
```cpp
int main() //函数头
// 函数体
{
    statements
    return 0;
}
```
在目前的C++语法中，main函数需要以 int main()开始。

#### 2.2.2 函数头的解释
一般来说，main函数不会被其他函数调用。但作为接口函数，main函数会被我们的计算机（linux、Windows）在使用C++编写程序的时候调用。因此一般来说，我们的main函数都是一个整型函数（int 类型），并且会返回一个值（0）。main后面的括号空置表示不调用任何参数，相当于void。虽然这样的效果相当于使用 `void main()` 但为了使计算机可以正常编译，我们还是会使用`int main()`作为函数头。


### 2.3 #include 编译指令
### 2.4 main()函数
### 2.5 使用cout 对象进行输出
### 2.6 在C++程序中加入注释
### 2.7 何时以及如何使用 endl
### 2.8 声明和使用变量
### 2.9 使用 cin 对象进行输入
### 2.10 定义和使用简单的函数






