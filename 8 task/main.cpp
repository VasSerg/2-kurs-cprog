#include "header.h"
#include <vector>
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
	Square f;
	vector <double> x = {0,2,0,2};
	vector <double> y = {0,0,2,2};
	f.setCoord(x,y);
    cout << "SquareInfo" << endl;;
    f.info();
    cout << endl;
    cout << endl;


    Rectangle p;
	p.setCoord(vector <double> {0,4,0,4},vector <double>{0,0,2,2});
    cout << "RectangleInfo" << endl;;
    p.info();
    cout << endl;
    cout << endl;


    Circle c(vector <double> {0,2},vector <double>{0,0});

    cout << "CircleInfo" << endl;;
    c.info();

    cout << endl;


    Ellipse e(vector <double> {0,4,0},vector <double>{0,0,2});
    cout << "EllipseInfo" << endl;
    e.info();
    cout << endl;
    cout << endl;
}
