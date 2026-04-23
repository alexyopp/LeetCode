#pragma once

#include <vector>

class SolutionBase
{
    virtual int hIndex(std::vector<int>& citations) = 0;
};
