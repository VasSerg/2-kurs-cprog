#include <iostream>
#include <string>
using namespace std;
//напишем для падающих тел например
class body
{
private:
    double velocity;
    double acceleration;
    static double gravAcc;
public:
    body(double v, double a) : velocity(v), acceleration(a) {}
    static double getGrav()
    {
        return gravAcc;
    }
    static void setGrav(double g)
    {
        gravAcc = g;
    }
    double getVelocity(double time)
    {
        return velocity + (acceleration + gravAcc) * time;
    }

};
double body::gravAcc = 9.81;
int main()
{
    body body1(2.34, 1);
    body body2(1.42, 0);

    cout << "Gravity acceleration: " << body::getGrav() << endl;
    cout << "Gravity acceleration: " << body1.getGrav() << " Velocity at time 10: " << body1.getVelocity(10) << endl;
    cout << "Gravity acceleration: " << body2.getGrav() << " Velocity at time 10: " << body2.getVelocity(10) << endl;
    cout << endl;

    //отправим на Марс
    body::setGrav(3.72);
    cout << "Gravity acceleration: " << body::getGrav() << endl;
    cout << "Gravity acceleration: " << body1.getGrav() << " Velocity at time 10: " << body1.getVelocity(10) << endl;
    cout << "Gravity acceleration: " << body2.getGrav() << " Velocity at time 10: " << body2.getVelocity(10) << endl;
    return 0;
}