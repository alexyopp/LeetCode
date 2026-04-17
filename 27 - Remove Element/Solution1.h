#pragma once

#include "SolutionBase.h"

class Solution1 : public SolutionBase
{
public:
    int removeElement(std::vector<int>& nums, int val)
    {
        int fIdx = 0;
        int bIdx = nums.size() - 1;
        int valCount = 0;

        while (fIdx <= bIdx)
        {
            if (nums[bIdx] == val)
            {
                ++valCount;
                nums.pop_back();
                --bIdx;
            }
            else if (nums[fIdx] == val)
            {
                ++valCount;
                nums[fIdx] = nums[bIdx];
                ++fIdx;
                nums.pop_back();
                --bIdx;
            }
            else
            {
                ++fIdx;
            }
        }

        return nums.size();
    }
};
