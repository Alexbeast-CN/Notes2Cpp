#! https://zhuanlan.zhihu.com/p/405577812
# C++ 学习笔记 -- 17

# 第十章 对象和类（中）

## 10.4 this 指针

到目前为止，每个类成员函数都只涉及一个对象，即调用它的对象。但有时候方法可能设计到多个对象，这是就需要使用`this`指针。依然以之前的股票模型为例。我们可以使用`show()`来输出手中持有股票价格最高的股票，但是由于程序无法直接访问`total_val()`，因此无法作出判断。要让程序知道储存的数据，最直接的方法是让方法返回一个值。比如：

```cpp
class Stock
{
    private:
    ...
    double total_val;
    ...
    public:
    double total() const {return total_val;}
    ...
};
```

这样我们可以查看到这个对象的总价值，但是如果我们要比较两个对象的股价，用这样的方法会有点麻烦。下面将介绍使用`this`指针来完成这样的操作。

**程序 10.7 stock20.h**

```cpp
// stock20.h -- augmented version
#ifndef STOCK20_H_
#define STOCK20_H_
#include <string>

class Stock
{
private:
    std::string company;
    int shares;
    double share_val;
    double total_val;
    void set_tot() { total_val = shares * share_val; }

public:
    Stock(/* args */);
    Stock(const std::string &co, long n = 0, double pr = 0.0);
    ~Stock();
    void buy(long num, double price);
    void sell(long num, double price);
    void update(double prive);
    void show() const;
    const Stock &topval(const Stock &s) const;
};
#endif
```

**程序 10.8 stock20.cpp**

```cpp
// stock20.cpp -- augmented version
#include <iostream>
#include "stock20.h"

// constructors
Stock::Stock()
{
    company = "no name";
    shares = 0;
    share_val = 0.0;
    total_val = 0.0;
}

Stock::Stock(const std::string &co, long n, double pr)
{
    company = co;
    if (n < 0)
    {
        std::cout << "Number os shares can't be negative;"
                  << company << " shares set to 0.\n";
        shares = 0;
    }
    else
        shares = n;
    share_val = pr;
    set_tot();
}

// class destructor
Stock::~Stock() {}

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

    if (num < 0)
    {
        std::cout << "Number of shares sold can't be negative. "
                  << "Transaction is aborted.\n";
    }
    else if (num > shares)
    {
        std::cout << "You can't sell more than you have . "
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

void Stock::show() const
{
    using std::cout;
    using std::ios_base;

    // set format to #.###
    ios_base::fmtflags orig =
        cout.setf(ios_base::fixed, ios_base::floatfield);
    std::streamsize prec = cout.precision(3);

    cout << "Company: " << company
         << "\n Shares: " << shares
         << "\n Share Price: $" << share_val;
    // set format to #.##
    cout.precision(2);
    cout << "\n Total Worth: $" << total_val << '\n';

    // restore original format
    cout.setf(orig, ios_base::floatfield);
    cout.precision(prec);
}

const Stock &Stock::topval(const Stock &s) const
{
    if (s.total_val > total_val)
        return s;
    else
        return *this;
}
```

为了验证`this`指针是否有用，我们需要再一个包含对象数组的程序中使用着用新方法。

## 10.5 对象数组

像变量一样，对象也可以创建一个数组。声明方法与之前的标准数组一样。

```cpp
Stock mystuff[4];   // creates an array of 4 Stock objects
```

下面用程序来做演示：

**程序 10.9 usestock2.cpp**

```cpp
// usestock2.cpp -- useing the stock class
// compile with stock20.cpp
#include <iostream>
#include "stock20.h"

const int STKS = 4;

int main(int argc, char const *argv[])
{
    // create an array of initialized objects
    Stock stocks[STKS] =
        {
            Stock("NanoSmart", 12, 20.0),
            Stock("Boffo Objects", 200, 2.0),
            Stock("Monolithic Obelisks", 130, 3.25),
            Stock("Fleep Enterprises", 60, 3.5)};

    std::cout << "Stock holdings:\n";
    int st;
    for (st = 0; st < STKS; st++)
        stocks[st].show();
    // set pointer to first element
    const Stock *top = &stocks[0];
    for (st = 1; st < STKS; st++)
        top = &top->topval(stocks[st]);
    // now top points to the most valuable holding
    std::cout << "\nMost valueable holding: \n";
    top->show();

    return 0;
}

```

**程序输出：**

```
Company: NanoSmart    
 Shares: 12
 Share Price: $20.000 
 Total Worth: $240.00 
Company: Boffo Objects
 Shares: 200
 Share Price: $2.000  
 Total Worth: $400.00 
Company: Monolithic Obelisks
 Shares: 130
 Share Price: $3.250
 Total Worth: $422.50
Company: Fleep Enterprises
 Shares: 60
 Share Price: $3.500
 Total Worth: $210.00

Most valueable holding:
Company: Monolithic Obelisks
 Shares: 130
 Share Price: $3.250
 ```

 **程序说明：**

 在上面的函数中，对象数组的概念比较简单，这里就不加说明了。重点来讲一下`this`指针。`this`指针出现在程序`stock20.cpp`中的`topval()`函数中

 ```cpp
 const Stock &Stock::topval(const Stock &s) const
{
    if (s.total_val > total_val)
        return s;
    else
        return *this;
}
```

这个函数的定义中，返回值是`Stock`类的地址，参数是一个`Stock`类对象的引用。而最后的返回值`*this`是调用`topval()`函数的这个对象的地址。

## 10.6 类作用域

在类中定义名称（如类数据成员名和类成员函数名）的作用域都是整个类，作用域为整个类的名称旨在该类中是已知的，在类外是不可知的。

### 10.6.1 作用域为类的常量

有时候，是符号常用的作用域为类很有用。例如，类声明可能使用字面值 12 来定义数组的长度，由于该常量对于所有对象来说都是相同的，因此创建一个由所有对象共享的常量是一个不错的主义。于是进行了下列的操作：

```cpp

class Bakery
{
    private:
        const int Months = 12;      // declare a constant? FAILS
        double cost [Months];
        ...
}

```

但是这样是行不通的，因为声明类只是描述了对象的形式，并没有创建对象。因此，在创建对象前，将没有用于储存值的空间。然而，有两种方式可以实现这个目标，兵器效果相同。

第一种是在类中声明一个枚举。在类声明中声明的枚举的作用域为整个类，因此可以用枚举为整型常量提供作用域为整个类的符号名称。即进行下面的代码操作：

```cpp
class Bakery
{
    private:
        enum {Month = 12};
        double cost [Months];
        ...
}

上面枚举不对创建类数据成员，对于这个类而言，`Months`只是一个符号名称，在作用域为整个类的代码中遇到它，编译器将用30来替换他。

另外一种方式在类中定义常量是使用`static`关键词：

```cpp

class Bakery
{
    private:
    static const int Month = 12;
    double cost [Month];
}
```

这里创建了一个名为 `Month`的常量，该常量将与其他静态常量储存在一起，而不是储存在对象中。因此只有一个`Month`常量，被所有的对象共享。

### 10.6.2 作用域内枚举

使用传统的枚举方法如：

```cpp

enum egg{Small, Medium, Large, Jumbo};
enum t_shirt{Small, Medium, Large, Jumbo};

```

上面的这段代码，编译器将无法通过，因为`egg Small`和`t_shirt Small`位于相同的作用域内，它们将发生冲突。为了避免这样的问题，我们应该使枚举量的作用域为类。

```cpp
enum class egg{Small, Medium, Large, Jumbo};
enum class t_shirt{Small, Medium, Large, Jumbo};
```

这样，我们就可以使用作用域解析符(::) 来分别访问枚举量了：

```cpp
egg choice = egg::Large;
t_shirt choice = t_shirt::Large;
```

## 10.7 抽象数据类型

之前我们介绍的类是一个非常具体的概念，但程序员通常需要定义更为通用的概念，也就我们所说的抽象数据类型(Abstract Data Type, ADT)。 

对于 C++ 的程序员而言，使用栈 (Stack) 来管理自动变量。栈的特性是：

* 可创建空栈；
* 可将数据项添加到栈顶（压入）；
* 可从栈顶删除数据项（弹出）；
* 可查看栈时候填满；
* 可以查看是否为空。

上面所描述的栈的特性，可以转换为一个类的声明，其中共有成员函数提供了表示栈操作的接口，而私有数据成员负责储存栈数据。下面使用程序来演示栈的实现：

**程序 10.10 stack.h**

```cpp
// satck.h -- class definition for the stack ADT
#ifndef STACK_H_
#define STACK_H_

typedef unsigned long Item; // use Item to represent unsigned long

class Stack
{
private:
    enum{ MAX = 10};              // constant specific to class
    Item items[MAX]; // holds stack items
    int top;        // index for top stack item

public:
    Stack();
    bool isempty() const;
    bool isfull() const;
    // push() returns false if stakc already is full, true otherwise
    bool push(const Item &item); // add item to stack
    // pop() returns false if stack already is empty, true otherwise
    bool pop(Item &item); // pop top into item
};

#endif
```

接下来是实现类的方法：

**程序 10.11 stack.cpp**

```cpp

// stack.cpp -- Stack member functions

#include "stack.h"
Stack::Stack() // create an empty stack
{
    top = 0;
}

bool Stack::isempty() const
{
    return top == 0;
}

bool Stack::isfull() const
{
    return top == MAX;
}

bool Stack::push(const Item &item)
{
    if (top < MAX)
    {
        items[top++] = item;
        return true;
    }

    else
        return false;
}

bool Stack::pop(Item &item)
{
    if (top > 0)
    {
        item = items[--top];
        return true;
    }
    else
        return false;
}

```

接下来测试一下刚刚创建的栈：

**程序 10.12 stacker.cpp**

```cpp
// stacker.cpp -- testing the Stack class
#include <iostream>
#include "stack.h"
#include <cctype> // or ctype.h

int main(int argc, char const *argv[])
{

    using namespace std;
    Stack st; // create an empty stack
    char ch;
    unsigned long po;
    cout << "Please enter A to add a purchase order,\n"
         << "P to process a PO, or Q to quit.\n";
    while (cin >> ch && toupper(ch) != 'Q')     // 当 cin 输入的值正确，并且不是Q的时候
    {
        while (cin.get() != '\n')               // 处理换行符
        {
            continue;
        }
        if (!isalpha(ch))                       // 判断字符是否为英文字母，如果是则返回0
        {
            cout << "\a";
            continue;
        }
        switch (ch)
        {
        case 'A':
        case 'a':
        {
            cout << "Enter a PO number to add:";
            cin >> po;
            if (st.isfull())
                cout << "stack already full\n";
            else
                st.push(po);
            break;
        }
        case 'p':
        case 'P':
        {
            if (st.isempty())
                cout << "stack already empty\n";
            else
            {
                st.pop(po);
                cout << "PO #" << po << "poped\n";
            }
            break;
        }
        }
        cout << "Please enter A to add a purchase order,\n"
             << "P to process a PO, or Q to quit.\n";
    }
    cout << "Bye\n";
    return 0;
}
```

**程序输出：**

```cpp
Please enter A to add a purchase order,
P to process a PO, or Q to quit.       
a
Enter a PO number to add:119922
Please enter A to add a purchase order,
P to process a PO, or Q to quit.
p
PO #119922poped
Please enter A to add a purchase order,
P to process a PO, or Q to quit.
a
Enter a PO number to add:112233
Please enter A to add a purchase order,
P to process a PO, or Q to quit.
a
Enter a PO number to add:445566
Please enter A to add a purchase order,
P to process a PO, or Q to quit.
p
PO #445566poped
Please enter A to add a purchase order,
P to process a PO, or Q to quit.
p
PO #112233poped
Please enter A to add a purchase order,
P to process a PO, or Q to quit.
p
stack already empty
Please enter A to add a purchase order,
P to process a PO, or Q to quit.
q
Bye
```

**程序说明：**

上面的一段程序让作为菜鸡的感到十分的佩服。下面我来试着对其分析一波。这里惊叹的点是，上面的程序巧妙的使用了 bool值作为返回量，在主函数的设计中，不断的使用布尔值来判断完成层层的判断。其逻辑为，首先判断是否输入了字符，然后判断是否字符不为Q。再然后判断输入的字符是否是英文字符。如果都满足条件，则进入`case`对情况进行判断，如果输入的是`A/a`则调用`isfull()`和`push()`。如果是`P/p`则调用`isempty()`和`pop()`。在这其中，由包含了利用布尔值进行的逻辑判断。层层的判断，使得函数的逻辑完整。

