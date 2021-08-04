// twoarg.cpp -- a function with 2 argumnets

#include <iostream>
using namespace std;

void n_chars(char, int);
int main(int argc, char const *argv[])
{
    int times;
    char ch;

    cout << "Enter a character: ";
    cin >> ch;

    while (ch != 'q') // q to quit
    {
        cout << "Enter an inter: ";
        cin >> times;
        n_chars(ch, times); // function with 2 arguments
        cout << "\nEnter another character or press the "
        << "q-key to quit.\n";
        cin >> ch;
    }
    cout << "The value of times is " << times << endl;
    return 0;
}

void n_chars(char ch, int n)
{
    while (n-- >0)
    {
        cout << ch;
    }
}
