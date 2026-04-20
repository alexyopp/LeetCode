#pragma once

#include "SolutionBase.h"


class Solution1 : public SolutionBase
{
public:
    bool canJump(std::vector<int>& nums)
    {
        // If nums has no "0" values, then the answer is trivially true (we can always jump at least 1 and advance eventually to the end)
        // If nums has "0" values, then we need to determine if there is a previous value such that it can by bypassed.
        // If we start from the beginning of the array, when we find a zero, we'll have to backtrack to locate a value that allows us to jump over it; if there are multiple zeroes in a group, this becomes problematic
        // If, instead we start from the end of the array, we have our goal (last index) and we see if we can reach it from a previous value
        //      if we run into a zero, save our goal, but keep iterating backwards until we find a non-zero value, and see if that gets us to our goal.  If it doesn't, keep iterating backwards until we find a value that does, or we hit the start of the array, in which case, our answer is false.

        int goalIdx = nums.size() - 1;
        int i = goalIdx - 1;
        while (i >= 0)
        {
            if (nums[i] > 0 && i + nums[i] >= goalIdx)
            {
                goalIdx = i;
            }

            --i;
        }

        return goalIdx == 0;
    }
};
