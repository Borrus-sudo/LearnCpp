#include <iostream>
using namespace std;

class Vehicle
{
public:
    virtual void display()
    {
        cout << "Ford";
    }
};

class Car : public Vehicle
{
    int price;

public:
    Car(int p = 10000) : price(p) {

                         };
    void display() override
    {
        cout << "Mustang";
    }
};
    
void display(Vehicle&);

int main()
{
    
    Car c1;
    Vehicle *v = &c1;
    v ->display();
    c1.display();
    display(c1);
    return 0;
}

void display(Vehicle &v)
{
    v.display();
}