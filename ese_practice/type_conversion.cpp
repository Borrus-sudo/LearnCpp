// WON'T WORK!!!!
#include <iostream>
using namespace std;
class B;
class A
{

public:
    float val;
    A(float v = 0) : val(v)
    {
    }
    A(const B &b)
    {
        val = b.a;
    }
};

class B
{
public:
    int a = 10;
    operator float()
    {
        return a;
    }
};

int main()
{
    // Write C++ code here
    B b;
    A a = b;
    cout << a.val;
    // cout << b;
    // std::cout << "Try programiz.pro";

    return 0;
}