# C++ Primer Plus 学习笔记 {ignore=true}
---

# 第四章：复合类型 {ignore=true}

## 本章学习内容： {ignore=true}
[TOC]
---

## 4.1 数组
数组可以储存多种同类型的值，要创建数组，可以使用声明语句，语句应指明以下3点：
* 存储再每个元素中的值的类型；
* 数组名；
* 数组中的元素数。

数组的通用格式是：
```cpp
TypeName ArrayName [ArraySize];
```
例如：
```cpp
short months [12];   // create a array of 12 short
```

数组之所以被称为复合类型是因为它是由其他类型来创建的。数组中的每个元素可以单独调用，其计数方式是从`0`到`n-1`。

下面的例程展示了数组的使用方法和属性：
```cpp
// arrayone.cpp -- samll array of integers
#include <iostream>

int main(int argc, char const *argv[])
{
    using namespace std;

    int yams [3];
    yams [0] = 7;
    yams [1] = 8;
    yams [2] = 6;

    int yamscost [3] =  {20, 30, 5};

    cout << "Total yams = " << yams [0] + yams[2] + yams[1];
    cout << endl;
    cout << "The package with " << yams [1] << " yams costs ";
    cout << yamscost[1] << " cent per yam. \n";
    int total = yams [0] * yamscost[0] + yams[1] * yamscost [1] + yams [2] * yamscost[2];
    cout << "The total yam expense is " << total << " cents.\n";

    cout << "\nSize of yams array = " << sizeof yams;
    cout << "bytes. \n";
    cout << "Size of one element = " << sizeof yams[0];
    cout << "bytes. \n";
    return 0;
}
```

out:
```
Total yams = 21
The package with 8 yams costs 30 cent per yam.
The total yam expense is 410 cents.

Size of yams array = 12 bytes.
Size of one element = 4 bytes.
```

### 4.1.1 数组初始化的规则
* 只有定义数组的时候才可以对数组进行初始化，此后就不能再用了，且不能把数据赋值给另外一个数组。
```cpp
int cards [4] {1, 2, 3, 4}; //allowed
int hands [4];              //allowed
hands = {5, 6, 7 ,8};       //not allowed   
hands = cards;              //not allowed
```
* 初始化的时候赋值的个数可以小于数组元素的数目，比如：
```cpp
float num[5] = {1, 2};
```
此时，只有数组中前两个数被赋值了，其他的数被置零。

* 零数组，将数组中的所有元素置零。
```cpp
float zeros [6] = {0};
```

* 如果初始化时，方括号[]内为空，则C++编译器会计算元素的个数，如：
```cpp
short things[] = {1, 5, 3, 8};
```
则编译器会将`things`中包含4个元素。

## 4.2 字符串
这里推荐使用以下的方式定义字符串变量：
```cpp
char name[] = "Alex";
```

### 4.2.1 字符串与数组
下面的例程将演示数组和字符串的结合使用方法：
```cpp
// strings.cpp -- store string in an array
#include <iostream>
#include <cstring>

int main(int argc, char *argv[])
{
    using namespace std;
    const int Size = 15;
    char name1[Size];   // empty array  
    char name2[Size] = "C++ Oldboy";// initialized array

    cout << "Howdy! I'm " << name2;
    cout << "What's your name? \n";
    cin >> name1;
    cout << "Well, " << name1 << " your name has ";
    cout << strlen(name1) << " letters and is stored\n";
    cout << "in an array of " << sizeof(name1) << " bytes. \n";
    name2[3] = '\0';    // set to null character
    cout << "Your initial letter is " << name1[0] << endl;
    cout << "Here are the first three letter of my name: ";
    cout << name2 << endl;

    return 0;
}
```

out:
```
Howdy! I'm C++ OldboyWhat's your name? 
Dao
Well, Dao your name has 3 letters and is stored
in an array of 15 bytes.
Your initial letter is D
Here are the first three letter of my name: C++
```

从程序的输出我们可以看出来，`strlen()`返回的是可见的字符串的长度，不包含`\0`。在程序中，我们将`name2[3]`设置为了`\0`因此虽然后面还有内容，但是不再显示。

### 4.2.2 字符串输入
使用`cin`作为字符串的输入的时候存在一些问题，下面的例程将反应出这个问题：

```cpp
// cinproblem.cpp -- reading more than one thing

#include <iostream>

int main(int argc, char *argv[])
{
    using namespace std;
    const int ArSize = 20;
    char name[ArSize];
    char city[ArSize];

    cout << "What's your name? \n";
    cin >> name;
    cout << "Which city do you live in? \n";
    cin >> city;

    cout << "Okey, now I know you're " << name << " and you live in ";
    cout << city << endl;
    
    return 0;
}
```

out:

```
What's your name? 
TIM D
Which city do you live in? 
Okey, now I know you're TIM and you live in D
```

在上面的例程中，我输入了我的名字： `TIM D` 还没来得及输入我所居住的城市，程序就已经结束了。并且程序将我的名字记为了`TIM`，将我的城市记为了`D`。这是因为`cin()`使用空白（空格、制表符、换行符）作为确定字符串结束的位置，并自动在结尾添加空字符。

为了解决这个问题，`istream`中的类（如`cin`）提供了一些面向行的类成员函数：`getline()`, `get()`。这两个函数都是读取一行的输入，知道换行符。他们之间的区别是，`getline()`会丢弃换行符，而`get()`不会。

为了熟悉这两个函数的使用方法，下面给出了一个例程：
```cpp
// instr.cpp -- read more than one word in getlin()

#include <iostream>
int main(int argc, char *argv[])
{
    using namespace std;
    const int ArSize = 20;
    char name[ArSize];
    char city[ArSize];

    cout << "What's your name? \n";
    cin.getline(name,ArSize);
    cout << "Which city do you live in? \n";
    cin.getline(city,ArSize);


    cout << "Okey, now I know you're " << name << " and you live in ";
    cout << city << endl;

    return 0;
}
```

out:
```
What's your name? 
TIM D
Which city do you live in? 
Suzhou
Okey, now I know you're TIM D and you live in Suzhou
```