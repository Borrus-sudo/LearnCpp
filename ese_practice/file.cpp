#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    fstream hello;
    hello.open("test.txt", ios::out | ios::app | ios::in);
    char c[] = "Hello World!!";
    cout << hello.tellg() << endl;
    cout << hello.tellp() << endl;
    hello.put('h');
    cout << hello.tellg() << endl;
    cout << hello.tellp() << endl;
    char c1;
    if (hello)
        cout << "exists";
    // hello.seekg(0);
    hello.get(c1);
    hello.get(c1);
    cout << hello.tellg();
    cout << hello.tellp() << endl;
    hello.close();
    cout << c1 << "This>>";

    return 0;
}