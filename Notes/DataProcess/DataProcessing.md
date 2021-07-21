@import "my-style.less"
# C++ Primer 学习笔记 {ignore=true}
---

# 第三章：处理数据 {ignore=true}

## 本章学习内容： {ignore=true}
[TOC]
---

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

