// lotto.cpp -- probability of winning

#include <iostream>

double probability(uint16_t numbers, uint16_t picks);

int main(int argc, char const *argv[])
{
    using namespace std;
    double total, choices;
    cout << "Enter the total number of choices of the game"
         << " card and the number of picks allowed:\n";
    while ((cin >> total >> choices) && choices <= total)
    {
        cout << "You have one chance in ";
        cout << probability(total, choices); // compute the odds
        cout << " of winning. \n";
        cout << "Next two numbers (q to quit): ";
    }
    cout << endl;
    return 0;
}

double probability(uint16_t numbers, uint16_t picks)
{
    double result = 1.0; // here come some local variables
    double n;
    uint16_t p;

    for (n = numbers, p = picks; p > 0; n--, p--)
        result = result * n / p;
    return result;
}
