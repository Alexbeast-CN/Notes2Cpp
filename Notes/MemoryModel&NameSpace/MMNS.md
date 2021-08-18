# 第九章 内存模型和名称空间

## 9.1 单独编译

C++ 和 C 一样，鼓励大家将函数放到单独的文件中进行编译。之前的例程中，很多的函数放在了一个文件之中，导致一个文件过于庞大，因此将函数放在不同的文件中，再利用头文件来引用，就可以将文件的结构变得更加的易读：

一般来说，头文件包含的内容有：

* 函数原型；
* 使用 `#define`或者`const`定义的符号常量；
* 结构声明；
* 类声明；
* 模板声明；
* 内联函数。

下面我们将展示一系列的程序：

程序9.1     coordin.h
---
```cpp
// coordin.h -- structure templates and function prototypes
// sturcture templates
#ifndef COORDIN_H_
#define COORDIN_H_

struct polar
{
    double distance; // distance from origin
    double angle;    // direction from origin
};

struct rect
{
    double x; // horizontal distance from origin
    double y; // vertical distance from origin
};

// prototypes
polar rect2polar(rect xypos);
void show_polar(polar dapos);

#endif
```

上面的头文件中`#ifndef` (if not defined) 避免多次包含同一个头文件，包含了一个头文件中包含的头文件。经过这个`#ifndef`语句处理过后，才会进行对于名称`COORDIN_H_`的定义。即处理`#ifndef`与`#endif`之间的内容。这样的方法并不是防止编译器对同一头文件包含两次，只是将除了第一次以外的包含内容忽略。

通常，`#define`语句用来创建符号常量，如下所示：
```cpp
#define MAXIMUM 4096
```

但是只要将`#define`用于名称就可以完成符号定义：

```cpp
#define COORDIN_H_
```

程序9.1     main.cpp
---
```cpp
// file1.cpp -- example of a three-file program
#include <iostream>
#include "coordin.h"    // 由于我的头文件和cpp文件放在同一路径内，所以这里直接包含头文件名

using namespace std;
int main(int argc, char *argv[])
{
    rect rplace;
    polar pplace;

    cout << "Enter the x and y values: ";
    while (cin >> rplace.x >> rplace.y)
    {
        pplace = rect2polar(rplace);
        show_polar(pplace);
        cout << "Next two numbers (q to quit): ";
    }
    cout << "Bye!\n";
    return 0;
}
```

程序9.2 func.cpp
---

```cpp
// func.cpp -- contains fucntions called in main.cpp

#include <iostream>
#include <cmath>
#include "coordin.h"    // structure templates, function prototypes

// convert rectangular to polar coordinates
polar rect2polar(rect xypos)
{
    using namespace std;
    polar answer;

    answer.distance =
        sqrt( pow(xypos.x,2) + pow(xypos.y,2));

    answer.angle = 
        atan2(xypos.y, xypos.x);
        return answer;
}

// show polar coordinates, converting angle to degrees
void show_polar(polar dapos)
{
    using namespace std;
    const double Rad2deg = 180/3.14;

    cout << "distance = " << dapos.distance;
    cout << "angle = " << dapos.angle * Rad2deg;
    cout << " degrees\n";
}

```

使用：
```
g++ -g func.cpp main.cpp -o  Coordin
```

对多个文件进行编译

程序输出：

```
Enter the x and y values: 2 3
distance = 3.60555angle = 56.3385 degrees
Next two numbers (q to quit): q
Bye!
```

## 9.2 储存持续性、作用域和连接性

### 9.2.1 作用域和链接

作用域（scope）描述了名称在文件（翻译单元）的多大范围可见。例如，函数中定义的变量可在该函数中使用，但是不能在其他的函数中使用；而文件中的函数定义之前定义的变量则可在所有函数中使用。

链接性（linkage）描述了名称如何在不同单元之间共享。链接性为外部的名称可以在文件间共享，链接性为内部的名称只能由一个文件中的函数共享。自动变量没有链接性，因为它们不能共享。

C++变量的作用域可以由多种。作用域为局部变量的只在定义它的函数体中可用（花括号括起来的{}）。作用域为全局（也叫做文件作用域）的变量在定义位置到文件结尾之间都可以使用。自动变量的作用域是局部，静态变量的作用域是全局还是局部取决于它是怎么被定义的。在名称空间中声明的变量，作用域是整个名称空间。

C++函数的作用域可以是整个类或者整个命名空间（包括全局的），但不是局部的。

### 9.2.2 自动储存持续性

默认情况下，在函数中声明的函数参数和变量储存持续性为自动，作用域为局部，没有连接性。也就是说，如果在`main()`和`oil()`函数中都声明了一个名为`tas`的变量，则会创建两个独立的变量 -- 只有在定义它们的函数中才能使用它们。当函数执行结束后，这些变量也就会消失。

那么如果在一个函数体中定义了一个变量`tas`又在函数体中的函数体中的新作用域内定义了变量`tas`情况会如何呢？

![ ](./pics/1.png)

这表明，自动变量旨在包含它们的函数或代码块中可见。

程序 9.4    auto.cpp
---
```cpp
// auto.cpp -- illustrating scope of automatic variables
#include <iostream>
void oil(int years)
{
    using namespace std;

    int texas = 2;
    cout << "In oil(), texas = " << texas << ", &texas =";
    cout << &texas << endl;
    cout << "In oil, years = " << years << ", &years = ";
    cout << &years << endl;
    {
        int teaxs = 113;
        cout << "In oil(), texas = " << texas << ", &texas =";
        cout << &texas << endl;
        cout << "In oil, years = " << years << ", &years = ";
        cout << &years << endl;
    }
    cout << "Post-block texas = " << texas;
    cout << ", &texas = " << &texas << endl;
}

int main(int argc, char *argv[])
{
    using namespace std;

    int texas = 31;
    int years = 2011;
    cout << "In main(), texas = " << texas << ", &texas =";
    cout << &texas << endl;
    cout << "In main, years = " << years << ", &years = ";
    cout << &years << endl;
    oil(texas);
    cout << "In main(), texas = " << texas << ", &texas =";
    cout << &texas << endl;
    cout << "In main, years = " << years << ", &years = ";
    cout << &years << endl;
    return 0;
}
```

程序输出为：

```
In main(), texas = 31, &texas =0x61fe1c
In main, years = 2011, &years = 0x61fe18
In oil(), texas = 2, &texas =0x61fddc
In oil, years = 31, &years = 0x61fdf0
In block(), texas = 113, &texas =0x61fdd8
Post-block texas = 2, &texas = 0x61fddc
In main(), texas = 31, &texas =0x61fe1c
In main, years = 2011, &years = 0x61fe18
```

可以看出，3个`texas`的地址各不相同。