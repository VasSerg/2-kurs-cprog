
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    vector <int> v;
    string s;
    
    cout << "Please write your array separated by spaces: " << endl;
    getline(cin, s);
    int i =  0;
    string num = "";
    for (char& chr : s) {
        if (isspace(chr))
            v.push_back(stoi(num)), num = "", i++;
        else
            num += chr;
    }
    v.push_back(stoi(num));

    sort(v.begin(), v.end(),[](int a, int b) { return a > b; });

    cout << "Your declining sorted array: " << endl;
    for (auto i = v.begin(); i != v.end(); ++i)
        cout << *i << " ";
    cout << endl;

    sort(v.begin(), v.end(), [](int a, int b) { return a < b; });

    cout << "Your upclining sorted array: " << endl;
    for (auto i = v.begin(); i != v.end(); ++i)
        cout << *i << " ";

    cout << endl;
}