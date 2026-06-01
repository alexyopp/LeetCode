#pragma once

#include <vector>

// Doing prefix and suffix products in-place

std::vector<int> productExceptSelf(std::vector<int>& nums) {
    std::vector<int> answers(nums.size());

    int product = 1;
    for (int i = 0; i < nums.size(); ++i)
    {
        answers[i] = product;
        product *= nums[i];
    }

    product = 1;
    for (int i = nums.size() - 1; i >= 0; --i)
    {
        answers[i] *= product;
        product *= nums[i];
    }

    return answers;
}
