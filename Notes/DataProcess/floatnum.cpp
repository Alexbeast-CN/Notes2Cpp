// floatnum.cpp -- floating-point types

#include <iostream>
using namespace std;
main()
{
    cout.setf(ios_base::fixed, ios_base::floatfield);

    float tub = 10.0 / 3.0;   //可以精确到小数点后六位数
    double mint = 10.0 / 3.0; //可以精确到小数点后15位数
    const float million = 1.0e6;

    cout << "tub = " << tub;
    cout << ", a minllion tub = " << million * tub;
    cout << ", \nand ten million tub = " << 10 * million * tub;
    cout << endl;

    cout << "mint = " << mint << ", and a million mint = ";
    cout << million * mint << endl;

    return 0;
}
