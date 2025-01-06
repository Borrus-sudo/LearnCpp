#include <iostream>
using namespace std;

class A
{
public:
    void display()
    {
        cout << "Hello the display!!";
    };
};

class B : virtual public A
{
    string name;

public:
    void display()
    {
        cout << "Hello the display from class B " << name;
    }
};
class C : virtual public A
{
    string name;

public:
    void display()
    {
        cout << "Hello the display from class C " << name;
    }
};

class D : public B, public C
{
    string name;

public:
    // void display()
    // {
    //     cout << name << endl;
    //     B::display();
    //     A::display();
    // }
};
int main()
{
    D d;
    d.A::display();
    
    return 0;
}