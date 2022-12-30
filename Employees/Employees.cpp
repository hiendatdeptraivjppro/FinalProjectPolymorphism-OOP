#include <iostream>
#include "Employees.h"
using namespace std;

DailyEmployee::DailyEmployee(int a, int b) {
	_dayCount = a;
	_paymentPerDay = b;
}


ProductEmployee::ProductEmployee(int a, int b) {
	_productCount = a;
	_paymentPerProduct = b;
}

Manager::Manager(int a, int b,int c) {
	_employeeCount = a;
	_paymentPerEmployee = b;
	_baseSalary = c;
}

int DailyEmployee::salary() {
	int salary = _dayCount * _paymentPerDay;
	return salary;
}

int ProductEmployee::salary() {
	int salary = _productCount * _paymentPerProduct;
	return salary;
}

int Manager::salary() {
	int salary = _employeeCount * _paymentPerEmployee + _baseSalary;
	return salary;
}
 
string DailyEmployee::toString() {
	return "DailyEmployee";
}

string ProductEmployee::toString() {
	return "ProductEmployee";
}

string Manager::toString(){
	return "Manager";
}