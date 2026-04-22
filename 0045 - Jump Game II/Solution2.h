#pragma once

// Breadth First Search (simplified)
// j indicates our maximum jump (can't be 0 unless it is also the only value in nums, in which case the solution is 0)
// For our first jump, we can go anyway from nums[i+1] to nums[j]
// Find the maximum value k between those indices, and that becomes the next jump range (nums[j+1] to nums[k])
// Repeat until the last index is part of a group; that is how many steps it takes us

#include "SolutionBase.h"

#include <algorithm>

class Solution2 : public SolutionBase
{
public:
    int jump(std::vector<int>& nums)
    {
        int leftIdx = 0;
        int rightIdx = 0;       // starting at index 0
        int numJumps = 0;

        while (rightIdx < nums.size() - 1)
        {
            int farthest = 0;
            for (int i = leftIdx; i < rightIdx + 1; ++i)
            {
                farthest = std::max(farthest, i + nums[i]);
            }
            leftIdx = rightIdx + 1;
            rightIdx = farthest;
            ++numJumps;
        }

        return numJumps;
    }
};
