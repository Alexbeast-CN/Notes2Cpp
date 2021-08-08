
#include <iostream>
using namespace std;
 
int main()
{
    int a, s=0;
    //回车表示数据输入结束
    while(cin.peek()!='\n')  //cin.peek()相当于偷看一眼再放回流中
    {
        cin>>a;
        s += a;
    }
    cout << s;
    return 0;
}