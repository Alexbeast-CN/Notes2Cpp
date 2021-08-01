// arrayone.cpp -- samll array of integers
#include <iostream>

int main(int argc, char const *argv[])
{
    using namespace std;

    int yams[3];
    yams[0] = 7;
    yams[1] = 8;
    yams[2] = 6;

    int yamscost[3] = {20, 30, 5};

    cout << "Total yams = " << yams[0] + yams[2] + yams[1];
    cout << endl;
    cout << "The package with " << yams[1] << " yams costs ";
    cout << yamscost[1] << " cent per yam. \n";
    int total = yams[0] * yamscost[0] + yams[1] * yamscost[1] + yams[2] * yamscost[2];
    cout << "The total yam expense is " << total << " cents.\n";

    cout << "\nSize of yams array = " << sizeof yams;
    cout << " bytes. \n";
    cout << "Size of one element = " << sizeof yams[0];
    cout << " bytes. \n";
    return 0;
}
