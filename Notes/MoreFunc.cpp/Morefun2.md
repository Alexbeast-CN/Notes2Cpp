## 8.3 默认参数

默认参数是指当函数调用中省略了实参时，自动使用的一个值。例如，如果将`void wow(int n)`设置成`n`有默认值为`1`，则函数调用`wow()`相当于`wow(1)`。这极大地提高了使用函数的灵活性。假如有一个名为`left()`的函数，他将字符串和`n`作为参数，并返回字符串前的`n`个字符。更准确的说时返回一个指针，该指针指向由原始字符串中被选中的部分组成的字符串。例如，函数调用`left(theory,3)`将创建一个新字符串`the`，并返回一个指向该字符串的指针。现在假设第二个函数的默认值被设置为1，则函数调用`left("theory",3)`仍然像阡陌讲诉那样工作，3将覆盖掉默认的值，但如果调用的时候输入`left("theory")`也不会报错。

那么如何设置默认值呢？这需要通过函数原型。例如：

```cpp
char * left(const char * str, int n = 1 )
```

此时我们就已经将函数的参数n的默认值设置为1了。另外，带有参数列表的函数，必须从右向左的添加默认值，比如：

```cpp
int harpo(int n, int m = 4, int j = 5);     // VALID
int chico(int n, int m = 4, int j);     // INVALID
int groucho(int n = 1, int m = 4, int j = 5);     // VALID
```

在调用类似`harpo()`函数的时候，就可以为这样的函数提供1个，2个或3个参数

```cpp
beeps = harpo(2);   // same as harpo(2,4,5)
beeps = harpo(1,8);   // same as harpo(1,8,5)
beeps = harpo(1,3,2);   
```

看来上面的调用后，你应该能理解一些，为什么必须从右向左添加默认值了，否则会出现：

```cpp
beeps = harpo(2, , 3);  // INIVALID
```

下面我们来看一个例程：

```cpp
// left.cpp -- string function with a default argument

#include <iostream>

const int ArSize = 80;

// This function returns a pointer to a new string
// consisting of the first n characters in the str string.
char * left (const char * str, int n = 1)
{
    if(n<0)
        n = 0;
    char * p = new char[n + 1];
    int i;
    for (i = 0; i < n && str[i]; i++)
        p[i] = str[i];  //copy characters
    while (i<=n)
        p[i++] = '\n';  // set rest of string to '\0'
    return p;
}

int main(int argc, char const *argv[])
{
    using namespace std;
    char sample[ArSize];
    cout << "Enter a string:\n";
    cin.get(sample,ArSize);
    char *ps = left(sample,4);
    cout << ps << endl;
    delete [] ps;       // free old string
    ps = left(sample);
    cout << ps << endl;
    delete [] ps;       // free old string

    return 0;
}
```

<font color = organe> 程序结果： </font>

```
Enter a string:
ForYouToGetTheFirstAFewCharacters
ForY
    
F   
```

<font color = organe> 程序说明： </font>

```cpp
    for (i = 0; i < n && str[i]; i++)
```

首先来解释一下这个循环，中间的条件有两个，一个是`i < n`这个我们比较好理解，目的是为了让程序可以按用户要求遍历字符串每一个小于`n`的值，而第二个条件`str[i]`的作用是检查字符串的第`i`个是否是一个空字符。遇到空字符的时候，循环便自动结束了。目的是为了防止用户输入的`n`大于字符串的字符数。

## 8.4 函数重载

函数重载又叫做函数多态。函数重载的关键是函数的参数列表 -- 也称为函数特征标(function signature)。如果两个函数的参数数目和类型相同，同时参数的排列顺序也相同，则它们的特征标相同，而变量名是无关紧要的。C++允许定义名称相同的函数，条件是它们的特征标不同。如果参数数目或者参数类型不同，则特征标也不同例如：

```cpp
void print (const char * str, int width);   // #1
void print (double d, int width);           // #2
void print (long l, int width);             // #3
void print (int i, int width);              // #4
void print (const char *str);               // #5
```

使用`print()`函数的时候，编译器将根据所采取的用法使用有相应特征标的原型：

```cpp
print("pancack", 15);                       // use #1
print("Syrup");                             // use #5
print(1999.0, 10);                          // use #2
print(1999, 12);                            // use #4
print(1999L, 15);                           // use #3
```

下面来看一下`const`对函数的重载的影响。

```cpp
void dribble (char * bits);          //overload
void dribble (const char * bits);    //overload
void dabble (char * bits);           // not overload
void drivel(const char * bits);      // not overload
```

在调用的时候：

```cpp
const char p1[20] = "How's the weather?";
char p2[20] = "How's business?";
dribble(p1);        // dribble(const char *)
dribble(p2);        // dribble(char *)
dabble(p1);         // not match
dabble(p2);         // dabble(char *)
drivel(p1);         // drivel(const char *)
drivel(p2);         // drivel(const char *)
```

从上面的例子我们可以看出来，函数能否调用`const`参数，与函数声明时是否有`const`有关，但是声明中有`const`参数的函数，调用时使用`const`或非`const`的参数都可以。

但是下面的函数重载方式就是不对的：

```cpp
long gronk(int n, float m);
double gronk(int n, float m);   // not allowed
```

特指标没有改变，只是改变了函数类型时，函数时不可以重载的。

```cpp
long gronk(int n, float m);
double gronk(float n, float m);     // allowed
```

### 8.4.1 重载示例

<font color = orange> 例程：</font>

```cpp
// leftover.cpp -- overloading the left() function
#include <iostream>

// This function returns the first ct digits of the number num
uint64_t left(uint64_t num, uint8_t ct)
{
    uint64_t digits = 1;
    uint64_t n = num;

    if (ct == 0 || num == 0)    // 在本题中其实用不到
        return 0;
    while (n /= 10)
        digits++;
    if (digits > ct)
    {
        ct = digits - ct;
        while (ct--)            // 当 ct-- != 0 时
            num /= 10;          // num 的位数减 1
        return num; // return left ct digits
    }
    else
        return num;
}

// This function returns a pointer to a new string
// consisting of the first n characters in the str string
char *left(const char *str, int n = 1)
{
    if (n < 0)
        n = 0;
    char *p = new char[n + 1];
    int i;
    for (i = 0; i < n && str[i]; i++)
        p[i] = str[i]; // copy characters
    while (i <= n)
        p[i++] = '\0'; // set rest of string to '\0'
    return p;
}

int main(int argc, char *argv[])
{
    using namespace std;
    char trip[9] = "Hawaii!!"; //test value
    uint64_t n = 12345678;     // test value
    int i;
    char *temp;

    for (i = 0; i < 10; i++)
    {
        cout << left(n, i) << endl;
        temp = left(trip, i);
        cout << temp << endl;
        delete[] temp; // point to temporary storage
    }
    return 0;
}
```

<font color = orange> 输出结果：</font>

```
0

1
H
12
Ha
123
Haw
1234
Hawa
12345
Hawai
123456
Hawaii
1234567
Hawaii!
12345678
Hawaii!!
12345678
Hawaii!!
```

<font color = orange> 程序说明：</font>

首先我们创建了2个`left()`函数，让`left()`可以分别重载为处理文字的函数，和处理数字的函数。主函数中循环输出数字以及其对应的字母，而`left()`数字函数中，` while (n /= 10)`是因为每个数位代表一个字母。函数的两个重载的写法有异曲同工之妙。

### 8.4.2 个人的体会

对于何时使用个人的理解是，为一个函数提供多种可以处理的数据格式，一般函数的名称暗示了这个函数的功能，但是由于C++多种的数据类型，一个函数往往难以应对各种数据类型，因此需要使用重载。

当函数的重载写好后，

## 8.5 函数模板

函数模板是通用的函数描述，也就是说，它们使用泛型来定义函数，其中的泛型可用具体的类型（如`int`或者`double`）替换。通过将类型作为参数传递给模板，可使得编译器生成该类型的函数。由于模板允许以泛型（而不是具体类型）的方式编写程序，因此有时也被称为通用编程。下面用一个例程来展示泛型的使用方法：


```cpp
// funtemp.cpp -- using a function template
#include <iostream>
// function template prototype
template <typename T> // or class T
void Swap(T &a, T &b);

int main(int argc, char *argv[])
{
    using namespace std;
        int i = 10;
        int j = 20;
        cout << "i, j = " << i << ", " << j << endl;
        cout << "Using compiler-generated int swapper: \n";
        Swap(i, j); // generates void Swap(int &, int &)
        cout << "Now i, j = " << i << ", " << j << endl;

        double x = 24.5;
        double y = 81.2;
        cout << "x, y = " << x << ", " << y << endl;
        cout << "Using compiler-generated int swapper: \n";
        Swap(x, y); // generates void Swap(double  &, double &)
        cout << "Now x, y = " << x << ", " << y << endl;
    return 0;
}

// funtion template definition
template <typename T> // or class T
void Swap(T &a, T &b)
{
    T temp; // temp a variable of type T
    temp = a;
    a = b;
    b = temp;
}
```

程序结果：

```
i, j = 10, 20
Using compiler-generated int swapper:
Now i, j = 20, 10
x, y = 24.5, 81.2
Using compiler-generated int swapper:
Now x, y = 81.2, 24.5
```

程序说明：

函数模板允许以任意类型的方式来定义函数。例如：

```cpp
template <typename T> // or class T
void Swap(T &a, T &b)
{
    T temp; // temp a variable of type T
    temp = a;
    a = b;
    b = temp;
}
```

上面一段的关键字`typename`可以使用`class`替换。`typename`和`template`的作用就是指出要创建一个模板，这个模板中的类型可以是任意类型。在大型工程中，使用模板可以让我们不用为向后兼容的问题产生烦恼。以上面的程序为例，使用模板后，编译器就会自动把`a`和`b`的`int`值传递给`temp`，`x`和`y`的`double`类型也一样。这个给人感觉类似于使用`auto`。

### 8.5.1 重载的模板

需要多个对不同类型使用同一算法的函数时，可以使用模板。然后不是所有类型都可以使用相同的算法。为了满足这种需求，可以像使用函数重载一样重载模板定义。和常规的函数重载一样，被重载的模板的函数特征标必须不同。下面将用一个例程来展示：

```cpp
// twotemps.cpp -- using overload template functions
#include <iostream>
template<class T>      // original template
void Swap(T &a, T &b);

template<class T>       // new template
void Swap(T *a, T *b, int n);

void Show(int a[]);
const int Lim = 8;
int main(int argc, char *argv[])
{
    using namespace std;
    int i = 10;
    int j = 20;
    cout << "i, j = " << i << ", " << j << endl;
    cout << "Using compiler-generated int swapper: \n";
    Swap(i, j); // matches original template
    cout << "Now i, j = " << i << ", " << j << endl;

    int d1[Lim] = {0, 7, 0, 4, 1, 7, 7, 6};
    int d2[Lim] = {0, 7, 2, 0, 1, 9, 6, 9};
    cout << "Original array:\n";
    Show(d1);
    Show(d2);
    Swap(d1,d2,Lim);        // matches new template
    cout << "Swapped array:\n";
    Show(d1);
    Show(d2);

    return 0;
}

template <class T>
void Swap(T &a, T &b)
{
    T temp;
    temp = a;
    a = b;
    b = temp;
}

template <class T>
void Swap(T *a, T *b, int n)
{
    T temp;
    for (int i = 0; i < n; i++)
    {
        temp = a[i];
        a[i] = b[i];
        b[i] = temp;
    }
    
}

void Show(int a[])
{
    using namespace std;
    cout << a[0] << a[1] << "/";
    cout << a[2] << a[3] << "/";
    for (int i = 0; i < Lim; i++)
    {
        cout << a[i];
    }
    cout << endl;
    
}
```

程序输出：

```
i, j = 10, 20
Using compiler-generated int swapper: 
Now i, j = 20, 10
Original array:
07/04/07041776
07/20/07201969
Swapped array:
07/20/07201969
07/04/07041776
```

### 8.5.2 显式具体化

假设定义了以下的结构：

struct job
{
    char name[40];
    double salary;
    int floor;
};

如果希望用一个模板函数来交换`salary`和`floor`成员，而不交换`name`成员，无法使用模板重载来完成。然后，我们可以提供以一个具体化函数定义 -- 称为显示具体化。下面我们来看一个例程：

```cpp
// twoswap.cpp -- specialization overrides a template
#include <iostream>
template <class T>
void Swap(T &a, T &b);

struct job
{   
    char name[40];
    double salary;
    int floor;
};

// explicit specialization
template <> void Swap<job>(job &j1, job &j2);
void Show(job &j);

int main(int argc, char *argv[])
{
    using namespace std;
    cout.precision(2);
    cout.setf(ios::fixed, ios::floatfield);
    int i = 10, j = 20;
    cout << "i, j = " << i << ", " << j << endl;
    cout << "Using compiler-generated int swapper:\n";
    Swap(i,j);
    cout << "Now i, j = "<< i << ", " << j << endl;

    job sue = {"Susan Yaffee", 73000.60, 7};
    job sidney = {"Sidney Taffee", 78060.72, 9};
    cout << "Before job swapping: \n";
    Show(sue);
    Show(sidney);
    Swap(sue, sidney);  // uses void Swap(job &, job &)
    cout << "After job swapping: \n";
    Show(sue);
    Show(sidney);

    return 0;
}

template <class T>
void Swap(T &a, T &b)
{
    T temp;
    temp = a;
    a = b;
    b = temp;
}

// swaps just the salary and floor fields of a job structure

template <> void Swap<job>(job &j1, job &j2)    // specialization
{
    double t1;
    int t2;
    t1 = j1.salary;
    j1.salary = j2.salary;
    j2.salary = t1;
    t2 = j1.floor;
    j1.floor = j2.floor;
    j2.floor = t2;
}

void Show(job &j)
{
    using namespace std;
    cout << j.name << ": $" << j.salary
         << "on floor " << j.floor << endl;
    
}
```

程序输出：

```cpp
i, j = 10, 20
Using compiler-generated int swapper:
Now i, j = 20, 10
Before job swapping: 
Susan Yaffee: $73000.60on floor 7    
Sidney Taffee: $78060.72on floor 9   
After job swapping: 
Susan Yaffee: $78060.72on floor 9    
Sidney Taffee: $73000.60on floor 7
```

程序说明：

上面的例程我们主要学习的点在于函数声明：

```cpp
template <> void Swap<job>(job &j1, job &j2);    // specialization
```

`template<>` 表明函数使用了模板，`Swap<job>`中的`<job>`是可选的，因为函数的参数类型表明，这是一个`job`的具体化，因此上面的声明也可以化简为：

```cpp
template <> void Swap<>(job &, job &);    // specialization
```

### 8.5.3 编译器的选择

下面将再利用两个例子来展示编译器在函数模板中的选择：

例一：

```cpp
// tempover.cpp -- template overloading
#include <iostream>

template <class T>      // template A
void ShowArray(T arr[], int n);

template <class T>
void ShowArray(T *arr[], int n);

struct debts
{
    char name[50];
    double amount;
};


int main(int argc, char const *argv[])
{
    using namespace std;
    int things[6] = {12, 32, 103, 302, 310, 130};
    struct debts mr_E[3] = 
    {
        {"Ima Wolfe", 2400.0},
        {"Ura Foxe", 1300.0},
        {"Iby Stout", 1800.0}
    };

    double * pd[3];

    // set pointer to the amount members of the structures in mr_E
    for (int i = 0; i < 3; i++)
    {
        pd[i] = &mr_E[i].amount;
    }

    cout << "Listing Mr.E's counts of things:\n";
    // things is an array of int
    ShowArray(things, 6);   // uses template A
    cout << "Listing Mr.E's debts:\n";
    ShowArray(pd,3);    // uses template B
    return 0;
}


template<typename T>
void ShowArray(T arr[], int n)
{
    using namespace std;
    cout << "template A\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ' ';
    }
    cout  << endl;
}

template<typename T>
void ShowArray(T * arr[], int n)
{
    using namespace std;
    cout << "template B\n";
        for (int i = 0; i < n; i++)
    {
        cout << *arr[i] << ' ';
    }
    cout  << endl;

}
```

程序输出：
```
Listing Mr.E's counts of things:
template A
12 32 103 302 310 130
Listing Mr.E's debts:
template B
2400 1300 1800
```

程序说明：

由于一对一的完全对应关系，编译器能够准确的找到所应用的函数重载。

例二：

```cpp
// choices.cpp -- choosing a template
#include <iostream>
    using namespace std;

template<typename T>
T lesser(T a, T b)  // #1
{
    cout << "#1 ";
    return a < b ? a : b;
}

int lesser(int a, int b) // #2
{
    cout << "#2 ";
    a = a < 0 ? -a : a;
    b = b < 0 ? -b : b;
    return a < b ? a : b;
}

int main(int argc, char const *argv[])
{

    int m = 20;
    int n = 30;
    double x = 16.3;
    double y = 29.0;

    cout << lesser(m,n) << endl;        // #1
    cout << lesser(x, y) << endl;       // #2
    cout << lesser<>(m, n ) << endl;    // #3
    cout << lesser<int>(x,y) << endl;   // #4
    return 0;
}
```

程序结果：

```
#2 20
#1 16.3
#1 20
#1 16
```

程序说明：

上面的例程中提供了一个模板和一个标准函数，其中模板返回两个值中较小的一个，而标准函数返回两个值中绝对值较小的一个。如果函数定义是在使用函数之前，它将充当函数原型。

第一次调用，参数为两个`int`值，与非模板函数完全匹配，因此使用#2.
第二次调用，参数为两个`double`值，与薄板匹配，因此使用#1.
第三次调用，`lesser<>`指出要使用模板函数，因此使用#1.
第四次调用语句`lesser<int>(x, y)` 是一个显示实例化，x和y被强制转换为了`int`值。这就是最后一个出现`16`的原因。