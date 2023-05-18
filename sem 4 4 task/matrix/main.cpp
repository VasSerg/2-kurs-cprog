#include <functional>
#include <iostream>
#include "matrix.cpp"

using namespace std;


template<typename T=int>
Matrix<T> Transpose(Matrix<T> m)
{
    Matrix<T> r(m.MaxCols, m.MaxRrows);
    for (int i = 0; i < m.MaxRrows; ++i) {
        for (int j = 0; j < m.MaxCols; ++j) {
            r.p[j][i] = m.p[i][j];
        }
    }
    return move(r);
}

int main(){
    Matrix<int> a(2,2);

    a.sett(0,0,3);
    a.sett(1,0,1);
    a.sett(0,1,2);

    Matrix<int> s(2,2);

    s.sett(0,0,2);
    s.sett(1,0,5);
    s.sett(0,1,3);


    cout << "Matrix a \n";
    a.print();
    cout << "Matrix s \n";
    s.print();

    Matrix<int> d(2,2);


    d = a + s;
    cout << "Matrix a + s \n";
    d.print();

    d = a * s;
    cout << "Matrix a * s \n";
    d.print();
    a = Transpose(a);
    cout << "Matrix a Transposed \n";
    a.print();

    Matrix<int> p(2,3);
    d = a + p;



    return 0;
}
