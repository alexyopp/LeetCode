#pragma once

/*  Iterate through nums; first element goes to left array (arr1), second element goes to right array (arr2), check against the
*   last value in arr1 to determine where the next element goes.  Repeat until the end of nums.  To save space, could just
*   insert values in result and keep a pointer to the end of the left "array", but the constraints are such that the benefit
*   of space saving probably doesn't outweigh the cost of inserting into the middle of result, vs. appending to the different
*   arrays and then smashing them together.
*   Well, actually, maybe not; we'd have to iterate over arr2 again to append the values into a new array, so, yes, it would be
*   worth being smart about this, just using one destination array, and saving the end point of the left array to add elements
*   there (additions to arr2 just go at the end of result).
*/

#include <vector>       //  for std::vector

using namespace std;

namespace Solution1
{
    class Solution {
    public:
        vector<int> resultArray(vector<int>& nums) {
            vector<int> result;

            //  Add the first two elements to kick things off.  Constraints guaruntee a minimum of 3 elements, so no need to handle special cases here.
            result.push_back(nums[0]);
            int endOfArr1Idx = 0;
            result.push_back(nums[1]);

            for (int i = 2; i < nums.size(); ++i)
            {
                if (result[endOfArr1Idx] > result.back())
                {
                    result.insert(result.cbegin() + endOfArr1Idx + 1, nums[i]);
                    ++endOfArr1Idx;
                }
                else
                {
                    result.push_back(nums[i]);
                }
            }

            return result;
        }
    };
}