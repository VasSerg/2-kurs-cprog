#include <iostream>
#include <set>
#include <vector>
#include <list>
#include <chrono>
#include <algorithm>


#define now() chrono::steady_clock::now()
#define time_point chrono::steady_clock::time_point
#define milisec chrono::duration_cast<chrono::milliseconds>

using namespace std;


int main() {
    int const num = 120000;

    //vector is faster than set
    // the situation changes at values between the values of 100000 and 120000 depending on random fillers
    //which is very big

    int nums[num];
    for (int i = 0; i < num; i++)
        nums[i] = rand();


    time_point start = now();

    set<int> a;
    for (int i : nums)
        a.insert(i);

    auto dur = now() - start;
    cout << "time: " << milisec(dur).count() << "ms" << endl << endl;


    start = now();

    vector<int> b;
    for (int i : nums)
        b.push_back(i);

    sort(b.begin(), b.end());

    dur = now() - start;
    cout << "time: " << milisec(dur).count() << "ms" << endl << endl;


    start = now();


    int c[num];
    for (int i = 0; i < num; i++) {
        c[i] = nums[i];
    }

    sort(c, c + num);

    dur = now() - start;
    cout << "time: " << milisec(dur).count() << "ms" << endl << endl;

    return 0;
}
