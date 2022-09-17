#include <iostream>
#include <math.h> 
using namespace std;

int main() {
    cout << "Please write your sorted array's size (<100): ";
    int s;
    cin >> s;

    cout << "Please write your sorted array: " << endl;
    const int maxSize = 100;
    float arr[maxSize];

    for (int i = 0; i < s; i++)
        cin >> arr[i];

    cout << "Please write value to search: " << endl;
    int searchVal;
    cin >> searchVal;

    int minn = 0;
    int maxx = s - 1;
    int mid = 0;
    int midVal;
    //cout << searchVal;
    while (minn <= maxx) {
        mid = ceil((minn + maxx) / 2);
        midVal = arr[mid];
        if (midVal < searchVal)
            minn = mid + 1;
        else {
            if (midVal > searchVal)
                maxx = mid - 1;
            else {
                cout << "Your value index is: ";
                cout << mid;
                break;
            }

        }

    }
    if (arr[mid] != searchVal)
        cout << "Value not found.";
    cout << endl;
}
