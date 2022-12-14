#include "fifo.cpp"

#include <iostream>

using namespace std;

int main() {

    MyFIFO<char,string> cha;
    cha.push('a');
    cha.push('b');
    cha.push('c');
    cha.push('d');

    cout << "String container";
    cout <<endl;
    cout << cha.get() << " ";
    cout << cha.get() << " ";
    cout << cha.get() << " ";
    cout << cha.get() << " ";
    cout <<endl;

    MyFIFO<int> in;
    in.push(0);
    in.push(5);
    in.push(8);

    cout << "Int array container";
    cout <<endl;
    cout << in.get() << " ";
    cout << in.get() << " ";
    cout << in.get() << " ";
    cout <<endl;

    MyFIFO<float> fl;
    fl.push(1.0);
    fl.push(2.34);
    fl.push(534.54);

    cout << "Float array container";
    cout <<endl;
    cout << fl.get() << " ";
    cout << fl.get() << " ";
    cout << fl.get() << " ";
    cout <<endl;
    return 0;
}


