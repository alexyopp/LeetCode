#pragma once

#include <vector>
#include <map>

using namespace std;

// If we use a map, then, when we run through the array, we could just check if the matching value exists in our map (which could store its index into the array)
//  Need to remember to not match against the current value, though.  Which means we need a structure that can have duplicate keys (the value 3 could be listed twice, for example)
vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> solution(2);

    // Fill in the map
    multimap<int, int> map;
    for (int i = 0; i < nums.size(); ++i)
    {
        // Key is the value at array[i], Value is the index (i)
        map.insert({ nums[i], i });
    }

    for (int i = 0; i < nums.size(); ++i)
    {
        // Look for target - nums[i] in the map
        auto iter = map.find(target - nums[i]);
        if (iter != map.cend())
        {
            // Loop through those values until we find one that isn't the index we're already at (nums[i] + nums[i] is not a valid solution)
            for (int n = 0; n < map.count(target - nums[i]); ++n)
            {
                if (iter->second != i)
                {
                    solution[0] = i;
                    solution[1] = iter->second;
                    return solution;
                }
                ++iter;
            }
        }
    }

    return solution;
}
