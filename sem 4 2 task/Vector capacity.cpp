#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> myvector;

    for (int i = 0; i < 9; i++) {
        myvector.push_back(i);

        cout << "size: " << (int)myvector.size() << '\n';
        cout << "capacity: " << (int)myvector.capacity() << '\n';
    }
    //capacity doubles each time it is filled, starting with number 1

    cout << endl;

    vector<int> myvector2;
    myvector2.reserve(3);
    cout << "size: " << (int)myvector2.size() << '\n';
    cout << "capacity: " << (int)myvector2.capacity() << '\n';


    for (int i = 0; i < 4; i++) {
        myvector2.push_back(i);
    }
    cout << "size: " << (int)myvector2.size() << '\n';
    cout << "capacity: " << (int)myvector2.capacity() << '\n';

    //capacity doubles each time it is filled, starting with number set in reserve function


    cout << endl;


    vector<int> myvector3;

    myvector3.push_back(1);
    int prev = myvector3.capacity();
    int now = myvector3.capacity();

    while ((now = prev) or (now = prev * 2)) {
        prev = myvector3.capacity();
        myvector3.push_back(1e6);
        now = myvector3.capacity();
        if (now == 2 * prev) {
            cout << "new capacity: " << now << endl;
            cout << "size: " << (int)myvector3.size() << '\n';
        }
    }


    cout << "size: " << (int)myvector3.size() << '\n';
    cout << "capacity: " << (int)myvector3.capacity() << '\n';
    cout << "prev: " << prev << '\n';
    //after reaching size of 1073741824 which is 2^30, capacity shows as negative number () and then becomes zero
    // first time it showed stack overflow error
    for (int i = 0; i <10; i++) {
        cout <<  myvector3[i];
    }

    myvector3.push_back(1e6);

    cout << "size: " << (int)myvector3.size() << '\n';
    cout << "capacity: " << (int)myvector3.capacity() << '\n';
    cout << "prev: " << prev << '\n';

    // the vector although did not lost its data, and increase the negative value of size as always
    return 0;
}