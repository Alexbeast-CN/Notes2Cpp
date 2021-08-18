// func.cpp -- contains fucntions called in main.cpp

#include <iostream>
#include <cmath>
#include "coordin.h"    // structure templates, function prototypes

// convert rectangular to polar coordinates
polar rect2polar(rect xypos)
{
    using namespace std;
    polar answer;

    answer.distance =
        sqrt( pow(xypos.x,2) + pow(xypos.y,2));

    answer.angle = 
        atan2(xypos.y, xypos.x);
        return answer;
}

// show polar coordinates, converting angle to degrees
void show_polar(polar dapos)
{
    using namespace std;
    const double Rad2deg = 180/3.14;

    cout << "distance = " << dapos.distance;
    cout << "angle = " << dapos.angle * Rad2deg;
    cout << " degrees\n";
}
