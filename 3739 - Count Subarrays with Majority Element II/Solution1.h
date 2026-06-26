#pragma once

/*  ...yeah...impoldev (YouTube) to the rescue again.  Time to learn about prefix sums!
*   Let's say we're looking at nums = [1, 2, 1, 2], target = 2.  Solution is 3 subarrays (the individual [2] and [2,1,2]).
*   Since we can't iterate through all the subarrays, instead we will iterate through nums one, keeping track of the accumulated
*   balance at each step.  The balance starts at 0, we add 1 when we find the target and subtract 1 when we find something else.
*   A positive balance indicates a valid subarray (e.g., [1, 2] balance = 0, [2, 1, 2] balance = 1).  If we track the
*   accumulated frequencies of different balances as we iterate, we can get our answer.
*   Sticking with the above input, initialize our results to 0.  We need to create two arrays of size (2*n)+1, where array[n] is
*   a balance of 0, with the balance possibly growing or shrinking to +n or -n.  Shown on a number line:
* 
*                                           |----|----|----|----|----|----|----|----|
*                               balance    -4   -3   -2   -1    0    1    2    3    4
*                                     i     0    1    2    3    4    5    6    7    8
*                                                               n
* 
*           frequency of unique balances = [0,   0,   0,   0,   1,   0,   0,   0,   0]
*   accumulated frequencies (prefix sum) = [0,   0,   0,   0,   1,   0,   0,   0,   0]
*
*   Begin iterating; the first value in nums is not or target, so the balance is -1; this is the first time we've seen a balance
*   of -1, so update the frequency array's -1 position (i=3) from 0 to 1.  The accumulated frequency value is the previous
*   accumulated frequency value (i=2, acc[2] = 0) + the current frequency (1).  Why the previous accumulated frequency value?
* 
*   Let's say we have some unique contributions(?) array [1, -1, 1]; to build the prefix sum of this, we start with the
*   accumulated number starts at 0, so for the first value in the prefix sum array, we have 0 + 1.  For the next value, our
*   accumulated number is now 1, so 1+ -1 for 0.  Our third value then is 0 + 1.  So the prefix sum is [1, 0, 1].  The sum of
*   the subarray i=1..2, [-1, 1] is prefixSum[2] (the right bound) - prefixSum[1] (the left bound) - prefixSum[0] (the previous
*   accumulated number), or 1 - 0 - 1, which tells us the sum of [-1, 1] is 0.  What this is doing is taking the accumulated
*   result up to the right bound, i.e, [1, 0, 1], and subtracting the accumulated result up to the left bound, i.e., [1], - 1.
*   The result of 0 indicates this would not be a subarray with the target as a majority element; RightBound - LeftBound > 0.
*   Solving the inequality for RightBound, we see that RightBound > LeftBound, we have a valid subarray.  Continuing from our
*   example, RightBound=1, LeftBound - 1=1, so not a valid subarray.  But if we took the subarray of i=2, the right bound is 1,
*   the left bound -1 is 0, and so that is a valid subarray.
*
*   Getting back to the [1, 2, 1, 2] array, our balance is -1 and our arrays are in the state:
*           frequency of unique balances = [0,   0,   0,   1,   1,   0,   0,   0,   0]
*   accumulated frequencies (prefix sum) = [0,   0,   0,   1,   1,   0,   0,   0,   0]
*
*   Our next iteration takes us to i=1, with a value of 2.  It is our target so we add 1 to the balance, giving us a balance of
*   zero, so we update our frequency array, such that freq[balance+n] += 1.  Our arrays update to:
*           frequency of unique balances = [0,   0,   0,   1,   2,   0,   0,   0,   0]
*   accumulated frequencies (prefix sum) = [0,   0,   0,   1,   3,   0,   0,   0,   0]
*
*   And result is updated with the value of the previous accumulated frequency, so result += 1 (result = 1).
*
*   Our next iteration takes us to i=2, with a value of 1.  It is not our target so we add -1 to the balance, giving us a new
*   balance of -1, so we update our frequency array, such that freq[balance+n] += 1.  Our arrays update to:
*           frequency of unique balances = [0,   0,   0,   2,   2,   0,   0,   0,   0]
*   accumulated frequencies (prefix sum) = [0,   0,   0,   2,   3,   0,   0,   0,   0]
*
*   And result is updated with the value of the previous accumulated frequency, so result += 0.
*
*   Finally our iteration takes us to i=3, with a value of 2.  It is our target so we add 1 to the balance, giving us a new
*   balance of 0, so we update our frequency array, such that freq[balance+n] += 1.  Our arrays update to:
*           frequency of unique balances = [0,   0,   0,   2,   3,   0,   0,   0,   0]
*   accumulated frequencies (prefix sum) = [0,   0,   0,   2,   5,   0,   0,   0,   0]
*
*   And result is updated with the value of the previous accumulated frequency, so result += 2 (result = 3).  Just to illustrate
*   what is happeneing, the 2 here is capturing the valid subarrays ending in i=3; [2] and [2, 1, 2].
*
*   Our iteration is complete, return result (3).
*
*   For the code below, add an additional leading zero to the frequency and accumulated frequency arrays, so there's a previous
*   value to pull from when balance = 0.
*/

#include <vector>       //  for std::vector

using namespace std;

namespace Solution1
{
    class Solution {
    public:
        long long countMajoritySubarrays(vector<int>& nums, int target) {
            int n = nums.size();
            int balance = n+1;
            vector<int> balanceFrequencies(2 * n + 2, 0 );
            vector<int> accumulatedFrequencies( 2 * n + 2, 0 );
            balanceFrequencies[balance] = 1;
            accumulatedFrequencies[balance] = 1;
            long long results{ 0 };

            for (auto num : nums)
            {
                if (num == target)
                {
                    balance += 1;
                }
                else
                {
                    balance -= 1;
                }

                balanceFrequencies[balance] += 1;
                accumulatedFrequencies[balance] = accumulatedFrequencies[balance - 1] + balanceFrequencies[balance];
                results += accumulatedFrequencies[balance - 1];
            }

            return results;
        }
    };
}
