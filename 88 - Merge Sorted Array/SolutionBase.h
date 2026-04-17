#pragma once

#include <vector>

class SolutionBase
{
    virtual void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) = 0;
};
