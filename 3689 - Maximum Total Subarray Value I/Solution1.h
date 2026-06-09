#pragma once

#include <vector>

using namespace std;

// Seems like I just need to find the minimum and maximum values of nums and multiply that (max-min) by k.

long long maxTotalValue(vector<int>& nums, int k) {
    if (nums.size() == 1)
    {
        return 0;   // (n - n) * k = 0
    }

    // nums.size() > 1
    int numsMin = nums[0];
    int numsMax = nums[0];

    for (auto num : nums)
    {
        if (num < numsMin)
        {
            numsMin = num;
        }

        if (num > numsMax)
        {
            numsMax = num;
        }
    }

    // (max - min) * k works on ints, so one of them needs to be a long long to do long long multiplication
    long long difference = (numsMax - numsMin);
    return difference * k;
}
