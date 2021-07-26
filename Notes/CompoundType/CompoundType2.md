# C++ Primer Plus 学习笔记 {ignore=true}
---
# 第四章：复合类型（下） {ignore=true}

## 本章学习内容： {ignore=true}
[TOC]
---

## 4.4 结构简介

### 4.4.1 结构例程
`struct`结构可以方便的存储多种不同类型的变量。下面的例程展示了`struct`的用法：
```cpp
// structure.cpp -- a simple structrue.

#include <iostream>
#include <cmath>
using namespace std;

struct Classmates
{
    char name[20];
    float height;
    float weight;
    int student_num;
};

int main(int argc, char *argv[])
{
    Classmates Tim =
    {
        "Tim",  // name value of Tim  
        180,    // height value of Tim
        67,     // weight value of Tim
        02      // Tim's student number
    };
//Tim is a structure variable of type Classmats

    Classmates Tom =
    {
        "Tom",
        177,
        68,
        06
    };

    Classmates Lucas =
    {
        "Lucas",
        190,
        78,
        27
    };


    cout << "There are 3 people in the list"
          << " namely: \n" << Tom.name << endl
          << Tim.name << endl << Lucas.name 
          << endl<<endl;

    cout << "The hight of Lucas is " << Lucas.height
        << "\nThe student number of Tom is " << Tom.student_num
        << "\nThe weight of Tim is " << Tim.weight
        << endl;

    return 0;
}
```
out:
```
There are 3 people in the list namely:
Tom
Tim
Lucas

The hight of Lucas is 190
The student number of Tom is 6
The weight of Tim is 67
```

`structure`的声明可以放在`main`的前面也可以放在`main`函数内部。但，如果将结构声明放在函数内部，则结构只能够被这个函数调用，其他函数不可以使用。

### 4.4.2 结构的形式

在初始化结构的时候其形式与声明时不同，结构内部之间的变量以逗号（,）隔开，最后一个变量末尾没有逗号。比如：
```cpp
    Classmates Lucas =
    {
        "Lucas",
        190,
        78,
        27
    };
```
他们分别表示为：
```cpp
    结构名称 变量名称 =
    {
        成员1,
        成员2,
        成员3
    }
```
除了上面展示的，所有整型，浮点数，数组，字符串，`string`都可以是结构成员的类型。

### 4.4.3 结构初始化的其他方式
除了之前例程里展示的方式，下面还将介绍3种结构的初始化方式：

* 将变量放在结束括号后：
```cpp
struct Name
{
    char [20] first_name;
    char [20] last_name;
} Man1, Man2;   // 2 variables
```

* 声明的同时初始化
```cpp
struct Name
{
    char [20] first_name;
    char [20] last_name;
} Man1 =
{
    "Leonardo",
    "DaVince"
};
```

* 声明时还可以省略结构名称：
```cpp
struct  // no tag
{
    char [20] first_name;
    char [20] last_name;
} Man1; // a tructure variable
```

### 4.4.4 结构数组
结构数组的意思将数组作为一个结构的变量，这个变量中的每一个元素都可以作为一个单独的结构变量。这么说可能有点绕，那么看看例程吧：
```cpp
// arrstruc.cpp -- an array of structures
#include <iostream>
struct inflatable
{
    char name[20];
    float volume;
    double price;
};
int main(int argc, char *argv[])
{
    using namespace std;
    inflatable guests[2] = // initializing an array of structs
        {
            {"Bambi", 0.5, 21.99},     // first structure in array
            {"Godzilla", 2000, 565.99} // second structure in array
        };

    cout << "The guests " << guests[0].name << " and "
         << guests[1].name << "\nhave a combined volume of "
         << guests[0].volume + guests[1].volume << "cubic cm. \n";

    return 0;
}
```
out:
```
The guests Bambi and Godzilla
have a combined volume of 2000.5cubic cm.
```

## 4.5 枚举
`enum`枚举工具提供了另外一种创建符号常量的方式，这种方式可以代替`const`。它还允许定义新类型，但必须按严格的限制进行。使用方式如下：
```cpp
enum spectrum {red, orange, yellow,green, blue, violet, indigo, ultravilet}; //共8个值
```
上方的语句完成了两项任务：
* 让 `spectrum`成为新类型的名称；`spectrum`被称为枚举(enumeraton)，就像`struct`变量被称为结构一样。
* 将`red`, `orange`, `yellow`等作为符号常量，它们对应的整数值为：0-7。这些常量叫做枚举量（enumerator）。

一般来说，枚举量不用来计算。

枚举常用来代替`const`，使用方法如下：
```cpp
enum {zero, null = 0, one, numero_uno = 1};
// zero 和 null 都是常量 0， one 和 number_uno 都是常量 1.
```

## 4.6 指针和自由存储空间




