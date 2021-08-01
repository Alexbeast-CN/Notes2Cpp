# C++ Primer 学习笔记 {ignore=true}
---
# 目录 {ignore=ture}
[TOC]
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
@import "./pics/4.png"
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
@import "./pics/5.png"
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
@import "./pics/6.png"
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
@import "./pics/7.png"

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
@import "./pics/8.png"

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
@import "./pics/9.png"
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
- [目录 {ignore=ture}](#目录-ignoreture)
  - [[TOC]](#toc)
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