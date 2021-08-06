// arrfun3.cpp -- functions with an array range

#include <iostream>

const int ArSize = 8;
int sum_arr(int *begin, int *end); //prototype
int main(int argc, char const *argv[])
{
    using namespace std;
    int cookies[ArSize];
    cout << "Please enter 8 numbers" << endl;
    for (int i = 0; i < 8; i++)
        cin >> cookies[i];

    int sum = sum_arr(cookies, cookies + ArSize);
    cout << "Total cookies eaten: " << sum << endl;
    sum = sum_arr(cookies, cookies + 3);
    cout << "The first 3 eater ate: " << sum << " cookies. \n";

    sum = sum_arr(cookies + 4, cookies + 8);
    cout << "The last 4 eaters ate: " << sum << " cookies. \n";

    return 0;
}

// return the sum of an integer array
int sum_arr(int *begin, int *end)
{
    const int *pt;
    int total = 0;

    for (pt = begin; pt != end; pt++)
        total = total + *pt;
    return total;
}