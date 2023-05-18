#include <iostream>
#pragma once
#include <cassert>

using namespace std;


template <typename T>
class alS{
    public:
    auto operator()(int MaxRrows, int MaxCols){
        T **p;
        p = new T*[MaxRrows];
        for (int i = 0; i < MaxRrows; ++i) {
            p[i] = new T[MaxCols];
        }
        return p;
    }
};


template<typename T, int MaxRrows, int MaxCols, class allocSpace = alS<T>>
class Matrix {
    public:
        T **p;


    Matrix()
    {
        p = allocSpace()(MaxRrows,MaxCols);
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


    T* operator[](int x){
        return p[x];
    }

    ~Matrix()
    {
        for (int i = 0; i < MaxRrows; ++i) {
            delete[] p[i];
        }
        delete[] p;
    }

    Matrix<T,MaxRrows,MaxCols,allocSpace>(const Matrix<T,MaxRrows,MaxCols,allocSpace>& m)
    {
        allocSpace()(MaxRrows,MaxCols);
        for (int i = 0; i < MaxRrows; ++i) {
            for (int j = 0; j < MaxCols; ++j) {
                p[i][j] = move(m.p[i][j]);
            }
        }
    }


    Matrix<T,MaxRrows,MaxCols,allocSpace>& operator=(const Matrix<T,MaxRrows,MaxCols,allocSpace>& m)
    {
        if (this == &m) {
            return *this;
        }

        allocSpace()(MaxRrows,MaxCols);

        for (int i = 0; i < MaxRrows; ++i) {
            for (int j = 0; j < MaxCols; ++j) {
                p[i][j] = m.p[i][j];
            }
        }
        return *this;
    }

    Matrix<T,MaxRrows,MaxCols,allocSpace> operator+(const Matrix<T,MaxRrows,MaxCols,allocSpace>& m)
    {
        Matrix<T,MaxRrows,MaxCols> r;
        for (int i = 0; i < MaxRrows; ++i) {
            for (int j = 0; j < MaxCols; ++j) {
                r.p[i][j] = p[i][j] + m.p[i][j];
            }
        }
        return r;
    }

    Matrix<T,MaxRrows,MaxCols,allocSpace> operator-(const Matrix<T,MaxRrows,MaxCols,allocSpace>& m)
    {
        Matrix<T,MaxRrows,MaxCols> r;
        for (int i = 0; i < MaxRrows; ++i) {
            for (int j = 0; j < MaxCols; ++j) {
                r.p[i][j] = p[i][j] - m.p[i][j];
            }
        }
        return r;
    }

    template< int MaxRrows1, int MaxCols1>
    Matrix<T,MaxRrows,MaxCols1,allocSpace> operator*(const Matrix<T,MaxRrows1,MaxCols1,allocSpace>& m)
    {
        Matrix<T,MaxRrows,MaxCols1> r;
        for (int i = 0; i < MaxRrows; ++i) {
            for (int j = 0; j < MaxCols1; ++j) {
                for (int k = 0; k < MaxCols1; ++k) {
                    r.p[i][j] += (p[i][k] * m.p[k][j]);
                }
            }
        }
        return r;
    }
};




