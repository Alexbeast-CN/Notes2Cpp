# 第七章 函数 -- C++的编程模块

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

首先来展示一些函数的原型，他们的特征标和返回类型相同：

```cpp
const double * f1(const double ar[  ], int n);
const double * f2(const double [], int);
const double * f3(const double *, int);
```

上面的原型中，`const double ar[]`可以简化为`const double []`，`int n` 可以简化为`int`。由于`*ar`与`ar[]`所代表的意义相同，因此也可以将`*ar`简化为`*`。

接下来，假设要声明一个指针指向这三个函数之一。

```cpp
const double *(*pa)(const double *,int);
```

当然声明的同时也可以进行初始化：

```cpp
const double *(*pa)(const double *,int) = f1;
```

使用C++的自动类推断，代码会更加简单：

```cpp
auto p2 = f2;
```

再看下面的代码：

```cpp
cout << (*p1)(av,3) << ": " << *(*p1)(av,3) << endl;
cout << p2(av,3) << ": " << *p2(av,3) << endl;
```

上面代码的前半部分输出的都是一个`double`类型的地址，后半部分是`double`的数值。

既然我们在上面声明了三个函数，那么有没有用一个指针数组来调用三个函数呢？答案是有的：
```cpp
const double * (*pa[3])(const double *, int) = {f1, f2, f2};
```
首先，`pa`是一个包含三个元素的数组，所以其后要跟一个`[]`，由于`[]`的优先级大于`*`，所以`*pa[3]`表示的是一个包含三个指针的数组。`const double *`是特征标，表示返回值是一个`const double *`类型。那么如何调用这个函数呢？

```cpp
const double * px = pa[0](av,3);
```

要想获取指向`double`的值，可使用运算符`*`

```cpp
double x = *pa[0](av,3);
```

>说实话，指针真的太恶心了。一层又一层的无限套娃啊。暂时跳过了，读不下去了

### 7.10.3 使用 typedef 进行简化

除了`auto`以外，还可以使用`typedef`进行简化：

```cpp
typedef double real;    // makes real another name for double
```

这里将上面说的函数指针类型进行`typedef`:

```cpp
typedef const double * (*p_fun)(const double *, int);       // p_fun now a type name
p_fun p1 = f1;                                              // p1 points to the f1() function
```
