// protos.cpp -- using trototypes and function calls
#include <iostream>

using namespace std;

void cheers(int n);   // prototype: no return value
double cube(double x); //prototype: returns a double

int main(int argc, char *argv[])
{
    cheers(5);
    cout << "Give me a number: ";
    double side;
    cin >> side;
    double volume = cube(side); //function call
    cout << "A " << side << "3-foot cube has a volume of ";
    cout << volume << "cubic foot.\n";
    cheers(cube(2));    // prototype protection at work
    return 0;
}

void cheers(int n)
{
    for (int i = 0; i < n; i++)
        cout << "Cheers!";
    cout << endl;
}

double cube (double x)
{
    return x*x*x;
}
