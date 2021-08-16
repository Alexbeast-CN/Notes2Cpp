# 基于 C++ Primer Plus 的学习笔记 {ignore=true}
---

# 第四章：复合类型（练习题） {ignore=true}

## 本章学习内容： {ignore=true}
[TOC]
---
## 4.10 练习题
### 4.10.1 练习题1
```
What's your first name? Betty
What's your last name? Sue
What letter grade do you deserve? B
What's your age? 22
Name: Betty Sue
Grade: B
Age: 22
```
程序：
```cpp
#include <iostream>

struct StudentInfo
{
    char FirstName [20];
    char LastName [20];
    char grade [20];
    int age;
} Student1;

int main(int argc, char const *argv[])
{
    using namespace std;
    cout << "What's your first name? ";
    cin.getline(Student1.FirstName, 20);
    cout << "What's your last name? ";
    cin.getline(Student1.LastName, 20);
    cout << "What letter grade do you deserve? ";
    cin.getline(Student1.grade,20);
    cout << "What's your age? ";
    cin >> Student1.age;
    cout << "Name: " << Student1.FirstName << " " << Student1.LastName << endl;
    cout << "Grade: " << Student1.grade << endl;
    cout << "Age: " << Student1.age << endl;

    return 0;
}
```
在上面的程序中，使用`struct`是为了方便输入更多学生的信息，比如将变量`Student1`变成一个数组`Student[20]`，即可以完成对20个学生的信息采集。写完上面程序后，我又对这个程序进行一点修改，使得一次就可以输入一个人全名，并分别记为`FirstName`和`LastName`：
```cpp
#include <iostream>

struct StudentInfo
{
    char FirstName [20];
    char LastName [20];
    char grade [20];
    int age;
} Student1;

int main(int argc, char const *argv[])
{
    using namespace std;
    cout << "What's your full name? ";
    cin >> Student1.FirstName >> Student1.LastName;cin.get();
    cout << "What letter grade do you deserve? ";
    cin.getline(Student1.grade,20);
    cout << "What's your age? ";
    cin >> Student1.age;
    cout << "Name: " << Student1.FirstName << " " << Student1.LastName << endl;
    cout << "Grade: " << Student1.grade << endl;
    cout << "Age: " << Student1.age << endl;

    return 0;
}
```
### 4.10.2 练习题2
William Wingate 从事披萨饼分析服务。对于每个披萨饼，都需要记录下列信息：
* 披萨饼公司的名字，可以有多个字母组成。
* 披萨的直径。
* 披萨的重量。
设计一个能够储存这些信息的结构，要求使用`new`来为结构分配内存。程序将请求用户输入上述信息。
程序：
```cpp
#include <iostream>

struct Pizza
{
    char Company[20];
    float Diameter;
    float Weight;
};

int main(int argc, char const *argv[])
{
    Pizza *p = new Pizza;

    std::cout << "Enter the company name.\n";
    std::cin.getline(p->Company, 20);
    std::cout << "Enter the Pizza's diameter in inch.\n";
    std::cin >> p->Diameter;
    std::cout << "Enter the Pizza's weight in kg.\n";
    std::cin >> p->Weight;

    std::cout << "Company: " << p->Company << std::endl;
    std::cout << "Diameter: " << p->Diameter << std::endl;
    std::cout << "weight: : " << p->Weight << std::endl;

    delete p;

    return 0;
}
```
out:
```
Enter the company name.
Fire Hourse
Enter the Pizza's diameter in inch.
14
Enter the Pizza's weight in kg.
2.3
Company: Fire Hourse
Diameter: 14
weight: : 2.3
```

### 4.10.3 练习题3
写一个程序，让用户输入一位运动员3次跳远的成绩，并显示次数和平均成绩，然后输出最大和最小值。使用array来存储对象。
```cpp
#include <iostream>
#include <array>
#include <cmath>

using namespace std;
int main(int argc, char const *argv[])
{
    array<double, 3> results;
    double sum{0};
    double max{0};
    double min{0};

    for (int i = 0; i <= 2; i++)
    {
        cout << "Please enter the jump result for the " << i + 1 << " time is:  ";
        cin >> results[i];
        sum = sum + results[i];
    }

    cout << "The results are:" << endl;
    max = results[0];
    min = results[0];
    for (int n = 0; n <= 2; n++)
    {
        cout << "The result for the " << n + 1 << "time is:" << endl;
        cout << results[n];
        if (max <= results[n])
        {
            max = results[n];
        }
        if (min >= results[n])
        {
            min = results[n];
        }
    }
    cout << "The average result for the athlete is: " << sum / 3 << endl;
    cout << "The best result is: " << max << endl;
    cout << "The worst result is: " << min << endl;

    return 0;
}
```
out:
```
The results are:
The result for the 1time is:
2.66The result for the 2time is:
2.67The result for the 3time is:
2.69The average result for the athlete is: 2.67333
The best result is: 2.69
The worst result is: 2.66
```