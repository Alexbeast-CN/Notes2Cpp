// fltadd.cpp -- precision problems with float

#include <iostream>

int main()
{
    using namespace std;
    float a = 2.34E+22f;
    float b = a + 1.0f;

    cout << "a = " << a << endl;
    cout << "b - a = " << b - a << endl;
 

    int dues = 20 * 5 + 24 * 6;
    int logs = 120 / 4 * 5;

    cout << "dues = "<< dues <<"\nlogs = "<< logs << endl;

   return 0;
}