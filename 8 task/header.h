#pragma once
#include <iostream>
#include <vector>
using namespace std;


class Figure {
protected:
	vector <double> points_x;
	vector <double> points_y;
public:
	virtual void setCoord(vector <double> x, vector <double> y) {
		points_x = x;
		points_y = y;
	}
};
class Polygon : public Figure {};
class Ellipses : public Figure {};


class Square : public Polygon {
private:
	double side=0;
public:
    Square(vector <double> x = {} , vector <double> y = {}) {
		points_x = x;
		points_y = y;
	}
	virtual double area() final;
    virtual double perimeter() final;
    virtual double info() final;
    double getSide();

};

class Rectangle : public Polygon {
private:
	double longside=0;
	double shortside=0;
public:
    Rectangle(vector <double> x = {} , vector <double> y = {}) {
		points_x = x;
		points_y = y;
	}
	virtual double area() final;
    virtual double perimeter() final;
    virtual double info() final;
	pair<double, double> getSides();

};

class Circle : public Ellipses {
private:
	double rad=0;
public:
	virtual double area() final;
    double getRad();
    virtual double perimeter() final;
    virtual double info() final;
    Circle(vector <double> x = {} , vector <double> y = {}) {
		points_x = x;
		points_y = y;
	}
};


class Ellipse : public Ellipses {
private:
	double longrad=0;
	double shortrad=0;
public:
    Ellipse(vector <double> x = {} , vector <double> y = {}) {
		points_x = x;
		points_y = y;
	}
	virtual double area() final;
    virtual double perimeter() final;
    virtual double info() final;
	pair<double, double> getRads();

};
