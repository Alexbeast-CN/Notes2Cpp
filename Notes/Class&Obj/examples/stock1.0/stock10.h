// stock10.h -- Stock class declaration with constructors, desturctor added
#ifndef STOCK10_H_
#define STOCK10_H_
#include <string>

class Stock
{
private:
    std::string company;
    long shares;
    double share_val;
    double total_val;
    void set_tot() { total_val = shares * share_val; }

public:
    Stock(/* args */);  // default constructor
    Stock(const std::string &co, long n, double pr);
    ~Stock();           // default destructor
    void buy(long num, double price);
    void sell(long num, double price);
    void update(double price);
    void show();
};

#endif