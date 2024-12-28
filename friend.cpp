#include <iostream>
using namespace std;

class Professional
{
    int salary = 10;
    friend void deductTax(Professional);
};

void deductTax(Professional p)
{
    p.salary -= 2;
}

int main()
{
    Professional p;
    deductTax(p);
    return 0;
}