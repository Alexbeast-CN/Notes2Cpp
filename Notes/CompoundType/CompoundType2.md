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
`new`的意义在于可以在运行阶段分配未命名的内存以储存值。使用方法是：
```cpp
typeName * pointer_name = new typeName;
```

下面的例程演示了`new`的用法：
```cpp
// use_new.cpp -- using the new operator
#include <iostream>
int main(int argc, char *argv[])
{
    using namespace std;
    int nights = 1001;
    int * pt = new int; //allocate space for an int
    *pt = 1001;         // store a value there

    cout << "nights value = " << nights
    << ": location " << &nights << endl;
    cout << "int value = " << *pt
    << " : location = " << pt << endl;

    double *pd = new double;    //allocate space for a double
    *pd = 1000001.0;    // store a double there

    cout << "double value = " << *pd 
    << ": location = " << pd << endl;
    cout << "location of pointer pd: " << &pd << endl;
    cout << "size of pt = " << sizeof (pt);
    cout << ": size of *pt = " << sizeof (*pt) << endl;
    cout << "size of pd = " << sizeof (pd);
    cout << " : size of *pd = " << sizeof(*pd) << endl;


    return 0;
}
```
out:
```
nights value = 1001: location 0x61fe14
int value = 1001 : location = 0x6d1680
double value = 1e+06: location = 0x6d16a0
location of pointer pd: 0x61fe08
size of pt = 8: size of *pt = 4
size of pd = 8 : size of *pd = 8
```

通过这个例程我发现，使用了`new`后，我们的指针也有了地址，`*pt`和`*pd`变成了普通变量，可以不用再对其命名就能直接调用了。这为我们使用指针提供了方便。

### 4.6.4 使用 delet 释放内存 
对于以后不再使用的变量，我们可以利用`delete`释放内存。使用方法如下：
```cpp
int *pt = new int;  //allocate memory with new
   // use the memory
delete ps;  /free memory with delet when done
```
使用`delete`的时候一定要注意，不要释放已经释放过的内存块。并且`delete`只能释放`new`分配的内存。
```cpp
// Don't do
int * ps = new int;
delete ps;
delete ps;
// Don't do
int jugs = 5;
int *pi = &jugs;
delete pi;
```

### 4.6.5 使用 new 来创建动态数组
#### 4.6.5.1 创建动态数组
创建一个包含10个 int 元素的数组：
```cpp
int * psome = new int [10]; // get a block of 10 ints
```
使用完后也可以使用`delete`释放这个内存块：
```cpp
delete [] psome;    // free a dynamic array
```

使用`new`和`delete`时应该遵守的规则：
* 不要使用`delete`来释放不是`new`分配的内存。
* 不要使用`delete`释放同一个内存2次。
* 当我们使用`new []`的时候，对应的也要使用`delete []`来释放内存。
* 如果使用`new`的时候，只能用`delete`（没有方括号的）来释放内存。
* 对空指针应用`delete`时安全的。

#### 4.6.5.1 使用动态数组
下面我们来利用一个例程讲解如何使用动态数组：
```cpp
// arraynew.cpp -- using the new operater for arrays
#include <iostream>
int main(int argc, char *argv[])
{
    using namespace std;
    double *p3 = new double[3]; //space for 3 doubles
    p3[0] = 0.2;
    p3[1] = 0.5;
    p3[2] = 0.8;
    cout << "p3[1] is " << p3[1] << endl;

    p3 = p3 + 1; // increase the pointer
    cout << "Now p3[0] is " << p3[0] << " and "
         << "p3[1] is " << p3[1] << endl;
    p3 = p3 - 1; //point back to beginning
    delete[] p3; // free the memory
    return 0;
}
```
out:
```
p3[1] is 0.5
Now p3[0] is 0.5 and p3[1] is 0.8
```

这段代码就体现出了动态数组和数组之间的差异，一般的数组不能够参与运算，但是当我们把动态数组 +1 后，则改变了指针的指向，最后我们将其减一，让指针回到原位，给`delete[]`提供正确的地址。

## 4.7 指针、数值和指针算术
首先我们用一个例程来看一下什么时指针算数：
```cpp
// addpntrs.cpp -- pointer addition

#include <iostream>
int main(int argc, char const *argv[])
{
    using namespace std;
    double wages[3] = {10000.0, 20000.0, 30000.0};
    short stack[3] = {3, 2, 1};

    //Here are two ways to get the address of an array
    double *pw = wages;    //name of an array = address
    short *ps = &stack[0]; // or use address operator
    // with array element
    cout << "pw = " << pw << ", *pw = " << *pw << endl;
    pw = pw + 1;
    cout << "add 1 to the pw pointer:\n";
    cout << "pw = " << pw << ", *pw = " << *pw << endl
         << endl;
    cout << "ps = " << ps << " *ps = " << *ps << endl;
    ps = ps + 1;
    cout << "ps = " << ps << " *ps = " << *ps << endl
         << endl;

    cout << "access two elements with array notation.\n";
    cout << "stack[0] = " << stack[0]
         << "stack[1] = " << stack[1] << endl;
    cout << "access two elements with pointer notation.\n";
    cout << "*stack = " << *stack
         << ", *(stakc + 1 ) = " << *(stack + 1) << endl;

    return 0;
}
```
out:
```
pw = 0x61fdf0, *pw = 10000
add 1 to the pw pointer:
pw = 0x61fdf8, *pw = 20000

ps = 0x61fdea *ps = 3
ps = 0x61fdec *ps = 2

access two elements with array notation.
stack[0] = 3stack[1] = 2
access two elements with pointer notation.
*stack = 3, *(stakc + 1 ) = 2
```




