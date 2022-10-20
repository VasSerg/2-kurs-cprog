#pragma once
#include <iostream>
#include <math.h>
#include<string>
#include <stdexcept>
# define pi           3.14159265358979323846
//#include <typeinfo>

using namespace std;
class imagineryClass
{
private:
    float real, img;
    float rad = -1, angle;
public:
    void set(int r,int i){
        real = r;
        img = i;
        rad = -1;
    }
    imagineryClass operator +(const imagineryClass& obj) {
        imagineryClass temp;
        temp.real = real + obj.real;
        temp.img = img + obj.img;
        return temp;
    }

    imagineryClass operator -(const imagineryClass& obj) {
        imagineryClass temp;
        temp.real = real - obj.real;
        temp.img = img - obj.img;
        return temp;
    }
    imagineryClass operator !() {
        imagineryClass temp;
        temp.real = real;
        temp.img = -img;
        return temp;
    }
    imagineryClass operator *(const imagineryClass& obj) {
        imagineryClass temp;
        temp.real = real * obj.real - img * obj.img;
        temp.img = real * obj.img + obj.real * img;
        return temp;
    }


    void toTrig(){
        if (rad == -1) {
            rad = sqrt(pow(real, 2) + pow(img, 2));
            if (rad != 0)
                angle = asin(img / rad);
            else {
                cout << "Your value can't be shown trigonometrical" << endl;
                //<< typeid(this).name() <<"
                rad = 0;
                angle = 0;
            }
        }
    }

    imagineryClass operator /(const imagineryClass& obj) {
        imagineryClass temp;

        toTrig();
        if (obj.rad != 0) {
            float tmpRad = rad / obj.rad;
            float tmpAngle = angle - obj.angle;
            temp.real = tmpRad * cos(tmpAngle);
            temp.img = tmpRad * sin(tmpAngle);
            return temp;
        }
        else
            cout << "You can't divide by zero" << endl;
            temp.real = 0;
            temp.img = 0;

            return temp;
    }  


    imagineryClass operator ^(const float& power) {
        imagineryClass temp;

        toTrig();
        float tmpRad = pow(rad, power);
        float tmpAngle = angle * power;

        temp.real = tmpRad * cos(tmpAngle);
        temp.img = tmpRad * sin(tmpAngle);
        return temp;
    }

    imagineryClass root(const float& root) {
        imagineryClass temp;

        toTrig();
        float tmpRad = pow(rad, 1/root);
        float tmpAngle = angle / root;

        temp.real = tmpRad * cos(tmpAngle);
        temp.img = tmpRad * sin(tmpAngle);
        return temp;
    }


    void Show(string state = "alg") {
        if (state == "alg")
            cout << real << ((img > 0)?" + ":" - ") << abs(img) << "i" << endl;
        else if (state == "trig") {
            toTrig();
            cout << rad << " * (cos(" << angle*360/(2*pi) << ") + i * sin(" << angle * 360 / (2 * pi) << "))" << endl;
        }
        else if (state == "exp") {
            toTrig();
            cout << rad << " * e ^ (i *" << angle / pi << " * pi)" << endl;
        }
    }
};