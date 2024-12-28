#include <iostream>
using namespace std;

class Hello
{
public:
    int side;
    Hello()
    {
        cout << "Default constructor" << endl;
        side = 10;
    }
    Hello(int holder)
    {
        cout << "Via the parametric constructor" << endl;
        side = holder;
    }
    Hello(Hello &obj)
    {
        obj.side = 100;
        cout << "Via the copy constructor" << endl;
        side = obj.side;
    }
};
int main()
{
    Hello a = Hello(30); // Copy Elison at play which prevents the unnecessary Copy Constructor call
    Hello b = 20;
    Hello c(30);
    Hello d = a;
    cout << a.side << endl;
    cout << d.side;
    return 0;
};