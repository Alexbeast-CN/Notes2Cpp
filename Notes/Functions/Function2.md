# 第七章 函数 -- C++的编程模块

## 7.5 函数和C-风格字符串

前面介绍过，C-风格的字符串以一些列字符组成，以空值字符结尾。在将字符串作为参数时意味着要传递的时地址，但是可以使用`const`来禁止对字符串参数进行修改。下面我们将介绍与字符串有关的一些特殊知识。

### 7.5.1 将C-风格字符串作为参数的函数

假设要将字符串作为参数传递给数组，则表示字符串的方式有3种：
* `char`数组；
* 用引号括起来的字符串常量（也成为字符串字面值）；
* 被设置为字符串的地址`char`指针。

但上述3种选择的类型都是`char`指针（`char*`），因此可以将其作为函数处理字符串的参数：
```cpp
char ghost[15] = "galloping";
char * str = "galumphing";
int n1 = strlen(ghost);         // ghost is &ghost[0]
int n2 = strlen(str);           // pointer to char
int n3 = strlen("gamboling");   // address of string
```

说是将字符串作为参数来传递，但实际传递的是字符串第一个字符的地址。这意味着字符串函数原型应将其表示字符串的形参声明为`char *`类型。

C-风格字符串与常规`char`数组之间的一个重要区别是，字符串内置有结束字符。不以空字符结尾的`char`只是数组。这意味着不必将字符串长度作为参数传递给函数（与数组不同），而函数可以通过循环依次检查字符串中的每一个字符，直到遇到结尾的空字符为止。下面的例程展示了这个方法：

```cpp
// strfun.cpp -- functions with a string argument

#include <iostream>
uint16_t c_in_str(const char * str, char ch);

int main()
{
    using namespace std;
    char mmm[15] = "minimum";   // string in an array
    // char uuu[15] = "ululate";
    char * wail = "ululate";    // wail points to string

    uint16_t ms = c_in_str(mmm,'m');
    uint16_t us = c_in_str(wail,'u');
    cout << ms << " m characters in " << mmm << endl;
    cout << us << " u characters in " << wail << endl;

    return 0;
}

uint16_t c_in_str (const char * str, char ch)
{
    uint16_t count = 0;

    while (*str)            //quit when *str is '\0'
    {
        if (*str == ch)
            count++;
        str++;              // move pointer to next char
    }
    return count;
}
```

很不幸，在C++17中，指针不能直接指向字符串了，当我输入上方代码时，编译器报错：
```
.\strfun.cpp: In function 'int main()':
.\strfun.cpp:11:19: warning: ISO C++ forbids converting a string constant to 'char*' [-Wwrite-strings]
     char * wail = "ululate";    // wail points to string
```

要想解决问题也很简单，只需要将
```cpp
    char * wail = "ululate";    // wail points to string
```
替换成：
```cpp
     char uuu[15] = "ululate";
    char * wail = uuu;    // wail points to string
```

输出结果是：
```
3m characters in minimum
2u characters in ululate
```

虽然有一点小问题，但程序依然有值得我们学习的地方：
```cpp
while (*str)
```
这个循环方式很方便的遍历了整个字符串，直到`'\n'`结束。

### 7.5.2 返回C-风格字符串的函数

虽然函数没有办法直接返回字符串，但是可以返回其地址。下面的例程展示其使用方法：
```cpp
// strgback.cpp -- a function that returns a pointer to char
#include <iostream>

char * buildstr(char c, int n);     // prototype
int main(int argc, char const *argv[])
{
    using namespace std;
    int times;
    char ch;

    cout << "Enter a character: ";
    cin >> ch;
    cout << "Enter a integer: ";
    cin >> times;
    char *ps = buildstr(ch, times);
    cout << ps << endl;
    delete [] ps;                   // free memory
    ps = buildstr('+',20);          // reuse poinetr 
    cout << ps << "-DONE-" << ps << endl;
    delete []  ps;                  // free memory
    return 0;
}

// builds string made of n c chararters
char * buildstr(char c, int n)
{
    char * pstr = new char[n + 1];
    pstr[n] = '\0';
    while (n-- > 0)
        pstr[n] = c;    // fill rest of string
    return pstr;
}
```

out:
```
Enter a character: V
Enter a integer: 46
VVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV
++++++++++++++++++++-DONE-++++++++++++++++++++
```

