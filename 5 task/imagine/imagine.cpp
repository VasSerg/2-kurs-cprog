#include "imagine.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
    imagineryClass a,b,c,d,e,f,g,h,j;
    a.set(5,7); 
    b.set(3, 9);
    c = a + b;
    d = a - b;
    e = a * b;
    h = a ^ 5.342;
    j = a.root(2);
    // ! - сопряжение
    f = !a;

    g = a / b;
    // Параметры alg, trig, exp отвечают за форму вывода. По умолчанию стоит alg.
    // trig специально выводится в виде n * pi, потому что так удобнее воспринимать для математиков
    a.Show();
    a.Show("trig");
    a.Show("exp");
    d.Show();
    e.Show();
    f.Show();
    g.Show();
    h.Show();
    j.Show();

    //критические случаи
    imagineryClass crit, c1;
    crit.set(0, 0);
     //перед выполнением укажет пользователю на наличие ошибки
    crit.Show("trig");
    c1 = a / crit;


    cout << endl;
    return 0;
}