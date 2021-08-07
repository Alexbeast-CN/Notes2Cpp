// strctfun.cpp -- functions with a sturcture argument
#include <iostream>
#include <cmath>

// structure delarations
struct polar
{
    double distance;
    double angle;
};

struct rect
{
    double x;
    double y;
};

// prototypes
polar rect2polar(rect xypos);
void show_polar(polar dapos);

int main(int argc, char const *argv[])
{
    using namespace std;
    rect rpoint;
    polar ppoint;

    cout << "Enter the x and y values: ";
    while (cin >> rpoint.x >> rpoint.y)
    {
        ppoint = rect2polar(rpoint);
        show_polar(ppoint);
        cout << "Next two numbers (q to quit): ";
    }

    cout << "Done. \n";
    return 0;
}

// convert rectangular to polar coordinates
polar rect2polar(rect xypos)
{
    using namespace std;
    polar answer;

    answer.distance =
        sqrt(pow(xypos.x, 2) + pow(xypos.y, 2));

    answer.angle = atan2(xypos.y, xypos.x);

    return answer;
}

// show polar coordinates, coverting angle to degrees
void show_polar(polar dapos)
{
    using namespace std;
    const double rad_to_deg = 180 / 3.1415;

    cout << "distance = " << dapos.distance << endl;
    cout << "angle = " << dapos.angle * rad_to_deg;
    cout << " degree\n";
}