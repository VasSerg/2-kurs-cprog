#include <functional>
#include <iostream>
#include "stringg.cpp"

using namespace std;


int main(){
    stringg a;
    a = "srhrthhddgfgt";
    cout << a.Size() << endl;
    a.Append("sfd");
    cout << a.Size()<< endl;
    cout << a[3]<< endl;
    int f = 3;
    cout << a[f]<< endl;

    return 0;
}

