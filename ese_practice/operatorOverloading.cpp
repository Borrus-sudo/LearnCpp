#include <iostream>
using namespace std;

class Matrix
{
    int matrix[3][3];

public:
    void input()
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cout << "Enter the element number " << (i + 1) * (j + 1);
                cin >> matrix[i][j];
                cout << endl;
            }
        }
    }
    friend Matrix operator+(const Matrix &matrix1, const Matrix &matrix2)
    {
        Matrix matrix3;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                matrix3.matrix[i][j] = matrix1.matrix[i][j] + matrix2.matrix[i][j];
            }
        }
        return matrix3;
    }
    void display(void);
};

void Matrix::display()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << this->matrix[i][j] << endl;
        }
    }
};

int main()
{
    Matrix m1;
    Matrix m2;
    m1.input();
    m2.input();
    Matrix m3 = m1 + m2;
    m3.display();
    return 0;
}