#pragma once

#include "SolutionBase.h"

class Solution1 : public SolutionBase
{
public:
    int removeDuplicates(std::vector<int>& nums)
    {
        int i = 0;
        int j = 0;
        int k = 0;

        while (i < nums.size())
        {
            if (nums[i] != nums[j])
            {
                // Reset j to the start of the new sequence.
                j = i;
                nums[k] = nums[i];
                ++k;
            }
            else
            {
                if (i - j < 2)
                {
                    nums[k] = nums[i];
                    ++k;
                }
            }
            ++i;
        }

        return k;
    }
};
