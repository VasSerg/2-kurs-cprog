#include <iostream>
#include <vector>
#include <chrono>
#include <cmath>
#include <iterator>
#include <list>
#include <forward_list>

#include "head.h"


using namespace std;

int main() {


    vector<int> vect = {1,3,5,9,12,17};
    auto ite1 = vect.begin();
    auto ite2 = vect.end();

    chrono::steady_clock::time_point start = chrono::steady_clock::now();
    cout << "1 found at: "<<BinSearch(ite1, ite2, 1, vect) << endl;
    cout << "7 found at: "<<BinSearch(ite1, ite2, 7, vect) << endl;
    cout << "9 found at: "<<BinSearch(ite1, ite2, 9, vect) << endl;
    cout << "17 1found at: "<<BinSearch(ite1, ite2, 17, vect) << endl;
    auto dur = chrono::steady_clock::now() - start;
    cout << "RandomAccess iterator time: " << chrono::duration_cast<chrono::milliseconds>(dur).count() << "ms" << endl << endl;




    list<int> lis = {1,3,5,9,12,17};
    auto ite3 = lis.begin();
    auto ite4 = lis.end();

    start = chrono::steady_clock::now();
    cout << "1 found at: "<<BinSearchBidirectional(ite3, ite4, 1, lis) << endl;
    cout << "7 found at: "<<BinSearchBidirectional(ite3, ite4, 7, lis) << endl;
    cout << "9 found at: "<<BinSearchBidirectional(ite3, ite4, 9, lis) << endl;
    cout << "17 found at: "<<BinSearchBidirectional(ite3, ite4, 17, lis) << endl;
    dur = chrono::steady_clock::now() - start;
    cout << "Bidirectional iterator time: " << chrono::duration_cast<chrono::milliseconds>(dur).count() << "ms" << endl << endl;



    forward_list<int> flis = {1,3,5,9,12,17};
    auto ite5 = flis.begin();
    auto ite6 = flis.end();

    start = chrono::steady_clock::now();
    cout << "1 found at: "<<BinSearchForward(ite5, ite6, 1, flis) << endl;
    cout << "7 found at: "<<BinSearchForward(ite5, ite6, 7, flis) << endl;
    cout << "9 found at: "<<BinSearchForward(ite5, ite6, 9, flis) << endl;
    cout << "17 found at: "<<BinSearchForward(ite5, ite6, 17, flis) << endl;
    dur = chrono::steady_clock::now() - start;
    cout << "Bidirectional iterator time: " << chrono::duration_cast<chrono::milliseconds>(dur).count() << "ms" << endl << endl;

}
