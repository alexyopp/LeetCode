#pragma once

/*  As we must solve by counting sort, there isn't really much that needs to figure out here.  Counting sort has us go through
*   the array, adding to the count of each element as we go.  So, for example, an input of [1, 4, 0, 2, 1, 1] would create the
*   counting array [1, 3, 1, 0, 1] (one 0, three 1s, one 2, zero 3s, one 4).  Once we have the counting array, then it's just a
*   matter of iterating through it, subtracting the values from our coins input to see how many units we can buy.
*
*   One optimization would be to use an ordered map instead of a vector.  To create the counting vector, we need to know the
*   highest value in the input array.  This would require us to run through the input array once to find the largest element,
*   and then again to actually count the elements.  But if we use an ordered map, we can just go through the array once, and it
*   only takes up as much memory as we need.
*
*   This is much slower and heavier than other LeetCode submissions but I'm guessing they didn't follow the directive of using
*   counting sort.
*/

#include <map>          //  for std::map
#include <vector>       //  for std::vector

using namespace std;

namespace Solution1
{
    class Solution {
    public:
        int maxIceCream(vector<int>& costs, int coins) {
            map<int, int> costCount;

            for (auto cost : costs)
            {
                ++costCount[cost];
            }

            int numIceCreamBars = 0;
            for (auto& [cost, count] : costCount)
            {
                while (count > 0)
                {
                    coins -= cost;
                    if (coins >= 0)
                    {
                        numIceCreamBars += 1;
                        count -= 1;
                    }
                    else
                    {
                        return numIceCreamBars;
                    }
                }
                
            }

            return numIceCreamBars;
        }
    };
}