#include "kucha.h"
#include "kuchaClass.cpp"

#include <iostream>

using namespace std;

int main() {
    Kucha<char> h;

    string s, num = "";
    cout << "Please write your chars separated by spaces: " << endl;
    getline(cin, s);

    for (char& chr : s) {
        if (!isspace(chr))
            h.push(chr);
    }


    h.showHeap();
    cout << endl;
    h.showArray();
    cout << endl;
    cout << "Max element: " << h.top();
    cout << endl;


    //with int
    Kucha<int> h2;
    int i = 0;
    s = "", num = "";
    cout << "Please write your integers separated by spaces: " << endl;
    getline(cin, s);

    for (char& chr : s) {
    if (isspace(chr))
        h2.push(stoi(num)), num = "", i++;
    else
        num += chr;
    }
    if (num != "") {
        h2.push(stoi(num));
        i++;
    }


    h2.showHeap();
    cout << endl;
    h2.showArray();
    cout << endl;
    cout << "Max element: " << h2.top();
    cout << endl;
    return 0;
}

