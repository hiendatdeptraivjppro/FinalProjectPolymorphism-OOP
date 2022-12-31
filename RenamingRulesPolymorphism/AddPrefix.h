#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include "IParsable.h"
#include "IRule.h"

class AddPrefix : public IRule
{
private:
    std::string data;

public:
    AddPrefix(std::string data)
    {
        this->data = data;
    }

    std::string rename(std::string filename)
    {
        std::stringstream ss;
        ss << data << " " << filename;
        return ss.str();
    }
};

class AddPrefixParser : public IParsable
{
public:
    IRule* parse(std::string data)
    {
        return new AddPrefix(data);
    }

    std::string getType()
    {
        return "AddPrefixParser";
    }
};