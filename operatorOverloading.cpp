#include <iostream>
using namespace std;

class Vec
{
    double val;
    Vec(double v) : val(v) {}
    friend Vec operator+(Vec v1, Vec v2);
};

Vec operator+(Vec v1, Vec v2)
{
    return Vec(v1.val + v2.val);
}
int main()
{
    return 0;
}