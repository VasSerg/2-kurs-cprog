#pragma once
#include <iostream>

using namespace std;

class fract {
private:
    int num, denom;
    int gcd(int a, int b);
public:

    explicit fract(int r = 0, int i = 1) :
        num(r), denom(i)
    {
        if (denom == 0)
        {
            std::cout << "Error: denominator can't be zero.\n";
        };
    }

    explicit fract(float r)
    {
        int tt = ceil(1000000 * r);
        num = tt;
        denom = 1000000;
    }
    explicit fract(double r)
    {
        fract temp;
        int tt = r * 1000000;
        num = tt;
        denom = 1000000;
    }

    void set(int r, int i);
    int lcm(int a, int b);

    fract contract(fract f);

    fract operator +(const fract& obj);

    fract operator -(const fract& obj);
    fract operator *(const fract& obj);

    fract operator /(const fract& obj);

    //сравнение

    bool operator ==(const fract& obj);
    bool operator >(const fract& obj);
    bool operator <(const fract& obj);


    //аналогично +,-,*,/
    fract operator +=(const fract& obj);

    fract operator -=(const fract& obj);


    fract operator *=(const fract& obj);

    fract operator /=(const fract& obj);
    //Префикс!
    fract operator ++(void);
    fract operator --(void);
    //Постфикс!
    fract operator ++(int d);
    fract operator--(int d);

    double todub();

    void Show(string state);

    int get(string what);

};