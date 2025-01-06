#include <iostream>
using namespace std;

class Vec
{
public:
    double val;

public:
    Vec(double v) : val(v) {}
    friend Vec operator +(Vec v1, Vec v2)
    {
        return Vec(v1.val + v2.val);
    };
};

// Vec operator+(Vec v1, Vec v2)
// {
//     return Vec(v1.val + v2.val);
// }
int main()
{
    Vec v1(0);
    Vec v2(1);
    Vec v3(0);
    v3 = v1 + v2;
    cout << v3.val;
    return 0;
}