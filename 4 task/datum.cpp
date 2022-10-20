
#include <iostream>
#include <string>
using namespace std;

int* takeArray(int* size) {
    string s, num = "";
    static int arr[4];
    cout << "Please write thee time&data needed to be stored separated by spaces (h,m,d,m,y): " << endl;
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
    *size = i;
    return arr;
}

struct Data {
    unsigned month : 4;
    unsigned hour : 5;
    unsigned day : 5;
    unsigned minute: 6;
    unsigned year : 12;
};


int main() {
    int size;
    int* ara = new int[5];
    ara = takeArray(&size);
    Data dat;
    dat.hour = ara[0];
    dat.minute = ara[1];
    dat.day = ara[2];
    dat.month = ara[3];
    dat.year = ara[4];
    //why not work(( 
    // delete[] ara;

    cout << "Your stored data: " << endl;
    //will work fine for a century
    string a = (dat.month > 10) ? "." : ".0";
    string c = (dat.day > 10) ? " " : " 0";
    string d = (dat.hour > 10) ? "" : "0";
    string e = (dat.day > 10) ? ":" : ":0";
    cout << d << dat.hour << e << dat.minute << c << dat.day << a << dat.month << "." << dat.year;
    cout << endl;
}