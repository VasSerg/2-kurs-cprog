#include "header.h"
#include <iostream>
#include <math.h>
using namespace std;
//Figure


//Square
double Square::getSide() {
    //они не обязательно вдоль осей
    //for (int i=1; i<4; i++){
    //if (points_x[i] == points_x[0]) {
    //    return abs(points_y[i] - points_y[0]);
    //}}
    double minim = 1/0.0;
    for (int i=0; i<4; i++){
        double n = pow((pow(points_y[i+1] - points_y[i],2)+pow(points_x[i+1] - points_x[i],2)),0.5);
        if (n<minim){
            minim = n;
        }}
    return minim;
};
double Square::area(){
    if (side == 0)
        side = getSide();
	return side * side;
}
double Square::perimeter(){
    if (side == 0)
        side = getSide();
	return side * 4;
}
double Square::info(){
    if (side == 0)
        side = getSide();
    cout << "The figure is Square."<< endl;
	cout << "Dots: "<< endl;
	for (int i=0; i<4; i++){
        cout << "X" << i+1 << ": " << points_x[i] << "  Y" << i+1 << ": " << points_y[i] << endl;
	}
	cout << "Side: " << side << endl;
    cout << "Perimeter: " << perimeter() << endl;
    cout << "Area: " << area() << endl;
}


//Polygon
pair<double, double> Rectangle::getSides() {
    //они не обязательно вдоль осей
    //for (int i=1; i<4; i++){
    //if (points_x[i] == points_x[0]) {
    //    return abs(points_y[i] - points_y[0]);
    //}}
    double minim = 1/0.0;
    double secondMinim = 1/0.0;
    for (int i=1; i<4; i++){
        double n = pow((pow(points_y[i] - points_y[0],2)+pow(points_x[i] - points_x[0],2)),0.5);

        if (n<minim){
            secondMinim = minim;
            minim = n;
        }
        else{
        if(n<secondMinim)
            secondMinim = n;
        }
        }

    return make_pair(minim, secondMinim);
};
double Rectangle::area(){
    if (longside == 0){
        pair<double, double> sides = getSides();
        shortside = sides.first;
        longside = sides.second;
        }
	return longside * shortside;
}
double Rectangle::perimeter(){
    if (longside == 0){
        pair<double, double> sides = getSides();
        shortside = sides.first;
        longside = sides.second;
        }
	return (longside + shortside) * 2;
}
double Rectangle::info(){
    if (longside == 0){
        pair<int, int> sides = getSides();
        shortside = sides.first;
        longside = sides.second;
        }

    cout << "The figure is Rectangle."<< endl;
	cout << "Dots: "<< endl;
	for (int i=0; i<4; i++){
        cout << "X" << i+1 << ": " << points_x[i] << "  Y" << i+1 << ": " << points_y[i] << endl;
	}
	cout << "Longside: " << longside << endl;
	cout << "Shortside: " << shortside << endl;
    cout << "Perimeter: " << perimeter() << endl;
    cout << "Area: " << area() << endl;
}


//Circle
double Circle::getRad() {
    return pow(pow(points_y[1] - points_y[0],2)+pow(points_x[1] - points_x[0],2),0.5);
};
double Circle::area(){
    if (rad == 0)
        rad = getRad();
    return rad * 3.1416 * 3.1416;
}
double Circle::perimeter(){
    if (rad == 0)
        rad = getRad();
	return 2 * rad * 3.1416;
}
double Circle::info(){
    if (rad == 0)
        rad = getRad();
    cout << "The figure is Circle."<< endl;
	cout << "Dots: "<< endl;
	for (int i=0; i<2; i++){
        cout << "X" << i+1 << ": " << points_x[i] << "  Y" << i+1 << ": " << points_y[i] << endl;
	}
	cout << "Radius: " << rad << endl;
    cout << "Perimeter: " << perimeter() << endl;
    cout << "Area: " << area() << endl;
}

//Ellipse
pair<double, double> Ellipse::getRads() {
    //они не обязательно вдоль осей
    //for (int i=1; i<4; i++){
    //if (points_x[i] == points_x[0]) {
    //    return abs(points_y[i] - points_y[0]);
    //}}
    double minim = 1/0.0;
    double secondMinim = 1/0.0;
    for (int i=1; i<3; i++){
        double n = pow((pow(points_y[i] - points_y[0],2)+pow(points_x[i] - points_x[0],2)),0.5);

        if (n<minim){
            secondMinim = minim;
            minim = n;
        }
        else{
        if(n<secondMinim)
            secondMinim = n;
        }
        }

    return make_pair(minim, secondMinim);
};
double Ellipse::area(){
    if (longrad == 0){
        pair<double, double> rads = getRads();
        shortrad = rads.first;
        longrad = rads.second;
        }
	return longrad * shortrad * 3.1416;
}
double Ellipse::perimeter(){
    if (longrad == 0){
        pair<double, double> rads = getRads();
        shortrad = rads.first;
        longrad = rads.second;
        }
	return 4*(( longrad * shortrad * 3.1416 + pow(longrad - shortrad,2))/(longrad + shortrad));
}
double Ellipse::info(){
    if (longrad == 0){
        pair<double, double> rads = getRads();
        shortrad = rads.first;
        longrad = rads.second;
        }
    cout << "The figure is Ellipse."<< endl;
	cout << "Dots: "<< endl;
	for (int i=0; i<3; i++){
        cout << "X" << i+1 << ": " << points_x[i] << "  Y" << i+1 << ": " << points_y[i] << endl;
	}
	cout << "Longrad: " << longrad << endl;
	cout << "Shortrad: " << shortrad << endl;
    cout << "Perimeter: " << perimeter() << endl;
    cout << "Area: " << area() << endl;
}
