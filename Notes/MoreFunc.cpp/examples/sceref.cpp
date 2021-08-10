// sceref.cpp -- defining and using a reference

#include <iostream>
int main(int argc, char const *argv[])
{
    using namespace std;
    int rats = 101;
    int &rodents = rats; // rodents is a reference
    cout << "rats = " << rats;
    cout << ", rodents = " << rodents << endl;

    cout << "rats address = " << &rats;
    cout << ", rodents address = " << &rodents << endl;

    int bunnies = 50;
    rodents = bunnies;
    cout << "bunnies = " << bunnies;
    cout << ", rats = " << rats;
    cout << ", rodents = " << rodents << endl;

    cout << "bunnies address is " << &bunnies << endl;
    
    cout << "rats address is " << &rats << endl;
    
    cout << "rodents address is " << &rodents << endl;

    return 0;
}
