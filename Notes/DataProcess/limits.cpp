// limits.cpp -- some integer limits

#include <iostream>
#include <cmath>
#include <climits> // use limit.h for older system

int main()
{
    using namespace std;
    int n_int = INT_MAX;      // initialize n_int to the max int value
    short n_short = SHRT_MAX; // symbols defined in climits file
    long n_long = LONG_MAX;
    long long n_llong = LLONG_MAX; 

    // sizeof operator yields size of type or of variable
    cout << "int is " << sizeof (int) << " bytes." << endl;
    cout << "short is " << sizeof n_short << " bytes." << endl;
    cout << "long is " << sizeof n_long << " bytes." << endl;
    cout << "long long is " << sizeof n_llong << " bytes." << endl;
    cout << endl;

    cout << "Maximum values:" << endl;
    cout << "int: " << n_int << " = 2^" << log2(n_int) << endl;
    cout << "short: " << n_short << " = 2^" << log2(n_short) << endl;
    cout << "long: " << n_long << " = 2^" << log2(n_long)<< endl;
    cout << "long long: " << n_llong << " = 2^" << log2(n_llong)<< endl;
    cout << endl;

    cout << "minimum int value = " << INT_MIN << endl;
    cout << "Bits per byte = " << CHAR_BIT << endl;

}