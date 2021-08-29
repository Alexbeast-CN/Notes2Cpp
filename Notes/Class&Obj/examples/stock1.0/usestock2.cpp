// usetock2.cpp -- using the Stock class
// compile with stcok10.cpp
#include <iostream>
#include "stock10.h"

int main(int argc, char const *argv[])
{
    using std::cout;
    cout <<"using constructors to create new objects\n";
    Stock stock1("NanoSmart", 12, 20.0);    // syntax 1
    stock1.show();
    Stock stock2 = Stock ("Boffo Objects", 2, 20);   // syntax 2
    stock2.show();

    cout << "Assigning stock1 to stock 2:\n";
    stock2 = stock1;
    cout << "Listing stock1 and stock2:\n";
    stock1.show();
    stock2.show();

    cout << "Using a constructor to reset an object\n";
    stock1 = Stock("Niftf Foods", 10, 40);  // temp object
    cout << "Revised stock1:\n";
    stock1.show();
    
    return 0;
}
