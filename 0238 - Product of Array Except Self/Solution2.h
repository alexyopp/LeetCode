#pragma once

#include <vector>

// Using prefix and suffix (postfix) product arrays

std::vector<int> productExceptSelf(std::vector<int>& nums) {
    std::vector<int> prefix(nums.size());
    std::vector<int> suffix(nums.size());
    std::vector<int> answers(nums.size());

    for (int i = 0; i < nums.size(); ++i)
    {
        if (i == 0)
        {
            prefix[0] = nums[0];
        }
        else
        {
            prefix[i] = prefix[i - 1] * nums[i];
        }
    }

    for (int i = nums.size() - 1; i >= 0; --i)
    {
        if (i == nums.size() - 1)
        {
            suffix[nums.size() - 1] = nums[nums.size() - 1];
        }
        else
        {
            suffix[i] = suffix[i + 1] * nums[i];
        }
    }

    for (int i = 0; i < nums.size(); ++i)
    {
        if (i == 0)
        {
            answers[i] = suffix[i + 1];
        }
        else if (i == nums.size() - 1)
        {
            answers[i] = prefix[i - 1];
        }
        else
        {
            answers[i] = prefix[i - 1] * suffix[i + 1];
        }
    }

    return answers;
}
