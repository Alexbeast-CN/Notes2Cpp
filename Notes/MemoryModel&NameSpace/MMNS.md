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

可以看出，3个`texas`的地址各不相同。这是因为程序在执行`main()`时，程序为`texas`和`year`分配空间，使得这些变量可见。当执行到过程`oil()`中的内部代码块时，原来的`texas`将不可见，它将被一个更新的定义代替。然而，当代码块运行结束时，其中定义的变量也将会过期。这类自动变量，会被编译器存放在栈中，其进出逻辑为先进后出。

### 9.2.3 静态持续变量

C++为静态存储持续变量提供了3种链接性：外部链接（可在其他文件种访问）、内部链接（只能在当前文件种访问）、无链接性（只能在当前函数或代码块种访问）。这3种链接性都在整个过程执行期间存在，与自动变量相比，它们的寿命更长。储存空间也不是栈而将被编译器分配固定的内存空间。

下面来介绍如果创建这3种静态持续变量：

1. 外部链接的静态持续变量需要在**代码块的外面**声明它。
2. 内部链接的静态持续变量需要在**代码块外**声明它，并使用`static`限制符。
3. 如果是没有连接性的静态持续变量，需要在**代码块内**声明它，并使用`static`限制符。

用代码的形式，分别展示以上方法：

```cpp
int global = 1000;          // static duration, external linkage
static int one_file = 50;   // static duration, internal linkage

int main()
{
    ...
}

void func1(int n)
{
    static int count = 0;   // static duration, no linkage
    int llama = 0;
}

void func2(int q)
{

}
```

如前面所说的，所有静态持续变量（global, one_file, count) 在整个程序执行期间都存在。在`func1`中声明的变量`count`的作用域为局部，没有连接性，这意味着只能在`func1()`函数中使用，就像自动变量`llama`一样，但是域`llama`不同的是，即使在`func1()`函数没有被执行的时候，`count`也会存在于存储中。而内外部链接的区别则是，内部的只能在一个文件中调用，而外部的则可以在其他的文件中使用。

### 9.2.4 静态持续性、外部连接性

单定义规则：

一方面，在每个使用外部变量的文件中，都必须声明它；另一方面，C++有“单定义规则” (One Definition Rule, ODR), 该规则指出，变量只能定义一次，为了满足这种需求，C++提供了两种变量声明。一种是定义声明 (defining declaration)或简称为定义 (definition)，它给变量分配储存空间；另外一种是引用声明 (referencing declaration) 或简称为声明 (declaration)，它不会给变量分配储存空间，因为它引用已有的变量。引用声明使用关键字`extern`，且不进行初始化；否则，声明为定义，导致分配内存空间：

```cpp
double up;              // definition, up is 0
extern int blem;        // blem defined elsewhere
extern char gr = 'z'    // defnition because initializad
```

如果要在多个文件种使用外部变量，只需要在一个文件中包含该变量的定义（单定义规则），但在使用该变量的其他所有文件中，都必须使用关键字 `extern` 声明它：

```cpp
// file01.cpp
extern int cats = 20;   // definition because of initialization
int dogs = 22;          // definition
int fleas;              // definition
...

// file02.cpp
// use cats and dogs from file01.cpp
extern int dogs;        // not definition because they use 
extern int cats;        // extern and have no initialization
...

// file03.cpp
// use cats, dogs, and fleas from file01.cpp
extern int dogs;
extern int cats;
extern int fleas;
```

下面用一个例程来展示这一概念：

**程序9.5**
```cpp
// external.cpp -- external variables
// compile with support.cpp

#include <iostream>
using namespace std;

// external variable
double warming = 0.3;    //warming defined
// function prototypes
void update(double dt);
void local();

int main(int argc, char const *argv[]) // uses global variable
{
    cout << "Global warming is " << warming << " degrees. \n";
    update(0.1);         // call function to change warming
    cout << "Global warming is " << warming << " degrees. \n";
    local();            // call function with local warming
    cout << "Global warming is " << warming << " degrees. \n";
    return 0;
}

```

**程序 9.6**

```cpp
// suppport.cpp -- use external variable
// complie with external.cpp
#include <iostream>
extern double warming;   // using warming from another file

// function prototypes
void update (double dt);
void local();

using std::cout;
void update (double dt) // modifies global variable
{
    extern double warming;  //optional redeclaration
    warming += dt;      // uses global warming
    cout << "Updating global warming to " << warming;
    cout << " degrees.\n";
}

void local()            // uses local variable
{
    double warming = 0.8;   // new variable hides external one

    cout << "Local warming = " << warming << " degrees.\n";
    // Access global variable with the 
    // scope resolution operator
    cout << "But global warming = " << ::warming;
    cout << " degrees.\n";
}
```

**程序输出：**

```
Global warming is 0.3 degrees.         
Updating global warming to 0.4 degrees.
Global warming is 0.4 degrees.         
Local warming = 0.8 degrees.
But global warming = 0.4 degrees.      
Global warming is 0.4 degrees. 
```

**程序说明：**

在上面的程序中，最值得关注的地方是`local()`函数，该函数中重新定义了一个局部变量`warming`，这个局部变量使得全局变量被隐藏了。此后，又使用了作用域运算符(::)获取到全局变量`warming`。

### 9.2.5 静态持续性、内部链接

将`static`限定符用于作用域为整个文件的变量时，该变量的链接性及那个为内部的。在多文件程序中，内部链接性和外部链接性之间的差别很大。并不是所有变量都需要成为全局变量，一些变量只需要在一个文件中使用，并且需要防止重名，需要使用`static`限定词将变量将变量限制在一个文件中。

下面还是由程序来演示这一方式的用法：

程序 9.7 twofile1.cpp

```cpp
// twofile1.cpp -- varibles with external and internal linkage
#include <iostream>
int tom = 3;            // external variable definition
int dick = 30;          // external variable definition
static int harry = 300; // static, internal linkage

// function prototype
void remote_access();

int main(int argc, char const *argv[])
{
    using namespace std;
    cout << "main() reports the following addresses: \n";
    cout << &tom << " = &tom," << &dick << " = &dick, ";
    cout << &harry << " = &harry\n";
    remote_access();
    return 0;
}
```

程序 9.9 twofile2.cpp

```cpp
// twofile2.cpp -- variables with internal and external linkage
#include <iostream>
extern int tom;       // tom defined elsewhere
static int dick = 10; // overrides external dick
int harry = 200;      // external variable definition,
                      // no confict with twofile1 harry

void remote_access()
{
    using std::cout;
    cout << "remote_access() reports the following addresses: \n";
    cout << &tom << " = &tom," << &dick << " = &dick, ";
    cout << &harry << " = &harry\n";
}
```

程序输出：

```
main() reports the following addresses:
0x403010 = &tom,0x403014 = &dick, 0x403018 = &harry
remote_access() reports the following addresses:
0x403010 = &tom,0x403020 = &dick, 0x403024 = &harry
```

### 9.2.6 静态储存持续性、无链接性

无链接性的持续变量是指在代码块中，用`static`限制的变量。它的特殊之处是在声明变量的函数结束后变量依然存在，因此二次调用依然可以使用，其变量的值只会在第一次被调用的时候被初始化，往后不会再初始化了。

下面用一个例程来展示

程序9.9 staticfile.cpp

```cpp
// static.cpp using a static local variable
#include <iostream>

// constants
const int ArSize = 10;
// function prototype
void strcount(const char *str);

int main()
{
    using namespace std;
    char input[ArSize];
    char next;

    cout << "Enter a line:\n";
    cin.get(input, ArSize);
    while (cin)
    {
        cin.get(next);
        while (next != '\n') // string didn't fit!
            cin.get(next);   // dispose of remainder
        strcount(input);
        cout << "Enter next line (empty line to quit):\n";
        cin.get(input, ArSize) ;
    }
    cout << "Bye\n";
    return 0;
}

void strcount(const char * str)
{
    using namespace std;
    static int total = 0; // static local varible
    int count = 0;        // auto local variable

    cout << "\"" << str << "\" constains ";
    while (*str++) // go to end of string
        count++;
    total += count;
    cout << count << " characters\n";
    cout << total << " characters total\n";
}
```

程序输出：

```
Enter a line:
Vscode
"Vscode" constains 6characters       
6 characters total
Enter next line (empty line to quit):
Vscode dead
"Vscode de" constains 9characters    
15 characters total
Enter next line (empty line to quit):

Bye
```

程序说明：

之前我们讲过`get()`和`getlin()`的区别。那么这里使用`get()`目的是为了读取到用户输入一行内容后的换行符，上面程序中使用到的代码块：

```cpp
    while (next != '\n') // string didn't fit!
        cin.get(next);   // dispose of remainder
```

其目的是为了处理用户的错误输入，因为程序中设置的输入长度为9个字符（第10个位字符为空字符）。如果用户的输入超出了9个字符，则程序会通过上面的代码，将多输入的字符导入`next`中，直到读取到用户输入的换行符为止。

另外一个的地方是：

```cpp
    while (*str++) // go to end of string
        count++;
```

这里的`while`条件是`*str = true`，逻辑是`*str++`，因为`str`的最后一位是`\0`所以，根据布尔值的逻辑，循环一直运行到字符串的最后一位。

### 9.2.7 说明符和限定符

**存储说明符：**

* register;
* static;
* extern;
* thread_local
* mustable

除了`thread_local`其他的限制符都不能在声明中与其他的限制符连用。

**限定符说明：**

1. cv限定符

c指的是`const`而v指的是`volatile`。这里我们先讲`voliatile`。`voliatile`表明，即使冲洗代码没有对内存单元进行修改，其值也可能发生变化。举一个例子：加入编译器发现，程序在几条语句中两次使用了某个变量的值，则编译器可能不是让程序查找这个值两次，而是将这个值缓存到寄存器中。而`voliatile`就是告诉编译器，不要做这样的优化。

2. mutable

`mustable`之处，即使结构（或类）变量为`const`，其某个成员也可以被修改,比如：

```cpp
struct data
{
    char name[30]
    mustable int accesses;
};

const data veep = {"Claybournne",0};
strcpy(veep.name, "Joye Joux");     // not allowed
veep.accesses++;                    // allowed
```

3. const

`const`限定符对默认存储类型稍有影响。在默认情况下，全局变量的链接性为外部的，但是`const`全局变量的链接性是内部的。也就是说：

```cpp
const int fingers = 10;     // same as static const int fingers = 10
```

### 9.2.8 函数和链接性

由于C++不允许在一个函数中定义另外一个函数，因此所有的函数的出巡持续性都是静态的。并且在默认情况下，函数的链接性为外部的，即可以在文件间共享。实际上，可以在函数原型中使用关键字`extern`来指出函数是在另一个文件中定义的（可选）。还可以使用关键字`static`将函数的链接性设置为内部的，使之只能在一个文件中使用。但是必须同时在原型和函数定义中使用该关键字：

```cpp
static int private(double x);
...
static int private(double x)
{

}
```

这意味着，该函数只在这个文件中可见，还意味着可以在其他文件中定义同名的函数。函数和变量都遵守单变量规则。

### 9.2.9 存储方案和动态分配

前面讲过运算符 `new`， 通过`new`分配的内存被称为动态内存。动态内存需要通过`new`和`delete`来控制，而不是由作用域和链接性规则来确定。这部分的内容暂时跳过。。。

## 9.3 名称空间

为了防止名称（变量、函数、结构、枚举、类以及类和结构的成员）之间发生冲突。C++提供了名称空间工具。

### 9.3.1 传统的C++名称空间

首先来复习一下C++已有的名称空间。

1. 声明区域：

声明区域可以是在其中进行声明的区域。例如，可以在函数外面声明全局变量，对于这种变量，其声明区域为其声明所在的文件。对于在函数中声明的变量，其声明区域为其声明所在的代码块。

2. 作用域

变量潜在的作用域从生命点开始，到其声明区域的结尾。因为潜在作用域比声明区域小，这是由于变量必须定义后才能使用。然后，变量并非在其潜在的作用域内的任何位置都是可见的。例如，它可能被另一个嵌套声明区域中的同名变量隐藏。

### 9.3.2 新的名称空间特性

C++新增了这样一个功能，即通过顶一个新的声明区域来创建命名的名称空间，这样做的目的之一是提供一个声明名称的区域。一个名称空间中的名称不会与另外一个名称空间的相同名称发生冲突，同时允许程序的其他部分使用该名称空间中声明的东西。例如：

```cpp
namespace Jack
{
    double pail;        // variable declaration
    void fetch();       // function prototype
    int pal;
    struct well{    };  // structure declaration
}

namespace Jill
{
    double ducket(double n) { ...  }    // fucntion definition
    double fetch;
    int pal;                            // variable declaration
    struct Hill { ... }                 // structure declaration
}

```

想要访问名称空间，最简单的方法是通过作用域解析运算符`::`，使用名称空间来限定该名称：

```cpp
Jack::pail = 12.32;     // use a variable
Jill::Hill mole         // create a type Hill structure
Jack::fetch();          // use a function
```

违背装饰的名称（如`pail`）称为限定的名称(unqualified name)；包含名称空间的名称(如 `Jack::pail`)称为限定的名称(qualified name)。

1. using 声明和 using 编译命令

我们并不希望每次使用名称时都对它进行限定，因此C++提供了两种机制（using 声明和 using 编译指令）来简化对名称空间中名称的使用。using 声明使用特定的标识符可用，using 编译指令使整个名称空间可用。

using 声明由被限定的名称和它前面的关键字 using 组成：

```cpp
using Jill::fetch;      // a using declaration
```

using 声明及那个特定的名称添加到它所属的声明区域中。例如 main() 中的 using 声明 `Jill::fetch`将 `fetch`添加到`main()`定义的声明区域中。完成该声明后，便可以使用名称`fetch`代替`Jill::fetch`。下面的代码说明了这样方式：

```cpp
namesapce Jill
{
    double bucket(double n)
    {
        ...
    }

    double fetch;
    struct Hill{ ... };
}

char fetch;

int main()
{
    Using Jill::fetch;      // put fetch into local namespace
    double fetch;           // Error! Already have a local fetch
    cin >> fetch;           // read a value into Jill::fetch
    cin >> ::fetch;         // read a value into global fetch
}
```

在使用上面方法的时候一定要注意不能出现二义性。下面举一个错误的示范：

```cpp
using jack::pal;
using jill::pal;
```

这样的方式将两个不同名称空间的`pal`变量都变成了局部变量，这就导致在使用`pal`的使用，编译器不知道该使用哪一个名称空间的`pal`而报错。

2. using 编译指令和 using 声明值比较
使用 `using`编译指令导入一个名称空间中所有的名称与使用多个`using`声明时不一样的，而更像是大量使用作用域解析运算符。使用`using` 声明时，就好像声明了相应的名称一样。如果某个名称已经在函数中声明了，则不能用`using`声明导入相同的名称。然而，使用`using`编译指令时，将进行名称解析。

在之前的内容中，大多数都是使用下面的方式进行名称空间使用：

```cpp
#include <iostream>
int main()
{
    using namespace std;
}
```

首先，`#include`将头文件`iostream`放到名称空间`std`中，然后，`using`编译指令是该名称空间在`main()`函数中可用。

但在实际的编程中，我们不建议这样使用名称空间，而是使用下面的方法：

```cpp

using std::cout;
using std::cin;
```
或者，

```cpp
std::cout << "Hello" << std::endl;
```

3. 名称空间的其他特性

可以将名称空间进行嵌套：

```cpp
namespace elements
{
    namespace fire
    {
        int flame;
        ...
    }
}
```

那么要想使用`flame`变量，需要`elment::fire::flame`两次解析域符号。这样的方式会显得比较复杂，但也有简化方法：

```cpp
namespace MEF = elements::fire;
using MEF::flame;
```

4. 未命名的名称空间

可以通过省略名称空间的方式来创建未命名的名称空间：

```cpp
namespace 
{
    int ice;
    int men;
}
```

### 9.3.3 名称空间示例

现在来看看一个多文件示例，该示例说明了名称空间的一些特性。

程序 9.11 namesp.h
```cpp
// namesp.h
#ifndef _NAMESP_H_
#define _NAMESP_H_

#include <string>
// create the pers and debts namespaces
namespace pers
{
    struct Person
    {
        std::string fname;
        std::string lname;
    };
    void getPerson(Person &);
    void showPerson(const Person &);
}

namespace debts
{
    using namespace pers;
    struct Debt
    {
        Person name;
        double amount;
    };
    void getDebt(Debt &);
    void showDebt(const Debt &);
    double sumDebts(const Debt ar[], int n);
} // namespace debts

#endif
```

程序 9.12 namesp.cpp

```cpp
// namesp.cpp -- namespaces
#include <iostream>
#include "namesp.h"

namespace pers
{
    using std::cout;
    using std::cin;
    using std::endl;

    void getPerson(Person & rp)
    {
        cout <<"Enter first name: ";
        cin >> rp.fname;
        cout << "Enter last name: ";
        cin >> rp.lname;
    }

    void showPerson(const Person & rp)
    {
        std::cout << rp.lname << ", " << rp.fname; 
    }  
}

namespace debts
{
    void getDebt(Debt & rd)
    {
        getPerson(rd.name);
        std::cout << "Enter debt: ";
        std::cin >> rd.amount;
    }
    void showDebt(const Debt & rd)
    {
        showPerson(rd.name);
        std::cout << ": $" << rd.amount << std::endl;
    }
    double sumDebts(const Debt ar[], int n)
    {
        double total = 0;
        for (int i = 0; i < n; i++)
        {
            total += ar[i].amount; 
        }
        return total;
    }
}
```

程序 9.12   namessp.cpp

```cpp
// namessp.cpp -- using namespaces
#include <iostream>
#include "namesp.h"

void other (void);
void another (void);

int main(int argc, char *argv[])
{
    using debts::Debt;
    using debts::showDebt;

    Debt golf = { {"Benny","Goatsniff"}, 120.0};
    showDebt(golf);
    other();
    another();  
    return 0;
}

void other (void)
{
    using std::cout;
    using std::endl;

    using namespace debts;

    Person dg = {"Doodles", "Glister"};
    showPerson(dg);
    cout << endl;
    Debt zippy[3];
    int i;
    for ( i = 0; i < 3; i++)
    {
        getDebt(zippy[i]);
    }

    for ( i = 0; i < 3; i++)
    {
        showDebt(zippy[i]);
    }
    cout << "Total debt: $" << sumDebts(zippy, 3) << endl;
    return;
    
}

void another (void)
{
    using pers::Person;
    Person collector = {"Milo", "Rightshift"};
    pers::showPerson(collector);
    std::cout << std::endl;
}
```

程序输出：

```
Goatsniff, Benny: $120
Glister, Doodles      
Enter first name: DDT 
Enter last name: L
Enter debt: 300
Enter first name: MMM
Enter last name: La
Enter debt: 200
Enter first name: Lsit
Enter last name: L
Enter debt: 2900
L, DDT: $300
La, MMM: $200
L, Lsit: $2900
Total debt: $3400
Rightshift, Milo
```

### 9.3.4 名称空间及其前途

随着程序员逐渐熟悉名称空间，将出现统一的编程理念。下面是当前的一些指导性原则。
* 使用在已命名的名称空间中声明的变量，而不是使用外部全局变量；
* 使用在已命名的名称空间中声明的变量，而不是使用静态全局变量；
* 如果开发了一个函数库或类库，将其放在一个名称空间中；
* 不要再头文件使用`using`编译命令，而应将`using`放在所有预处理器编译指令`#include`之后；
* 导入名称时，首选使用作用域解析运算符或`using`声明的方法。

