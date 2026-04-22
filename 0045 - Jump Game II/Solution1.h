#pragma once

#include "SolutionBase.h"

// Brute Force
class Solution1 : public SolutionBase
{
public:
    int jump(std::vector<int>& nums)
    {
        int shortestJumps = 1000;
        int curJumps = 0;
        findEnd(nums, 0, &shortestJumps, curJumps);

        return shortestJumps;
    }

    void findEnd(std::vector<int>& nums, int currentIdx, int* shortestJumps, int curJumps)
    {
        // Found the end
        if (currentIdx >= nums.size() - 1)
        {
            if (curJumps < *shortestJumps)
            {
                *shortestJumps = curJumps;
            }

            return;
        }
        else
        {
            for (int j = nums[currentIdx]; j > 0; --j)
            {
                findEnd(nums, currentIdx + j, shortestJumps, curJumps+1);
            }
        }
    }
};
