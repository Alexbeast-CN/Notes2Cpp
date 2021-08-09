# 第八章 函数探幽

## 8.1 C++ 内联函数

内联函数可以提高程序的运行速度。由于编译后的程序，不同的函数被储存在了不同的堆栈中，系统逐行执行程序遇到调用函数的时候需要跳到另外一个内存块，来回的跳跃导致系统效率较低。但是内联函数将函数与其他函数内联，因此不用再调用函数，就可以执行，因而提高了程序运行的效率。但程序的内存需求将比原来增加。

使用此特性，必须采取以下措施之一：

* 在函数声明前面加上关键字`inline`；
* 在函数定义前面加上关键字`inline`。

通常的做法是省略原型，将整个定义（即函数头和所有函数代码）放在本应该提供原型的地方。对此种行为，编译器将不再提供递归。

下面展示一个例程：

```cpp
// inline.cpp -- using an inline function
#include <iostream>

// an inline function definition
inline double square(double x) 
{
    return x*x;
}

int main(int argc, char const *argv[])
{
    using namespace std;
    double a, b;
    double c = 13.0;

    a = square(5.0);
    b = square(3.5 + 7.5);  // it can pass expressions
    cout << "a = " << a << ", b = " << b << endl;
    cout << "c = " << c;
    cout << ", c square is " << square(c++) << endl;
    cout << "Now c = " << c << endl;
    return 0;
}
```

out:

```
a = 25, b = 121
c = 13, c square is 169
Now c = 14
```


