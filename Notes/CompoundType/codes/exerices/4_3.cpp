#include <iostream>
#include <array>
#include <cmath>

using namespace std;
int main(int argc, char const *argv[])
{
    array<double, 3> results;
    double sum{0};
    double max{0};
    double min{0};

    for (int i = 0; i <= 2; i++)
    {
        cout << "Please enter the jump result for the " << i + 1 << " time is:  ";
        cin >> results[i];
        sum = sum + results[i];
    }

    cout << "The results are:" << endl;
    max = results[0];
    min = results[0];
    for (int n = 0; n <= 2; n++)
    {
        cout << "The result for the " << n + 1 << "time is:" << endl;
        cout << results[n];
        if (max <= results[n])
        {
            max = results[n];
        }
        if (min >= results[n])
        {
            min = results[n];
        }
    }
    cout << "The average result for the athlete is: " << sum / 3 << endl;
    cout << "The best result is: " << max << endl;
    cout << "The worst result is: " << min << endl;

    return 0;
}
