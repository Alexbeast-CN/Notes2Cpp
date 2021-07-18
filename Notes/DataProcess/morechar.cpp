// morechar.cpp -- the char type and int type constreasted 
#include <iostream>
int main()
{
    using namespace std;
    char ch = 'M';  //asign ASCII code for M to ch
    int i =ch;  // store the same code in int
    cout << "The AXCII code for " << ch << " is " << i << endl;

    cout << "Add one to the character code" << endl;
    ch = ch + 1;    //change character code in ch
    i = ch;
    cout << "The AXCII code for " << ch << " is " << i << endl;
    
    // using the cout.put() the display the char
    cout << "Display the char in cout.put(): ";
    cout.put(ch);
    cout.put('!');
    cout << endl;
    cout << endl;
    cout.put(i);
    cout << endl << "Done" << endl;
    return 0;
}