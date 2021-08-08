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


```