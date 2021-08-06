// strfun.cpp -- functions with a string argument

#include <iostream>
uint16_t c_in_str(const char * str, char ch);

int main()
{
    using namespace std;
    char mmm[15] = "minimum";   // string in an array
    // char uuu[15] = "ululate";
    char * wail = "ululate";    // wail points to string

    uint16_t ms = c_in_str(mmm,'m');
    uint16_t us = c_in_str(wail,'u');
    cout << ms << " m characters in " << mmm << endl;
    cout << us << " u characters in " << wail << endl;

    return 0;
}

uint16_t c_in_str (const char * str, char ch)
{
    uint16_t count = 0;

    while (*str)            //quit when *str is '\0'
    {
        if (*str == ch)
            count++;
        str++;              // move pointer to next char
    }
    return count;
}
