#include <functional>
#include <iostream>
#include "matrix.cpp"

using namespace std;

Matrix&& Transpose(Matrix m)
{
    Matrix r(m.MaxCols, m.MaxRrows);
    for (int i = 0; i < m.MaxRrows; ++i) {
        for (int j = 0; j < m.MaxCols; ++j) {
            r.p[j][i] = m.p[i][j];
        }
    }
    return move(r);
}

int main(){
    Matrix a(2,2);

    a.sett(0,0,3);
    a.sett(1,0,1);
    a.sett(0,1,2);

    Matrix s(2,2);

    s.sett(0,0,2);
    s.sett(1,0,5);
    s.sett(0,1,3);


    cout << "Matrix a \n";
    a.print();
    cout << "Matrix s \n";
    s.print();

    Matrix d(2,2);


    d = a + s;
    cout << "Matrix a + s \n";
    d.print();

    d = a * s;
    cout << "Matrix a * s \n";
    d.print();
    a = Transpose(a);
    cout << "Matrix a Transposed \n";
    a.print();

    Matrix p(2,3);
    //выдаёт ассерт.
    d = a + p;
    // Я пытался сделать проверку в compile time с помощью static_assert(),
    //но для этого размеры матриц должны быть константы. Ну, можно конечно записать перед сложением:
    //static_assert(a.MaxRrows != s.MaxRrows);
    //static_assert(a.MaxCols != s.MaxCols);
    // но тогда надо было всё делать const



    return 0;
}

