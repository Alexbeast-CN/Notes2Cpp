// leftover.cpp -- overloading the left() function
#include <iostream>

// This function returns the first ct digits of the number num
uint64_t left(uint64_t num, uint8_t ct)
{
    uint64_t digits = 1;
    uint64_t n = num;

    if (ct == 0 || num == 0)
        return 0;
    while (n /= 10)
        digits++;
    if (digits > ct)
    {
        ct = digits - ct;
        while (ct--)
            num /= 10;
        return num; // return left ct digits
    }
    else
        return num;
}

// This function returns a pointer to a new string
// consisting of the first n characters in the str string
char *left(const char *str, int n = 1)
{
    if (n < 0)
        n = 0;
    char *p = new char[n + 1];
    int i;
    for (i = 0; i < n && str[i]; i++)
        p[i] = str[i]; // copy characters
    while (i <= n)
        p[i++] = '\0'; // set rest of string to '\0'
    return p;
}

int main(int argc, char *argv[])
{
    using namespace std;
    char trip[9] = "Hawaii!!"; //test value
    uint64_t n = 12345678;     // test value
    int i;
    char *temp;

    for (i = 0; i < 10; i++)
    {
        cout << left(n,i) << endl;
        temp = left(trip, i);
        cout << temp << endl;
        delete[] temp; // point to temporary storage
    }
    return 0;
}
