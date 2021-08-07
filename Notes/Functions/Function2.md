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