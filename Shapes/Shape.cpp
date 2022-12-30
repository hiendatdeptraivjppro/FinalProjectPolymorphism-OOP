#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include "Shape.h"
using namespace std;

Rectangle::Rectangle(int a, int b) {
	_width = a;
	_height = b;
}

string Rectangle::toString() {
	stringstream builder;
	builder << "width " << _width << " height " << _height;
	string result = builder.str();
	return result;
}

double Rectangle::area() {
	double area = _width * _height;
	return area;
}

double Rectangle::perimeter() {
	double perimeter = (_width + _height) * 2;
	return perimeter;
}

Square::Square(int a) {
	_side = a;
}

string Square::toString() {
	stringstream builder;
	builder << "side " << _side;
	string result = builder.str();
	return result;
}

double Square::area() {
	double area = _side * _side;
	return area;
}

double Square::perimeter() {
	double perimeter = _side * 4;
	return perimeter;
}

Circle::Circle(int a) {
	_radius = a;
}

string Circle::toString() {
	stringstream builder;
	builder << "radius " << _radius;
	string result = builder.str();
	return result;
}

double Circle::area() {
	double area = M_PI * _radius * _radius;
	return area;
}

double Circle::perimeter() {
	double perimeter = 2 * M_PI * _radius;
	return perimeter;
}
