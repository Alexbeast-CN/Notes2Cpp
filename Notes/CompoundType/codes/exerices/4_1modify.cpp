#include <iostream>

struct StudentInfo
{
    char FirstName[20];
    char LastName[20];
    char grade[20];
    int age;
} Student1;

int main(int argc, char const *argv[])
{
    using namespace std;
    cout << "What's your full name? ";
    cin >> Student1.FirstName >> Student1.LastName;
    cin.get();
    cout << "What letter grade do you deserve? ";
    cin.getline(Student1.grade, 20);
    cout << "What's your age? ";
    cin >> Student1.age;
    cout << "Name: " << Student1.FirstName << " " << Student1.LastName << endl;
    cout << "Grade: " << Student1.grade << endl;
    cout << "Age: " << Student1.age << endl;

    return 0;
}