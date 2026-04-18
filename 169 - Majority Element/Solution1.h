#pragma once

#include "SolutionBase.h"

#include <algorithm>

class Solution1 : public SolutionBase
{
public:
    int majorityElement(std::vector<int>& nums)
    {
        int n = nums.size();
        int majorityTest = n / 2;

        // With a sorted array, we would have more information
        std::sort(nums.begin(), nums.end());

        // Assuming the majority element always exists, and assuming there is only one(?)
        int i = 1;  // to iterate through
        int j = 0;  // to track the start of a group
        int curMajority = nums[j];    // to save the majority element

        while (i < n)
        {
            if (nums[i] != nums[j])
            {
                if (i - j > majorityTest)
                {
                    curMajority = nums[j];
                    break;
                }
                j = i;
            }

            ++i;
        }

        if (i - j > majorityTest)
        {
            curMajority = nums[j];
        }

        return curMajority;
    }
};
