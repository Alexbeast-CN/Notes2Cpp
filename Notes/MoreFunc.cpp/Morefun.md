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

## 8.2 引用变量

### 8.2.1 引用变量

<font color = oragne>一个例程：</font>

```cpp
// firstref.cpp -- defining and using reference
# include <iostream>
int main(int argc, char const *argv[])
{
    using namespace std;
    int rats = 101;
    int & rodents = rats;   // rodents is a reference
    cout << "rats = " << rats;
    cout <<", rodents = " << rodents << endl;
    rodents++;
    cout << "rats = " << rats;
    cout <<", rodents = " << rodents << endl;

    // some implementation require type casting the following
    // addressed to type unsigned
    cout << "rats address = " << &rats;
    cout << ", rodents address = " << &rodents <<endl;
    return 0;
}
```

<font color = oragne>输出结果：</font>

```
rats = 101, rodents = 101
rats = 102, rodents = 102
rats address = 0x61fe14, rodents address = 0x61fe14
```

<font color = oragne>程序说明：</font>

1. 下面语句中的`&`运算符不是地址运算符，而是将`rodents`的类型声明为`int&`，即指向`int`变量的引用：

```cpp
int & rodents = rats;
```

2. 但是下面语句中的`&`运算符是地址运算符，其中`&rodents`表示`rodents`引用的变量的地址：

```cpp
cout << ", rodents address = " << &rodents <<endl;
```

3. 从上面的程序可知，`rats`和`rodents`的值和地址都相同。将`rodents`加一会影响到这两个变量。但这并没有说明引用的经典用途，即作为函数参数，具体地说是结构和对象参数。

<font color = oragne>另一个例程：</font>

```cpp
// sceref.cpp -- defining and using a reference

#include <iostream>
int main(int argc, char const *argv[])
{
    using namespace std;
    int rats = 101;
    int &rodents = rats; // rodents is a reference
    cout << "rats = " << rats;
    cout << ", rodents = " << rodents << endl;

    cout << "rats address = " << &rats;
    cout << ", rodents address = " << &rodents << endl;

    int bunnies = 50;
    rodents = bunnies;
    cout << "bunnies = " << bunnies;
    cout << ", rats = " << rats;
    cout << ", rodents = " << rodents << endl;

    cout << "bunnies address is " << &bunnies << endl;
    
    cout << "rats address is " << &rats << endl;
    
    cout << "rodents address is " << &rodents << endl;

    return 0;
}
```

<font color = oragne>输出结果：</font>

```
rats = 101, rodents = 101
rats address = 0x61fe14, rodents address = 0x61fe14
bunnies = 50, rats = 50, rodents = 50
bunnies address is 0x61fe10
rats address is 0x61fe14
rodents address is 0x61fe14
```

<font color = oragne>程序说明：</font>

从上面的程序可以看出，`rodents`完全扮演的就是`rats`的别名，当利用`rodents = rats`时，`rats`的值确实发生了改变，但是他们依然公用同一个地址。

### 8.2.2 将引用做函数参数

利用一个数据交换的例程来演示，利用引用来做函数的参数：

<font color = oragne>例程：</font>

```cpp
// swaps.cpp -- swapping with references and pointers
#include <iostream>
void swapr(int & a, int & b)    // a, b aliases for ints
{
    int temp;

    temp = a;   // use a, b for values of variables
    a = b;
    b = temp;
}

void swapp(int *p, int *q)      // p, q are addresses of ints
{
    int temp;

    temp = *p;  // use *p and *q for values of variables
    *p = *q;
    *q = temp;
}

void swapv(int a, int b)        // a, b are new variables
{
    int temp;

    temp = a;   // use a and b for values of varibales
    a = b;
    b = temp;
}

int main(int argc, char const *argv[])
{
    using namespace std;
    int wallet1 = 300;
    int wallet2 = 250;
    cout << "wallet1 = $" << wallet1;
    cout << " wallet2 = $" << wallet2 << endl;

    cout << "Using references to swap contents:\n";
    swapr(wallet1, wallet2);    // pass variables
    cout << "wallet1 = $" << wallet1;
    cout << " wallet2 = $" << wallet2 << endl;

    cout << "Using pointer to swap contents:\n";
    swapp(&wallet1, &wallet2);    // pass variables
    cout << "wallet1 = $" << wallet1;
    cout << " wallet2 = $" << wallet2 << endl;

    cout << "Tring to use passing by vlaue:\n";
    swapv(wallet1, wallet2);    // pass variables
    cout << "wallet1 = $" << wallet1;
    cout << " wallet2 = $" << wallet2 << endl;  
    return 0;
}
```

<font color = oragne>输出结果：</font>

```cpp
wallet1 = $300 wallet2 = $250
Using references to swap contents:
wallet1 = $250 wallet2 = $300
Using pointer to swap contents:
wallet1 = $300 wallet2 = $250
Tring to use passing by vlaue:
wallet1 = $300 wallet2 = $250
```

<font color = oragne>程序说明：</font>

首先用引用和指针的方式都成功交换了数据，但是值的方法失败了，它也本该如此。

从上面的程序中，你多少可以感受到一些引用带来的便捷之处。

### 8.2.3 引用的属性和特别之处

依然用例程来展示：

<font color = oragne>例程：</font>

```cpp
// cubes.cpp -- regular and reference arguemnts
#include <iostream>
double cube(double a)
{
    a *= a * a;
    return a;
}

double refcube(double &ra)
{
    ra *= ra * ra;
    return ra;
}

int main(int argc, char const *argv[])
{
    using namespace std;
    double x = 3.0;

    cout << cube(x);
    cout << " = cube of " << x << endl;
    cout << refcube(x);
    cout << " = cube of " << x << endl;

    return 0;
}
```

<font color = oragne>输出结果：</font>

```
27 = cube of 3
27 = cube of 27
```

<font color = oragne>程序说明：</font>

从结果可以看出`refcube()`中修改了`main()`中的`x`值，但是`cube()`中没有，这提醒我们为何通常要按值传递。如果我们不希望`x`的值被修改，可以把这样定义：

```cpp
refcube(const double &ra)
```

这样定义时，如果`ra`的值发生了变化，编译器就会报错。

并且因为引用的特性，在传递参数的时候，如果使用的是表达式，就不太合理，因为表达式不是一个变量。比如：

```cpp
double z = refcube (x + 3.0);    
```

但其实，像上面那样的句子其实是可以正常编译的，编译的过程中，编译器将一个无名变量赋值给了`ra`。下面我们将讨论这种临时变量应该什么时候使用：

首先我们来看一下，什么时候会创建一个临时变量呢？

* 实参的类型正确，但不是左值；
* 实参的类型不正确，但是可以转换成正确的类型。

左值是什么呢？左值参数是可以被引用的数据参数，比如，变量、数组元素、结构元素、引用和接触引用的指针都是左值。非左值包括字面常量和包含多项式的表达式。现在回到前面的示例：

```cpp
double refcube (const double &ra)
{
    return ra*ra*ra;
}
```

然后考虑下面的代码：

```cpp
double side = 3.0;
double * pd = &side;
double & rd = side;
long egde = 5L;
double lens[4] = {2.0, 5.0, 10.0, 12.0};

double c1 = refcube(side);      // ra is side
double c2 = refcube(lens[2]);   // ra is lens[2]
double c3 = refcube(rd);        // ra is rd is side
double c4 = refcube(*pd);       // ra is *pd is side
double c5 = refcube(edge);      // ra is temporary variable
double c6 = refcube(7.0);       // ra is temporary varible
double c7 = refcube(side + 1);  // ra is temporary varible
```

当编译器产生临时变量时，函数调用期间会存在，调用后就被删除。

### 8.2.4 将引用用于结构

还是用例子来说明：

<font color = oragne>例程：</font>

```cpp
// strctref.cpp -- using structure references
#include <iostream>
#include <string>
struct free_throws
{
    std::string name;
    int made;
    int attempts;
    float percent;
};

void display(const free_throws & ft)
{
    using std::cout;
    cout << "Name: " << ft.name << "\n";
    cout << "Made: " << ft.made << "\t";
    cout << "Attempts: " << ft.attempts << "\t";
    cout << "Percent: " << ft.percent << "\n";
}

void set_pc(free_throws & ft)
{
    if (ft.attempts != 0)
        ft.percent = 100.0*float(ft.made)/float(ft.attempts);
    else   
        ft.percent = 0;
}

free_throws & accumulate(free_throws & target, const free_throws & source)
{
    target.attempts += source.attempts;
    target.made += source.made;
    set_pc(target);
    return target;
}

int main(int argc, char const *argv[])
{
    // partial initializations -- remaining members set to 0
    free_throws one = {"Ifelsa Branch", 13, 14};
    free_throws two = {"Andor Knott", 10, 16};
    free_throws three = {"Minnie Max", 7, 9};
    free_throws four = {"Whily Looper", 5, 9};
    free_throws five = {"Long Long", 6, 14};
    free_throws team = {"Throwgoods", 0 ,0};

    // no initialization
    free_throws dup;

    set_pc(one);
    display(one);
    accumulate(team, one);
    display(team);

    // use return value as argument
    display(accumulate(team,two));
    accumulate(accumulate(team,three),four);
    display(team);

    // use return value in assigment
    dup = accumulate(team,five);
    std::cout << "Displaying team:\n";
    display(team);
    std::cout << "Displaying dup after assignment:\n";
    display(dup);
    set_pc(four);

    // ill-advised assigment
    accumulate(dup,five) = four;
    std::cout << "Displaying dup after ill-advised assignment:\n";
    display(dup);   
    return 0;
}
```

<font color = oragne>输出结果：</font>

```
Name: Ifelsa Branch
Made: 13        Attempts: 14    Percent: 92.8571
Name: Throwgoods
Made: 13        Attempts: 14    Percent: 92.8571
Name: Throwgoods
Made: 23        Attempts: 30    Percent: 76.6667
Name: Throwgoods
Made: 35        Attempts: 48    Percent: 72.9167
Displaying team:
Name: Throwgoods
Made: 41        Attempts: 62    Percent: 66.129
Displaying dup after assignment:
Name: Throwgoods
Made: 41        Attempts: 62    Percent: 66.129
Displaying dup after ill-advised assignment:
Name: Whily Looper
Made: 5 Attempts: 9     Percent: 55.5556
```