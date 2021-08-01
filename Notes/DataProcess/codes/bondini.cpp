// using escape sequences

#include <iostream>
int main()
{
    using namespace std;
    cout << "\aOperation \"HyperHype\" is now activated! \n";
    cout << "Enter your agent code:________\b\b\b\b\b\b\b\b";
    long code;
    cin >> code;
    cout << "\aYour Entered " << code <<"...\n";
    cout << "\aCode verified! Process with plan Z3! \n";

    return 0;
}