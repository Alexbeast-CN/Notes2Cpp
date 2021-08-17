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

    cout << lesser(m,n) << endl;
    cout << lesser(x, y) << endl;
    cout << lesser<>(m, n ) << endl;
    cout << lesser<int>(x,y) << endl;
    return 0;
}
