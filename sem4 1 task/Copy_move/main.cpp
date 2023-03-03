#include <iostream>
#include <vector>
#include <chrono>

#include "header.h"

using namespace std;

int main(){
    Mem1 A(1e7);

    for (int i = 0; i < A.length; i++)
        A.dat[i] = 6;

    Mem1 B(1e7);

    Mem2 C(1e7);
    for (int i = 0; i < C.length; i++)
        C.dat[i] = 6;

    Mem2 D(1e7);


    chrono::steady_clock::time_point start = chrono::steady_clock::now();
    Mem1 E(A);

    auto dur = chrono::steady_clock::now() - start;
    cout << "Copy time: " << chrono::duration_cast<chrono::milliseconds>(dur).count() << "ms" << endl;



    start = chrono::steady_clock::now();
    Mem2 F(move(C));

    dur = chrono::steady_clock::now() - start;
    cout << "Move time: " << chrono::duration_cast<chrono::milliseconds>(dur).count() << "ms" << endl;



    start = chrono::steady_clock::now();
    A = B;

    dur = chrono::steady_clock::now() - start;
    cout << "Copy time: " << chrono::duration_cast<chrono::milliseconds>(dur).count() << "ms" << endl;



    start = chrono::steady_clock::now();
    C = move(D);

    dur = chrono::steady_clock::now() - start;
    cout << "Move time: " << chrono::duration_cast<chrono::milliseconds>(dur).count() << "ms" << endl;
};
