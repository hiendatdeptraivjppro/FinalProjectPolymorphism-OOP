#pragma once

#include <iostream>
#include <sstream>
#include "IParsable.h"

class OneSpaceOnly : public IRule
{
public:
    OneSpaceOnly(std::string data)
    {
    }

    std::string rename(std::string filename)
    {
        std::stringstream ss;
        bool isSpace = false;
        for (int i = 0; i < filename.length(); i++)
        {
            if (filename[i] == ' ')
            {
                if (!isSpace)
                {
                    ss << filename[i];
                    isSpace = true;
                }
            }
            else if (isupper(filename[i]) && islower(filename[i + 1]))
            {
                if (i > 0 && filename[i - 1] != ' ')
                {
                    ss << " ";
                }
                ss << filename[i];
                isSpace = false;
            }
            else
            {
                ss << filename[i];
                isSpace = false;
            }
        }

        return ss.str();
    }
};

class OneSpaceOnlyParser : public IParsable
{
public:
    IRule* parse(std::string data)
    {
        return new OneSpaceOnly(data);
    }

    std::string getType()
    {
        return "OneSpaceOnlyParser";
    }

};