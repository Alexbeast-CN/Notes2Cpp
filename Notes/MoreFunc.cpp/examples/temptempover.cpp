// tempover.cpp -- template overloading
#include <iostream>

template <class T>      // template A
void ShowArray(T arr[], int n);

template <class T>
void ShowArray(T *arr[], int n);

struct debts
{
    char name[50];
    double amount;
};


int main(int argc, char const *argv[])
{
    using namespace std;
    int things[6] = {12, 32, 103, 302, 310, 130};
    struct debts mr_E[3] = 
    {
        {"Ima Wolfe", 2400.0},
        {"Ura Foxe", 1300.0},
        {"Iby Stout", 1800.0}
    };

    double * pd[3];

    // set pointer to the amount members of the structures in mr_E
    for (int i = 0; i < 3; i++)
    {
        pd[i] = &mr_E[i].amount;
    }

    cout << "Listing Mr.E's counts of things:\n";
    // things is an array of int
    ShowArray(things, 6);   // uses template A
    cout << "Listing Mr.E's debts:\n";
    ShowArray(pd,3);    // uses template B
    return 0;
}


template<typename T>
void ShowArray(T arr[], int n)
{
    using namespace std;
    cout << "template A\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ' ';
    }
    cout  << endl;
}

template<typename T>
void ShowArray(T * arr[], int n)
{
    using namespace std;
    cout << "template B\n";
        for (int i = 0; i < n; i++)
    {
        cout << *arr[i] << ' ';
    }
    cout  << endl;

}