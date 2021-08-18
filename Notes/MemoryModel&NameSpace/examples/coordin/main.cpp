// file1.cpp -- example of a three-file program
#include <iostream>
#include "coordin.h"    // 由于我的头文件和cpp文件放在同一路径内，所以这里直接包含头文件名

using namespace std;
int main(int argc, char *argv[])
{
    rect rplace;
    polar pplace;

    cout << "Enter the x and y values: ";
    while (cin >> rplace.x >> rplace.y)
    {
        pplace = rect2polar(rplace);
        show_polar(pplace);
        cout << "Next two numbers (q to quit): ";
    }
    cout << "Bye!\n";
    return 0;
}
