# 第七章：函数（练习题）

## 7.11 练习题

### 7.11.1 第一题：

<font color = #FFA500>题目：</font>

写一个程序，不断要求用户输入两个数，直到其中一个为0.对于每两个数，程序将使用一个函数来计算他们的调和平均数，并将结果返回给`main()`，而后者将报告结果。调和平均数公式如下：
$$ \overline{x} = 2.0\frac{ x\times y}{x + y}$$

<font color = #FFA500>程序：</font>

```cpp
#include <iostream>

double Harmonic_mean(double, double);

int main(int argc, char const *argv[])
{
    double x, y;
    std::cout << "Enter two positive numbers: ";
    std::cin >> x >> y;
    while (x > 0 && y > 0)
    {
        double mean = Harmonic_mean(x, y);
        std::cout << "The Harmonic mean of these two number is: "
                  << mean << std::endl
                  << std::endl;
        std::cout << "please enter another two positive numbers: \n"
                  << "(unpositive figure will terminate the programme)\n";
        std::cin >> x >> y;
    }
    std::cout << "-Done-" << std::endl;

    return 0;
}

double Harmonic_mean(double x, double y)
{
    double mean;
    mean = 2.0 * x * y / (x + y);
    return mean;
}
```

<font color = #FFA500>结果：</font>

```
nter two positive numbers: 2 9
The Harmonic mean of these two number is: 3.27273

please enter another two positive numbers:
(unpositive figure will terminate the programme)
1 8
The Harmonic mean of these two number is: 1.77778

please enter another two positive numbers:
(unpositive figure will terminate the programme)
10 0
-Done-
```

### 7.11.2 第二题：

<font color = #FFA500>题目：</font>

编写一个程序，要求用户最多输入10个高尔夫球的成绩，并将其存储在一个数组中。程序允许用户提前结束输入，并在一行上显示所有成绩，然后报告平均成绩。请使用3个数组处理函数来分别进行输入、显示和计算平均值：

<font color = #FFA500>程序：</font>

```cpp
#include <iostream>
//constants
const int N = 10;

// prototypes
int fill_table(double *);
void display(const double *, int);
void mean(const double *, int);

using namespace std;

int main(int argc, char const *argv[])
{
    double ar[10];
    cout << "Please enter the resluts: \n";
    int i = fill_table(ar);
    display(ar, i);
    mean(ar, i);

    return 0;
}

int fill_table(double *ar)
{
    int i;
    for (i = 0; i < N; i++)
    {
        cout << "#" << i + 1 << ": ";
        cin >> ar[i];
        if (ar[i] < 0)
            break;
    }
    return i;
}

void display(const double *ar, int i)
{
    cout << "The results are: \n";
    for (int j = 0; j < i; j++)
        cout << ar[j] << " ";
    cout << endl;
}

void mean(const double *ar, int i)
{
    double sum = 0;
    for (int j = 0; j < i; j++)
        sum += ar[j];
    double mean = sum / i;
    cout << "The mean of the results is: " << mean << endl;
}
```

<font color = #FFA500>结果：</font>

```
Please enter the resluts: 
#1: 1
#4: 4
#6: 6
#7: 7
#8: 8
#9: 9
#10: 10
The results are:
1 2 3 4 5 6 7 8 9 10
The mean of the results is: 5.5
```

### 7.11.3 第三题

<font color = #FFA500>题目：</font>

下面是一个结构声明：
```cpp
struct box
{
    char maker[40];
    float height;
    float weith;
    float length;
    float volume;
}
```

1. 编写一个函数，按值传递`box`结构，并显示每个成员的值。
2. 编写一个函数，传递`box`结构的地址，并将`volume`成员设置为其他三位长度的乘积。
3. 编写一个函数使用这两个函数的简单程序。

<font color = #FFA500>程序：</font>

```cpp
#include <iostream>

struct Box{
    char maker[40];
    float height;
    float width;
    float length;
    float volume;
};

using namespace std;

void a(Box);
void b(Box *);

int main(void)
{
    Box x = {"Box", 2.0, 3.0, 3.5, 0.0};

    // output
    a(x);
    cout << endl;
    // modify volume
    b(&x);
    
    // output again
    a(x);
    cout << endl;
    return 0;
}

void a(Box box)
{
    cout << "maker " << box.maker << endl;
    cout << "height " << box.height << endl;
    cout << "width " << box.width << endl;
    cout << "length " << box.length << endl;
    cout << "volume " << box.volume << endl;
}

void b(Box * pbox)
{
    pbox->volume = pbox->height * pbox->length * pbox->width;
}
```

<font color = #FFA500>结果：</font>

```
maker Box
height 2 
width 3
length 3.5
volume 0

maker Box
height 2
width 3
length 3.5
volume 21

```

### 7.11.4 第四题

<font color = #FFA500>题目：</font>

定义一个递归函数，接受一个整数参数，并返回该参数的阶乘。通用的公式是，如果n大于零，则 $n! = n(n-1)!$。在程序中对该函数进行测试，程序使用循环让用户输入不同的值，程序报告这些值的阶乘。

<font color = #FFA500>程序：</font>

```cpp
#include <iostream>

uint16_t factorial(uint16_t n);

using namespace std;

int main(int argc, char const *argv[])
{
    uint16_t n;
    cout << "Enter a nature number: ";
    while (cin >> n)
    {
        int n2 = factorial(n);
        cout << n << "! = " << n2 << endl;
        cout << "Enter another number (q to quit): ";
    }

    cout << "-Done-\n";
    return 0;
}

uint16_t factorial(uint16_t n)
{
    if (n == 0)
        return 1;

    return n * factorial(n - 1);
}

```

<font color = #FFA500>结果：</font>

```cpp
Enter a nature number: 3
3! = 6
Enter another number (q to quit): 4
4! = 24
Enter another number (q to quit): 7
7! = 5040
Enter another number (q to quit): 1
1! = 1
Enter another number (q to quit): 3
3! = 6
Enter another number (q to quit): 0
0! = 1
Enter another number (q to quit): 1
1! = 1
Enter another number (q to quit): q
-Done-
```

### 7.11.5 第五题

<font color = #FFA500>题目：</font>

编写一个程序，使用下列函数：
1. `Fill_array()`将一个`double`数组的名称和长度作为参数。它提示用户输入`double`值，并将这些值存储到数组中。当函数被填满或用户输入非数字时，输入将停止，并返回实际输入了多少数字。
2. `Show_array()`将一个`double`数组的名称和长度作为参数，并显示该数组的内容。
3. `Reverse-array()`将一个数组的名称和长度作为参数，并将存储在数组中的值的顺序反转。

<font color = #FFA500>程序：</font>

```cpp
#include <iostream>

const int Len = 10;

int Fill_array(double*);
void Show_array(double*, int);
void Reverse_array(double*, int);

using namespace std;

int main(int argc, char const *argv[])
{
    double array[Len] = {0};
    int i = 0;
    cout << "Enter a array: ";
    i = Fill_array(array);
    cout << endl;
    cout << "The array is: [";
    Show_array(array, i);
    cout << "]";
    cout << endl;
    cout << "\nThe inverse array is: [";
    Reverse_array(array, i);
    cout << "]";
    return 0;
}

int Fill_array(double* ar)
{
    int j = 0;
    while(cin.peek()!='\n')
    {   
        cin >> ar[j];
        j++;  
    }
        
    return j;
}
void Show_array(double* ar, int n)
{
    int j;
    for (j = 0; j < n; j++)
        cout << ar[j] << " ";
}
void Reverse_array(double* ar, int n)
{
    int m = n-1;
    for (m; m >= 0; m--)
        cout << ar[m] << " ";
}
```

<font color = #FFA500>结果：</font>

Enter a array: 2 8 9 3 10 0

The array is: [2 8 9 3 10 0 ]

The inverse array is: [0 10 3 9 8 2 ]

### 7.11.6 第六题

<font color = #FFA500>题目：</font>

设计一个名为`calculate()`的函数，它接受两个`double`值和一个指向函数的指针，而被指向的函数接受两个`double`值，并返回以`double`值。`calculate()`函数的类型也是`double`，并返回值被指向的函数使用`calculate()`的两个`double`参数计算得到的值。假如，假设`add()`函数的定义如下：

```cpp
double add (double x, double y)
{
    return x + y;
}
```

则下述代码中的函数调用导致`calculate()`把2.5和10.4传递给`add()`函数，并返回`add()`的返回值（12.9）：
```cpp
double q = calculate(2.5, 10.4, add);
```

<font color = #FFA500>程序：</font>

```cpp
#include <iostream>

using namespace std;

typedef double (*pfunc)(double, double);

double add(double, double);
double mul(double, double);
double calculate(double, double, pfunc);

int main(void)
{
    double x, y;
    pfunc pfun_arr[2] = {add, mul};

    cout << "Enter 2 floats: ";
    while((cin >> x) >> y)
    {
        double res;
        for(int i = 0; i < 2; ++i)
        {
            res = calculate(x, y, pfun_arr[i]);
            cout << "result #" << i << ": " << res << endl;
        }
            cout << "Enter 2 floats again: " << endl;

    }
    return 0;
}

double add(double x, double y)
{
    return x + y;
}

double mul(double x, double y)
{
    return x*y;
}

double calculate(double x, double y, pfunc pf)
{
    return (*pf)(x, y);
}
```

<font color = #FFA500>结果：</font>

```
Enter 2 floats: 1.2 4.2
result #0: 5.4        
result #1: 5.04       
Enter 2 floats again: 
1  
2
result #0: 3
result #1: 2
Enter 2 floats again:
q
```