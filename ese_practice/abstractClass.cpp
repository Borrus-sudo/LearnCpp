#include <iostream>
using namespace std;

// Use Abstract Class, Virtual Functions, Virtual Class

class Shape
{
public:
    string name;

public:
    Shape(string name) : name(name)
    {
        cout << "Hello From Shape Constructor";
    };
    virtual Shape &draw(int, int) = 0;
    virtual void debug()
    {
        cout << "Debug Function You Know!!!" << this->name;
    }
};

class Circle : public Shape
{
    string name;

public:
    Circle(string name) : Shape(name), name(name + "Child")
    {
        cout << "Hello From Circle Constructor";
    };
    Circle &draw(int x, int y)
    {
        cout << "Drawing@!!!";
        return *this;
    };
};

class Rect : public Shape
{
    string name;

public:
    Rect(string name) : Shape(name), name(name)
    {
        cout << "Hello From Rectangle Constructor";
    }
    Rect &draw(int x, int y)
    {
        cout << "Drawing a rectangle";
        return *this;
    }
};

void loop(Shape &s)
{
    s.draw(10, 10).debug();
}

int main()
{
    Circle c("My Circle!!!!");
    loop(c);
    return 0;
}