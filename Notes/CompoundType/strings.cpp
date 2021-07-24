// strings.cpp -- store string in an array
#include <iostream>
#include <cstring>

int main(int argc, char *argv[])
{
    using namespace std;
    const int Size = 15;
    char name1[Size];   // empty array  
    char name2[Size] = "C++ Oldboy";// initialized array

    cout << "Howdy! I'm " << name2;
    cout << "What's your name? \n";
    cin >> name1;
    cout << "Well, " << name1 << " your name has ";
    cout << strlen(name1) << " letters and is stored\n";
    cout << "in an array of " << sizeof(name1) << " bytes. \n";
    name2[3] = '\0';    // set to null character
    cout << "Your initial letter is " << name1[0] << endl;
    cout << "Here are the first three letter of my name: ";
    cout << name2 << endl;

    return 0;
}
