// strtype1.cpp -- using the C++ string class
#include <iostream>
#include <cstring>

int main(int argc, char *argv[])
{
    using namespace std;

    char animal1[20];
    char animal2[20] = "jaguar";
    string str1;
    string str2 = "panther";

    cout << "Enter a kind of feline." << endl;;
    cin.get(animal1,20).get();
    cout << "Enter another feline." << endl;
    cin >> str1;
    cout << "Here are some felines: " <<
    animal1 << " " << animal2 << " " <<
    str1 << " " << str2 << endl;
    cout << "The third letter in " << animal2 <<
    " is " << animal2[2] << endl;
    cout << "The third letter in " << str2 <<
    " is " << str2[2] << endl;

    return 0;
}
