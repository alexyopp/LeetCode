#pragma once

#include <algorithm>    //  for std::lower_bound, std::sort
#include <bit>          //  for std::bit_width (C++20)
#include <numeric>      //  for std::iota
#include <utility>      //  for std::swap
#include <vector>       //  for std::vector

using namespace std;

namespace Solution1
{
    class Solution {
    public:
        vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
            //  Store the nums indices in order of their associated diffs.
            vector<int> numsIdx(n);
            iota(numsIdx.begin(), numsIdx.end(), 0);
            sort(numsIdx.begin(), numsIdx.end(),
                [&nums](const int lhsIdx, const int rhsIdx)
                {
                    return nums[lhsIdx] < nums[rhsIdx];
                });

            //  Create a lookup table into numsIdx
            vector<int> pos(n);
            for (int i = 0; i < n; ++i)
            {
                pos[numsIdx[i]] = i;
            }

            //  Binary lifting table
            int numCols = std::bit_width(static_cast<unsigned int>(n));
            int numRows = n;
            vector<vector<int>> jumps(numRows, vector<int>(numCols));
            for (int i = 0, left = 0; i < numRows; ++i)
            {
                while (nums[numsIdx[i]] - nums[numsIdx[left]] > maxDiff) { ++left; }
                jumps[i][0] = left;
            }
            for (int j = 1; j < numCols; ++j)
            {
                for (int i = 0; i < n; ++i)
                {
                    jumps[i][j] = jumps[jumps[i][j - 1]][j - 1];
                }
            }
            
            //  Process queries
            int q = queries.size();
            vector<int> answers(q, 0);
            for (int i = 0; i < q; ++i)
            {
                int sourceIdx = queries[i][0];
                int destIdx = queries[i][1];

                //  Early out for queries looking for a path from a node to itself
                if (sourceIdx == destIdx)
                {
                    answers[i] = 0;
                    continue;
                }

                //  Translate node indices into numDiffs space, ensure source < dest
                sourceIdx = pos[sourceIdx];
                destIdx = pos[destIdx];
                if (sourceIdx > destIdx) { swap(sourceIdx, destIdx); }

                int step = 0;
                for (int i = numCols - 1; i >= 0; --i)
                {
                    if (jumps[destIdx][i] > sourceIdx)
                    {
                        destIdx = jumps[destIdx][i];
                        step += 1 << i;     // 2^i
                    }
                }

                answers[i] = jumps[destIdx][0] <= sourceIdx ? step + 1 : -1;
            }
            return answers;
        }
    };
}