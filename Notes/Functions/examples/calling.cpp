// calling.cpp -- defining,prototyping and calling a fucntion

#include <iostream>

void simple();  //function prototype

int main(int argc, char *argv[])
{
    using namespace std;
    cout << "main() will call the simple() function: \n";
    simple();   //function call
    cout << "main() is finished with the simple() function. \n";
    // cin.get();
    return 0;
}

void simple()
{
    using namespace std;
    cout << "I'm but a simple function.\n";
}
