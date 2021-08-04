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
