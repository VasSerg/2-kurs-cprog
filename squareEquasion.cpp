#include <iostream>
using namespace std;
int main()
{
    int a, b, c;
    cin >> a;
    cin >> b;
    cin >> c;
    int d = pow(b,2) - 4 * a * c;
    if (d < 0 or a == 0){
        cout << "No Solutions";
    }
    else {
        if (d == 0) {
            cout << "One Solution Found: " << -b / (2 * a);
        }
        else {
            cout << "Two Solutions Found: " << (-b + sqrt(d)) / (2 * a) << (-b - sqrt(d)) / (2 * a);
        }
    }
    cout << "";
}