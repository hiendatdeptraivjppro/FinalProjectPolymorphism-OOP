#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
#include "IParsable.h"
#include "IRule.h"
using namespace std;
class AddCurrentMonth : public IRule
{
public:
    AddCurrentMonth(std::string data)
    {
    }

    std::string rename(std::string filename)
    {
        std::stringstream ss;
        time_t now = time(0);
        tm* ltm = localtime(&now);
        ss << 1 + ltm->tm_mon << " " << filename;
        return ss.str();
    }
};

class AddCurrentMonthParser : public IParsable
{
public:
    IRule* parse(std::string data)
    {
        return new AddCurrentMonth(data);
    }

    std::string getType()
    {
        return "AddCurrentMonthParser";
    }

};