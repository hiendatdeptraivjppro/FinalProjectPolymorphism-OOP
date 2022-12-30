#pragma once
#include <string>


class IShape {
public:
	virtual std::string toString() = 0;
	virtual double area() = 0;
	virtual double perimeter() = 0;
};
class Rectangle:public IShape {
private:
	int _width;
	int _height;
public:
	Rectangle(int, int);
	std::string toString();
	double area();
	double perimeter();
};

class Square:public IShape {
	int _side;
public:
	Square(int);
	std::string toString();
	double area();
	double perimeter();
};

class Circle:public IShape {
private:
	int _radius;
public:
	Circle(int);
	std::string toString();
	double area();
	double perimeter();
};