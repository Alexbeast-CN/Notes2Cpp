// instr.cpp -- read more than one word in getlin()

#include <iostream>
int main(int argc, char *argv[])
{
    using namespace std;
    const int ArSize = 20;
    char name[ArSize];
    char city[ArSize];

    cout << "What's your name? \n";
    cin.getline(name,ArSize);
    cout << "Which city do you live in? \n";
    cin.getline(city,ArSize);


    cout << "Okey, now I know you're " << name << " and you live in ";
    cout << city << endl;

    return 0;
}
