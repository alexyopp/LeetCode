#pragma once

#include "SolutionBase.h"

#include <unordered_map>

class Solution2 : public SolutionBase
{
public:
    int majorityElement(std::vector<int>& nums)
    {
        // Brute force method; just iterate through the array as-is, counting elements as we go, and report the value that satisfies the majorityTest
        int n = nums.size();
        int majorityTest = n / 2;
        std::unordered_map<int, int> map;
        int curMajority = nums[0];

        for (int i = 0; i < n; ++i)
        {
            map[nums[i]] += 1;
            if (map[nums[i]] > majorityTest)
            {
                curMajority = nums[i];
                break;
            }
        }

        return curMajority;
    }
};
