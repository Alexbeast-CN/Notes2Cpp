// hexoct.cpp -- display valuesin hex and octal
#include <iostream>
using namespace std;
int main()
{
    int a = 42;
    
    cout << "a in decimal is: " << a << endl;
    cout << hex; // manipulator for changing number base
    cout << "a in hexadecimal is: " << a << endl;
    cout << oct; // manipulator for changing number base
    cout << "a in octal is: " << a << endl;
    return 0;

}