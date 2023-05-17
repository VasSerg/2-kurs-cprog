#include <iostream>
#pragma once
#include <cassert>
using namespace std;

class Matrix {
    public:
        int MaxRrows, MaxCols;
        double **p;

    Matrix(int rows, int cols) : MaxRrows(rows), MaxCols(cols)
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

    double& operator()(int x, int y){
        return p[x][y];
    }

    void sett(int x, int y, double num){
        p[x][y] = num;
    }

    ~Matrix()
    {
        for (int i = 0; i < MaxRrows; ++i) {
            delete[] p[i];
        }
        delete[] p;
    }

    Matrix(const Matrix& m) : MaxRrows(m.MaxRrows), MaxCols(m.MaxCols)
    {
        allocSpace();
        for (int i = 0; i < MaxRrows; ++i) {
            for (int j = 0; j < MaxCols; ++j) {
                p[i][j] = move(m.p[i][j]);
            }
        }
    }

    Matrix& operator=(const Matrix& m)
    {
        if (this == &m) {
            return *this;
        }

        assert(MaxRrows == m.MaxRrows);
        assert(MaxCols == m.MaxCols);
        for (int i = 0; i < MaxRrows; ++i) {
            delete[] p[i];
        }
        delete[] p;

        MaxRrows = m.MaxRrows;
        MaxCols = m.MaxCols;
        allocSpace();

        for (int i = 0; i < MaxRrows; ++i) {
            for (int j = 0; j < MaxCols; ++j) {
                p[i][j] = m.p[i][j];
            }
        }
        return *this;
    }

    Matrix operator+(const Matrix& m)
    {
        assert(MaxRrows == m.MaxRrows);
        assert(MaxCols == m.MaxCols);
        Matrix r(MaxRrows,MaxCols);
        for (int i = 0; i < MaxRrows; ++i) {
            for (int j = 0; j < MaxCols; ++j) {
                r.p[i][j] = p[i][j] + m.p[i][j];
            }
        }
        return move(r);
    }

    Matrix operator-(const Matrix& m)
    {
        assert(MaxRrows == m.MaxRrows);
        assert(MaxCols == m.MaxCols);
        Matrix r(MaxRrows,MaxCols);
        for (int i = 0; i < MaxRrows; ++i) {
            for (int j = 0; j < MaxCols; ++j) {
                r.p[i][j] = p[i][j] - m.p[i][j];
            }
        }
        return move(r);
    }

    Matrix operator*(const Matrix& m)
    {
        assert(MaxRrows == m.MaxRrows);
        assert(MaxCols == m.MaxCols);
        Matrix r(MaxRrows,MaxCols);
        for (int i = 0; i < r.MaxRrows; ++i) {
            for (int j = 0; j < r.MaxCols; ++j) {
                for (int k = 0; k < MaxCols; ++k) {
                    r.p[i][j] += (p[i][k] * m.p[k][j]);
                }
            }
        }
        return move(r);
    }

    void allocSpace()
    {
        p = new double*[MaxRrows];
        for (int i = 0; i < MaxRrows; ++i) {
            p[i] = new double[MaxCols];
        }
    }
};


