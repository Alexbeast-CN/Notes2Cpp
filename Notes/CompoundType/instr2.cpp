// instr.cpp -- read more than one word with get() & get()

#include <iostream>
int main(int argc, char *argv[])
{
    using namespace std;
    const int ArSize = 20;
    char name[ArSize];
    char city[ArSize];

    cout << "What's your name? \n";
    cin.get(name,ArSize).get();
    cout << "Which city do you live in? \n";
    cin.get(city,ArSize).get();


    cout << "Okey, now I know you're " << name << " and you live in ";
    cout << city << endl;

    return 0;
}