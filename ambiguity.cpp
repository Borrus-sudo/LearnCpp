#include <iostream>
using namespace std;

class A
{
public:
    A() { cout << "Default constructor" << endl; }
    explicit A(int x = 1) { cout << "Constructor with x = " << x << endl; }
};

int main()
{
    // Why is this not an implicit constructor call?
    A obj;
    cout << "Hello World";
    return 0;
}
