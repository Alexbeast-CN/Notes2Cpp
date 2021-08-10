// firstref.cpp -- defining and using reference
# include <iostream>
int main(int argc, char const *argv[])
{
    using namespace std;
    int rats = 101;
    int & rodents = rats;   // rodents is a reference
    cout << "rats = " << rats;
    cout <<", rodents = " << rodents << endl;
    rodents++;
    cout << "rats = " << rats;
    cout <<", rodents = " << rodents << endl;

    // some implementation require type casting the following
    // addressed to type unsigned
    cout << "rats address = " << &rats;
    cout << ", rodents address = " << &rodents <<endl;
    return 0;
}
