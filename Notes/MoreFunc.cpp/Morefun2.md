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

```