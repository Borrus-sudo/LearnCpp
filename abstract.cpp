class Abstract
{
public:
    virtual void implement() = 0;
};

class Implement : public Abstract
{
public:
    void implement() {
        // cout << "Hello";
    };
};

void implement(Abstract *a)
{
    (*a).implement();
    a -> implement();
}

int main()
{
    Implement i1;
    Abstract *a = &i1;
    i1.implement();
    implement(a);
    return 0;
}