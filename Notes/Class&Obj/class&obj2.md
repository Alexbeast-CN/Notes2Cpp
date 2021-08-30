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