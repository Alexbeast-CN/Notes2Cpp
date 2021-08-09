// inline.cpp -- using an inline function
#include <iostream>

// an inline function definition
inline double square(double x) 
{
    return x*x;
}

int main(int argc, char const *argv[])
{
    using namespace std;
    double a, b;
    double c = 13.0;

    a = square(5.0);
    b = square(3.5 + 7.5);  // it can pass expressions
    cout << "a = " << a << ", b = " << b << endl;
    cout << "c = " << c;
    cout << ", c square is " << square(c++) << endl;
    cout << "Now c = " << c << endl;
    return 0;
}
