#pragma once

/*  impoldev (YouTube) to the rescue.
*
*   But time limit exceeded!
*/

#include <cmath>        //  for std::abs
#include <map>          //  for std::map
#include <ranges>       //  for views::iota (C++20)
#include <vector>       //  for std::vector

using namespace std;

namespace Solution1
{
    class UnionFind {
    private:
        int n;
        map<int, int> parent;

    public:
        UnionFind(int n) : n(n)
        {
            for (int i = 0; i < n; ++i)
            {
                parent[i] = i;
            }
        }

        int findParent(int nodeIdx)
        {
            if (parent[nodeIdx] != nodeIdx)
            {
                parent[nodeIdx] = findParent(parent[nodeIdx]);
            }

            return parent[nodeIdx];
        }

        void unify(int nodeAIdx, int nodeBIdx)
        {
            int parentOfA = findParent(nodeAIdx);
            int parentOfB = findParent(nodeBIdx);
            parent[parentOfA] = parentOfB;
        }
    };

    class Solution {
    public:
        vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
            UnionFind uf(n);

            for (int i : std::views::iota(1, n))
            {
                if (abs(nums[i] - nums[i - 1]) <= maxDiff)
                {
                    uf.unify(i - 1, i);
                }
            }

            vector<bool> answers(queries.size(), false);
            for (int i : std::views::iota(0, static_cast<int>(queries.size())))
            {
                int nodeSource = queries[i][0];
                int nodeDest = queries[i][1];
                answers[i] = uf.findParent(nodeSource) == uf.findParent(nodeDest);
            }
            return answers;
        }
    };
}
