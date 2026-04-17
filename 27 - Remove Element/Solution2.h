#pragma once

#include "SolutionBase.h"

class Solution2 : public SolutionBase
{
public:
    int removeElement(std::vector<int>& nums, int val)
    {
        //  int i, to iterate through nums
        //  int k, to save our next insertion point
        //  while i < nums.size
        //      if (nums[i] != val)
        //          nums[k] = nums[i]
        //          ++k;
        //      ++i
        //  return k

        int i = 0;
        int k = 0;
        for (i; i < nums.size(); ++i)
        {
            if (nums[i] != val)
            {
                nums[k] = nums[i];
                ++k;
            }
        }
        return k;
    }
};
