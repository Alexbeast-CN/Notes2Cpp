// arrstruc.cpp -- an array of structures
#include <iostream>
struct inflatable
{
    char name[20];
    float volume;
    double price;
};
int main(int argc, char *argv[])
{
    using namespace std;
    inflatable guests[2] = // initializing an array of structs
        {
            {"Bambi", 0.5, 21.99},     // first structure in array
            {"Godzilla", 2000, 565.99} // second structure in array
        };

    cout << "The guests " << guests[0].name << " and "
         << guests[1].name << "\nhave a combined volume of "
         << guests[0].volume + guests[1].volume << "cubic cm. \n";

    return 0;
}
