#! https://zhuanlan.zhihu.com/p/404822654
# 第十章 对象和类（上）

对象和类是 C++ 相对于 C语言而言 最重要的改进特点。

## 10.1 过程性编程和面向对象性编程

过程性编程方法，首先考虑的是要遵守的步骤，然后再考虑如何表示这些数据。但是一个面向对象（OOP）的程序员首先要考虑的是数据，不仅要考虑如何表示数据，还要考虑如何使用数据：

举一个例子，一个垒球队要记录球队的数据，其中需要选手的姓名、击球次数、击中次数、命中率。那么我要跟踪的是什么？是选手。因此要有一个表示选手的姓名和统计数据的对象。我需要一些处理该对象的方法。首先需要一种将基本信息加入到该名单中的方法；其次，计算机应计算一些东西，如命中率，因此需要添加一些执行计算的方法。程序应自动完成这些计算，而无需用户干涉。另外还需要一些更细你和显示信息的方法。所以，用户与数据交互的方式有三种：初始化、更新和报告 -- 这就是用户的接口。

总之，采用OOP方法时，首先从用户的角度考虑对象 -- 描述对象所需的数据以及描述用户与数据交互所需的操作。完成对接口的描述后，需要确定如何实现接口和数据储存，最后，使用新的设计方案创建出程序。

## 10.2 类
类时一个将抽象转换为用户定义类型的C++工具，它将数据表示和操纵数据的方式组合成一个整洁的包。下面来看一个表示股票的类。
首先，必须考虑如何表示股票。可以将一股作为基本单元，定义一个表示一股股票的类。然而，这一意味着需要100个对象才能表示100股，这不现实。相反，可以将默认当前持有的某种股票作为一个基本单元，数据表示中包含他持有的股票数据。一种比较显示的方法是，必须记录最初购买的价格和购买的日期等内容。另外，还必须管理诸如拆股等事件。首次定义类就要考虑这么多因素有些困难，因此我们对其进行简化。具体的数，应该将可执行的操作限制为：

* 获得股票
* 增持
* 卖出股票
* 更细股票价格
* 显示关于所持股票的信息

可以根据上诉清单定义一个 `stock`类的共有接口。

接下来定义类。一般来说，类规范由两个部分组成。
* 类声明：以数据成员的方式描述数据部分，以成员函数（被称为方法）的方式秒速共有接口。
* 类方法定义：描述如何实现类成员函数。

这里根据上面的描述，写出一个类的声明：

**程序10.1 stock00.h**

```cpp
// stock00.h -- stock class interface
// version 00
#ifndef STOCK00_H_
#define STOCK00_H_

#include <string>

class stock00
{
private:
    std::string company;    // 公司名称
    long shares;            // 所持股票数量
    double share_val;       // 每个的价格
    double total_val;       // 股票总价值
    void set_tot() { total_val = shares * share_val; }  // 就地定义total_val的算法

public:
    void acquire(const std::string &co, long n, double pr);
    void buy(long num, double price);
    void sell(long num, double price);
    void update(double price);
    void show();
}; // note semicolon at the end

#endif
```

语法讲解：

1. 首先，C++ 关键词 `class` 指出这些代码定义了一个类设计。这种语法指出，`Stock`是这个新类的类型名。该声明让我们能够声明`Stock`类型的变量 -- 称为对象或示例。每个对象都表示一支股票。例如，下面的声明创建两个`Stock`对象，他们分别名为`sally`和`solly`：

```cpp
Stock sally;
stock solly;
```
2. 访问控制。关键词 `private`和`public`关键词描述了对类成员的访问控制。使用类对象的程序都可以直接访问共有部分，但只有通过共有成员函数（或友元函数）来访问对象的私有成员。例如，要修改`Stock`类的`share`成员，只能通过`Stock`的成员函数。因此，共有成员函数是程序和对象的私有成员之间的桥梁，提供了对象和程序之间的接口。防止程序直接访问数据被称为数据隐藏。C++ 还提供了第三个访问关键字 `protetced`。这里暂时不介绍。

类设计要金科将的及那个共有接口与实现细节分开。共有接口表示设计的抽象组件。将实现细节放在一起并将它们与抽象分开被称为封装。数据隐藏（将数据放在类的私有部分中）是一种封装，将实现的细节隐藏在私有部分，将像`Stock`类对`set_tot()`所作的那样。封装的另一个例子是，将类函数定义和声明放在不同的文件中。

数据隐藏不仅可以防止直接访问数据，还让开发者（类的用户）无需了解数据是如何被表示的。例如，`show()`成员将显示某只股票的总价格（和一些其他内容），这个值可以存储在对象中，也可以在需要时通过计算得到。从使用类的角度看，使用哪些方法没有什么区别。所需要知道的只是各类成员函数的功能；也就是说，需要知道成员函数接受什么样的参数以及返回什么类型的值。原则是将实现细节从接口设计中分离出来。如果以后找到了更好的、实现数据表示或成员函数细节的方法，可以对这些细节进行修改，而无需修改程序接口，这使得程序维护起来更加容易。

3. 控制对成员的访问：共有、私有

无论类成员是数据成员还是成员函数，都可以在类的共有部分或者私有部分中声明它。但由于隐藏数据是OOP主要目标之一，因此数据项通常放在私有部分，组成类接口的成员函数放在公有部分；否则，就无法从程序中调用这些函数。正如 `Stock`声明所表明的，也可以把成员函数放在私有部分中。不能直接从程序中调用这种函数，但共有方法却可以使用他们。通常，程序员使用私有成员函数来处理不属于共有接口的实现细节。

其实不必在类声明使用关键字`private`，因为这是类对象的默认访问控制：

```cpp

class world
{
    float mass;
    char name[20];

    public:
    void tele(void);
};
```

### 10.2.3 实现类成员函数

在定义成员函数时，使用作用域解析运算符(::)来指出函数所处的类。例如，`update()`成员函数的函数头如下：

```cpp
void Stock::update(double price)
```

这种表示意味着我们定义的`update()`函数是`Stock`类的成员。这不仅将`update()`标识为成员函数，还意味着我们可以将另一个类的成员函数也命名为`update()`。例如，`Buffoon()`类的`update()`函数的函数头如下：

```cpp
void Buffoon::update()
```

下面用代码来展示类的使用

**程序10.2 stock00.cpp**

```cpp
// stock00.cpp -- implementing the stock class
// version 00

#include <iostream>
#include "stock00.h"

void Stock00::acquire(const std::string &co, long n, double pr)
{
    company = co;
    if (n < 0)
    {
        std::cout << "Number of shares can't be negative; "
                  << company << " shares set to 0. \n";
        shares = 0;
    }
    else
    {
        shares = n;
    }
    share_val = pr;
    set_tot();
}

void Stock00::buy(long num, double price)
{
    if (num < 0)
    {
        std::cout << "Number of shares purchased can't be negative. "
                  << "Transaction is aborted.\n";
    }
    else
    {
        shares += num;
        share_val = price;
        set_tot();
    }
}

void Stock00::sell(long num, double price)
{
    using std::cout;
    if (num < 0)
    {
        std::cout << "Number of shares sold can't be negative. "
                  << "Transaction is aborted.\n";
    }
    else if (num > shares)
    {
        cout << "You can't sell more than you have! "
             << "Transaction is aborted.\n";
    }
    else
    {
        shares -= num;
        share_val = price;
        set_tot();
    }
}

void Stock00::update(double price)
{
    share_val = price;
    set_tot();
}

void Stock00::show()
{
    std::cout << "Company: " << company
              << "\n    Shares: " << shares
              << "\n    Share Price: $" << share_val
              << "\n    Totol Worth: $" << total_val << std::endl;
}

```

**程序说明：**

1. 成员函数说明

在上面的程序中，我们利用共有函数对私有变量进行访问，这样的技术与允许我们能够控制数据如何被使用。在这里它允许我们加入这些安全防护措施，避免不适当的交易。

2. 内联方法

定义位于类声明中的函数都将自动成为内联函数，因此`Stock::set_tot()`是一个内联函数。类声明常将非常短小的成员函数作为内联函数，`set_tot()`符合这样的要求。

3. 方法使用哪个对象

这是使用对象时最重要的一个方面：如何将类方法应用于对象。下面的代码使用了一个对象的`shares`成员：

```cpp
Stock00 kate, joe;
```

这将创建两个`Stock00`类对象，一个为`kate`,另一个为`joe`。接下来。在使用过程中，我们需要像使用结构成员一样，通过成员运算符：

```cpp
kate.show();    // the kate object call the member function
joe.show();     // the joe object call the member function
```

所创建的每一个新对象都有自己的储存空间，用于储存其内部变量和类成员；但同一个类的所有对象共享同一组类方法，即每种方法只有一个副本。例如，假设`kate`和`joe`都是`Stock`对象，则`kate.shares`将占据一个内存块，而`joe.shares`占用另一个内存块，但是`kate.show()`和`joe.show()`都是调用同一个方法，也就是说他们将执行同一个代码块，知识将这些代码用于不同的数据。在OOP中，调用成员函数被称为发送消息，因此将同样的消息发送给两个不同的对象将调用同一个方法，但该方法被用于两个不同的对象。

### 10.2.4 使用类

对于类而言，C++希望将它做的尽可能的像内置的类型一样。它也可以使用`new`和`delete`来分配内存。可以将对象作为函数的参数和返回值，也可以将一个对象赋值给另一个对象。

下面用一个例子来展示一些基础的使用方法：

**程序 10.3 useStock.cpp**

```cpp
// useStock.cpp -- the client program
// compile with stock00.cpp

#include <iostream>
#include "stock00.h"
int main(int argc, char *argv[])
{
    Stock00 fluffy_the_cat;
    fluffy_the_cat.acquire("NanoSmart", 20, 12.50);
    fluffy_the_cat.show();
    fluffy_the_cat.buy(15, 18.125);
    fluffy_the_cat.show();
    fluffy_the_cat.sell(400, 20.00);
    fluffy_the_cat.show();
    fluffy_the_cat.buy(300000, 40.125);
    fluffy_the_cat.show();
    fluffy_the_cat.sell(300000, 0.125);
    fluffy_the_cat.show();
    return 0;
}

```

**程序输出：**

```
Company: NanoSmart    
    Shares: 20        
    Share Price: $12.5
    Totol Worth: $250 
Company: NanoSmart
    Shares: 35
    Share Price: $18.125
    Totol Worth: $634.375
You can't sell more than you have! Transaction is aborted.
Company: NanoSmart
    Shares: 35
    Share Price: $18.125
    Totol Worth: $634.375
Company: NanoSmart
    Shares: 300035
    Share Price: $40.125
    Totol Worth: $1.20389e+07
Company: NanoSmart
    Shares: 35
    Share Price: $0.125
    Totol Worth: $4.375
```

这里，`main()`只是用来测试`Stock`类的设计。当`Stock`类的运行于预期的相同后，便可以在其他程序中将`Stock`类作为用户定义的类型使用。要使用新类型，最关键的是要了解成员函数的功能，而不必考虑其他实现细节。

### 10.2.5 修改实现

上面的程序输出中，有一些数字的表现方式令人不太满意。而`ostream`类提供了一种修改方法，在`cout`对象中添加一个`.precision()`就可以限制输出数字的位数。

比如，对之前写的`show()`函数进行修改：

```cpp

void Stock00::show()
{
    using std::cout;
    using std::ios_base;
    
    // set format to #.###
    ios_base::fmtflags orig = 
        cout.setf(ios_base::fixed, ios_base::floatfield);
    std::streamsize prec = cout.precision(3);
}
```

## 10.3 类的构造函数和析构函数

C++ 的目标之一是让使用类对象就像使用标准类型一样，然而，到现在为止，我们还不能这样做。这是因为之前我们写的数据部分的访问状态时私有的，这意味着程序不能直接访问数据成员。上面的例子中，程序只能通过成员函数来访问数据成员。但如果我们使数据成员成为共有，而不是私有，就可以按刚才介绍的方法初始化类对象，但这样就违背了类的一个初衷：数据隐藏。

由于我们无法用常规的方法对于对象中成员变量进行初始化，那么就要用另外一个特殊的成员函数 -- 类构造函数，将新构造的对象进行自动初始化。

### 10.3.1 声明和定义构造函数

现在需要创建 `Stock`的构造函数。由于需要为`Stock`对象提供 3 个值，因此应为构造函数提供3个参数。那么我们在创建函数原型的时候就可以：

```cpp
Stock(const string & co, long n = 0; double pr = 0.0);
```

那么构造函数的定义就可以为：

```cpp
void Stock00::shock(const std::string &co, long n, double pr)
{
    company = co;
    if (n < 0)
    {
        std::cout << "Number of shares can't be negative; "
                  << company << " shares set to 0. \n";
        shares = 0;
    }
    else
    {
        shares = n;
    }
    share_val = pr;
    set_tot();
}
```

在创建构造函数的时候，我们要避免使用类成员的名称，比如：

```cpp
// DONT DO
Stock::stock(const string & company, long shares, double share_val)
```
这样做会导致混乱。比如：

```cpp
shares = shares
```

### 10.3.2 使用构造函数

C++ 提供了两种方式来使用构造函数：

1. 显式的构造函数

```cpp
Stock food = Stock("world Cabbage", 250, 1.25);
```

2. 隐式的构造函数

```cpp
Stock garment = {"Furry Mason", 50, 2.5};
```

上面两种方式是等价的。

构造函数也可以和`new`一起使用：

```cpp
Stock *pstock = new Stock("Electorshcok Game", 20, 2.3);
```

上面的语句创建了一个`Stock`对象，将其初始化为参数提供的值，并将该对象的地址赋给`pstock`指针。在这种情况下，对象没有名称，但可以使用指针来管理该对象。

### 10.3.3 默认构造函数

默认构造函数时在位提供显式初始值时，用来创建对象的构造函数。也就是说，它时用于下面这种声明的构造函数：

```cpp
Stock fluffy_the_cat;   // use the default constructor
```

但是一般来说，我们会直接在使用默认构造函数的时候，会直接初始化其内部的值。比如:

```cpp
Stock::stock()
{
    company = "no name";
    share = 0;
    share_val = 10;
    total_val = 10;
}
```

### 10.3.4 析构函数

用构造函数创建对象后，程序负责跟踪该对象，知道其过期为止。对象过期时，程序将自动调用一个特殊的成员函数 -- 析构函数。比如，我们用`new`创建了一个构造函数，则需要析构函数使用`delete`来释放这些内容。

使用析构函数时，在的类名称前加上`~`。比如，`stock`类的析构函数是`~stock()`。

什么时候需要用到析构函数呢？这是由编译器来决定的，通常不应再代码中显示的调用析构函数。如果创建的是静态储存类对象，则其析构函数将在程序结束时被自动调用。如果创建的时自动储存对象，则其析构函数将在程序执行完代码块时自动被调用。如果对象时通过`new`创建，则它将留在栈内或自由储存空间，当`delete`时，其析构函数将被自动调用。

由于在类对象过期时析构函数将被自动调用，因此必须有一个析构函数。如果程序员没有提供析构函数，编译器会隐式的声明一个默认析构函数，并在发现导致对象被删除的代码后，提供默认的析构函数的定义。

### 10.3.5 改建 Stock 类

下面将构造函数和析构函数加入到类和方法的定义中。

1. 头文件

这里将之前的`acquire()`函数删除了，用构造函数来代替。

**程序10.4 stock10.h**

```cpp
// stock10.h -- Stock class declaration with constructors, desturctor added
#ifndef STOCK10_H_
#define STOCK!)_H_
#include <string>

class Stock
{
private:
    std::string company;
    long shares;
    double share_val;
    double total_val;
    void set_tot() { total_val = shares * share_val; }

public:
    Stock(/* args */) // default constructor
    Stock(const std::string &co, long n, double pr);
    ~Stock()          // default destructor
    void buy(long num, double price);
    void sell(long num, double price);
    void update(double price);
    void show();
};

#endif
```

2. 实现文件

**程序 10.5 stock10.cpp**

```cpp
// stock10.cpp -- Stock class with constructors, desconstor added
#include <iostream>
#include "stock10.h"

// constructors
Stock::Stock() // default constructor
{
    std::cout << "Default constructor called\n";
    company = "no name";
    shares = 0;
    share_val = 0;
    total_val = 0;
}

Stock::Stock(const std::string & co, long n, double pr)
{
    std::cout << "Constructor using " << co << " called\n";
    company = co;
    if (n < 0)
    {
        std::cout << "Number of shares can't be negative; "
                  << company << " shares set to 0. \n";
        shares = 0;
    }
    else
    {
        shares = n;
    }
    share_val = pr;
    set_tot();
}

Stock::~Stock() 
{
    std::cout << "Bye, " << company << "!\n";
}

// other methods
void Stock::buy(long num, double price)
{
    if (num < 0)
    {
        std::cout << "Number of shares purchased can't be negative. "
                  << "Transaction is aborted.\n";
    }
    else
    {
        shares += num;
        share_val = price;
        set_tot();
    }
}

void Stock::sell(long num, double price)
{
    using std::cout;
    if (num < 0)
    {
        std::cout << "Number of shares sold can't be negative. "
                  << "Transaction is aborted.\n";
    }
    else if (num > shares)
    {
        cout << "You can't sell more than you have! "
             << "Transaction is aborted.\n";
    }
    else
    {
        shares -= num;
        share_val = price;
        set_tot();
    }
}

void Stock::update(double price)
{
    share_val = price;
    set_tot();
}

void Stock::show()
{
    using std::ios_base;
    // set format to #.###pragma region 
    ios_base::fmtflags orig = 
        std::cout.setf(ios_base::fixed, ios_base::floatfield);
    std::streamsize prec = std::cout.precision(3);

    std::cout << "Company: " << company
              << "\n    Shares: " << shares
              << "\n    Share Price: $" << share_val
              << "\n    Totol Worth: $" << total_val << std::endl;
}
```

3. 客户文件

**程序 10.6 usestock2.cpp**

```cpp
// usetock2.cpp -- using the Stock class
// compile with stcok10.cpp
#include <iostream>
#include "stock10.h"

int main(int argc, char const *argv[])
{
    using std::cout;
    cout <<"using constructors to create new objects\n";
    Stock stock1("NanoSmart", 12, 20.0);    // syntax 1
    stock1.show();
    Stock stock2 = Stock ("Boffo Objects", 2, 20);   // syntax 2
    stock2.show();

    cout << "Assigning stock1 to stock 2:\n";
    stock2 = stock1;
    cout << "Listing stock1 and stock2:\n";
    stock1.show();
    stock2.show();

    cout << "Using a constructor to reset an object\n";
    stock1 = Stock("Niftf Foods", 10, 40);  // temp object
    cout << "Revised stock1:\n";
    stock1.show();
    
    return 0;
}
```

**程序输出：**

```
using constructors to create new objects
Constructor using NanoSmart called      
Company: NanoSmart
    Shares: 12
    Share Price: $20.000
    Totol Worth: $240.000
Constructor using Boffo Objects called  
Company: Boffo Objects
    Shares: 2
    Share Price: $20.000
    Totol Worth: $40.000
Assigning stock1 to stock 2:
Listing stock1 and stock2:
Company: NanoSmart
    Shares: 12
    Share Price: $20.000
    Totol Worth: $240.000
Company: NanoSmart
    Shares: 12
    Share Price: $20.000
    Totol Worth: $240.000
Using a constructor to reset an object
Constructor using Niftf Foods called
Bye, Niftf Foods!
Revised stock1:
Company: Niftf Foods
    Shares: 10
    Share Price: $40.000
    Totol Worth: $400.000
Bye, NanoSmart!
Bye, Niftf Foods!
```

**程序说明：**

这里我比较关注的点在于最后析构函数的调用。也就是接近末尾的那个`Bye`语句最后的那两个`Bye`的输出语句。第一次解构函数被调用是在对`stock1`重新赋值时，这时编译器创建了一个临时对象，当赋值完成后，编译器就会自动删除临时变量。而最后的两个删除时因为主函数结束了，在自动变量存放的栈中，后创建的对象被先删除，最先创建的变量最后被删除。程序最后`stock2 = NanSmart` 而 `stock1 = Niftf Foods`， 而创建对象的顺序是`stock1`在前，`stock2`在后。

对于类而言，也可以使用`const`关键词。比如：

```cpp
const Stcok land = Stock("Kludgehorn Proerties");
land.show();
```

向上面的这样的用法，`show()`将无法保证调用对象不被修改，要想达到我们的目的，实际的用法应该如下：

```cpp
void stock::show() const    // promises not to change invoking object
```

以上面的方法声明和定义的类函数被称为`const`成员函数。就像应尽可能将`const`引用和指针作用函数形参一样，只要类方法不修改调用对象，就应将其声明为`const`