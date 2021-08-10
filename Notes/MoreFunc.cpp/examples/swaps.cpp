// swaps.cpp -- swapping with references and pointers
#include <iostream>
void swapr(int & a, int & b)    // a, b aliases for ints
{
    int temp;

    temp = a;   // use a, b for values of variables
    a = b;
    b = temp;
}

void swapp(int *p, int *q)      // p, q are addresses of ints
{
    int temp;

    temp = *p;  // use *p and *q for values of variables
    *p = *q;
    *q = temp;
}

void swapv(int a, int b)        // a, b are new variables
{
    int temp;

    temp = a;   // use a and b for values of varibales
    a = b;
    b = temp;
}

int main(int argc, char const *argv[])
{
    using namespace std;
    int wallet1 = 300;
    int wallet2 = 250;
    cout << "wallet1 = $" << wallet1;
    cout << " wallet2 = $" << wallet2 << endl;

    cout << "Using references to swap contents:\n";
    swapr(wallet1, wallet2);    // pass variables
    cout << "wallet1 = $" << wallet1;
    cout << " wallet2 = $" << wallet2 << endl;

    cout << "Using pointer to swap contents:\n";
    swapp(&wallet1, &wallet2);    // pass variables
    cout << "wallet1 = $" << wallet1;
    cout << " wallet2 = $" << wallet2 << endl;

    cout << "Tring to use passing by vlaue:\n";
    swapv(wallet1, wallet2);    // pass variables
    cout << "wallet1 = $" << wallet1;
    cout << " wallet2 = $" << wallet2 << endl;  
    return 0;
}
