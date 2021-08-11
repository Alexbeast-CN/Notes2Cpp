# 第八章 函数探幽 （上）

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
    std::string name;   // 名字
    int made;           // 成功的次数
    int attempts;       // 尝试的次数
    float percent;      // 命中率
};

// 显示队伍中的每项指标
void display(const free_throws & ft)
{
    using std::cout;
    cout << "Name: " << ft.name << "\n";
    cout << "Made: " << ft.made << "\t";
    cout << "Attempts: " << ft.attempts << "\t";
    cout << "Percent: " << ft.percent << "\n";
}

// 计算命中率
void set_pc(free_throws & ft)
{
    if (ft.attempts != 0)
        ft.percent = 100.0*float(ft.made)/float(ft.attempts);
    else   
        ft.percent = 0;
}

// 累计
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
    // 设置了部分结构成分的初始化，命中率初始化为0
    free_throws one = {"Ifelsa Branch", 13, 14};
    free_throws two = {"Andor Knott", 10, 16};
    free_throws three = {"Minnie Max", 7, 9};
    free_throws four = {"Whily Looper", 5, 9};
    free_throws five = {"Long Long", 6, 14};
    free_throws team = {"Throwgoods", 0 ,0};

    // no initialization
    // 没有对dup进行初始化
    free_throws dup;

    // 计算队员1 的命中率
    set_pc(one);
    // 显示队员1 的各项指标
    display(one);
    // 将队员1 的指标添加到整个队伍
    accumulate(team, one);
    // 显示整个队伍的各项指标
    display(team);

    // use return value as argument
    // 将队员2 的指标添加到队伍并展示
    display(accumulate(team,two));
    // 将队员3 和 4 的指标添加到队伍
    accumulate(accumulate(team,three),four);
    // 显示整个队伍的各项指标
    display(team);

    // use return value in assigment
    // accumulate 的返回值是一个结构，因此dup 接收了整个队伍的结构数据
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

<font color = oragne>讨论：</font>

1. 为何要返回引用

我们来看一下上面程序中的一个语句：

```cpp
dup = accumulate(team, five);
```

我们知道`acuumulate()`返回的是一个指向结构的引用，这相当于在使用的过程中直接把`team`赋值到`dup`。假如我们使用的返回值是结构，那么我们需要将结构赋值到一个临时的位置，再将其赋值给`dup`。

2. 返回引用时需要注意的问题

返回引用时最重要的一点是，应该避免返回函数终止时不再存在内存单元引用。我们应该避免编写下面的代码：

```cpp
const free_throw & conle2(free_throws & ft)
{
    free_throw newguy;  // first step to big error
    newguy = ft;        // copy info
    return newguy;      // return reference to copy
}
```

该函数返回一个指向临时变量`newguy`的引用，但是再函数运行完毕后它将不复存在。为了避免这样的现象，可以使用`new`为字符串分配内存空间，并返回指向该内存空间的指针。例如：

```cpp
const free_throws & clone (feee_thorws & ft)
{
    free_throws * pt;
    pt* = ft;       // copy info
    return *pt;     // return reference to copy
}
```

第一个语句创建了一个无名的`free_throws`结构，并让指针`pt`指向该结构，因此`*pt`就是该结构。上述代码似乎会返回该结构，但是函数声明表明，该函数实际上将返回这个结构的引用。因此，便可以这样使用该函数：

```cpp
free_throws & jolly = clone(three);
```

这使得`jolly`称为了新结构的引用。这种方法存在一个问题：再不需要使用`new`分配的内存的时候，应该使用`delete`来释放它们。调用`clone()`隐藏了对`new`的嗲用，这使得以后会容易忘记使用`delete`来释放内存。

3. 为何将`const`用于引用返回类型

首先来看一下下面的语句：

```cpp
accumulate(dup,five) = four;
```

语句的效果是：先用`five`的数据添加到`dup`中，再使用`four`的内容覆盖`dup`的内容。这是一个很奇怪的语句，但为什么这样的语句可以编译通过呢？在赋值语句中，左边必须是可以修改的佐值。也就是说，在赋值表达式中，左边的子表达式必须标识一个可修改的内存块。在这里函数返回指向`dup`的引用，因此它确实是一个这样的内存块，因此这条语句是合法的。但如果是常规（非引用）返回类型是右值，不能通过地址访问的值。这样的表达式就只能存在于赋值语句的右边，比如，字面值（10.0）和表达式（x + y ）。

但是如果我们将`accumulate()`定义前面加一个`const`限制符，则函数将不能再被这样使用。

### 8.2.5 将引用用于类对象

通常，我们使用引用的方式，让函数将类（string, ostream, istream, ofstream, 和 ifstream）等类的对象作为参数。

下面我们来看一个例程，例程中有些设计方案是糟糕的，甚至存在非常大的缺陷。

```cpp
// struote.cpp -- different designs
#include <iostream>
#include <string>
using namespace std;
string version1(const string & s1, const string & s2)
{
    string temp;
    temp = s2 + s1 +s2;
    return temp;
}

const string & version2 (string & s1, const string & s2)    // has side effect
{
    s1 = s2 + s1 + s2;
    // safe to return reference passed to function
    return s1;
}
/*
const string & version3(string &s1, const string & s2)
{
    string temp;

    temp = s2 + s1 + s2;
    // unsafe to return reference to local variable
    return temp;
}
*/
int main(int argc, char *argv[])
{
    string input;
    string copy;
    string result;

    cout << "Enter a string: ";
    getline(cin,input);
    copy = input;
    cout << "Your string as entered: " << input << endl;
    result = version1(input, "***");
    cout << "Your string enhanced: " << result << endl;
    cout << "Your orignal string: " << input << endl;

    result = version2(input,"###");
    cout << "Your string enhanced: " << result << endl;
    cout << "Your orignal string: " << input << endl;

/*
    cout << "Resetting original string.\n";
    input = copy;
    result = version3(input,"@@@");
    cout << "Your string enhanced: " << result << endl;
    cout << "Your orignal string: " << input << endl;
*/
    return 0;
}
```

将注释打开会导致报错：

```
.\strquote.cpp: In function 'const string& version3(std::__cxx11::string&, const string&)':
.\strquote.cpp:21:12: warning: reference to local variable 'temp' returned [-Wreturn-local-addr]
     string temp;
            ^~~~
```
这时说我们将一个本地的变量返回了。

加上注释后，的程序结果是：

```
Enter a string: FALSE    
Your string as entered: FALSE
Your string enhanced: ***FALSE***
Your orignal string: FALSE
Your string enhanced: ###FALSE###
Your orignal string: ###FALSE###
```

<font color = oragne>程序说明：</font>

我们直接来解释为什么`version3`会无法通过编译。因为`version3`返回的是一个指向声明变量的一个引用。但是当这个函数运行完成后，其`temp`变量的内存就被删除掉了，无法用这样的方式进行编译。

### 8.2.6 对象、继承和引用

书上说了一大堆，我也没有看懂是啥意思，这里还是直接放例程吧。。。

<font color = oragne>例程：</font>

```cpp
// filefunc.cpp -- function with ostream & parameter

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

void file_it(ostream & os, double fo, const double fe[], int n)
{
    ios_base::fmtflags initial;
    initial = os.setf(ios_base::fixed); // save initial formatting state
    os.precision(0);
    os << "Focal length of objective: " << fo << " mm\n";
    os.setf(ios::showpoint);
    os.precision(1);
    os.width(12);
    os << "f.l. eyepiece";
    os.width(15);
    os << "magnification" << endl;
    for (int i = 0; i < n; i++)
    {
        os.width(12);
        os << fe[i];
        os.width(15);
        os << int (fo/fe[i] + 0.5) <<endl;
    }
    os.setf(initial);   // restore initial formatting state
}
const int LIMIT = 5;
int main(int argc, char const *argv[])
{
    ofstream fout;
    const char * fn = "ep - data.txt";
    fout.open(fn);
    if(!fout.is_open())
    {
        cout << "Can't open" << fn << ". Bye. \n";
        exit(EXIT_FAILURE);
    }
    double objective;
    cout << "Enter the fical length of your "
        << "telescope objective in mm: ";
    cin >> objective;
    double eps[LIMIT];
    cout << "Enter the focal lengths, in mm, of " << LIMIT
        << "eyepieces: \n";
    for(int i = 0; i < LIMIT; i++)
    {
       cout << "Eyepiece #" << i + 1 << ": ";
       cin >> eps[i]; 
    }
    file_it(fout, objective, eps, LIMIT);
    file_it(cout, objective, eps, LIMIT);
    cout << "Done\n";
    return 0;
}
```

<font color = oragne>输出结果：</font>

```
Enter the focal lengths, in mm, of 5eyepieces: 
Eyepiece #1: 30
Eyepiece #2: 19
Eyepiece #3: 14
Eyepiece #4: 8.8
Eyepiece #5: 7.5
Focal length of objective: 1800 mm
f.l. eyepiece  magnification      
        30.0             60       
        19.0             95       
        14.0            129       
         8.8            205       
         7.5            240       
Done
```

<font color = oragne>程序说明：</font>

对于该程序，最重要的一点是，参数`os`（其类型是`ostream &`）可以指向`ostream`对象（如cout），也可以指向`ofstream`对象（fout）。该程序还演示了如何使用`ostream`类中的格式化方法。方法`setf()`让您能够设置各种格式化的状态。例如，方式调用`setf(ios_base::fixed)`将对象置于使用定点表示法的模式；`setf(ios_base::showpoint)`将对象置于显示小数点的模式，即使小数部分为零。方法`precision()`指定了显示多少位小数（假定对象处于定点模式下）。所有这些设置都将一直保持不变，直到再次调用响应的方法重新设置它们。方法`width()`设置下一次输出操作使用的字段宽度，这种设置只在显示下一个值时有效，然后将恢复到默认设置。默认的字段宽度都为零，这意味刚好能够容纳下要显示的内容。

函数`file_it()`使用了两个有趣的方法调用：

```cpp
ios_base::fmtflags initial;
initial = os.setf(ios_base::fixed);  // save initial formatting state
...
os.setf(initial); 
```

方法`setf()`返回调用它之前有效的所有格式化设置。`ios_base::fmtflages`是存储这种信息所需的数据类型名称。因此，将返回值赋值给`initial`将存储调用`file_it()`之前的格式化设置，然后便可以使用变量`initial`作为参数来调用`setf()`，将所有的格式化设置恢复到原来的值。因此，该函数将对象反倒传递给`file_it()`之前的状态。

需要说明的最后一点是，每一个对象都储存了字节的格式化设置。因此，当程序将`cout`传递给`file_it()`的时候`cout`的设置将被修改，然后被回复；当程序将`fout`传递给`file_it()`时，`fout`的设置将被修改，然后被回复。

### 8.2.7 何时使用引用参数

使用引用参数的主要原因有两个：
* 程序员能够修改调用函数中的数据对象。
* 通过传递引用而不是整个数据对象，可以提高程序的运行速度。

当数据对象比较大的时候（如结构和类对象），第二个原因更加重要。这些也是使用指针参数的原因。至于什么时候使用指针？什么时候使用引用？什么时候按值传递呢？下面有一些指导：

对于使用传递的值而不作修改的函数。
* 如果数据对象很小，如内置数据类型或小型结构，则按值传递。
* 如果数据对象时数组，则使用指针，因为这是唯一的选择，并将指针声明为指向`const`的指针。
* 如果数据对象是较大的结构，则使用`const`指针或`const`引用，以提高程序的效率。这样可以节省赋值结构所需要的时间和空间。
* 如果数据对象是类对象，则使用`const`引用。类设计的语义常常要求使用引用。

对于修改调用函数中的数据的函数:
* 如果数据对象是内置数据类型，则使用指针。如果看到如：`fixit(&x)`这样的代码（其中`x`是`int`），则很明显，该函数将修改`x`。
* 如果数据对象是数组，则只能使用指针。
* 如果数据对象是结构，则使用引用或指针。
* 如果数据对象是类对象，则使用引用。


