#pragma once

#include <vector>
#include <map>

using namespace std;

// Refinement of Solution2: rather than create the map first, fill it as we go and check back against it for each new i.
vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> solution(2);

    // No longer needs to be a multimap, since we don't need to worry about duplicate entries anymore.
    map<int, int> map;
    for (int i = 0; i < nums.size(); ++i)
    {
        auto iter = map.find(target - nums[i]);
        if (iter != map.cend())
        {
            // Guaranteed to be a unique index, since we haven't added nums[i] to the map yet.
            solution[0] = i;
            solution[1] = iter->second;
            return solution;
        }
        else
        {
            // Key is the value at array[i], Value is the index (i)
            map.insert({ nums[i], i });
        }
    }

    return solution;
}
