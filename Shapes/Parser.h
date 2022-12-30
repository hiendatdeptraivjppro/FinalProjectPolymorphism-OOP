#pragma once

#include <iostream>
#include "Shape.h"
#include "Utils.h"
using namespace std;

class IParsable
{
public:
    virtual IShape* parse(string str) = 0;
};

class CircleParser : public IParsable
{
    IShape* parse(string str)
    {
        string argv = Utils::String::split(str, "=")[1];
        return new Circle(stoi(argv));
    }
};

class RectangleParser : public IParsable
{
    IShape* parse(string str)
    {
        vector<string> tokens = Utils::String::split(str, ", ");
        string argv1 = Utils::String::split(tokens[0], "=")[1];
        string argv2 = Utils::String::split(tokens[1], "=")[1];
        return new Rectangle(stoi(argv1), stoi(argv2));
    }
};

class SquareParser : public IParsable
{
    IShape* parse(string str) {
        string argv = Utils::String::split(str, "=")[1];
        return new Square(stoi(argv));
    }
};