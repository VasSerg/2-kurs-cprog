#include "classhe.h"
#include <iostream>
#include <string>
using namespace std;


void fract::set(int r, int i) {
    num = r;
    denom = i;
}
int fract::gcd(int a, int b){
    if (b != 0) {
        a = abs(a);
        b = abs(b);
        if (a % b == 0)
            return b;
        if (b % a == 0)
            return a;
        if (a > b)
            return gcd(a % b, b);
        return gcd(a, b % a);
    }
    else
        return 0;
}

int fract::lcm(int a, int b) {
    return a * b / gcd(a, b);
}


fract fract::contract(fract f) {
    int c = gcd(abs(f.num), abs(f.denom));
    if (c != 0) {
        f.denom /= c;
        f.num /= c;
        return f;
    }
    else
        return f;
}

fract fract::operator +(const fract& obj) {
    fract temp;
    temp.denom = ((denom * obj.denom >= 0) ? 1 : -1) * lcm(abs(denom), abs(obj.denom));
    temp.num = num * temp.denom / denom + obj.num * temp.denom / obj.denom;
    temp = contract(temp);
    return temp;
}

fract fract::operator -(const fract& obj) {
    fract temp;
    temp.denom = ((denom * obj.denom > 0) ? 1 : -1) * lcm(abs(denom), abs(obj.denom));
    temp.num = num * temp.denom / denom - obj.num * temp.denom / obj.denom;
    return contract(temp);
}
fract fract::operator *(const fract& obj) {
    fract temp;
    temp.num = num * obj.num;
    temp.denom = denom * obj.denom;
    return contract(temp);
}

fract fract::operator /(const fract& obj) {
    fract temp;
    temp.num = num * obj.denom;
    temp.denom = denom * obj.num;
    return contract(temp);
}

//сравнение

bool fract::operator ==(const fract& obj) {
    fract temp;
    temp = *this - obj;
    return ((temp.num == 0) ? true : false);
}
bool fract::operator >(const fract& obj) {
    fract temp;
    temp = *this - obj;
    return ((temp.num * temp.denom > 0) ? true : false);
}
bool fract::operator <(const fract& obj) {
    fract temp;
    temp = *this - obj;
    return ((temp.num * temp.denom > 0) ? false : true);
}


//аналогично +,-,*,/
fract fract::operator +=(const fract& obj) {
    denom = ((denom * obj.denom >= 0) ? 1 : -1) * lcm(abs(denom), abs(obj.denom));
    num = num * denom / denom + obj.num * denom / obj.denom;
    *this = contract(*this);
    return *this;
}

fract fract::operator -=(const fract& obj) {
    denom = ((denom * obj.denom > 0) ? 1 : -1) * lcm(abs(denom), abs(obj.denom));
    num = num * denom / denom - obj.num * denom / obj.denom;
    *this = contract(*this);
    return *this;
}


fract fract::operator *=(const fract& obj) {
    num = num * obj.num;
    denom = denom * obj.denom;
    *this = contract(*this);
    return *this;
}

fract fract::operator /=(const fract& obj) {
    num = num * obj.denom;
    denom = denom * obj.num;
    *this = contract(*this);
    return *this;
}
//Префикс!
fract fract::operator ++(void)
{
    num += denom;
    return *this;
}
fract fract::operator --(void)
{
    num -= denom;
    return *this;
}
//Постфикс!
fract fract::operator ++(int d)
{
    num += denom;
    return *this;
}
fract fract::operator--(int d)
{
    num -= denom;
    return *this;
}

double fract::todub() {
    return double(denom) / num;
}

void fract::Show(string state = "fract") {
    if (state == "fract")
        cout << ((num * denom >= 0) ? "" : "-") << abs(num) << "/" << abs(denom) << endl; \
        if (state == "doub")
            cout << todub() << endl;
}

int fract::get(string what = "num") {
    if (what == "num")
        return num;
    if (what == "denom")
        return denom;
}