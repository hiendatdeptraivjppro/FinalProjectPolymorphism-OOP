#pragma once
#include <string>
class Employee {
public:
	virtual int salary()=0;
	virtual std::string toString() = 0;
};

class DailyEmployee :public Employee {
private:
	int _dayCount;
	int _paymentPerDay;
public:
	DailyEmployee(int, int);
	int salary();
	std::string toString();
};

class ProductEmployee :public Employee {
private:
	int _productCount;
	int _paymentPerProduct;
public:
	ProductEmployee(int, int);
	int salary();
	std::string toString();
};

class Manager :public Employee {
private:
	int _employeeCount;
	int _paymentPerEmployee;
	int _baseSalary;

public:
	Manager(int, int,int);
	int salary();
	std::string toString();
};