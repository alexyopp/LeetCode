#pragma once

#include "SolutionBase.h"

class Solution1 : public SolutionBase
{
public:
    void rotate(std::vector<int>& nums, int k)
    {
        // Naive
        int n = nums.size();
        std::vector<int> rotated(n);

        // size = 5, k = 3, 0->3, 1->4, 2->5, 3->0  
        for (int i = 0; i < n; ++i)
        {
            rotated[(i + k) % n] = nums[i];
        }

        nums = rotated;
    }
};
