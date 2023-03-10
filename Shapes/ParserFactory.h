#pragma once
#include <iostream>
#include "Parser.h"
#include "Parser.h"
using namespace std;

class ParserFactory
{
public:
    IParsable* create(string type)
    {
        if (type == "Square")
        {
            return new SquareParser();
        }
        else if (type == "Rectangle")
        {
            return new RectangleParser();
        }
        else if (type == "Circle")
        {
            return new CircleParser();
        }
        else
        {
            throw "Unknown type";
        }
    }
};