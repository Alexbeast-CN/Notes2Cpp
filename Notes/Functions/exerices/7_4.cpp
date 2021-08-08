#include <iostream>

uint16_t factorial(uint16_t n);

using namespace std;

int main(int argc, char const *argv[])
{
    uint16_t n;
    cout << "Enter a nature number: ";
    while (cin >> n)
    {
        int n2 = factorial(n);
        cout << n << "! = " << n2 << endl;
        cout << "Enter another number (q to quit): ";
    }

    cout << "-Done-\n";
    return 0;
}

uint16_t factorial(uint16_t n)
{
    if (n == 0)
        return 1;

    return n * factorial(n - 1);
}
