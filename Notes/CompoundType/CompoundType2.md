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

### 4.7.1 程序说明
在大多数情况下，C++将组名解释为数组的第一个元素的地址。因此，下面的语句将`pw`声明指向`double`类型的指针，然后将他初始化为`wages`中第一个元素的地址。
```cpp
double * pw = wages;
```
和所有数组一样`wages`也存在下面的等式：
```cpp
wages = &wages[0] = address of first element of array
```

程序中使用的`* (stack + 1)`与`stack[1]`的效果相同。但是`* (stack + 1)`与`*stack + 1` 又不一样，其区别是后者将指针偏移了。

指针与数组的另外一个区别是，在使用`sizeof`运算符的时候，对数组对应的是数组的长度，而对指针应用`sizeof`得到的是指针的长度。比如之前的例子中，使用`sizeof(wages)`的结果会是24， `sizeof(pw)`的结果是4.

### 4.7.2 数组的地址
对数组取地址的时候，数组名不会被解释为其地址，而是数组中第一个元素的地址，而对数组名应用地址运算符的时候，得到的是整个数组的地址：
```cpp
short tell[10]; // tell an array of 20 bytes
cout << tell << endl;    // displays &tell[0]
cout << &tell << endl;   // displays address of whole array
```
从数字上说，这两个结果是相同的，但是从概念上说，`&tell[0]`是一个2字节内存的地址，而`&tell`是一个20字节内存块的地址。内存，表达式`tell + 1`将地址加2，而表达式`&tell + 1`将地址加20。

### 4.7.3 指针小结
* 声明指针
```cpp
typeName * pointerName;
```
* 给指针赋值

```cpp
double * pn;             // pn can point to a double value
double * pa;             // so can pa
char * pc;               // pc can point to a char value
double bubble = 3.2;     
pn = &bubble;            // assign address of bubble to pn
// assign address of newly allocated char memory to pc    
pc = new char;           

// assign address of 1st element of arrary of 30 double to pa 
pa = new double[30];
```

* 对指针解除引用
对指针解除引用意味着获得指针所指向的值。
```cpp
cout << *pn;   // print the value of bubble
*pc = 's';     // place 's' into the memory location whose address is pc
```
注意：不要对未初始化的指针解除引用。

* 区别指针和指针所指向的值
如果`pt`是指向`int`的指针，则`*pt`是完全等同于`int`变量。
```cpp
int * pt = new int;
*pt = 5
```

* 数组名
一般情况下，C++将数组名视为数组第一个元素的地址。
```cpp
int tacos [10];     // now tacos is the same as &tacos[0]
```

* 指针算术
C++允许指针和整数相加。加1的结果等于原来的地址值加上指向的对象占用的总字节数。还可以将一个指针减去另一个指针，获得两个指针的差。后一种运算将得到一个整数，仅当两个指针指向同一个数组时，这种运算才有意义；这将得到两个元素的间隔。
下面时一些示例：
```cpp
int tacos[10] = {5,2,8,4,1,2,2,4,6,8};
int * pt = tacos;   // suppose pf and taci are the address 3000
pt = pt + 1;        // now pt is 3004 if a int is 4 bytes
int *pe = &tacos[9];     // pe is 3036 if a int is 4 bytes
pe = pe - 1;             // pe is 3036, the address of tacos [8]
int diff = pe - pt;      // diff is 7, the separation between tacos[8] and tacos[1]
```

* 数组的动态联编和静态联编
使用数组声明来创建数组时，将采用静态联编，即数组的长度在编译时设置：
```cpp
int tacos [10];     // static binding, size fixed at compile time
```
使用`new[]`运算符创建数组时，将采用动态联编（动态数组），即将在运行时为数组分配空间，其长度也将在运行时设置。使用完这种数组后，应使用`delete[]`释放器占用的内存;
```cpp
int size;
cin >> size;
int *pz = new int [size];     // dynamic binding, size set at run time

delete [] pz;                 // free memory when finished
```

* 数组表示法和指针表示法
使用方括号数组表示法等同于对指针解除引用：

`tacos[0]`等同于`*tacos` 就是`tacos`地址处的值。
`tacos[3]`等同于`*(tacos + 3)` 就是 `tacos + 3`地址处的值。
数组名和指针变量都是如此，因此对于指针和数组名，即可以使用指针表示法，也可以使用数组表示法。
下面是一些示例：
```cpp
int * pt = new int [10];      // pt points to block of 10 ints
*pt = 5;                      // set element number 0 to 5
pt[0] = 6;                    // set element number 0 to 6
pt[9] = 44;                   // set element number 9 to 44
int coats [10];
* (coats + 4) = 12;           // set coats[4] to 12
```

### 4.7.4 使用 new 创建动态结构
下面的例程展示了使用`new`创建一个动态结构的方法：
```cpp
// newstrct.cpp  -- using new with a structure
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
    inflatable *ps = new inflatable; // allot memory for structure
    cout << "Enter name of inlatable item: ";
    cin.get(ps->name, 20); // method 1 for member access
    cout << "Enter volume in cubic feet: ";
    cin >> (*ps).volume; // method 2 for member access
    cout << "Enter price: $";
    cin >> ps->price;
    cout << "Name: " << (*ps).name << endl;    // method 2
    cout << "Volume: " << ps->volume << endl;  // method 1
    cout << "Price: $" << (*ps).price << endl; // method 2
    delete ps;                                 // free memory used by structure
    return 0;
}
```
out:
```
Enter name of inlatable item: Football
Enter volume in cubic feet: 23
Enter price: $17.2
Name: Football
Volume: 23
Price: $17.2
```
一个使用`delete`的示例：
```cpp
// delete.cpp -- using the delete operator
#include <iostream>
#include <cstring>
using namespace std;
char *getname(void); // function prototype
int main(int argc, char *argv[])
{
    char *name; //create pointer but no storage

    name = getname(); // assign address of string to name
    cout << name << " at " << (int *)name << endl;
    delete[] name; // memory freed

    name = getname(); // reuse freed memory
    cout << name << " at " << (int *)name << endl;
    delete[] name; // memory freed

    return 0;
}

char *getname() // return pointer to new string
{
    char temp[80]; // temporary storage
    cout << "Enter last name: ";
    cin >> temp;
    char *pn = new char[strlen(temp) + 1];

    strcpy(pn, temp); // copy string into smaller space
    return pn;
}
```
out:
```
Enter last name: Kang
Kang at 0xeb1680
Enter last name: Chen
Chen at 0xeb1680
```

程序说明：
首先来看一下函数`getname()`。它使用`cin`将单词放入`temp`数组中，然后使用`new`重新分配内存。重新分配的内存使用的空间为`strlen(temp) + 1`，加一是因为还需要一个字符来储存字符串。然后使用`strcpy()`将`temp`中的字符串复制到新的内存块中。最后，函数返回`pn`这是字符串副本的地址。