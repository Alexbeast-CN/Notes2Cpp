// auto.cpp -- illustrating scope of automatic variables
#include <iostream>
void oil(int years)
{
    using namespace std;

    int texas = 2;
    cout << "In oil(), texas = " << texas << ", &texas =";
    cout << &texas << endl;
    cout << "In oil, years = " << years << ", &years = ";
    cout << &years << endl;
    {
        int texas = 113;
        cout << "In block(), texas = " << texas << ", &texas =";
        cout << &texas << endl;
    }
    cout << "Post-block texas = " << texas;
    cout << ", &texas = " << &texas << endl;
}

int main(int argc, char *argv[])
{
    using namespace std;

    int texas = 31;
    int years = 2011;
    cout << "In main(), texas = " << texas << ", &texas =";
    cout << &texas << endl;
    cout << "In main, years = " << years << ", &years = ";
    cout << &years << endl;
    oil(texas);
    cout << "In main(), texas = " << texas << ", &texas =";
    cout << &texas << endl;
    cout << "In main, years = " << years << ", &years = ";
    cout << &years << endl;
    return 0;
}
