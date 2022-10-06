#include<iostream>

using namespace std;
//проблема при выборе между int и double
void f(float i) {};
void f(double i) {};


int main() {
    bool a = 1;
    int b = 4;
    char c = 6;
    f(a);
    f(b);
    f(c);
}