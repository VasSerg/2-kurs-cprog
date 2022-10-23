#include "classhe.h"
#include "fract.cpp"
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{

    fract a, b, c, d, e, f, h, j;


    a.set(5, -7);
    b.set(-3, 9);


    // Параметры fract и doub отвечают за форму вывода. По умолчанию стоит fract.
    cout << "a" << endl;
    a.Show();
    cout << endl;
    //Я нарошно сокращаю только при вполнении операции, но не при выводе,
    //чтобы юзеру показывались те же значения, которые он вводит, а не что-то изменённое
    cout << "b" << endl;
    b.Show();
    cout << endl;

    a.Show("doub");
    cout << endl;

    cout << "a + b" << endl;
    c = a + b;
    c.Show();
    cout << endl;

    cout << "a - b" << endl;
    d = a - b;
    d.Show();
    cout << endl;

    cout << "a * b" << endl;
    e = a * b;
    e.Show();
    cout << endl;

    cout << "a / b" << endl;
    f = a / b;
    f.Show();
    cout << endl;



    cout << "a *= b" << endl;
    a *= b;
    //то же значение что и e
    a.Show();
    cout << endl;
    cout << "a == e" << endl;
    cout << (a == e) << endl;
    cout << endl;
    //аналогично
    cout << "a += b" << endl;
    a += b;
    a.Show();
    cout << endl;
    cout << "a -= b" << endl;
    a -= b;
    a.Show();
    cout << endl;
    cout << "a /= b" << endl;
    a /= b;
    a.Show();
    cout << endl;
    //префиксный
    ++a;
    a.Show();
    --a;
    a.Show();
    //постфиксный
    a++;
    a.Show();
    a--;
    a.Show();

    //сравнение    
    cout << "a > b" << endl;
    cout << (a>b) << endl;
    cout << endl;
    cout << "a < b" << endl;
    cout << (a < b) << endl;
    cout << endl;
    cout << "a == b" << endl;
    cout << (a == b) << endl;
    cout << endl;
    //get() принимает параметры num и denom, которые отвечают
    //за получаемую от функции переменную. По умолчанию стоит num.
    int num, denom;
    num = a.get("num");
    denom = a.get("denom");
    cout << "a numerator and denominator parameters are: " << endl << num << " and " << denom << endl << endl;

    //explicit

    fract g(4, 8);
    g.Show();
    /*
    double dob = 8.2342346;
    fract r(dob);
    r.Show();
    float fl = 3.42356f;
    fract tem = (fract)fl;
    tem.Show();
    a = b + (fract)fl;
    a.Show();
    */


    //критические случаи
    fract crit, c1;
    fract y;
    y.set(0, 0);
    crit.set(0, 0);
    crit.Show();
    c1 = a / crit;
    c1.Show();





    cout << endl;
    return 0;
}