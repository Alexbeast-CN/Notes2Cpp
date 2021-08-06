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








