#pragma once

#include "SolutionBase.h"

class Solution3 : public SolutionBase
{
public:
    int majorityElement(std::vector<int>& nums)
    {
        // Boyer- Moore Voting Algorithm (First Pass, a.k.a. Candidate Selection)
        //  If we can't assume nums has a majority element, the Second Pass (a.k.a. Verification) tests the result of the First Pass to confirm it.
        int count = 0;
        int result;

        for (int i = 1; i < nums.size(); ++i)
        {
            if (count == 0)
            {
                result = nums[i];
            }

            if (nums[i] == result)
            {
                ++count;
            }
            else
            {
                --count;
            }
        }
    }
};
