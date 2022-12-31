#pragma once

#include <iostream>
#include <regex>
#include "IParsable.h"

class RemoveSpecialChars : public IRule
{
private:
    std::string data;

public:
    RemoveSpecialChars(std::string data)
    {
        this->data = data;
    }

    std::string rename(std::string filename)
    {
        // 10 is the length of "blacklist="
        std::string blacklist = data.substr(10, data.length() - 10);
        std::regex pattern("[" + blacklist + "]");
        return std::regex_replace(filename, pattern, "");
    }
};

class RemoveSpecialCharsParser : public IParsable
{
public:
    IRule* parse(std::string data)
    {
        return new RemoveSpecialChars(data);
    }


    std::string getType()
    {
        return "RemoveSpecialCharsParser";
    }
};