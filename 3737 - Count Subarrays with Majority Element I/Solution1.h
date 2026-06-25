#pragma once

/*  First of all, how many of the elements are our target number?  If it's 0, then there won't be any subarrays with our number
*   in them.  Next, now that we know how many times our target is in the input array, there are at least that many solutions
*   (subarrays of one at the position of our targets).  Next... unclear.  How many subarrays are there in total?
*   For [1], just one.
*   For [1, 2], there's [1], [2], [1, 2]
*   For [1, 2, 3], there's [1], [2], [3], [1, 2], [2, 3], [1, 3]
*   For [1, 2, 3, 4], there's [1], [2], [3], [4], [1, 2], [2, 3], [3, 4], [1, 2, 3], [2, 3, 4], [1, 2, 3, 4]
*   For [1, 2, 3, 4, 5], there's [1], [2], [3], [4], [5], [1, 2], [2, 3], [3, 4], [4, 5], [1, 2, 3], [2, 3, 4], [3, 4, 5], [1, 2, 3, 4], [2, 3, 4, 5], [1, 2, 3, 4, 5]
*   So, for arrays of size:     1   2   3   4   5   6
*   We have subarrays of num:   1   3   6   10  15  21?
*   This is the triangular number sequence, which is the formula n(n+1)/2.  But I don't think that will tell us how many
*   subarrays contain our target, let alone how many have it as a majority element.
*   Brute force has us build out all of the subarrays, and then we count how many of our target element is in each.  Constraints
*   are small (input array has between 1 and 1000 elements), so the largest number of subarrays we'll have will be 500,500
*   (thanks triangular number sequence formula!).  That's a lot, but will it exceed time limits?
*
*   It does.  Makes sense, building all those subarrays takes a lot of time.
*
*   So, instead of building and searching, maybe just iterate through them all and count as we go?  If we use two iterators,
*   leaving one at the start of the subarray (i) and advancing the second (j), counting the number of targets in that subarray.
*
*   STILL too slow!  I guess we can count it ourselves, rather than relying on std::count.
*/

//#include <algorithm>        //  for std::count
#include <vector>           //  for std::vector

using namespace std;

namespace Solution1
{
    class Solution {
    public:
        int countMajoritySubarrays(vector<int>& nums, int target) {
            int targetCount = count(nums.cbegin(), nums.cend(), target);
            if (targetCount == 0)
            {
                return 0;
            }

            int results{ 0 };
            int i{ 0 };
            int j{ 0 };
            targetCount = 0;
            for (int i = 0; i < nums.size(); ++i)
            {
                targetCount = 0;
                for (int j = i; j < nums.size(); ++j)
                {
                    if (nums[j] == target)
                    {
                        ++targetCount;
                    }

                    if ((targetCount * 2) > (j - i + 1))
                    {
                        ++results;
                    }
                }
            }

            /*  Still too slow
            int results{ 0 };
            auto leftIter = nums.cbegin();
            auto rightIter = nums.cbegin();
            while (leftIter != nums.cend())
            {
                rightIter = leftIter+1;
                while (true)
                {
                    if ((count(leftIter, rightIter, target) * 2) > (rightIter - leftIter))
                    {
                        ++results;
                    }

                    if (rightIter != nums.cend())
                    {
                        ++rightIter;
                    }
                    else
                    {
                        break;
                    }
                }

                ++leftIter;
            }
            */

            /*  Too slow
            vector<vector<int>> subarrays;
            for (int i = 0; i < nums.size(); ++i)
            {
                for (int j = i; j < nums.size(); ++j)
                {
                    vector<int> subarray;
                    for (int k = 0; k < (j - i)+1; ++k)
                    {
                        subarray.push_back(nums[i+k]);
                    }
                    subarrays.push_back(subarray);
                }
            }

            int results{ 0 };
            for (auto subarray : subarrays)
            {
                if (2 * count(subarray.cbegin(), subarray.cend(), target) > subarray.size())    //  multiplication faster than division
                {
                    ++results;
                }
            }
            */

            return results;
        }
    };
}
