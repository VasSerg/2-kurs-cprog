#include <iostream>
#pragma once
#include <cassert>

using namespace std;

template<typename T, int MaxRrows, int MaxCols>
class Matrix {
    public:
        T **p;


    Matrix()
    {
        allocSpace();
        for (int i = 0; i < MaxRrows; ++i) {
            for (int j = 0; j < MaxCols; ++j) {
                p[i][j] = 0;
            }
        }
    }

    void print()
    {
        for (int i = 0; i < MaxRrows; ++i) {
            for (int j = 0; j < MaxCols; ++j) {
                cout << p[i][j] << " ";
            }
            cout << endl;
        }
    }

    T& operator()(int x, int y){
        return p[x][y];
    }

    void sett(int x, int y, T num){
        p[x][y] = num;
    }

    ~Matrix()
    {
        for (int i = 0; i < MaxRrows; ++i) {
            delete[] p[i];
        }
        delete[] p;
    }

    Matrix<T,MaxRrows,MaxCols>(const Matrix<T,MaxRrows,MaxCols>& m)
    {
        allocSpace();
        for (int i = 0; i < MaxRrows; ++i) {
            for (int j = 0; j < MaxCols; ++j) {
                p[i][j] = move(m.p[i][j]);
            }
        }
    }


    Matrix<T,MaxRrows,MaxCols>& operator=(const Matrix<T,MaxRrows,MaxCols>& m)
    {
        if (this == &m) {
            return *this;
        }

        allocSpace();

        for (int i = 0; i < MaxRrows; ++i) {
            for (int j = 0; j < MaxCols; ++j) {
                p[i][j] = m.p[i][j];
            }
        }
        return *this;
    }

    Matrix<T,MaxRrows,MaxCols> operator+(const Matrix<T,MaxRrows,MaxCols>& m)
    {
        Matrix<T,MaxRrows,MaxCols> r;
        for (int i = 0; i < MaxRrows; ++i) {
            for (int j = 0; j < MaxCols; ++j) {
                r.p[i][j] = p[i][j] + m.p[i][j];
            }
        }
        return move(r);
    }

    Matrix<T,MaxRrows,MaxCols> operator-(const Matrix<T,MaxRrows,MaxCols>& m)
    {
        Matrix<T,MaxRrows,MaxCols> r;
        for (int i = 0; i < MaxRrows; ++i) {
            for (int j = 0; j < MaxCols; ++j) {
                r.p[i][j] = p[i][j] - m.p[i][j];
            }
        }
        return move(r);
    }

    template< int MaxRrows1, int MaxCols1>
    Matrix<T,MaxRrows,MaxCols> operator*(const Matrix<T,MaxRrows1,MaxCols1>& m)
    {
        Matrix<T,MaxRrows,MaxCols1> r;
        for (int i = 0; i < MaxRrows; ++i) {
            for (int j = 0; j < MaxCols1; ++j) {
                for (int k = 0; k < MaxCols1; ++k) {
                    r.p[i][j] += (p[i][k] * m.p[k][j]);
                }
            }
        }
        return move(r);
    }

    void allocSpace()
    {
        p = new T*[MaxRrows];
        for (int i = 0; i < MaxRrows; ++i) {
            p[i] = new T[MaxCols];
        }
    }
};

