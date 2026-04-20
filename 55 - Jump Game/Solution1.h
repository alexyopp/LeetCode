#pragma once

#include "SolutionBase.h"

// I believe this works, though it is untenable for large nums

class Solution1 : public SolutionBase
{
public:
    bool canJump(std::vector<int>& nums)
    {
        return canJump(nums, 0);
    }

    bool canJump(std::vector<int>& nums, int startIdx)
    {
        if (startIdx == nums.size() - 1)
        {
            return true;
        }
        else if (startIdx >= nums.size())
        {
            return false;
        }

        for (int jumpLength = nums[startIdx]; jumpLength > 0; --jumpLength)
        {
            if (canJump(nums, startIdx + jumpLength))
            {
                return true;
            }
        }

        return false;
    }
};
