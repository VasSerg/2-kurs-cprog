#include <vector>
#include <iostream>
#include <string>

using namespace std;

unsigned int RShashh(float f) {
    unsigned int b = 378551;
    unsigned int a = 63689;
    unsigned int hashh = 0;
    unsigned int i = 0;

    string s = to_string(f);
    const char* str = s.c_str();
    unsigned int length = s.length();

    for (i = 0; i < length; ++str, ++i)
    {
        hashh = hashh * a + (*str);
        a = a * b;
    }
    return hashh;
}


int main() {

    float 卐1 = 7.545567f;
    float 卐2 = 75.45567f;
    float 卐3 = -0.0f;
    float 卐4 = +0.0f;


    cout << RShashh(卐1) << endl;
    cout << RShashh(卐2) << endl;
    //разные - хорошо
    cout << RShashh(卐3) << endl;
    cout << RShashh(卐4) << endl;
    //тоже разные - ваще круто

    return 0;
}



