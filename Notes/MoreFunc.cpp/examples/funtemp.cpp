// funtemp.cpp -- using a function template
#include <iostream>
// function template prototype
template <typename T> // or class T
void Swap(T &a, T &b);

int main(int argc, char *argv[])
{
    using namespace std;
        int i = 10;
        int j = 20;
        cout << "i, j = " << i << ", " << j << endl;
        cout << "Using compiler-generated int swapper: \n";
        Swap(i, j); // generates void Swap(int &, int &)
        cout << "Now i, j = " << i << ", " << j << endl;

        double x = 24.5;
        double y = 81.2;
        cout << "x, y = " << x << ", " << y << endl;
        cout << "Using compiler-generated int swapper: \n";
        Swap(x, y); // generates void Swap(double  &, double &)
        cout << "Now x, y = " << x << ", " << y << endl;
    return 0;
}

// funtion template definition
template <typename T> // or class T
void Swap(T &a, T &b)
{
    T temp; // temp a variable of type T
    temp = a;
    a = b;
    b = temp;
}