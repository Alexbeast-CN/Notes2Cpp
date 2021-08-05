// arrfun1.cpp -- functions with an array argument

#include <iostream>

const int ArSize = 8;
int sum_arr(int arr[], int n);      //prototype
int main(int argc, char const *argv[])
{
    using namespace std;
    int cookies[ArSize];
    cout << "Please enter 8 numbers" << endl;
    for (int i = 0; i < 8; i++)
        cin >> cookies[i];

    int sum = sum_arr(cookies, ArSize);
    cout << "Total cookies eaten: " << sum << endl;
    return 0;
}

// return the sum of an integer array
int sum_arr(int arr[], int n)
{
    int total = 0;
    for (int i = 0; i <n; i++)
        total = total + arr[i];
    
    return total;
}