#include <iostream>
//constants
const int N = 10;

// prototypes
int fill_table(double *);
void display(const double *, int);
void mean(double *, int);

using namespace std;

int main(int argc, char const *argv[])
{
    double ar[10];
    cout << "Please enter the resluts: \n";
    int i = fill_table(ar);
    display(ar, i);
    mean(ar, i);

    return 0;
}

int fill_table(double *ar)
{
    int i;
    for (i = 0; i < N; i++)
    {
        cout << "#" << i + 1 << ": ";
        cin >> ar[i];
        if (ar[i] < 0)
            break;
    }
    return i;
}

void display(const double *ar, int i)
{
    cout << "The results are: \n";
    for (int j = 0; j < i; j++)
        cout << ar[j] << " ";
    cout << endl;
}

void mean(double * arr, int i)
{
    double sum = 0;
    for (int j = 0; j < i; j++)
        sum += arr[j];
    double mean = sum / i;
    cout << "The mean of the results is: " << mean << endl;
}
