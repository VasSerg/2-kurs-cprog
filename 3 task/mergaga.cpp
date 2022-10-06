
#include <iostream>
#include <string>
using namespace std;


void merge(int arr[], int const &left, int const &mid, int const &right)
{
    auto const left_arr = mid - left + 1;
    auto const right_arr = right - mid;


    int* l = new int[left_arr];
    int* r = new int[right_arr];

    for (int i = 0; i < left_arr; i++)
        l[i] = arr[left + i];
    for (int j = 0; j < right_arr; j++)
        r[j] = arr[mid + 1 + j];



    int l_ind = 0, r_ind = 0;
    int mid_ind = left;

    // merging arrays with values comparison
    while (l_ind < left_arr and r_ind < right_arr) {
        if (l[l_ind] <= r[r_ind]) {
            arr[mid_ind] = l[l_ind];
            l_ind++;
        }
        else {
            arr[mid_ind] = r[r_ind];
            r_ind++;
        }
        mid_ind++;
    }
    // add elements if any left
    while (l_ind < left_arr) {
        arr[mid_ind] = l[l_ind];
        l_ind++;
        mid_ind++;
    }

    while (r_ind < right_arr) {
        arr[mid_ind] = r[r_ind];
        r_ind++;
        mid_ind++;
    }
    delete[] l;
    delete[] r;
}


void merge_sort(int arr[], int const left, int const right)
{
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;
    merge_sort(arr, left, mid);
    merge_sort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

void main() {
    string s, num = "";
    int arr[100];
    cout << "Please write your array separated by spaces: " << endl;
    getline(cin, s);
    int i = 0;
    for (char& chr : s) {
        if (isspace(chr))
            arr[i] = stoi(num), num = "", i++;
        else
            num += chr;
    }
    if (num != "") {
        arr[i] = stoi(num);
        i++;
    }

    int size = i;

    merge_sort(arr, 0, size-1);

    cout << "Your sorted array: " << endl;
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}