#pragma once

#include "SolutionBase.h"

class Solution1 : public SolutionBase
{
public:
    int removeDuplicates(std::vector<int>& nums)
    {
        //  i = 1, k = 0
        //  while i < nums.size()
        //      if (nums[i] == nums[k])
        //          ++i
        //      else
        //          ++k
        //          nums[k] = nums[i]
        //  return k + 1 (k is currently index of the last element, rather than size of nums)

        int i = 1;
        int k = 0;
        while (i < nums.size())
        {
            if (nums[i] == nums[k])
            {
                ++i;
            }
            else
            {
                ++k;
                nums[k] = nums[i];
            }
        }
        return k + 1;
    }
};
