#include <functional>
#include <iostream>
#include "matrix.cpp"

using namespace std;


template<typename T, int MaxRrows, int MaxCols,class allocSpace = alS<T>>
Matrix<T,MaxRrows,MaxCols,allocSpace> Transpose(Matrix<T,MaxRrows,MaxCols,allocSpace>&& m)
{
    Matrix<T,MaxRrows,MaxCols> r;
    for (int i = 0; i < MaxRrows; ++i) {
        for (int j = 0; j < MaxCols; ++j) {
            r.p[j][i] = m.p[i][j];
        }
    }
    return r;
}

int main(){
    Matrix<int,2,2> a;
    a[0][0] = 1;
    a[1][0] = 3;
    a[0][1] = 2;

    Matrix<int,2,2> s;

    s[0][0] = 1;
    s[1][0] = 5;
    s[0][1] = 3;



    cout << "Matrix a \n";
    a.print();
    cout << "Matrix s \n";
    s.print();

    Matrix<int,2,2> d;


    d = a + s;
    cout << "Matrix a + s \n";
    d.print();

    d = a * s;
    cout << "Matrix a * s \n";
    d.print();
    a = Transpose(move(a));
    cout << "Matrix a Transposed \n";
    a.print();

    Matrix<int,2,3> p;
    //d = a + p;



    return 0;
}
