#pragma once

#include <iostream>
#include "IRule.h"

class IParsable
{
public:
    virtual IRule* parse(std::string data) = 0;
    virtual std::string getType() = 0;
};