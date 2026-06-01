#pragma once

#include <vector>

// Brute force; fails on large input; not O(n), obviously

std::vector<int> productExceptSelf(std::vector<int>& nums) {
    std::vector<int> answer(nums.size(), 1);

    for (int i = 0; i < nums.size(); ++i)
    {
        for (int j = 0; j < nums.size(); ++j)
        {
            if (i != j)
            {
                answer[j] *= nums[i];
            }
        }
    }

    return answer;
}
