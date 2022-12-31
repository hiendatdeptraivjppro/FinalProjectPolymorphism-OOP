#pragma once

#include <iostream>
#include <sstream>
#include <regex>
#include "IParsable.h"

class Replace : public IRule
{
private:
    std::string pattern;
    std::string to;

public:
    Replace(std::string data)
    {
        int posStart = data.find_first_of("=");
        int posEnd = data.find_first_of(",");

        this->pattern = data.substr(posStart + 1, posEnd - posStart - 1);
        this->to = data.substr(posEnd + 5, data.length() - posEnd - 1);
    }

    std::string rename(std::string filename)
    {
        std::regex patternRegex(pattern);
        return std::regex_replace(filename, patternRegex, to);
    }
};

class ReplaceParser : public IParsable
{
public:
    IRule* parse(std::string data)
    {
        return new Replace(data);
    }

    std::string getType()
    {
        return "ReplaceParser";
    }
};