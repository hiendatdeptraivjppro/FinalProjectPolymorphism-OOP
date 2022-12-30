#pragma once

#include <iostream>
#include "Employees.h"
using namespace std;

class IParsable{
public:
    virtual Employee* parse(string data) = 0;
    virtual string getType() = 0;
};

class DailyEmployeeParser : public IParsable{
public:
    Employee* parse(string data){
        int dayCount = 0;
        int paymentPerDay = 0;

        int splitPosition = data.find_first_of("=");
        string key = data.substr(0, splitPosition);
        string value = data.substr(splitPosition + 1, data.length() - splitPosition - 1);
        dayCount = stoi(value);

        data = data.substr(splitPosition + 1, data.length() - splitPosition - 1);
        splitPosition = data.find_first_of("=");
        key = data.substr(0, splitPosition);
        value = data.substr(splitPosition + 1, data.length() - splitPosition - 1);
        paymentPerDay = stoi(value);

        return new DailyEmployee(dayCount, paymentPerDay);
    }

    string getType(){
        return "DailyEmployee";
    }
};

class ProductEmployeeParser : public IParsable{
public:
    Employee* parse(string data){
        int productCount = 0;
        int paymentPerProduct = 0;

        int splitPosition = data.find_first_of("=");
        string key = data.substr(0, splitPosition);
        string value = data.substr(splitPosition + 1, data.length() - splitPosition - 1);
        productCount = stoi(value);

        data = data.substr(splitPosition + 1, data.length() - splitPosition - 1);
        splitPosition = data.find_first_of("=");
        key = data.substr(0, splitPosition);
        value = data.substr(splitPosition + 1, data.length() - splitPosition - 1);
        paymentPerProduct = stoi(value);

        return new ProductEmployee(productCount, paymentPerProduct);
    }

    string getType(){
        return "ProductEmployee";
    }
};


class ManagerParser : public IParsable{
public:
    Employee* parse(string data){
        int employeeCount = 0;
        int paymentPerEmployee = 0;
        int baseSalary = 0;

        int splitPosition = data.find_first_of("=");
        string key = data.substr(0, splitPosition);
        string value = data.substr(splitPosition + 1, data.length() - splitPosition - 1);
        employeeCount = stoi(value);

        data = data.substr(splitPosition + 1, data.length() - splitPosition - 1);
        splitPosition = data.find_first_of("=");
        key = data.substr(0, splitPosition);
        value = data.substr(splitPosition + 1, data.length() - splitPosition - 1);
        paymentPerEmployee = stoi(value);

        data = data.substr(splitPosition + 1, data.length() - splitPosition - 1);
        splitPosition = data.find_first_of("=");
        key = data.substr(0, splitPosition);
        value = data.substr(splitPosition + 1, data.length() - splitPosition - 1);
        baseSalary = stoi(value);

        return new Manager(employeeCount, paymentPerEmployee, baseSalary);
    }

    string getType(){
        return "Manager";
    }
};