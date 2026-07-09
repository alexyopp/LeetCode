#pragma once

/*  Code with Vick (YouTube) to the rescue!
*
*   Since nums is in order, and all we need to know is if a path exists between two given nodes, if node a and node b don't have
*   an edge, then node a can't connect to node c, they're in different groups (or components).  So, run through nums, and build
*   the map of linked components (runs of edges with <= maxDiff).  Then, for every query, just check if the source and
*   destination nodes are in the same group.
*/

#include <cmath>        //  for std::abs
#include <ranges>       //  for views::iota (C++20)
#include <vector>       //  for std::vector

using namespace std;

namespace Solution2
{
    class Solution {
    public:
        vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
            int curComponent{ 0 };
            vector<int> component(nums.size(), curComponent);
            for (int i : std::views::iota(1, static_cast<int>(nums.size())))
            {
                if (abs(nums[i] - nums[i - 1]) > maxDiff)
                {
                    ++curComponent;
                }
                component[i] = curComponent;
            }
            
            vector<bool> answers(queries.size(), false);
            for (int i : std::views::iota(0, static_cast<int>(queries.size())))
            {
                int nodeSource = queries[i][0];
                int nodeDest = queries[i][1];
                answers[i] = component[nodeSource] == component[nodeDest];
            }
            return answers;
        }
    };
}
