# 基于 《C++ Primer Plus》 的学习笔记 
---
## 目录
- [第二章：开始学习C++](#第二章开始学习c)
  - [2.1 创建C++程序](#21-创建c程序)
    - [2.1.1 第一个cpp程序](#211-第一个cpp程序)
    - [2.1.2 程序的运行](#212-程序的运行)
  - [2.2 C++ 程序的一般格式](#22-c-程序的一般格式)
    - [2.2.1 一般格式](#221-一般格式)
    - [2.2.2 函数头的解释](#222-函数头的解释)
  - [2.3 #include 编译指令](#23-include-编译指令)
    - [2.3.1 C++的预处理器和iostream文件](#231-c的预处理器和iostream文件)
    - [2.3.2 空间名称](#232-空间名称)
  - [2.4 使用 cout 对象进行输出](#24-使用-cout-对象进行输出)
    - [2.4.1 一条cout语句的解释](#241-一条cout语句的解释)
    - [2.4.2 控制符endl](#242-控制符endl)
    - [2.4.3 换行符](#243-换行符)
  - [2.5 声明和使用变量](#25-声明和使用变量)
    - [2.5.1 一个例程](#251-一个例程)
    - [2.5.2变量声明](#252变量声明)
    - [2.5.3 cout](#253-cout)
  - [2.6 使用 cin 对象进行输入](#26-使用-cin-对象进行输入)
    - [例程](#例程)
  - [2.7 定义和使用简单的函数](#27-定义和使用简单的函数)
    - [2.7.1 有返回值的函数](#271-有返回值的函数)
    - [2.7.2 函数变体](#272-函数变体)
    - [2.7.3 用户自定义的函数](#273-用户自定义的函数)
- [第三章：处理数据](#第三章处理数据)
  - [3.1 简单变量](#31-简单变量)
    - [3.1.1 变量名称](#311-变量名称)
    - [3.1.2 整型](#312-整型)
    - [3.1.3 数据的初始化](#313-数据的初始化)
    - [3.1.4 无符号类型](#314-无符号类型)
    - [3.1.5 整型字面值](#315-整型字面值)
    - [3.1.6 char 类型](#316-char-类型)
    - [3.1.7 布尔类型（bool）](#317-布尔类型bool)
  - [3.2 const 限定符](#32-const-限定符)
  - [3.3 浮点数](#33-浮点数)
  - [3.4 C++ 算术运算符](#34-c-算术运算符)
    - [3.4.1 5个基本的算数运算符](#341-5个基本的算数运算符)
    - [3.4.2 运算符的优先性](#342-运算符的优先性)
    - [3.4.3 除法分支](#343-除法分支)
    - [3.4.4 类型转换](#344-类型转换)
      - [3.4.4.1 初始化和赋值进行的转换](#3441-初始化和赋值进行的转换)
      - [3.4.4.2 以{}方式初始化时进行的转换](#3442-以方式初始化时进行的转换)
      - [3.4.4.3 表达式中的转换](#3443-表达式中的转换)
      - [3.4.4.4 强制类型转换](#3444-强制类型转换)
      - [3.4.4.5 C++ 11 中的auto声明](#3445-c-11-中的auto声明)
- [第四章：复合类型](#第四章复合类型)
  - [4.1 数组](#41-数组)
    - [4.1.1 数组初始化的规则](#411-数组初始化的规则)
  - [4.2 字符串](#42-字符串)
    - [4.2.1 字符串与数组](#421-字符串与数组)
    - [4.2.2 字符串输入](#422-字符串输入)
  - [4.3 String类介绍](#43-string类介绍)
  - [4.4 结构简介](#44-结构简介)
    - [4.4.1 结构例程](#441-结构例程)
    - [4.4.2 结构的形式](#442-结构的形式)
    - [4.4.3 结构初始化的其他方式](#443-结构初始化的其他方式)
    - [4.4.4 结构数组](#444-结构数组)
  - [4.5 枚举](#45-枚举)
  - [4.6 指针和自由存储空间](#46-指针和自由存储空间)
    - [4.6.1 声明和初始化指针](#461-声明和初始化指针)
    - [4.6.2 指针的危险](#462-指针的危险)
    - [4.6.3 使用new来分配内存](#463-使用new来分配内存)
    - [4.6.4 使用 delet 释放内存](#464-使用-delet-释放内存)
    - [4.6.5 使用 new 来创建动态数组](#465-使用-new-来创建动态数组)
      - [4.6.5.1 创建动态数组](#4651-创建动态数组)
      - [4.6.5.1 使用动态数组](#4651-使用动态数组)
  - [4.7 指针、数值和指针算术](#47-指针数值和指针算术)
    - [4.7.1 程序说明](#471-程序说明)
    - [4.7.2 数组的地址](#472-数组的地址)
    - [4.7.3 指针小结](#473-指针小结)
    - [4.7.4 使用 new 创建动态结构](#474-使用-new-创建动态结构)
  - [4.8 类型组合](#48-类型组合)
    - [4.8.1 程序分析](#481-程序分析)
  - [4.9 数组的替代品](#49-数组的替代品)
    - [4.9.1 模板类 vector](#491-模板类-vector)
    - [4.9.2 模板类 array](#492-模板类-array)
    - [4.9.3 比较数组、vector 对象和array 对象](#493-比较数组vector-对象和array-对象)
  - [4.10 练习题](#410-练习题)
    - [4.10.1 练习题1](#4101-练习题1)
    - [4.10.2 练习题2](#4102-练习题2)
    - [4.10.3 练习题3](#4103-练习题3)
- [第七章 函数 -- C++的编程模块](#第七章-函数----c的编程模块)
  - [7.1 复习函数的基础知识](#71-复习函数的基础知识)
    - [7.1.1 定义函数](#711-定义函数)
    - [7.1.2 函数原型和调用](#712-函数原型和调用)
  - [7.2 函数参数和按值传递](#72-函数参数和按值传递)
    - [7.2.1 多个参数](#721-多个参数)
    - [7.2.2 一个例题](#722-一个例题)
  - [7.3 函数与数组](#73-函数与数组)
    - [7.3.1 函数如何使用指针来处理数组](#731-函数如何使用指针来处理数组)
    - [7.3.2 更多数组函数示例](#732-更多数组函数示例)
    - [7.3.4 使用数组区间的函数](#734-使用数组区间的函数)
    - [7.3.4 指针和`const`](#734-指针和const)
  - [7.4 函数和二维数组](#74-函数和二维数组)
  - [7.5 函数和C-风格字符串](#75-函数和c-风格字符串)
    - [7.5.1 将C-风格字符串作为参数的函数](#751-将c-风格字符串作为参数的函数)
    - [7.5.2 返回C-风格字符串的函数](#752-返回c-风格字符串的函数)
  - [7.6 函数和结构](#76-函数和结构)
    - [7.6.1 传递和返回结构](#761-传递和返回结构)
    - [7.6.2 另一个处理结构的函数示例：](#762-另一个处理结构的函数示例)
    - [7.6.3 传递结构地址](#763-传递结构地址)
  - [7.7 函数和`string`对象](#77-函数和string对象)
  - [7.8 函数与 array 对象](#78-函数与-array-对象)
  - [7.9 递归](#79-递归)
    - [7.9.1 包含一个递归调用的递归](#791-包含一个递归调用的递归)
    - [7.9.2 包含多个递归调用的递归](#792-包含多个递归调用的递归)
  - [7.10 函数指针](#710-函数指针)
    - [7.10.1 基础知识](#7101-基础知识)
    - [7.10.2 输入探讨函数指针](#7102-输入探讨函数指针)
---
# 第二章：开始学习C++ 

## 2.1 创建C++程序

### 2.1.1 第一个cpp程序

myfirst.cpp

```cpp
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

### 2.1.2 程序的运行

代码完成后使用g++进行编译。首先`Terminal` :fa-arrow-right: `New Terminal` 打开一个终端。查看目前终端所在的所在路径。

![ ](https://github.com/Alexbeast-CN/Notes2Cpp/blob/main/Notes/StartUp/pics/1.png)

如图，目前所在的文件是`StartUp`中，也是`MyFirst.cpp`所在的的文件夹；若不是，需使用指令`cd`，将路径切换到`.cpp`文件所在的路径。
例：
![ ](https://github.com/Alexbeast-CN/Notes2Cpp/blob/main/Notes/StartUp/pics/2.png)

然后再运行`g++`的指令编译刚才的代码：
```cdm
g++ -g .\MyFirst.cpp -o MyFirst  
```
此时，左侧的目录就可以看到刚刚创建的一个叫`MyFirst.exe`的执行文件。
直接在Terimial中输入`.\MyFirst.exe`我们运行这个文件，结果如下：
![ ](https://github.com/Alexbeast-CN/Notes2Cpp/blob/main/Notes/StartUp/pics/3.png)

至此，我们的第一个C++程序完成。

## 2.2 C++ 程序的一般格式
### 2.2.1 一般格式
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

### 2.2.2 函数头的解释
一般来说，main函数不会被其他函数调用。但作为接口函数，main函数会被我们的计算机（linux、Windows）在使用C++编写程序的时候调用。因此一般来说，我们的main函数都是一个整型函数（int 类型），并且会返回一个值（0）。main后面的括号空置表示不调用任何参数，相当于void。虽然这样的效果相当于使用 `void main()` 但为了使计算机可以正常编译，我们还是会使用`int main()`作为函数头。

## 2.3 #include 编译指令
### 2.3.1 C++的预处理器和iostream文件
如果程序需要输入或输出工具，需要提供以下两行代码：
``` cpp
#include <iostream>
using namespace std;
```

### 2.3.2 空间名称
` #include <iostream>`相当于将<iostream>文件添加到了我们所写的程序中，编译的时候，会将`<iostream>`的源码和程序代码文件的内容所组成的一个复合程序传到编译器中。有了`<iostream>`文件后，我们就可以使用`cin`和`cout`进行输入和输出了。
C++的头文件去掉了之前版本的`.h`后缀。再去掉后缀的同时，我们添加了另外一行`using namespace std;`代码。其含义是`使用空间名称：std`。之所以这样是因为不同的封装库中可能有相同名称的函数。比如，Micoflop 和 Piscine 库中都含有一个名为 wanda()的函数，如果直接调用这个函数，我们的编译器将不知道调用哪一个库中的函数，因此需要使用`空间名称（namespace）`来为我们区分不同版本的wanda函数。
```cpp
Microflop::wanda("go dancing?");    //using Microflop namespace version
Piscine::wanda("a fish named Desire");  //using Piscine namespace
```
但是，每一次使用一个函数都要加上前缀是一个分麻烦的事情，因此，我们可以使用`using`提前声明我们需要使用的函数：

```cpp
using std::cin;     // make cin available
using std::cout;    // make cout available
using std::endl;    // make endl available
```

这样以后在使用`cin`, `cout`, `endl`的时候都不需要再添加`std::`前缀了。除此之外，我们也可以使用一开始我们用的方法。
```cpp
using namespace std;
```
但这是一种比较偷懒的方法，可以使得所有`std` 库中的函数都可以使用。虽然在大型工程中并不推荐使用这种方法，但是目前所学的内容中仅仅使用这样的方法就可以了。

## 2.4 使用 cout 对象进行输出
### 2.4.1 一条cout语句的解释
在需要显示一条消息的时候，我们要使用cout函数，如：
```cpp
std::cout<<"come up and c++ with me some time";
```
在上面的函数中：
```cpp
std::cout<<"come up and c++ with me some time";
^    ^   ^  ^
1    2   3  4

1. 所使用的空间名称
2. cout 对象
3. 运算符
4. 字符串
```
`<<` 有一个形象的含义，就是将右侧的字符数，流入到`cout`中去。

### 2.4.2 控制符endl
```cpp
cout << endl;
```
endl(end of line)是一个特殊的运算符，表示重启一行。在字符串打印的时候，光标不会自动移动到下一行，而是停留在输出字符串的后面，每一条cout语句的输出从前一条输出的末尾开始，比如：
```cpp
#include <iostream>
using namespace std;
main()
{
cout << "The Good, the";
cout << "Bad,";
cout << "and the Ukulele";
cout << endl;
} 
```
结果如下：
![ ](https://github.com/Alexbeast-CN/Notes2Cpp/blob/main/Notes/StartUp/pics/4.png)

输出为：
```
The Good, theBad, and the Ukulele
```
### 2.4.3 换行符
C++依然保留了C中的`\n`换行符，使用方法是：
``` cpp
cout << "What about you? \n"
```
一般在输出用引号括起来的字符串时，使用`\n`会更加方便，而其他情况下还是使用`endl`更加方便。比如，创建一个空行：
``` cpp
cout << "\n";
cout << endl;
```

## 2.5 声明和使用变量
### 2.5.1 一个例程
```cpp
# include <iostream>

int main()
{
    using namespace std;

    int n;
    n = 25;
    cout << "n = ";
    cout << n;
    cout << endl;
    n--;
    cout << "n = ";
    cout << n;
    cout << endl;
    return 0;
}
```
结果如下：
![ ](https://github.com/Alexbeast-CN/Notes2Cpp/blob/main/Notes/StartUp/pics/5.png)

```
n = 25
n = 24
```
### 2.5.2变量声明
在C++中在使用变量之前，必须对变量进行声明，比如这里使用了
``` cpp
int n;
```
int 表示变量是一个整型，它可以是正也可以是负，但不可以有小数。这样可以防止在使用变量的时候出现打错的现象。比如：

![ ](https://github.com/Alexbeast-CN/Notes2Cpp/blob/main/Notes/StartUp/pics/6.png)

在输入变量的时候，便会有提示出现。

### 2.5.3 cout
在上面的例子中，可以看到输入下面代码的时候，不是直接输出n，而是输出了 n 的值。
```cpp
cout << n;
```
## 2.6 使用 cin 对象进行输入
### 例程
```cpp
// getinfo.cpp -- input and output
#include <iostream>

int main()
{
    using namespace std;

    int carrots;

    cout << "How many carots do you have?" << endl;
    cin >> carrots; // c++ input
    cout << "Here are two more." << endl;
    carrots = carrots + 2;
    cout << "Now you have " << carrots << " carrots." << endl;
    return 0;
}
```
结果如下：
![ ](https://github.com/Alexbeast-CN/Notes2Cpp/blob/main/Notes/StartUp/pics/7.png)


```
How many carots do you have?
23
Here are two more
Now you have 25 carrots.
```

## 2.7 定义和使用简单的函数
C++的函数分为两种，一种是有返回值的函数，另外一种是没有返回值的函数。
### 2.7.1 有返回值的函数
有返回值的函数，如标准库`<cmath>`中的sqrt()函数。使用方法如下：
```cpp
X = sqrt(6.25);
^   ^    ^
1   2    3

1. 函数返回的值赋值给X
2. 函数名称
3. 传递给函数的参数
```
Out：
```cpp
X = 2.5
```
发送出去，被赋值给X的值，就叫做函数的返回值。但使用有返回值的函数之前，要告诉C++的编译器，函数的参数和返回值的类型是什么。也就是说，参数和返回值是整数、小数、字符还是什么别的类型。比如刚才使用的sqrt()函数，函数的原型是：

```cpp
double sqrt(double);
```
第一个double表示函数返回值是double类型，第二个double表示函数输入值是一个double类型。那么我们在使用他的时候，就应该：

```cpp
double x;
double y;

x = 25;
y = sqrt(x);
```
那么一个完整的sqrt程序就应该是：
```cpp
// sqrt.cpp -- using sqrt() function
#include <iostream>
#include <cmath>

using namespace std;
int main(){
    double x;
    cout << "please enter a number." << endl;
    cin >> x;
    double y;
    y = sqrt (x);
    cout << "the square root of the number is: " << y << endl;

    return 0;
}
```
运行结果是：
![ ](https://github.com/Alexbeast-CN/Notes2Cpp/blob/main/Notes/StartUp/pics/8.png)


```
please enter a number.
25
the square root of the number is: 5
```
### 2.7.2 函数变体
除了sqrt()，这样的有一个参数，一个返回值的函数外，还有一些有多个参数，或没有参数，或有多个返回值的函数。比如：
```cpp
// pow函数接受2个参数，第一个为底，第二个为幂。
double pow(double double);
// rand函数不接受参数，随机返回一个整数。
int rand();
// 没有返回值的函数。
void buck();
// void 表明了函数没有返回值。
```
### 2.7.3 用户自定义的函数

例程：
```cpp
// convert stone to pounds

#include <iostream>
int stone2lb(int);  //function prototype
int main()
{
    using namespace std;
    int stone;
    cout << "Enter the wight in stone" << endl;
    cin >> stone;
    int pounds = stone2lb(stone);
    cout << stone << " stone = " ;
    cout << pounds << " pounds" << endl;
    return 0;
}

int stone2lb(int sts)
{
    return 14 * sts;
}
```
输出结果如下：
![ ](https://github.com/Alexbeast-CN/Notes2Cpp/blob/main/Notes/StartUp/pics/9.png)

```
Enter the wight in stone
12
12 stone = 168 pounds
```

当然，例程中的stone2lb函数也可以改为：
```cpp
int stone2lb(int sts)
{
    int pounds = 14 * sts;
    retuen pounds;
}
```
# 第三章：处理数据 

## 3.1 简单变量
要把数据储存在计算机中，必须满足以下三个条件：
* 信息将储存在哪里；
* 要存储什么值；
* 储存什么类型的信息。

一般来说，我们使用C++存储数据会用到类似于下面的代码：
```cpp
int bitcoin;
bitcion = 2000;
```
这些语句可以告诉程序，它正在存储`整数`，并使用`bitcoin`为名称进行存储，存储的值为`5`。这时，程序会找到一个可以存下`bitcoin`大小的内存，但这个存储位置并没有反馈给我们，我们可以通过使用`&`运算符来检索`bitcoin`的存储地址。

### 3.1.1 变量名称
C++提倡使用有一定意义的变量名称，比如手机的价格：`PriceOfPhone`，而是随意的使用`x`之类的名称。这样的命名方式在编写大型工程的时候，对程序员的帮助很大。此外，C++还有一些必须遵守的命名规则；
* 名称中只能使用字母、数字和下划线(_)。
* 名称的第一个字不可以是数字。
* 区分大小写。
* C++对名称没有长度限制，但某些平台可能会
* 以两个下划线大头，或以下划线和大写字母打头的名称会被保留给现实（编译器及其使用的资源）使用。以一个下划线打头的名称会被保留给现实，用作全局标识符。如：`_time`这样的名称编译器不会报错，但可能会导致未知的结果。


### 3.1.2 整型
在C++中，我们使用`int`, `short`, `long`, 和`long long`来声明一个整型变量。其中的区别是不同声明的最小二进制长度不一样：

* `int` 至少16位
* `short` 至少16位
* `long` 至少32位
* `long long`最小64位

对于16位的`int`来说，其取值范围在-2^15^ 到 +2^15^，也就是从-32768 ~ +32768。

当然，我们也可以写一个程序来查看每一个整型声明的位数和取值范围：

```cpp
// limits.cpp -- some integer limits

#include <iostream>
#include <cmath>
#include <climits> // use limit.h for older system

int main()
{
    using namespace std;
    int n_int = INT_MAX;      // initialize n_int to the max int value
    short n_short = SHRT_MAX; // symbols defined in climits file
    long n_long = LONG_MAX;
    long long n_llong = LLONG_MAX; 

    // sizeof operator yields size of type or of variable
    cout << "int is " << sizeof (int) << " bytes." << endl;
    cout << "short is " << sizeof n_short << " bytes." << endl;
    cout << "long is " << sizeof n_long << " bytes." << endl;
    cout << "long long is " << sizeof n_llong << " bytes." << endl;
    cout << endl;

    cout << "Maximum values:" << endl;
    cout << "int: " << n_int << " = 2^" << log2(n_int) << endl;
    cout << "short: " << n_short << " = 2^" << log2(n_short) << endl;
    cout << "long: " << n_long << " = 2^" << log2(n_long)<< endl;
    cout << "long long: " << n_llong << " = 2^" << log2(n_llong)<< endl;
    cout << endl;

    cout << "minimum int value = " << INT_MIN << endl;
    cout << "Bits per byte = " << CHAR_BIT << endl;

}
```
out：
```
int is 4 bytes.
short is 2 bytes.
long is 4 bytes.
long long is 8 bytes.

Maximum values:
int: 2147483647 = 2^31
short: 32767 = 2^15
long: 2147483647 = 2^31
long long: 9223372036854775807 = 2^63

minimum int value = -2147483648
Bits per byte = 8
```
结果来自于64位的win10系统。

### 3.1.3 数据的初始化
在C++中，我们可以使用以下方式对于数据进行初始化：
* `int hamburgers = {23}; // set hamburgers to 23`
* `int hamburgers{23}; // set hamburgers to 23`
* `int hamburgers{};   // set hamburgers to 0`

### 3.1.4 无符号类型
之前介绍的4种整型都有无符号数，如`short`可以表示的范围是从-32786到+32768，则无符号的`short`就可以表示从0到+65532。但没有办法再表示负数了。
``` cpp
unsigned short a;
unsigned int b;
unsigned long c;
unsigned long long d;
```
对于前面两类的数据，当他们已经到达最大值的时候，再对其+1会怎样呢？
答案是他们会变成其最小值：
```cpp
short a{32767};
unsigned short b{65535};

cout >> a++ >> endl;
cout >> b++ >> endl;
```
out:
```
a = -32767
b = 0
```

### 3.1.5 整型字面值
在计算机的世界中，将数字表示位二进制，八进制，十六进制都是时常出现的事情，在`cout`中，可以通过如下的例程中的代码，方便的展示八进制和十六进制的数：
```cpp
// hexoct.cpp -- display valuesin hex and octal
#include <iostream>
using namespace std;
int main()
{
    int a = 42;
    
    cout << "a in decimal is: " << a << endl;
    cout << hex; // manipulator for changing number base
    cout << "a in hexadecimal is: " << a << endl;
    cout << oct; // manipulator for changing number base
    cout << "a in octal is: " << a << endl;
    return 0;

}
```
out:
```
a in decimal is: 42
a in hexadecimal is: 2a
a in octal is: 52
```

### 3.1.6 char 类型
例程：
```cpp
// morechar.cpp -- the char type and int type constreasted 
#include <iostream>
int main()
{
    using namespace std;
    char ch = 'M';  //asign ASCII code for M to ch
    int i =ch;  // store the same code in int
    cout << "The AXCII code for " << ch << " is " << i << endl;

    cout << "Add one to the character code" << endl;
    ch = ch + 1;    //change character code in ch
    i = ch;
    cout << "The AXCII code for " << ch << " is " << i << endl;
    
    // using the cout.put() the display the char
    cout << "Display the char in cout.put(): ";
    cout.put(ch);
    cout.put('!');
    cout << endl;
    cout << endl;
    cout.put(i);
    cout << endl << "Done" << endl;
    return 0;
}
```
out:
```
The AXCII code for M is 77
Add one to the character code
The AXCII code for N is 78
Display the char in cout.put(): N!

N
Done
```
### 3.1.7 布尔类型（bool）

bool类型只能表示true或false。比如：
```cpp
bool is_ready = true;
```

`true`和`false`都可以转换为 int 的值，分为是`1`和`0`。
```cpp
int ans = true; // ans will be asigned as 1.
int promise = false; // promisde will be asigned as 0.
```
此外任何的数值或指针都可以被转换为 bool 值，任何非零的值都会被转换为true，而零会被转换成false。
```cpp
bool start = -100; // start is true.
bool stop = 0; //stop is false.
```

## 3.2 const 限定符
`const`限定符可以方便我们再程序中设置一些常量，我们只需要修改一个位置，其他地方的值便会随之改变。与此类似的是C语言中的`#define`，但`const`要优于`#define`，因为`const`可以为常量创建类型。
```cpp
const float pi = 3.14;
const float g = 9.81;
```

用`const`设定之后就可以使用`pi`和`g`来表示对应的数值了。

## 3.3 浮点数
C++中有3种浮点类型：`float`, `double`, `long double`。其中`float`至少32位，`double`至少64位，`long double`可以为80，96，128位。下面我们用一个程序来展示他们之间精度的差异。

```cpp
// floatnum.cpp -- floating-point types

#include <iostream>
using namespace std;
main()
{
    cout.setf(ios_base::fixed, ios_base::floatfield);

    float tub = 10.0 / 3.0;   //可以精确到小数点后六位数
    double mint = 10.0 / 3.0; //可以精确到小数点后15位数
    const float million = 1.0e6;

    cout << "tub = " << tub;
    cout << ", a minllion tub = " << million * tub;
    cout << ", \nand ten million tub = " << 10 * million * tub;
    cout << endl;

    cout << "mint = " << mint << ", and a million mint = ";
    cout << million * mint << endl;

    return 0;
}
```

out:

```
tub = 3.333333, a minllion tub = 3333333.250000,    
and ten million tub = 33333332.000000
mint = 3.333333, and a million mint = 3333333.333333
```

通常cout会删除结尾的零。例如，将3333333.250000显示为3333333.25。调用`cout.setf()`将会覆盖这种行为。但要注意的是，`tub` 和 `mint` 由于`cout`的原因，都被打印为3.333333，但由于`float`和`double`精度的不同，当$tub\times 1e6$ 后变成了333333.250000，而$mint\times 1e6$ 依然是333333.333333。

## 3.4 C++ 算术运算符

### 3.4.1 5个基本的算数运算符
* 加+
* 减- 
* 乘*
* 除/ （会丢弃小数部分）
* 求模% （两个操作数必须是整形，浮点数将会报错，得到两数相除的余数）

### 3.4.2 运算符的优先性
算数运算符遵循先乘除、后加减的规则。例如：
```cpp
int x = 1 + 2 * 3;
```
运算的顺序是 $1+(2*3) = 7$。
此外再据一些例子：
```cpp

int dues = 20 * 5 + 24 * 6;
int logs = 120 / 4 * 5;
```
其结果是：
```
dues = 244
logs = 150
```

### 3.4.3 除法分支

除法运算符(/) 的行为取决操作数的类型。如果两个操作数都是整数，则C++将执行整数除法。这意味着结果的小数部分将被丢弃，使得最后的结果是一个整数。如果其中一个（或两个）操作数是浮点数，则小数部分将被保留，结果为浮点数。以下例程将演示这个方法：

```cpp
// divid.cpp -- integer and floating-point division

#include <iostream>
using namespace std;

int main()
{
    cout.setf(ios_base::fixed, ios_base::floatfield);
    cout << "Integer divsion: 9/5 = " << 9/5 << endl;
    cout << "Floating-point division: 9.0/5.0 = ";
    cout << 9.0/5.0 << endl;
    cout << "Mixed division: 9.0/5 = " << 9.0/5 << endl;
    cout << "double constants: 1e7/9.0 = ";
    cout << 1e7/9.0 << endl;
    cout << "float constants: 1e7f/9.0f = ";
    cout << 1.e7f/9.0f << endl;

    return 0;  
}

```

out:
```
Integer divsion: 9/5 = 1
Floating-point division: 9.0/5.0 = 1.800000
Mixed division: 9.0/5 = 1.800000
double constants: 1e7/9.0 = 1111111.111111
float constants: 1e7f/9.0f = 1111111.125000
```

### 3.4.4 类型转换
由于C++有11种整形和3种浮点类型，因此计算机需要处理大量不同的运算时，会遇到需要转换类型的情况。

#### 3.4.4.1 初始化和赋值进行的转换

例如下面的情况，将一个short类型的数赋值给long类型。
``` cpp
short thirty;
long so_long;

so_long = thirty;   //assigning a short to a long
```
这个时候，C++会自动把thirty（16位）的数拓展为32位，并储存在so_long中。

但是如果将一个很大的long值（如2111222333）赋值给float变量，则精确度将会降低，因为float只有6位有效数据，因此这个值将会被四舍五入为2.1122E9。

#### 3.4.4.2 以{}方式初始化时进行的转换
这种方式的类型转换比较严格，列表初始化不允许缩窄。例如，不允许将浮点类型转换为整型。例如：
```cpp
const int code = 66;
int x = 66;
char c1 {31325};    // narrowing, not allowed
char c2 = {66};     // allowed because char can hold 66
char c3 {code};     // ditto
char c4 = {x};      // not allowed, x is not constant
x = 31325;
cahr c5 = x;        // allowed by this form of initialization
```

上述代码中，对于c4来说，x是一个变量，因此编译器无法初始化c4的值。

#### 3.4.4.3 表达式中的转换
当不同类型进行算数运算的时候，会进行一些转换，编译器会一次查阅下面的列表：
1. 如果有一个操作数的类型是long double，则将另外一个操作上转换为long double。
1. 如果有一个操作数的类型是double，则将另外一个操作数的类型转换为double。
1. 如果有一个操作数的类型是float，则将另外一个操作数转换为float。
1. 如果操作数都是整型，因此执行整型提升。
1. 在这种情况下，如果两个操作数都是有符号货无符号的，且其中一个操作数的级别比另一个低，则转换为级别高的类型。
1. 如果一个操作数有符号，另一个没有符号，且无符号的操作数的级别比有符号的操作数高，则将有符号的操作数转换为无符号操作数所属的类型。
1. 否则，如果有符号操作数课表示为无符号类型的所有可能取值，则将无符号操作数转换为有符号操作数的所属类型。
1. 否则，将两个操作数都转换为有符号类型的无符号版本。

上面的规则提到了级别，简单来说，有符号整型的级别按从高到底一次为：
long long > long > int > short > signed char。 无符号整型的排列顺序与有符号整型的顺序相同。类型： char, signed char 和 unsigned char 的级别相同。类型bool的级别最低。

#### 3.4.4.4 强制类型转换
下面的例程展示了强制转换类型的使用：
```cpp
// typecast.cpp -- forcing type changes
#include <iostream>
int main()
{
    using namespace std;
    int auks, bats, coots;

    // the following statement adds the values as double,
    // then converts the result to int
    auks = 19.99 + 11.99;

    // these statements add values as int
    bats = (int)19.99 + (int)11.99;
    coots = int(19.99) + int(11.99);

    cout << "auks = " << auks << ", bats " << bats;
    cout << ", coots = " << coots << endl;

    char ch = 'Z';
    cout << "The code for " << ch << " is "; //print as char
    cout << int(ch) << endl;                // print as int
    cout << "Yes, the code is ";
    cout << static_cast<int>(ch) << endl; // using static_cast
    return 0;
}
```

out:
```
auks = 31, bats 30, coots = 30
The code for Z is 90
Yes, the code is 90
```

#### 3.4.4.5 C++ 11 中的auto声明
在初始化声明中如果使用了auto，而不指定变量的类型，编译器将把变量的类型设置成与初始值形同：
```cpp
auto n = 100;       // n is int
auto x = 1.5;       // x is double
auto y = 1.3e12L    //y is long double
```

# 第四章：复合类型
## 4.1 数组
数组可以储存多种同类型的值，要创建数组，可以使用声明语句，语句应指明以下3点：
* 存储再每个元素中的值的类型；
* 数组名；
* 数组中的元素数。

数组的通用格式是：
```cpp
TypeName ArrayName [ArraySize];
```
例如：
```cpp
short months [12];   // create a array of 12 short
```

数组之所以被称为复合类型是因为它是由其他类型来创建的。数组中的每个元素可以单独调用，其计数方式是从`0`到`n-1`。

下面的例程展示了数组的使用方法和属性：
```cpp
// arrayone.cpp -- samll array of integers
#include <iostream>

int main(int argc, char const *argv[])
{
    using namespace std;

    int yams [3];
    yams [0] = 7;
    yams [1] = 8;
    yams [2] = 6;

    int yamscost [3] =  {20, 30, 5};

    cout << "Total yams = " << yams [0] + yams[2] + yams[1];
    cout << endl;
    cout << "The package with " << yams [1] << " yams costs ";
    cout << yamscost[1] << " cent per yam. \n";
    int total = yams [0] * yamscost[0] + yams[1] * yamscost [1] + yams [2] * yamscost[2];
    cout << "The total yam expense is " << total << " cents.\n";

    cout << "\nSize of yams array = " << sizeof yams;
    cout << "bytes. \n";
    cout << "Size of one element = " << sizeof yams[0];
    cout << "bytes. \n";
    return 0;
}
```

out:
```
Total yams = 21
The package with 8 yams costs 30 cent per yam.
The total yam expense is 410 cents.

Size of yams array = 12 bytes.
Size of one element = 4 bytes.
```

### 4.1.1 数组初始化的规则
* 只有定义数组的时候才可以对数组进行初始化，此后就不能再用了，且不能把数据赋值给另外一个数组。
```cpp
int cards [4] {1, 2, 3, 4}; //allowed
int hands [4];              //allowed
hands = {5, 6, 7 ,8};       //not allowed   
hands = cards;              //not allowed
```
* 初始化的时候赋值的个数可以小于数组元素的数目，比如：
```cpp
float num[5] = {1, 2};
```
此时，只有数组中前两个数被赋值了，其他的数被置零。

* 零数组，将数组中的所有元素置零。
```cpp
float zeros [6] = {0};
```

* 如果初始化时，方括号[]内为空，则C++编译器会计算元素的个数，如：
```cpp
short things[] = {1, 5, 3, 8};
```
则编译器会将`things`中包含4个元素。

## 4.2 字符串
这里推荐使用以下的方式定义字符串变量：
```cpp
char name[] = "Alex";
```

### 4.2.1 字符串与数组
下面的例程将演示数组和字符串的结合使用方法：
```cpp
// strings.cpp -- store string in an array
#include <iostream>
#include <cstring>

int main(int argc, char *argv[])
{
    using namespace std;
    const int Size = 15;
    char name1[Size];   // empty array  
    char name2[Size] = "C++ Oldboy";// initialized array

    cout << "Howdy! I'm " << name2;
    cout << "What's your name? \n";
    cin >> name1;
    cout << "Well, " << name1 << " your name has ";
    cout << strlen(name1) << " letters and is stored\n";
    cout << "in an array of " << sizeof(name1) << " bytes. \n";
    name2[3] = '\0';    // set to null character
    cout << "Your initial letter is " << name1[0] << endl;
    cout << "Here are the first three letter of my name: ";
    cout << name2 << endl;

    return 0;
}
```

out:
```
Howdy! I'm C++ OldboyWhat's your name? 
Dao
Well, Dao your name has 3 letters and is stored
in an array of 15 bytes.
Your initial letter is D
Here are the first three letter of my name: C++
```

从程序的输出我们可以看出来，`strlen()`返回的是可见的字符串的长度，不包含`\0`。在程序中，我们将`name2[3]`设置为了`\0`因此虽然后面还有内容，但是不再显示。

### 4.2.2 字符串输入
使用`cin`作为字符串的输入的时候存在一些问题，下面的例程将反应出这个问题：

```cpp
// cinproblem.cpp -- reading more than one thing

#include <iostream>

int main(int argc, char *argv[])
{
    using namespace std;
    const int ArSize = 20;
    char name[ArSize];
    char city[ArSize];

    cout << "What's your name? \n";
    cin >> name;
    cout << "Which city do you live in? \n";
    cin >> city;

    cout << "Okey, now I know you're " << name << " and you live in ";
    cout << city << endl;
    
    return 0;
}
```

out:

```
What's your name? 
TIM D
Which city do you live in? 
Okey, now I know you're TIM and you live in D
```

在上面的例程中，我输入了我的名字： `TIM D` 还没来得及输入我所居住的城市，程序就已经结束了。并且程序将我的名字记为了`TIM`，将我的城市记为了`D`。这是因为`cin()`使用空白（空格、制表符、换行符）作为确定字符串结束的位置，并自动在结尾添加空字符。

为了解决这个问题，`istream`中的类（如`cin`）提供了一些面向行的类成员函数：`getline()`, `get()`。这两个函数都是读取一行的输入，知道换行符。他们之间的区别是，`getline()`会丢弃换行符，而`get()`不会。

为了熟悉这两个函数的使用方法，下面给出了一个例程：
```cpp
// instr.cpp -- read more than one word in getlin()

#include <iostream>
int main(int argc, char *argv[])
{
    using namespace std;
    const int ArSize = 20;
    char name[ArSize];
    char city[ArSize];

    cout << "What's your name? \n";
    cin.getline(name,ArSize);
    cout << "Which city do you live in? \n";
    cin.getline(city,ArSize);


    cout << "Okey, now I know you're " << name << " and you live in ";
    cout << city << endl;

    return 0;
}
```

out:
```
What's your name? 
TIM D
Which city do you live in? 
Suzhou
Okey, now I know you're TIM D and you live in Suzhou
```

`getline()`一次可以读取一行的输入信息，以换行符确定行尾，并将换行符变成空字符。

另外一种`get()`与`getline()`的不同点就在于`get()`并不是以换行符结尾，而是会读取换行符。要实现`getlin()`的效果，我们可以使用`cin.get(name, size).get()`下面的例程将会展示`get()`的用法：

```cpp
// instr.cpp -- read more than one word with get() & get()

#include <iostream>
int main(int argc, char *argv[])
{
    using namespace std;
    const int ArSize = 20;
    char name[ArSize];
    char city[ArSize];

    cout << "What's your name? \n";
    cin.get(name,ArSize).get();
    cout << "Which city do you live in? \n";
    cin.get(city,ArSize).get();


    cout << "Okey, now I know you're " << name << " and you live in ";
    cout << city << endl;

    return 0;
}
```

out:
```
What's your name? 
Which city do you live in? 
Suzhou
Okey, now I know you're TIM D and you live in Suzhou
```

但如果我们只使用`cin.get()`则会出现以下现象：
```
What's your name?
TIM D
Which city do you live in?
Okey, now I know you're TIM D and you live in
```
在我第一次输入后，便不再询问再次输入。书籍《C++ Primer Plus》推荐的输入方式是`cin.get()`，具体原因会在后面的章节中讲到。

## 4.3 String类介绍

在`string`头文件中的`string`类是和字符串类型功能类似的存在。其好处是我们可以像处理变量一样，去处理strig。下面的例程演示了`string`的用法。

```cpp
// strtype1.cpp -- using the C++ string class
#include <iostream>
#include <cstring>

int main(int argc, char *argv[])
{
    using namespace std;

    char animal1[20];
    char animal2[20] = "jaguar";
    string str1;
    string str2 = "panther";

    cout << "Enter a kind of feline." << endl;;
    cin.get(animal1,20).get();
    cout << "Enter another feline." << endl;
    cin >> str1;
    cout << "Here are some felines: " <<
    animal1 << " " << animal2 << " " <<
    str1 << " " << str2 << endl;
    cout << "The third letter in " << animal2 <<
    " is " << animal2[2] << endl;
    cout << "The third letter in " << str2 <<
    " is " << str2[2] << endl;

    return 0;
}
```

out:

```
Enter a kind of feline.
Tiger
Enter another feline.
Ocelot 
Here are some felines: Tiger jaguar Ocelot panther
The third letter in jaguar is g
The third letter in panther is n
```

`string`类相比使用`char`会有很多方便之处：
* 无需声明长度，在使用`cin >> str1;`的时候，程序会自动调整`str1`的长度。
* `string`可以进行赋值，`string`类的操作会比数组更加方便，一个数组不能赋值给另一个数组，但`string`可以。

```cpp
string animal1 = "tiger";
char charr1[20] = "tiger";
string animal2;
char charr2[20];
animal2 = animal1;  //VALID
charr2 = charr1;    //INVALID
```

* `string`类简化了字符串的合并操作。可以使用运算符`+`将两个`string`对象合并起来，还可以用`+=`将一个字符串添加到另一个`string`对象的结尾。
```cpp
string str1 = "I LOVE";
string str2 = "U";
string str3;
str3 = str1 + str2;
str1 += str2;
```
则：
```
str3 = I LOVE U
str1 = I LOVE U
```
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

在`main()`中，返回值（地址）被赋给了指针`name`。该指针是在`main()`中定义的，但它指向`getname()`函数中分配的内存块。内存被释放后再次调用`getname()`，从结果看，这次使用的内存地址依然是上一次选择的地址。


## 4.8 类型组合
不多说了直接上例程：
```cpp
// mistypes.cpp -- some type combinations
#include <iostream>

struct antarctic_years_end
{
    int year;
    // some really interesting data, etc.
};

int main(int argc, char *argv[])
{
    antarctic_years_end s01, s02, s03;
    s01.year = 1998;
    antarctic_years_end *pa = &s02; //指向结构的指针
    pa->year = 1999;
    antarctic_years_end trio[3]; // array of 3 structures
    trio[0].year = 2003;
    std::cout << trio->year << std::endl;
    const antarctic_years_end *arp[3] = {&s01, &s02, &s03};
    std::cout << arp[1]->year << std::endl;
    const antarctic_years_end **ppb = arp;
    auto ppb = arp; //C++ 11 automatic tyoe deduction
    std::cout << (*ppb)->year << std::endl;
    std::cout << (*(ppb + 1))->year << std::endl;
    return 0;
}
```
out:
```
2003
1999
1998
1999
```
### 4.8.1 程序分析
首先，我们创建了一个结构：
```cpp
struct antarctic_years_end
{
    int year;
};
然后创建这种结构的变量：
```cpp
antarctic_years_end s01, s02, s03;
```
再通过成员运算符访问变量：
```cpp
s01.year = 1998;
```
也可以创建指针指向这种结构的指针：
```cpp
antarctic_years_end * pa = &s02;
```
该指针设置为有效地址后就可以使用简介成员运算符来访问成员：
```cpp
pa ->year = 1999;
```
创建一个结构数组：
```cpp
antarctic_years_end trio[3];
```
然后使用成员运算符访问元素成员：
```cpp
trio[0].year = 2003;
```
其中`trio`是一个数组，而`trio[0]`是一个结构，`trio[0].year`是该结构的一个成员。由于数组名也是一个指针，因此我们也可以使用间接成员运算符：
```cpp
(trio+1) ->year = 2004;
```
创建一个指针数组：
```cpp
const antarctic_years_end * arp[3] = {&s01, &s02, &s03};
```
`arp`是一个指针数组，那么`arq[1]`就是一个指针，可以将间接成员运算符应用于它：
```cpp
std::cout << arp[1]->year << std:endl;
```
我们也可以创建指向上述数组的指针：
```cpp
const antarctic_years_end ** ppa = arp;
```
其中`arp`是一个数组名称，因此它是第一个元素的地址。但第一个元素为指针，因此`ppa`是一个指针，指向`const antarctic_years_end`的指针。当然`ppa`的命名比较复杂。我们可以直接使用`auto`来创建它：
```cpp
auto ppb = arp;
```
因为`auto`知道`arp`的类型，因此可以推出`ppb`的类型。`ppa`与`ppb`等价。
由于`ppa`是一个指向结构指针的指针，因此`*ppa`是一个结构指针，可以使用间接成员运算符应用于它：
```cpp
std::cout << (*ppa)->year << std::endl;
```

## 4.9 数组的替代品

### 4.9.1 模板类 vector
基本上来说，`vector`是使用`new`创建动态数组的替代品。它可以自动完成`new`和`delete`的内存管理工作。

要使用`vector`对象，必须包含头文件`vector`，其名称空间是`std`。下面是一些例子：

```cpp
#include <vector>
...
using namespace std;
vector<int> vi; // create a zero-size array of int
int n;
cin >> n;
vector<double> vd(n);   // create an array of n doubles
```

其通用使用方法是：
```cpp
vector<typeName> vt(n_elem)
```
### 4.9.2 模板类 array
`vector`类的功能比数组强大，但是效率低。因此有些时候我们也可以使用`array`来代替数组：
```cpp
#include <array>
...
using namespace std;
array<int, 5> ai;
array<double, 4> ad = {1.2, 2.1, 3.42, 4.3};
```

其通用使用方法是：
```cpp
array<typeName, n_elem> arr
```
于`vector`不同的是，创建的`n_elem`不能是变量。

### 4.9.3 比较数组、vector 对象和array 对象
直接看例程：
```cpp
// choices.cpp -- array variations
#include <iostream>
#include <vector>
#include <array>
int main(int argc, char const *argv[])
{
    using namespace std;
    double a1[4] = {1.2, 2.4, 3.6, 4.8};
    vector<double> a2(4);
    a2[0] = 1.0/3.0;
    a2[1] = 1.0/5.0;
    a2[2] = 1.0/7.0;
    a2[3] = 1.0/9.0;
    array<double, 4> a3 = {3.14, 2.72, 1.62, 1.41};
    array<double, 4> a4;
    a4 = a3;    // valid for array objects of same size

    cout << "a1[2] : " << a1[2] << " at " << &a1[2] << endl;
    cout << "a2[2] : " << a2[2] << " at " << &a2[2] << endl;
    cout << "a3[2] : " << a3[2] << " at " << &a3[2] << endl;
    cout << "a4[2] : " << a4[2] << " at " << &a4[2] << endl;

    //misdeed
    a1[-2] = 20.2;
    cout << "a1[-2] : " << a1[-2] << " at " << &a1[-2] << endl;
    
    return 0;
}
```
out:
```
a1[2] : 3.6 at 0x61fdf0
a2[2] : 0.142857 at 0x1e1690
a3[2] : 1.62 at 0x61fdb0
a4[2] : 1.62 at 0x61fd90
a1[-2] : 20.2 at 0x61fdd0
```

**程序说明**
无论是数组，`vector`还是`array`对象，都可以使用标准的数组表示法来访问各个元素。其次，从地址可知，`array`对象和数组存储再同样的存储区域（即栈）中，而`vector`在另外一个区域（自由存储区或堆）中。第三，注意到可以将一个`array`赋值给另一个`array`对象。而数组必须逐元素复制数据。

接下来有一行代码值得我们注意：
```cpp
a1[-2] = 20.2;
```
由指针的知识我们知道，上面的代码可以转换成如下代码：
```cpp
* (a1 -2) = 20.2;
```
其含义是找到`a1`指向的地方，向前移两个`double`元素，并将20.2储存到目的地。但这样使用方法其实并不是一个合适的行为，如果我们像禁止这样的非法索引，可以使用`at()`:
```cpp
a2.at(1) = 2.3;
```
## 4.10 练习题
### 4.10.1 练习题1
```
What's your first name? Betty
What's your last name? Sue
What letter grade do you deserve? B
What's your age? 22
Name: Betty Sue
Grade: B
Age: 22
```
程序：
```cpp
#include <iostream>

struct StudentInfo
{
    char FirstName [20];
    char LastName [20];
    char grade [20];
    int age;
} Student1;

int main(int argc, char const *argv[])
{
    using namespace std;
    cout << "What's your first name? ";
    cin.getline(Student1.FirstName, 20);
    cout << "What's your last name? ";
    cin.getline(Student1.LastName, 20);
    cout << "What letter grade do you deserve? ";
    cin.getline(Student1.grade,20);
    cout << "What's your age? ";
    cin >> Student1.age;
    cout << "Name: " << Student1.FirstName << " " << Student1.LastName << endl;
    cout << "Grade: " << Student1.grade << endl;
    cout << "Age: " << Student1.age << endl;

    return 0;
}
```
在上面的程序中，使用`struct`是为了方便输入更多学生的信息，比如将变量`Student1`变成一个数组`Student[20]`，即可以完成对20个学生的信息采集。写完上面程序后，我又对这个程序进行一点修改，使得一次就可以输入一个人全名，并分别记为`FirstName`和`LastName`：
```cpp
#include <iostream>

struct StudentInfo
{
    char FirstName [20];
    char LastName [20];
    char grade [20];
    int age;
} Student1;

int main(int argc, char const *argv[])
{
    using namespace std;
    cout << "What's your full name? ";
    cin >> Student1.FirstName >> Student1.LastName;cin.get();
    cout << "What letter grade do you deserve? ";
    cin.getline(Student1.grade,20);
    cout << "What's your age? ";
    cin >> Student1.age;
    cout << "Name: " << Student1.FirstName << " " << Student1.LastName << endl;
    cout << "Grade: " << Student1.grade << endl;
    cout << "Age: " << Student1.age << endl;

    return 0;
}
```
### 4.10.2 练习题2
William Wingate 从事披萨饼分析服务。对于每个披萨饼，都需要记录下列信息：
* 披萨饼公司的名字，可以有多个字母组成。
* 披萨的直径。
* 披萨的重量。
设计一个能够储存这些信息的结构，要求使用`new`来为结构分配内存。程序将请求用户输入上述信息。
程序：
```cpp
#include <iostream>

struct Pizza
{
    char Company[20];
    float Diameter;
    float Weight;
};

int main(int argc, char const *argv[])
{
    Pizza *p = new Pizza;

    std::cout << "Enter the company name.\n";
    std::cin.getline(p->Company, 20);
    std::cout << "Enter the Pizza's diameter in inch.\n";
    std::cin >> p->Diameter;
    std::cout << "Enter the Pizza's weight in kg.\n";
    std::cin >> p->Weight;

    std::cout << "Company: " << p->Company << std::endl;
    std::cout << "Diameter: " << p->Diameter << std::endl;
    std::cout << "weight: : " << p->Weight << std::endl;
    
    delete p;
    return 0;
}
```
out:
```
Enter the company name.
Fire Hourse
Enter the Pizza's diameter in inch.
14
Enter the Pizza's weight in kg.
2.3
Company: Fire Hourse
Diameter: 14
weight: : 2.3
```

### 4.10.3 练习题3
写一个程序，让用户输入一位运动员3次跳远的成绩，并显示次数和平均成绩，然后输出最大和最小值。使用array来存储对象。
```cpp
#include <iostream>
#include <array>
#include <cmath>

using namespace std;
int main(int argc, char const *argv[])
{
    array<double, 3> results;
    double sum{0};
    double max{0};
    double min{0};

    for (int i = 0; i <= 2; i++)
    {
        cout << "Please enter the jump result for the " << i + 1 << " time is:  ";
        cin >> results[i];
        sum = sum + results[i];
    }

    cout << "The results are:" << endl;
    max = results[0];
    min = results[0];
    for (int n = 0; n <= 2; n++)
    {
        cout << "The result for the " << n + 1 << "time is:" << endl;
        cout << results[n];
        if (max <= results[n])
        {
            max = results[n];
        }
        if (min >= results[n])
        {
            min = results[n];
        }
    }
    cout << "The average result for the athlete is: " << sum / 3 << endl;
    cout << "The best result is: " << max << endl;
    cout << "The worst result is: " << min << endl;

    return 0;
}
```
out:
```
The results are:
The result for the 1time is:
2.66The result for the 2time is:
2.67The result for the 3time is:
2.69The average result for the athlete is: 2.67333
The best result is: 2.69
The worst result is: 2.66
```

# 第七章 函数 -- C++的编程模块

## 7.1 复习函数的基础知识
创建自己的函数的时候，需要提供3个方面的内容 -- 定义、函数原型和调用。下面的例子展示了这3个步骤
```cpp
// calling.cpp -- defining,prototyping and calling a fucntion

#include <iostream>

void simple();  //function prototype

int main(int argc, char *argv[])
{
    using namespace std;
    cout << "main() will call the simple() function: \n";
    simple();   //function call
    cout << "main() is finished with the simple() function. \n";
    // cin.get();
    return 0;
}

void simple()
{
    using namespace std;
    cout << "I'm but a simple function.\n";
}
```

out:
```
main() will call the simple() function: 
I'm but a simple function.
main() is finished with the simple() function.
```
这就是一个简单的示例，不再过多解释。

### 7.1.1 定义函数

函数可以分成两类，一种是没有返回值的函数，另一种是有返回值的函数。没有返回值的函数被称为`void`函数，其通式如下：
```cpp
void functionName(parameterList)
{
    statement(s);
    return;     // optional
}
```

其中，`parameterList`指定了传递给函数的参数类型和数量。下面有一个例子说明：
```cpp
void cheers(int n)
{
    for (int i =0; i < n; i++)
    {
        std::cout << "cheers" << std::endl;

    }
}
```
上面的例子就展示了输入参数`n`来表达打印次数。而`int`为`n`的数据类型。

有返回值的函数将生成一个值，并将它返回给调用函数。换句话来说，如果函数返回9.0的平方根`sqrt(9.0)`，则该函数调用的值为`3.0`。这样有返回值的函数，其通用格式如下：
```cpp
typeName FunctinoName(parameterList)
{
    statements
    return value;   // value is type cast to type typeName
}
```

对于有返回值的函数，必须有返回语句，以便将值返回给调用它的函数。值本身可以是常量、变量，也可以是表达式，只是其结果的类型必须是`typeName`类型或可以转变为`typeName`。C++对于返回值有一定的限制：不能是数组，但可以是其他任何类型 -- 整数、浮点数、指针，甚至可以是结构和对象！（有趣的是，虽然C++函数不能直接返回数组，但可以将数组作为结构或对象组成部分来返回。）

如果函数中包含多条返回语句（例如，他们位于不同的`if else`中），则函数在执行遇到第一条返回语句后结束。例如，在下面的例子中，else并不是必须的。
```cpp
int bigger(int a, int b)
{
    if (a>b)
        return a;
    else
        return b;
}
```

### 7.1.2 函数原型和调用
首先举一个例子，展示函数原型：
```cpp
// protos.cpp -- using trototypes and function calls
#include <iostream>

using namespace std;

void cheers(int);   // prototype: no return value
double cube(double x); //prototype: returns a double

int main(int argc, char *argv[])
{
    cheers(5);
    cout << "Give me a number: ";
    double side;
    cin >> side;
    double volume = cube(side); //function call
    cout << "A " << side << "3-foot cube has a volume of ";
    cout << volume << "cubic foot.\n";
    cheers(cube(2));    // prototype protection at work
    return 0;
}

void cheers(int n)
{
    for (int i = 0; i < n; i++)
        cout << "Cheers!";
    cout << endl;
}

double cube (double x)
{
    return x*x*x;
}
```
out:
```
Cheers!Cheers!Cheers!Cheers!Cheers!
Give me a number: 3
A 3-foot cube has a volume of 27cubic foot.
Cheers!Cheers!Cheers!Cheers!Cheers!Cheers!Cheers!Cheers!
```

有了这个例子，大家应该懂了如何写一个函数的原型了。但，
<font color = orange>1. 为什么需要原型呢</font>？

原型描述了函数到编译器的接口。在使用`double volume = cube (side)`时，原型告诉编译器，`cube()`有一个`double`参数。如果程序没有提供这样的参数，原型将让编译器能够捕获这种错误。为了编译的效率，我们在写原型的时候，把返回值的类型也告诉编译器。

<font color = orange>2. 原型的语法</font>：
函数原型也是一条语句，因此必须以分号结束。获得原型最简单的方法是，复制函数定义中的函数头，并添加分号。比如：

```cpp
double cude (double x);

double cude (double x)  // 这是函数头
{
    ...
}
```

然而，函数原型不要求提供变量名称，有类型别表就足够了。对于`cheer()`的原型，该程序只提供了类型：

```cpp
void cheers (int);
```

<font color = orange>3. 原型的功能</font>：
原型可以确保以下几点：

* 编译器正确处理函数返回值；
* 编译器检查使用的参数数目是否正确；
* 编译器检查使用的参数类型是否正确。如果不正确，则转换为正确的类型。

## 7.2 函数参数和按值传递
C++通常按值传递参数，这意味着将数值参数传递给函数，而后者将其赋给一个新的变量。例如：
```cpp
double volume = cude(side);
```
其中，`side`是一个变量，在前面的程序中，其值为5.`cube()`的函数头如下：
```cpp
double cube (double x)
```
被调用时，该函数将创建一个新的名为 `x` 的`double`变量，并将其初始化为`5`，这样，`cube()`执行的操作将不会影响到`main()`中的数据，因为`cube()`使用的时`side`的副本，而不是原来的数据。稍后将介绍一个实现这种保护的列子。由于接受传递值的变量被称为形参。传递给函数的值称为实参。出于简化的目的，C++使用参数(argument)来表示实参，使用参量(parameter)来表示形参，因此参数传递将参量赋值给参数。

在函数中声明的变量（包括参数）是该函数私有的。在函数被调用时，计算机将为这些变量分配内存；在函数结束的时候，计算机又将释放这些内存。这样的变量又被称为局部变量，因为它们被限制在函数中。这还意味着，如果在`main()`中声明一个`x`变量，同时在另一个函数中也声明了一个名为`x`的变量，则它们将是两个完全不同的，毫无关系的变量。

### 7.2.1 多个参数
函数可以有多个参数。在调用函数的时候，只需要使用逗号将这些参数隔开：
```cpp
n_chars('Z',25);
```
上面的函数调用将两个参数传递给`n_chars()`，那么定义的时候也需要声明两个变量：
```cpp
void n_chars(char c, int n)     // two arguments
```
声明参数的时候，即使两个参数的类型相同，也必须分别指定两个参数的类型，而不能像声明变量那样，将声明组合在一起。
```cpp
void fifi(float a, float b) //declear each variable separately
void fufu(float a,b)    // NOT ALLOW
```
对于函数的原型也是一样的。
```cpp
void fifi(float a, float b); //declear each variable separately
void fufu(float a,b);    // NOT ALLOW
```

下面的程序演示了有2个参数的函数：
```cpp
// twoarg.cpp -- a function with 2 argumnets

#include <iostream>
using namespace std;

void n_chars(char, int);
int main(int argc, char const *argv[])
{
    int times;
    char ch;

    cout << "Enter a character: ";
    cin >> ch;

    while (ch != 'q') // q to quit
    {
        cout << "Enter an inter: ";
        cin >> times;
        n_chars(ch, times); // function with 2 arguments
        cout << "\nEnter another character or press the "
        << "q-key to quit.\n";
        cin >> ch;
    }
    cout << "The value of times is " << times << endl;
    return 0;
}

void n_chars(char ch, int n)
{
    while (n-- >0)
    {
        cout << ch;
    }
}
```

out:
```
Enter a character: k
Enter an inter: 8
kkkkkkkk
Enter another character or press the q-key to quit.
q
The value of times is 8
```

### 7.2.2 一个例题
**题目**：《彩票游戏》
让参与者从51个数字中选取6个。随后，彩票管理者随机抽取6个数。如果参与者选择的数字与这6个数字完全相同，将赢得百万大奖。那么我们将用函数来计算赢得彩票的概率。

<font color = #1E90FF>分析：</font>
首先我们列一个公式，设获奖概率为P，则P的计算公式为：
$$ P = \frac{6}{51}\times\frac{5}{50}\times\frac{4}{49}\times\frac{3}{48}\times\frac{2}{47}\times\frac{1}{46}$$

<font color = #1E90FF>例程：</font>

```cpp
// lotto.cpp -- probability of winning

#include <iostream>

double probability(uint16_t numbers, uint16_t picks);

int main(int argc, char const *argv[])
{
    using namespace std;
    double total, choices;
    cout << "Enter the total number of choices of the game"
         << " card and the number of picks allowed:\n";
    while ((cin >> total >> choices) && choices <= total)
    {
        cout << "You have one chance in ";
        cout << probability(total, choices); // compute the odds
        cout << " of winning. \n";
        cout << "Next two numbers (q to quit): ";
    }
    cout << endl;
    return 0;
}

double probability(uint16_t numbers, uint16_t picks)
{
    double result = 1.0; // here come some local variables
    double n;
    uint16_t p;

    for (n = numbers, p = picks; p > 0; n--, p--)
        result = result * n / p;
    return result;
}
```

out:
```
Enter the total number of choices of the game card and
the number of picks allowed:
51 6
You have one chance in 1.80095e+07 of winning.
Next two numbers (q to quit): q
```

<font color = #1E90FF>程序说明：</font>

程序使用`numbers`作为牌的总数，`picks`作为需要参与者选取的个数。每一次选择的概率都是$P = \frac{picks}{numbers} $，而每选取一次牌库以及需要选取的个数都会`-1`。因此只需让概率相乘，直到`picks`变成零，即为我们要求的概率。

## 7.3 函数与数组
在函数的使用过程中需要经常用到数组。这里我们可以将数组名作为参数使用。例如下面的声明中，将一个形参声明为数组名。

```cpp
int sum_arr(int arr[ ], int n)  // arr = array name, n = size
```

从声明看，我们的函数中有一个`arr`数组，其后面的方括号为空表示可以将任何长度的数组传递给函数。但其实，`arr`并不是一个数组，而是一个指针！好消息是在编写函数的时候可以将`arr`看作为一个数组。

下面将展示一道例题，包括数组的函数中含数组参数的使用。

<font color = #1E90FF>题目：</font>
用一个数组记录野餐中每个人吃甜饼的数量。每个数组引索都对应一个人，元素值对应于这个人所持的甜饼的数量。要求甜饼的总数。

```cpp
// arrfun1.cpp -- functions with an array argument

#include <iostream>

const int ArSize = 8;
int sum_arr(int arr[], int n);      //prototype
int main(int argc, char const *argv[])
{
    using namespace std;
    int cookies[ArSize];
    cout << "Please enter 8 numbers" << endl;
    for (int i = 0; i < 8; i++)
        cin >> cookies[i];

    int sum = sum_arr(cookies, ArSize);
    cout << "Total cookies eaten: " << sum << endl;
    return 0;
}

// return the sum of an integer array
int sum_arr(int arr[], int n)
{
    int total = 0;
    for (int i = 0; i <n; i++)
        total = total + arr[i];
    
    return total;
}
```

out:

```
Please enter 8 numbers
1 3 5 8 4 8 4 8
Total cookies eaten: 41
```

### 7.3.1 函数如何使用指针来处理数组
一般情况下，C++将数组名视为指针。`cookies == &cookies[0]`。但该规则有一些例外的情况。首先数组声明使用数组名来标记存储位置；其次，对数组名使用`sizeof`将得到整个数组的长度（以字节为长度）；第三，将地址运算符&用于数组名时，将返回整个数组的地址，例如`&cookies`将返回一个32字节内存块的地址（如果int长度为4字节）。

如果是这样的话，我们在声明函数的时候使用指针的形式来声明，即`int * `。这表明，函数头还是这样的:
```cpp
int sum_arr(int * arr, int n) // arr = array name, n = size
```

那么借用指针的思想，上面的例程中的部分语句还可以写作：
```cpp
arr[i] = *(ar + 1);     // values in two notations
&arr[i] = ar + 1;       // addrress in two notations
```

### 7.3.2 更多数组函数示例

<font color = #1E90FF>示例1：</font>
假设使用一个数组来记录房地产的价值，房地产的数目不超过5个。在考虑对房地产数组进行操作的时候，有2个基本的要点，首先我们要将值读入数组中，另外我们还要重新评估每种房地产的价值，假设每种房地产都以相同的比例增加或减少。

那么我们的代码就可以写作：
```cpp
//arrayfun2.cpp -- array functions and const
#include <iostream>
const int Max = 5;
// function prototypes
int fill_array(double * ar, int limit);
void show_array(const double * ar, int n);
void revalue(double r, double * ar, int n);

int main(int argc, char const *argv[])
{
    using namespace std;
    double properties[Max];

    int size = fill_array(properties, Max);
    show_array(properties, size);
    if (size > 0 )
    {
        cout << "Enter revaluation factor: ";
        double factor;
        while (!(cin >> factor))    //bad input
        {
            cin.clear();
            while (cin.get() != '\n')
                continue;
            cout << "Bad input; please enter a number: ";
        }
        revalue(factor, properties, size);
        show_array(properties, size);
    }
    cout << "Done. \n";
    cin.get();
    cin.get();
    return 0;
}

int fill_array(double * ar, int limit)  
{
    using namespace std;    
    double temp;
    int i;
    for ( i = 0; i < limit; i++)    // 逐个读取数组中的元素
    {
        cout << "Enter value #" << (i + 1) << ": ";
        cin >> temp;
        if (!cin)   // 如果有错误输入（非double类型的值）
        {
            cin.clear();    // 清空输入
            while (cin.get() != '\n')
                continue;   // 执行下一行代码
            cout << "Bad input; input process terminated.\n";
            break;
        }
        else if (temp < 0)  // 负数为中断信号
            break;
        ar [i] = temp;
    }
    return i;
}

 void show_array(const double * ar, int n)
 {
     using namespace std;
     for (int i = 0; i < n; i++)
     {
         cout << "Property #" << (i+1) << ": $";
         cout << ar[i] << endl;
     }
 }

// multiplies each element of ar[] by r
void revalue (double r, double * ar, int n)
{
    for (int i = 0; i < n; i++)
        ar[i] *= r;
}
```

out:
```
Enter value #1: 1000
Enter value #2: 3200
Enter value #3: 1200
Enter value #4: -1
Property #1: $1000
Property #2: $3200
Property #3: $1200
Enter revaluation factor: 0.3
Property #1: $300
Property #3: $360
Done.
```

<font color = #1E90FF>程序说明：</font>

1. 填充数组
```cpp
int fill_array(double * ar, int limit)
```
上面的函数是我们的填充数组函数，它有两个参数，一个是我们的数组名，另一个是数组的最大长度。这里我们人为的设置数组的最大长度为5。函数的作用是连续的将值读入数组中，当然考虑到可能有些没有5个房产，因此我们也要设置一个可以提前结束循环的按键。这里考虑到房产价值不会为负，因此将负数作为输入结束的指令。另外，该函数还应该为错误输入做出反应，如停止输入等。

2. 显示数组以及用`const`保护数组
```cpp
void show_array(const double * ar, int n );
```
为了确保函数不会修改原始数组，我们需要在声明中使用`const`字符来保护数组。在上方函数的声明中，指针`ar`指向的是常量数据。这意味着不能使用`ar`修改数据。也以为着只能查看而不能修改。因此，如果在`show_array`函数中使用了`ar[0] +=10;`操作，编译器则会报错。

3. 修改数组
```cpp
void revalue (double r, double * ar, int n);
```
在这个函数中，一共有3个参数，分别为重新评估因子，数组指针，元素数目。由于我们需要修改数组中元素的值，因此我们不能使用`const`。

在这个过程中，我们使用的是自下而上的一种思想，即先思考数据类型和设计恰当的函数来处理数据，然后将这些函数合成以给程序。与之对应的自上而下的思想则是先指定模块化设计方案，然后再研究细节。

### 7.3.4 使用数组区间的函数 
用C++函数处理数组的传统方式是将数组中的数据种类，数组的起始位置和数组中元素的数量提交给它。还有另外一种给函数提供所需信息的方法是元素区间法。这可以通过两个指针来完成。一个指针表示数组的开头，另一个指针标识数组的尾部。也就是说，对于一个数组而言，标识数组结尾的参数将是指向最后一个元素后面的指针。例如：
```cpp
double elbuod[20];
```
则指针`elboud`和`elboud + 20`定义了区间。首先，数组名`elboud`指向第一个元素。表达式`elboud + 19`指向最后一个元素，即`elboud[19]`。因此`elboud + 20`指向数组结尾后面的一个位置。下面的例程将展示这个功能的用法：

```cpp
// arrfun3.cpp -- functions with an array range

#include <iostream>

const int ArSize = 8;
int sum_arr(int *begin, int *end); //prototype
int main(int argc, char const *argv[])
{
    using namespace std;
    int cookies[ArSize];
    cout << "Please enter 8 numbers" << endl;
    for (int i = 0; i < 8; i++)
        cin >> cookies[i];

    int sum = sum_arr(cookies, cookies + ArSize);
    cout << "Total cookies eaten: " << sum << endl;
    sum = sum_arr(cookies, cookies + 3);
    cout << "The first 3 eater ate: " << sum << " cookies. \n";

    sum = sum_arr(cookies + 4, cookies + 8);
    cout << "The last 4 eaters ate: " << sum << " cookies. \n";

    return 0;
}

// return the sum of an integer array
int sum_arr(int *begin, int *end)
{
    const int * pt;
    int total = 0;

    for (pt = begin; pt != end; pt++)
        total = total + *pt;
    return total;
}
```

out:
```
Please enter 8 numbers
5 6 7 2 1 5 3 4 
Total cookies eaten: 33
The first 3 eater ate: 18 cookies.
The last 4 eaters ate: 13 cookies.
```

<font color = #1E90FF>程序说明：</font>

值得注意的是`sun_array()`中的`for`循环

```cpp
for (pt = begin; pt != end; pt++)
    total = total + *pt;
```

它将`pt`设置为指向要处理的第一个元素(begin指向的元素)的指针，并且将`*pt`（元素的值）加入到`total`中。然后，循环通过递增的操作来更新`pt`，使指指向下一个元素。只要`pt`不等于`end`，这一过程就将继续下去。当`pt`等于`end`时，它将指向区间中最后一个元素的后面的一个位置，此循环结束。

### 7.3.4 指针和`const`

有两种方式将`const`关键词用于指针。第一种方式是让指针指向一个常量对象，这样可以方式使用该指针来修改所指向的值；第二种方法是将指针本身声明为常量，这样可以防止改变指针指向的位置。比如：

```cpp
int age = 39;
const int * pt = &age
```

该声明指出，`pt`指向一个`const int` （这里是39），因此不能使用`pt`来修改这个值。换句话说，`*pt`的值为`const`，不能修改：

```cpp
* pt += 1;      // Invalid because pt points to a const int
cin >> *pt;     // Invalid because pt points to a const int
```

但这并不意味着，`*pt`的值不会变，当我们改变`age`的值的时候，就会修改`*pt`。

```cpp
age = 20;
```

以前我们经常将常规变量的地址赋值给常规的指针，而这里将常规变量的地址赋值给`const`指针。因此还有两种可能：将`const`变量的地址赋值给`const`的指针、及那个`const`的地址给常规的指针。但实际上，只有第一种是可行的。

```cpp
const float g_earth = 9.81;
const float * pe = &g_earth;    // VALID

const float g_moon = 1.63;
float * pm = &g_moon;           // INVALID
```

对于第一种情况来说，既不能用`g_earth`来修改值9.81，也不能使用`pe`来修改。但是C++中禁止使用第二种情况，因为如果将`g_moon`的地址赋给`pm`，则可以使用`pm`来修改`g_moon`的值，这使得`g_moon`的`const`状态很荒谬。如果指针指向指针，则状态更加的复杂。前面讲过，如果只涉及一级间接关系，则将非`const`指针赋值给`const`指针是可以的：

```cpp
int age = 39;               // age ++ is a valid operation
int * pa = &age;            // *pd = 41 is a valid operation
const int * pb = pa;        // *pt = 42 is an invalid operation
```

然而进入两级间接关系的时候，与一级间接关系一样，将`const`和非`const`混合的指针赋值方式将不再安全。如果允许这样做，则可以编写这样的代码：

```cpp
const int **pp2;
int * p1;
const int n = 13;
pp2 = &p1;      //not allowed, but suppose it were
*pp2 = &n       //valid, both const, but sets p1 to point at n
*p1 = 10;       //valid but changes const n
```
上述的代码，将一个非`const`地址赋值给了一个`const`指针，因此可以使用`p1`来修改`const`数据。

假如有一个由`const`数据组成的数组：
```cpp
const int months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
```

则禁止将常量数组的地址赋给非常量指针，这意味着不能将数组名作为参数传递给使用非常量形参的函数：

```cpp
int sum(int arr[], int n);  // should have been const int arr[]
...
int j = sum(months, 12);    // not allowed
```
上述函数调用试图将`const`指针(months)赋值给非`const`指针(arr)，编译器将禁止这样的行为。

因此我们应该尽可能的使用`const`
将指针参数声明为指向常量数据的指针由两条理由：
* 专业可以避免由于无意间修改数据导致的编程错误。
* 使用`const`使得函数能够处理`const`和非`const`实参，否则将只能接受非`const`数据。
  
除此之外，还有一个微妙之处：
```cpp
int age = 39;
const int * pt = &age;
```

上面的声明中`const`可以防止修改`pt`指向的值，而不能防止修改`pt`的值，也就是说，可以及那个一个新地址赋给pt:

```cpp
int sage = 80;
pt = &sage;     // okey to poin to anther location
```

但是仍然不能使用`pt`来修改指向它的值（现在是80）。

第二种使用`const`的方式使得无法修改指针的值：

```cpp
int sloth = 3;
const int * ps = &sloth;        // a pointer to const int
int * const finger = &sloth;    // a const pointer to int
```

上面的声明中，关键词`const`的位置与之间的不同。这种声明格式使得`finger`只能指向`sloth`，但是允许使用`finger`来修改`sloth`的值。中间的声明不循序使用`ps`来修改`sloth`的值，但是允许将`ps`指向另一个位置。简而言之，`finger`和`* ps `都是`const`，而`*finger`和`ps`不是。

当然还可以声明指向`const`对象的`const`指针：
```cpp
double trouble = 2.0E30;
const double * const stick = &trouble;
```
其中，`stick`只能指向`trouble`，而`stick`不能用来修改`trouble`的值。简而言之，`stick`和`&stick`都是`const`。

## 7.4 函数和二维数组
假设我们要对一个二维数组中的元素求和：

```cpp
int data [3] [4] = {{1,2,3,4},{9,8,7,6},{2,4,6,8}}; // 三行四列的数组
int total = sum(data, 3);
```

那么`sum`的原型是什么样的呢？`data`是一个数组名，该数组有3个元素。第一个元素本身是一个数组，有四个`int`值组成。因此`data`的类型是一个执行由四个`int`组成的数组的指针，因此正确的原型如下：

```cpp
int sum (int (*ar2)[4], int size );
```

上面声明中的括号是必不可少的，因为后面要将声明由一个指向`int`的指针组成的数组，而不是由一个指向由4个`int`组成的数组的指针。另外函数的参数不能是数组：`int *ar2[4]`。

另外还有一种格式：
```cpp
int sum(int ar2[][4], int size);
```
这两种格式的含义完全相同。

上面的两个格式都指出，`ar2`不是数组而是指针。并且可以看出，每一行的元素个数在声明的时候就已经指定了，为4。但是行数并没有指定，没有限制。比如：

```cpp
int a[100][4];
int b[6][4];
...
int total1 = sum(a, 100);   //sum all of a
int total2 = sum(b, 6);   //sum all of b
int total3 = sum(a, 10);   //sum first 10 rows of a 
int total4 = sum(a+10, 20);   //sum next 20 rows of a
```

由于参数`ar2`是指向数组的指针，那么我们在定义函数的时候，最好就将`ar2`看作是一个二维数组的名称。下面是一个可行的函数定义：

```cpp
int sum(int ar2[][4], int size)
{
    int total = 0;
    for (int r = 0; r < size; r++)  // 遍历行
        for (int c = 0; c < 4; c++) // 遍历列
            total += ar2[r][c];
    
    return total;
}
```

下面来总结一下之前提出的概念:
```cpp

ar2                 //pointer to first row of an array of 4 int
ar2 +r              // pointer to row r (an array of 4 int)
*(ar2 + r)          // row r (an array of 4 int, hence the name of an array,
                    // thus a pointer to the first int in te row, i.e., ar2[r])

*(ar2 + r) + c      // pointer int number c in row r, i.e., ar2[r] + c
*(*(ar2 + r) + c)   // value of int number c in row r, i.e., ar2[r][c]
```

在声明`sum()`代码的时候参数`ar2`没有使用`const`因为`ar2`是指向指针的指针。

## 7.5 函数和C-风格字符串

前面介绍过，C-风格的字符串以一些列字符组成，以空值字符结尾。在将字符串作为参数时意味着要传递的时地址，但是可以使用`const`来禁止对字符串参数进行修改。下面我们将介绍与字符串有关的一些特殊知识。

### 7.5.1 将C-风格字符串作为参数的函数

假设要将字符串作为参数传递给数组，则表示字符串的方式有3种：
* `char`数组；
* 用引号括起来的字符串常量（也成为字符串字面值）；
* 被设置为字符串的地址`char`指针。

但上述3种选择的类型都是`char`指针（`char*`），因此可以将其作为函数处理字符串的参数：
```cpp
char ghost[15] = "galloping";
char * str = "galumphing";
int n1 = strlen(ghost);         // ghost is &ghost[0]
int n2 = strlen(str);           // pointer to char
int n3 = strlen("gamboling");   // address of string
```

说是将字符串作为参数来传递，但实际传递的是字符串第一个字符的地址。这意味着字符串函数原型应将其表示字符串的形参声明为`char *`类型。

C-风格字符串与常规`char`数组之间的一个重要区别是，字符串内置有结束字符。不以空字符结尾的`char`只是数组。这意味着不必将字符串长度作为参数传递给函数（与数组不同），而函数可以通过循环依次检查字符串中的每一个字符，直到遇到结尾的空字符为止。下面的例程展示了这个方法：

```cpp
// strfun.cpp -- functions with a string argument

#include <iostream>
uint16_t c_in_str(const char * str, char ch);

int main()
{
    using namespace std;
    char mmm[15] = "minimum";   // string in an array
    // char uuu[15] = "ululate";
    char * wail = "ululate";    // wail points to string

    uint16_t ms = c_in_str(mmm,'m');
    uint16_t us = c_in_str(wail,'u');
    cout << ms << " m characters in " << mmm << endl;
    cout << us << " u characters in " << wail << endl;

    return 0;
}

uint16_t c_in_str (const char * str, char ch)
{
    uint16_t count = 0;

    while (*str)            //quit when *str is '\0'
    {
        if (*str == ch)
            count++;
        str++;              // move pointer to next char
    }
    return count;
}
```

很不幸，在C++17中，指针不能直接指向字符串了，当我输入上方代码时，编译器报错：
```
.\strfun.cpp: In function 'int main()':
.\strfun.cpp:11:19: warning: ISO C++ forbids converting a string constant to 'char*' [-Wwrite-strings]
     char * wail = "ululate";    // wail points to string
```

要想解决问题也很简单，只需要将
```cpp
    char * wail = "ululate";    // wail points to string
```
替换成：
```cpp
     char uuu[15] = "ululate";
    char * wail = uuu;    // wail points to string
```

输出结果是：
```
3m characters in minimum
2u characters in ululate
```

虽然有一点小问题，但程序依然有值得我们学习的地方：
```cpp
while (*str)
```
这个循环方式很方便的遍历了整个字符串，直到`'\n'`结束。

### 7.5.2 返回C-风格字符串的函数

虽然函数没有办法直接返回字符串，但是可以返回其地址。下面的例程展示其使用方法：
```cpp
// strgback.cpp -- a function that returns a pointer to char
#include <iostream>

char * buildstr(char c, int n);     // prototype
int main(int argc, char const *argv[])
{
    using namespace std;
    int times;
    char ch;

    cout << "Enter a character: ";
    cin >> ch;
    cout << "Enter a integer: ";
    cin >> times;
    char *ps = buildstr(ch, times);
    cout << ps << endl;
    delete [] ps;                   // free memory
    ps = buildstr('+',20);          // reuse poinetr 
    cout << ps << "-DONE-" << ps << endl;
    delete []  ps;                  // free memory
    return 0;
}

// builds string made of n c chararters
char * buildstr(char c, int n)
{
    char * pstr = new char[n + 1];
    pstr[n] = '\0';
    while (n-- > 0)
        pstr[n] = c;    // fill rest of string
    return pstr;
}
```

out:
```
Enter a character: V
Enter a integer: 46
VVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV
++++++++++++++++++++-DONE-++++++++++++++++++++
```

<font color = ogrange> 程序说明：</font>

首先，我们在创建一个包含n个字符的字符串的时候，需要能够储存`n+1`个字符的空间，以便能够储存空字符。然后程序中选择从后往前对字符串进行填充。下面的代码将循环n次，直到减少到0。

```cpp
while (n-- > 0)
    pstr[n] = c;
```

在最后一轮的循环开始时，n的值为1.由于`n--`意味着先使用这个值，然后对其递减，因此`while`循环测试条件将对1和0进行比较，发现测试为`true`，循环继续，然后将`n`减少为0，因此`pstr[0]`时最后一个被填充的元素。

## 7.6 函数和结构

函数与结构相比数组要简单，因为可以直接传入和返回。

### 7.6.1 传递和返回结构

<font color = ogrange>例程：</font>

```cpp
// travel.cpp -- using structures with functions
#include <iostream>

struct travel_time
{
    int hours;
    int mins;
};
const int Mins_per_hr = 60;

travel_time sum(travel_time t1, travel_time t2);
void show_time(travel_time t);

int main(int argc, char const *argv[])
{
    using namespace std;
    travel_time day1 = {5, 45};         // 5 hrs, 45 mins
    travel_time day2 = {4, 55};         // 4 hrs, 45 mins

    travel_time trip = sum(day1, day2);
    cout << "Two-day total: ";
    show_time(trip);

    travel_time day3 = {4, 32};
    cout << "Three-day total: ";
    show_time(sum(trip,day3));

    return 0;
}

travel_time sum(travel_time t1, travel_time t2)
{
    travel_time total;

    total.mins = (t1.mins + t2.mins) % Mins_per_hr;
    total.hours = (t1.hours + t2.hours) + 
    (t1.mins + t2.mins) / Mins_per_hr;

    return total;
}

void show_time (travel_time t)
{
    using namespace std;
    cout << t.hours << " hours, "
    << t.mins << " minutes.\n";
}
```

out:
```
Two-day total: 10 hours, 40 minutes.
Three-day total: 15 hours, 12 minutes.
```

<font color = ogrange>程序说明：</font>

1. 首先我们来看一下`sum()`函数。在函数原型的时候，这个函数与以前的原型不太类似：
   ```cpp
   travel_time sum (travel_time t1, travel_time t2);
   ```
   函数返回值的类型是`travel_time`结构，参数也是2个这种结构的变量。

2. 在程序中，我们可以把`travel_time`当作一个标准的类型名，它既可以用来声明变量，也可以声明函数返回类型和函数的参数类型。由于`sum()`返回值是`travel_time`结构，因此我们也可以将其作为`show_time()`的参数。

### 7.6.2 另一个处理结构的函数示例：

<font color = ogrange>题目：</font>
这一次我们要写一个函数，将直角坐标系转换为极坐标。这时我们就需要两个结构，一个用来表示（x，y），另一个表示（d, theta）。值得注意的是，在C++的数学库中，角度单位是弧度制，因此需要使用$\theta = rad*180\degree/\pi $来转换。

<font color = ogrange>例程：</font>

```cpp
// strctfun.cpp -- functions with a sturcture argument
#include <iostream>
#include <cmath>

// structure delarations
struct polar
{
    double distance;
    double angle;
};

struct rect
{
    double x;
    double y;
};

// prototypes
polar rect2polar(rect xypos);
void show_polar(polar dapos);

int main(int argc, char const *argv[])
{
    using namespace std;
    rect rpoint;
    polar ppoint;

    cout << "Enter the x and y values: ";
    while (cin >> rpoint.x >> rpoint.y)
    {
        ppoint = rect2polar(rpoint);
        show_polar(ppoint);
        cout << "Next two numbers (q to quit): ";
    }

    cout << "Done. \n";
    return 0;
}

// convert rectangular to polar coordinates
polar rect2polar(rect xypos)
{
    using namespace std;
    polar answer;

    answer.distance =
        sqrt(pow(xypos.x, 2) + pow(xypos.y, 2));

    answer.angle = atan2(xypos.y, xypos.x);

    return answer;
}

// show polar coordinates, coverting angle to degrees
void show_polar(polar dapos)
{
    using namespace std;
    const double rad_to_deg = 180 / 3.1415;

    cout << "distance = " << dapos.distance << endl;
    cout << "angle = " << dapos.angle * rad_to_deg;
    cout << " degree\n";
}
```

out:
```
Enter the x and y values: 30 40
distance = 50
angle = 53.1317 degree
Next two numbers (q to quit): -100 100
distance = 141.421
angle = 135.004 degree
Next two numbers (q to quit): q
Done.
```

<font color = ogrange>程序解释：</font>

值得一提的循环的中的条件。程序中使用的是：

```cpp
    while (cin >> rpoint.x >> rpoint.y)
```

`cin`是`istream`类的一个对象。抽取运算符`>>`被设计成使得`cin >> rpoint.x`也是一个`istream`对象。因此，在整个`while`循环中测试表达式的最终结果是`cin`，而`cin`被用于测试表达式中时，将根据输入是否成功，被转换成`bool`值`true`或者`false`。因此在程序中，`cin`期望用户输入两个数字，如果有非数字的输入，则表达式将返回`false`给`while`，导致循环结束。

### 7.6.3 传递结构地址

接着上面的例程，如果为了提高效率，将地址作为形参传递给函数`show_polar`该怎么做呢？

1. 调用函数时，将结构的地址`&ppoint`而不是结构本事`&ppoint`传递给它。
2. 将形参声明为指向`polar`的指针，即`polar*`类型。由于函数不应该修改结构，因此使用了`const`修饰符。
3. 由于形参时指针而不是结构，因此应使用间接成员运算符`->`而不是成员运算符`.`。

那么函数就应该修改为：

```cpp

void show_polar (const polar * pda)
{
    using namespace std;
    const double Rag_to_Deg = 57.28577952;

    cout << "distance = " << pda-> distance;
    cout ", angle = " << pda->angle*Rad_to_Deg;
    cout << "degrees.\n";
}
```

如果是对`rect2polar()`函数进行修改，则是：

```cpp
void rect2polar(const rect * pxy, polar * pda)
{
    using namespace std;
    pda->distance = sqrt(pow(pxy->x,2)+pxy->y,2);
    pda->angle = atan2(pxy->y,pxy->x);
}
```

主函数的`while loop`中则需要将参数全部修改成地址。

```cpp
while (cin >> rpoint.x >> rpoint.y)
{
    rect2polar(&rpoint,&ppoint);
    show_polar(&ppoint);
    cout << "Next two numbers (q to quit); ";>
}
```

## 7.7 函数和`string`对象

虽然C-风格字符串与`string`对象的用途几乎相同，但是`string`对象与结构更像。函数中使用`string`的方式，将由一个例程展示：

<font color = ogrange>例程：</font>

```cpp
// topfive.cpp -- handling an array of string object
#include <iostream>
#include <string>
using namespace std;

const int SIZE = 5;
void display(const string sa[], int n);

int main(int argc, char const *argv[])
{
    string list [SIZE];     // an array olding 5 string object
    cout << "Enter your " << SIZE << "favorite astronomical sights: \n";
    for (int i = 0; i < SIZE; i ++)
    {
        cout << i + 1<< ": ";
        getline(cin,list[i]);
    }

    cout << "Your list: \n";
    display(list, SIZE);

    return 0;
}

void display (const string sa[], int n)
{
    for (int i = 0; i < n; i++)
        cout << i + 1 << ": " << sa[i] << endl;
}
```

out:
```
Enter your 5favorite astronomical sights: 
1: Orion Nebula
2: M13
3: Saturn
4: Jupiter
5: Moon
Your list: 
1: Orion Nebula
2: M13
3: Saturn
4: Jupiter
5: Moon
```

<font color = ogrange>程序说明：</font>

由于形参`sa`是一个指向`string`对象的指针，因此`sa[i]`是一个`string`对象，可以像下面这样使用：

```cpp
 cout << i + 1 << ": " << sa[i] << endl;
```

## 7.8 函数与 array 对象

<font color = ogrange>题目：</font>
写一个程序记录四季的开销

<font color = ogrange>例程：</font>

```cpp
// arrobj.cpp -- functions with array objects

#include <iostream>
#include <array>
#include <string>

// constant data

const int Seasons = 4;
const std::array<std::string, Seasons> Snames = 
{"Spring", "Summer", "Fall", "Winter"};

// function to modify array object
void fill(std::array<double, Seasons> * pa);

// function that uses array object without modifying it
void show(std::array<double, Seasons> da);

int main(int argc, char const *argv[])
{
    std::array<double, Seasons> expenses;
    fill(&expenses);
    show(expenses);
    return 0;
}

void fill(std::array<double,Seasons> *pa)
{
    using namespace std;
    for (int i = 0; i < Seasons; i++)
    {
        cout << "Enter " << Snames[i] << " expenses: ";
        cin >> (*pa)[i];
    }
}

void show(std::array<double, Seasons> da)
{
    using namespace std;
    double total = 0.0;
    cout << "\nEXPENSES\n";
    for (int i = 0; i < Seasons; i++)
    {
        cout << Snames[i] << ": $" << da[i] <<endl;
        total +=da[i];
    }
    cout << "Total expenses: $" << total << endl;
}
```

out:
```
Enter Spring expenses: 212
Enter Summer expenses: 256
Enter Fall expenses: 208
Enter Winter expenses: 244

EXPENSES
Spring: $212
Summer: $256
Fall: $208
Winter: $244
Total expenses: $920
```

<font color = ogrange>程序说明：</font>

值得一提的是`pa`是一个指向`array<double, 4>`对象的指针，因此`*pa`为这种对象，而`(*pa)[i]`是该对象的一个元素。由于运算符优先级的影响，其中的括号必不可少。

## 7.9 递归

C++函数有一个有趣的特点 -- 可以调用自己（`main`不可以），这种功能被称为递归。

### 7.9.1 包含一个递归调用的递归

<font color = ogrange>例程：</font>

```cpp
// recur.cpp -- using recursion 
# include <iostream>
void countdown (int n);

int main(int argc, char const *argv[])
{
    countdown(4);
    return 0;
}

void countdown(int n)
{
    using namespace std;
    cout << "Counting down ... " << n <<endl;

    if (n > 0)
        countdown(n-1);     // function calls itself
    cout << n << ": Kaboom!\n";
}
```

out:
```
Counting down ... 4
Counting down ... 3
Counting down ... 2
Counting down ... 1
Counting down ... 0
0: Kaboom!
1: Kaboom!
2: Kaboom!
3: Kaboom!
4: Kaboom!
```

<font color = ogrange>程序说明：</font>

首先我们查看输出：`counting down`后面的数字是逐渐减少的，而`kaboom！`前面的数字是递增的。这是因为在输出`counting down`后，函数就进入了自我的调用，因此在`if`条件结束之前，函数会被一直调用。当最后一个函数被调用完，`if`条件失效，程序开始向下进行，从而输出`0: Kaboom!`。这是一个由内向外的过程。

值得注意的是，每一个递归调用会创建自己的一套变量，因此当程序到达第五次调用时，已经有了5个独立的`n`变量。

### 7.9.2 包含多个递归调用的递归

<font color = ogrange>题目：</font>

将一个字符串分别从左右两边进行输入：

<font color = ogrange>例程：</font>

```cpp
// ruler.cpp -- using recursion to subdivide a ruler
#include <iostream>
const int Len = 66;
const int Divs = 6;

void subdivide(char ar[], int low, int high, int level);
int main(int argc, char const *argv[])
{
    char ruler[Len];
    int i;
    for (i = 1; i < Len - 2; i++)
        ruler[i] = ' ';
    ruler[Len - 1] = '\0';
    int max = Len -2;
    int min = 0;
    ruler[min] = ruler[max] = '|';
    std::cout << ruler << std::endl;
    for (i = 1; i <= Divs; i++)
    {
        subdivide(ruler,min,max,i);
        std::cout << ruler << std::endl;
        for (int j = 1; j < Len - 2; j++)
            ruler[j] = ' ';      // reset to blank ruler
    }
    return 0;
}

void subdivide(char ar[], int low, int high, int level)
{
    if (level == 0)
        return;
    int mid = (high + low) / 2;
    ar[mid] = '|';
    subdivide(ar, low, mid, level - 1);
    subdivide(ar, mid, high, level - 1);
}
```

out:

```
|                                                               |
|                               |                               |
|               |               |               |               |
|       |       |       |       |       |       |       |       |
|   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | |
|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
```
<font color = ogrange>程序说明：</font>

程序种中的`subdivide()`函数使用变量`level`来控制递归层级。函数调用自身十，将把`level`减一，当`level`归零的时候，桉树将不再调用自己。注意，`subdivide()`函数会调用自己两次，一次针对左半边，另一次针对右边。最初中点被用作调用的右端点和另一次调用的左端点。调用次数将呈几何级数增长。也就是说，调用一次导致两个调用，然后导致4个调用。因此6个层级可以导致$2^6 = 64$次调用。将64格全部填满。

## 7.10 函数指针

### 7.10.1 基础知识

这里我们将举一个例子来阐释这个过程。需要写一个`estimate()`函数来估算编写指定行数代码的时间，并且希望每个程序员提供自己的算法来估算时间。为了完成这个功能，必须要完成以下工作：

* 获取函数的地址；
* 声明一个函数指针；
* 使用函数指针来调用函数。

1. 获取函数的地址

获取函数的地址很简单：只要使用函数名（后面不跟函数）即可。也就是说，如果`think()`是一个函数，则`think`是该函数的地址。要将函数作为参数进行传递，必须传递函数名。一定要区分传递的是函数的地址还是函数的返回值：

```cpp  
process(think);         // passes address of think() to process()
thought(think());       // passes return value of think() to thought()
```

`process()`调用使得`process()`函数能够在其内部调用`think()`函数。`thought()`调用首先调用`think()`函数，然后及那个`think()`的返回值传递给`thought()`函数。

2. 声明函数指针

声明指向某种数据类型的指针时，必须指定指针指向的类型。同样，声明指向函数的指针时，也必须指定指针指向的函数类型。这意味着声明应指定函数的返回类型以及函数的特征表（参数列表）。也就是说，声明应像函数原型那样指出有关函数的信息。例如一个函数原型如下：

```cpp
double pam(int);    // prototype
```

则正确的指针类型声明如下：

```cpp
double (*pf)(int);  // pf points to a function that takes
                    // one int argument and that
                    // returns type double
```

上面的声明中`*pf`是`pam`的替换，因此`(*pf)`也是函数，则`pf`就是函数指针。

需要注意的是，要为声明提供正确的运算符优先级，必须在声明中使用括号将`*pf`扩起。括号的优先级比*运算符高，因此`*pf（int)`意味着`pf()`是一个返回指针的函数，而`(*pf)(int)`意味着`pf`是一个指向函数的指针：

```cpp
double (*pf)(int);  // pf points to a function that returns double
double *pf(int);    // pf() a function that returns a pointer-to-double
```

正确的声明`pf`后，还应该将相应的地址赋予它：
```cpp
double pam(int);
double (*pf)(int);
pf = pam;
```

3. 使用指针来调用函数

前面讲过，`(*pf)`扮演的角色是与函数名相同，因此需要使用`(*pf)`时，只需要将它看作函数名即可：

```cpp
double pam(int);
double (*pf)(int);
pf = pam;               // pf now points to the pam() function
double x = pam(4);      // call pam() using the function name
double y = (*pf)(5);    // call pam() using the pointer pf
```

实际上，C++可以直接使用`pf`：
```cpp
double y = pf(5);   // also call pam() using the pointer pf
```

<font color = ogrange>例程：</font>

```cpp
// fun_prt.cpp -- pointers to functions
#include <iostream>
double betsy(int);
double pam(int);

// second argument is pointer to a type double function that
// takes a type int argument
void estimate (int lines, double (*pf)(int));

int main(int argc, char const *argv[])
{
    using namespace std;
    int code;
    cout << "How many lines of code do you need?\n";
    cin >> code;
    cout << "Here's Betsy's estimate: \n";
    estimate(code,betsy);
    cout << "Here's pam's estimate: \n";
    estimate(code,pam);
    return 0;
}

double betsy (int lns)
{
    return 0.05 * lns;
}

double pam (int lns)
{
    return 0.03 * lns + 0.0004 * lns * lns;
}

void estimate (int lines, double (*pf)(int))
{
    using namespace std;
    cout << lines << "lines will take ";
    cout << (*pf)(lines) << " hours(s)\n";
}
```

out:
```
How many lines of code do you need?
30
Here's Betsy's estimate: 
30lines will take 1.5 hours(s)
Here's pam's estimate:
30lines will take 1.26 hours(s)
```

### 7.10.2 输入探讨函数指针
