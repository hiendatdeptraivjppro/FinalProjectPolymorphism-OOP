#pragma once

#include <iostream>

class IRule{
public:
    virtual std::string rename(std::string filename) = 0;
};