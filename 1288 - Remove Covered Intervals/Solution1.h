#pragma once

/*  First thing to do is to sort intervals by their starts in increasing order and then by their ends in decreasing order (if
*   their starts are equal).  This will allow us to know that the current interval we're looking at possibly contains the
*   following interval, but not the other way around.  It would be a simple matter of checking the end points against each
*   other.
*
*   It's a little slow, but light.
*/

#include <algorithm>    //  For std::sort
#include <vector>       //  For std::vector

using namespace std;

namespace Solution1
{
    class Solution {
    public:
        int removeCoveredIntervals(vector<vector<int>>& intervals) {
            auto intervalSort = [](const vector<int>& lhs, const vector<int>& rhs) {
                if (lhs[0] < rhs[0]) { return true; }
                else if (lhs[0] == rhs[0]) { return lhs[1] >= rhs[1]; }
                else { return false; }
            };
            sort(intervals.begin(), intervals.end(), intervalSort);

            int intervalIdx = 0;
            while (intervalIdx < intervals.size() - 1)
            {
                if (intervals[intervalIdx][0] <= intervals[intervalIdx + 1][0] &&
                    intervals[intervalIdx][1] >= intervals[intervalIdx + 1][1])
                {
                    intervals.erase(intervals.begin() + intervalIdx + 1);
                }
                else
                {
                    ++intervalIdx;
                }
            }

            return intervals.size();
        }
    };
}