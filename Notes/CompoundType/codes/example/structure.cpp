// structure.cpp -- a simple structrue.

#include <iostream>
#include <cmath>
using namespace std;

struct Classmates
{
    char name[20];
    float height;
    float weight;
    int student_num;
};

int main(int argc, char *argv[])
{
    Classmates Tim =
    {
        "Tim",  // name value of Tim  
        180,    // height value of Tim
        67,     // weight value of Tim
        02      // Tim's student number
    };
//Tim is a structure variable of type Classmats

    Classmates Tom =
    {
        "Tom",
        177,
        68,
        06
    };

    Classmates Lucas =
    {
        "Lucas",
        190,
        78,
        27
    };


    cout << "There are 3 people in the list"
          << " namely: \n" << Tom.name << endl
          << Tim.name << endl << Lucas.name 
          << endl<<endl;

    cout << "The hight of Lucas is " << Lucas.height
        << "\nThe student number of Tom is " << Tom.student_num
        << "\nThe weight of Tim is " << Tim.weight
        << endl;

    return 0;
}

