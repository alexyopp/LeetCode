#pragma once

#include "SolutionBase.h"

class Solution3 : public SolutionBase
{
public:
    void rotate(std::vector<int>& nums, int k)
    {
        // Reverse the whole array, then reverse the two parts (the first k elements, then the next n-k elements)
        k = k % nums.size();

        reverse(nums, 0, nums.size() - 1);
        reverse(nums, 0, k-1);
        reverse(nums, k, nums.size() - 1);
    }

    void reverse(std::vector<int>& nums, int start, int end)
    {
        int temp;
        while (start < end)
        {
            temp = nums[start];
            nums[start] = nums[end];
            nums[end] = temp;
            ++start;
            --end;
        }
    }
};
