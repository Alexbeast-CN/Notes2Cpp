#include <iostream>

struct Pizza
{
    char Company[20];
    float Diameter;
    float Weight;
};

int main(int argc, char const *argv[])
{
    Pizza *p = new Pizza;

    std::cout << "Enter the company name.\n";
    std::cin.getline(p->Company, 20);
    std::cout << "Enter the Pizza's diameter in inch.\n";
    std::cin >> p->Diameter;
    std::cout << "Enter the Pizza's weight in kg.\n";
    std::cin >> p->Weight;

    std::cout << "Company: " << p->Company << std::endl;
    std::cout << "Diameter: " << p->Diameter << std::endl;
    std::cout << "weight: : " << p->Weight << std::endl;

    delete p;
    return 0;
}
