# 第七章：函数（练习题）

## 第一题：

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

## 第二题：

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

## 第三题

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
