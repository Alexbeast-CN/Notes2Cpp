# C++ Primer Plus 学习笔记 {ignore=true}
---
# 第四章：复合类型（下） {ignore=true}

## 本章学习内容： {ignore=true}
[TOC]
---

## 4.6 指针和自由存储空间
指针是C++中的一个重要概念。指针是一个变量，其储存的是值的地址，而不是值的本身。比如，变量`home`，其地址由`&home`表示。一般来说，我们声明变量数组的时候会声明这个数组中有多少个元素，但有些时候一开始所声明的元素，也许要少于我们需要使用的所有元素。为了避免这样的问题，C++的面向对象（OOP）功能就发挥作用了，我们可以先为变量声明一个地址，再将变量储存起来。使用关键词`new`请求正确数量的内存以及使用指针来跟踪新分配的内存的位置。下面的例程将演示如何使指针。
```cpp
// pointer.cpp -- our first pointer variable

#include<iostream>
using namespace std;

int main(int argc, char *argv[])
{
    int update = 6;
    int *p_update;  // declare pointer to an int
    p_update = &update; // assign address of int to pointer

    cout << "Values: update = " << update;
    cout << " *p_update is " << *p_update << endl;

    cout << "Address: &update = " << &update;
    cout << " p_update = " << p_update << endl;

    // use pointer to change value
    *p_update = *p_update+1;
    cout << "Now update = " << update << endl;

    return 0;
}
```
out:
```
Values: update = 6 *p_update is 6
Address: &update = 0x61fe14 p_update = 0x61fe14
Now update = 7
```

从中可以知，`upate`和`p_update`只不过是硬币的两面，变量`update`表示值，`p_update`表示地址，`update`通过`&`运算符获取地址，`p_update`通过`*`指针获取值。因此，`*p_update`与`update`完全等价，可以像`int`变量那样使用`*p_update`。并且`*p_update`的改变会影响到`update`的值。

### 4.6.1 声明和初始化指针
在写 * 运算的时候有2中写法：
```cpp
// handle 1
int *ptr;
```
和
```cpp
// handle 2
int* ptr;
```
1 中强调`*ptr`是一个`int`类型的值。
2 中强调`int*`是一个类型 -- 指向`int`的指针。

我们甚至可以不加空格直接写成：
```cpp
int*ptr;
```
但这种方法并不推荐。此外如果我们使用指针声明变量的时候，写成以下形式可能会出现一些问题：
```cpp
int* p1, p2;
```
这里的`p1`是一个指针，而`p2`是一个`int`变量。每一个指针的声明都需要一个*。

### 4.6.2 指针的危险
首先举一个错误的例子：
```cpp
long *num; // create a pointer-to-long
*num = 233333;  // place a value in never-never land
```
因为C++指针不会被赋予一个存储地址，所以如果初始化的时候没有给`*num`一个地址，所以`*num`的值就变得不确定了。

### 4.6.3 使用new来分配内存






