#pragma once

/*  Seems straightforward; sort the array, and then assign an increasing ranking to each element, provided their not the same.
*   But how do I get the rankings back in the correct order?  Could create a new arr, but with pairs (first value for the value,
*   second value for the position); sort that, then place the ranking in the correct spot in the rankings vector.
*/

#include <algorithm>    //  for std::sort
#include <utility>      //  for std::pair
#include <vector>       //  for std::vector

using namespace std;

namespace Solution1
{
    class Solution {
    public:
        vector<int> arrayRankTransform(vector<int>& arr) {
            //  Early outs
            if (arr.size() == 0) { return {}; }
            if (arr.size() == 1) { return {1}; }

            //  Create a new arr, with the positions of each element saved into the element and sort it in ascending order
            vector<pair<int, int>> newArr(arr.size());
            for (int i = 0; i < arr.size(); ++i)
            {
                newArr[i] = make_pair(arr[i], i);
            }
            sort(newArr.begin(), newArr.end(), [](const pair<int, int>& a, const pair<int, int>& b) { return a.first < b.first; });

            //  Iterate through newArr, checking the current value against the previous, and assigning the appropriate rank to
            //  the correct position in the ranking list.
            vector<int> ranking(arr.size());
            int curRank{ 1 };
            if (newArr.size() >= 0) { ranking[newArr[0].second] = curRank; }
            for (int i = 1; i < newArr.size(); ++i)
            {
                if (newArr[i].first > newArr[i - 1].first) { ranking[newArr[i].second] = ++curRank; }
                else { ranking[newArr[i].second] = curRank; }
            }

            return ranking;
        }
    };
}
