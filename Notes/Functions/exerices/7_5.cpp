#include <iostream>

const int Len = 10;

int Fill_array(double*);
void Show_array(double*, int);
void Reverse_array(double*, int);

using namespace std;

int main(int argc, char const *argv[])
{
    double array[Len] = {0};
    int i = 0;
    cout << "Enter a array: ";
    i = Fill_array(array);
    cout << endl;
    cout << "The array is: [";
    Show_array(array, i);
    cout << "]";
    cout << endl;
    cout << "\nThe inverse array is: [";
    Reverse_array(array, i);
    cout << "]";
    return 0;
}

int Fill_array(double* ar)
{
    int j = 0;
    while(cin.peek()!='\n')
    {   
        cin >> ar[j];
        j++;  
    }
        
    return j;
}
void Show_array(double* ar, int n)
{
    int j;
    for (j = 0; j < n; j++)
        cout << ar[j] << " ";
}
void Reverse_array(double* ar, int n)
{
    int m = n-1;
    for (m; m >= 0; m--)
        cout << ar[m] << " ";
}