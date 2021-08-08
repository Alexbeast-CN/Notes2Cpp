#include <iostream>

double Harmonic_mean(double, double);

int main(int argc, char const *argv[])
{
    double x, y;
    std::cout << "Enter two positive numbers: ";
    std::cin >> x >> y;
    while (x > 0 && y > 0)
    {
        double mean = Harmonic_mean(x, y);
        std::cout << "The Harmonic mean of these two number is: "
                  << mean << std::endl
                  << std::endl;
        std::cout << "please enter another two positive numbers: \n"
                  << "(unpositive figure will terminate the programme)\n";
        std::cin >> x >> y;
    }
    std::cout << "-Done-" << std::endl;

    return 0;
}

double Harmonic_mean(double x, double y)
{
    double mean;
    mean = 2.0 * x * y / (x + y);
    return mean;
}