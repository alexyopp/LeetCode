#pragma once

#include <vector>

using namespace std;

// Brute Force
//  for every index, sum with every following index until we find the one that matches.
vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> solution(2);
    for (int i = 0; i < nums.size() - 1; ++i)
    {
        for (int j = i + 1; j < nums.size(); ++j)
        {
            if (nums[i] + nums[j] == target)
            {
                solution[0] = i;
                solution[1] = j;
                return solution;
            }
        }
    }

    return solution;
}
