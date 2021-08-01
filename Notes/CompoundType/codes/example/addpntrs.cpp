// addpntrs.cpp -- pointer addition

#include <iostream>
int main(int argc, char const *argv[])
{
    using namespace std;
    double wages[3] = {10000.0, 20000.0, 30000.0};
    short stack[3] = {3, 2, 1};

    //Here are two ways to get the address of an array
    double *pw = wages;    //name of an array = address
    short *ps = &stack[0]; // or use address operator
    // with array element
    cout << "pw = " << pw << ", *pw = " << *pw << endl;
    pw = pw + 1;
    cout << "add 1 to the pw pointer:\n";
    cout << "pw = " << pw << ", *pw = " << *pw << endl
         << endl;
    cout << "ps = " << ps << " *ps = " << *ps << endl;
    ps = ps + 1;
    cout << "ps = " << ps << " *ps = " << *ps << endl
         << endl;

    cout << "access two elements with array notation.\n";
    cout << "stack[0] = " << stack[0]
         << "stack[1] = " << stack[1] << endl;
    cout << "access two elements with pointer notation.\n";
    cout << "*stack = " << *stack
         << ", *(stakc + 1 ) = " << *(stack + 1) << endl;

    return 0;
}
