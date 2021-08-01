// pointer.cpp -- our first pointer variable

#include<iostream>
using namespace std;

int main(int argc, char *argv[])
{
    int update = 6;
    int *p_update;  // declare pointer to an int
    p_update = &update; // assign address of int to pointer

    cout << "Values: update = " << update;
    cout << " *p_update is " << *p_update << endl;

    cout << "Address: &update = " << &update;
    cout << " p_update = " << p_update << endl;

    // use pointer to change value
    *p_update = *p_update+1;
    cout << "Now update = " << update << endl;

    return 0;
}
