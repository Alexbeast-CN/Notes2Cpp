// getinfo.cpp -- input and output
#include <iostream>

int main()
{
    using namespace std;

    int carrots;

    cout << "How many carots do you have?" << endl;
    //cin.get();
    cin >> carrots; // c++ input
    //cin.get();
    cout << "Here are two more." << endl;
    carrots = carrots + 2;
    cout << "Now you have " << carrots << " carrots." << endl;
    return 0;
}