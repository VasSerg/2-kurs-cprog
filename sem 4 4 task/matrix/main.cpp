#include <functional>
#include <iostream>
#include "matrix.cpp"

using namespace std;


template<typename T, int MaxRrows, int MaxCols>
Matrix<T,MaxRrows,MaxCols> Transpose(Matrix<T,MaxRrows,MaxCols>&& m)
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

    a.sett(0,0,3);
    a.sett(1,0,1);
    a.sett(0,1,2);

    Matrix<int,2,2> s;

    s.sett(0,0,2);
    s.sett(1,0,5);
    s.sett(0,1,3);


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
