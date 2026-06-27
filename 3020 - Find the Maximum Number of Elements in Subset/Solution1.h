#pragma once

/*  We need to know how many of each element exists in the array (so that we know we have at least two of a particular value),
*   so create an ordered map and run through nums to fill it.  Then iterate through the ordered map, taking the value and
*   looking for its square in the map.  If the map contains two of those, then look for the square of the square, otherwise, if
*   there's only one, we've reached the peak and the number of elements in this subset is the number of iterations * 2 (for the
*   two elements at each step) - 1 (our last step only had one element).  If there are 0 of this value, then the number of
*   elements in this subarray is the ((number of iterations - 1) * 2) - 1.
*
*   Before iterating on our map, check the value of 1, since its square and square of its square, etc. are all 1, we determine
*   the number of elements in the subset by just the count of 1s.  If the count is odd, that is the number of elements, if it is
*   even, then count-1 is the number of elements. [1], or [1, 1, 1], or [1, 1, 1, 1, 1], or [1, 1, 1, 1, 1, 1, 1], etc.
*/

#include <algorithm>    //  for std::max
#include <map>          //  for std::map
#include <vector>       //  for std::vector

using namespace std;

namespace Solution1
{
    class Solution {
    public:
        int maximumLength(vector<int>& nums) {
            map<long long, int> numsCount;
            for (auto value : nums)
            {
                ++numsCount[value];
            }

            int maxLength{ 0 };
            if (numsCount.contains(1))
            {
                maxLength = (numsCount[1] % 2 == 1 ? numsCount[1] : numsCount[1] - 1);
                numsCount.erase(1);
            }

            for (auto [value, count] : numsCount)
            {
                int iterations{ 1 };
                if (count >= 2)
                {
                    long long curVal{ value };
                    int curCount{ count };
                    while (curCount >= 2)
                    {
                        curVal *= curVal;
                        if (numsCount.contains(curVal))
                        {
                            curCount = numsCount[curVal];
                            ++iterations;
                        }
                        else
                        {
                            curCount = 0;
                        }
                    }
                }
                maxLength = max(maxLength, (iterations * 2) - 1);
            }

            return maxLength;
        }
    };
}
