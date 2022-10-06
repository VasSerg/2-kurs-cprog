#include<iostream>

using namespace std;
//проблема при выборе между int и double
void f(float i) {};
void f(double i) {};


int main() {
    bool a = 1;
    int b = 4;
    char c = 6;
    f(a);
    f(b);
    f(c);
}


/*
#include <array>
#include <iostream>
#include <string_view>
using namespace std;

int main() {
    int size;
    const int maxSize = 100;
    int arr[maxSize];
    cout << "Please write your array's size (<100): ";
    cin >> size;
    cout << "Please write your array separated by spaces: " << endl;
    getline(cin, s);
    for (int i = 0; i < size; i++)
        cin >> arr[i];

    sort(arr[0], arr[size]);
    cout << "Your sorted array: " << endl;
    for (int i = 0; i < size; i++)
        cout << arr[i];
}
*/

/*#include <algorithm>
#include <cstddef>
#include <iterator>
#include <memory>

#include <iostream>
#include <vector>
using namespace std;


void merge_sort(int array[], size_t size){
        size_t const left = size / 2;
        size_t const right = size - left;

        merge_sort(&array[0], left);
        merge_sort(&array[left], right);


        size_t leftInd = 0, rightInd = left, temp = 0;
        unique_ptr<int[]> tmp_array(new int[size]);

        while (leftInd < left and rightInd < size){
            if (array[leftInd] < array[rightInd]){
                tmp_array[temp++] = move(array[leftInd]);
                leftInd++;
            }
            else{
                tmp_array[temp++] = move(array[rightInd]);
                rightInd++;
            }

            if (leftInd == left){
                copy(make_move_iterator(&array[rightInd]),
                    make_move_iterator(&array[size]),
                    &tmp_array[temp]);
                break;
            }
            if (rightInd == size){
                copy(make_move_iterator(&array[leftInd]),
                    make_move_iterator(&array[left]),
                    &tmp_array[temp]);
                break;
            }
        }

        copy(make_move_iterator(tmp_array),
            make_move_iterator(&tmp_array[size]),
            array);
}


void main(){
    int size;
    const int maxSize = 100;
    int arr[maxSize];
    cout << "Please write your array's size (<100): ";
    cin >> size;
    cout << "Please write your array: " << endl;
    for (int i = 0; i < size; i++)
        cin >> arr[i];

    merge_sort(arr, size);
    cout << "Your sorted array: " << endl;
    for (int i = 0; i < size; i++)
        cout << arr[i];
}
*/