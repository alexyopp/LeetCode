#pragma once

/*  I was having trouble understanding the examples, such as why, in Example 1, 1 was chosen for subsequence 1 and 2 and 3 were
*   chosen for subsequence 2.  Why not just 2 for subsequence 2?  The answer lies in the second point of the conditions: "The
*   GCD of the elements of seq1 is equal to the GCD of the elements of seq2."  Just chosing 2 for the second subsequence is
*   invalid, because the GCD of 2 is 2.  But if the 2 is paired with a 3, now the GCD of 2,3 is 1, matching the GCD of
*   subsequence 1.
*
*   That didn't get me closer to figuring this out on my own though, so impoldev (YouTube) to the rescue again.
*
*   Recognize that, while iterating through nums, at each step, you have three choices; either include the element in
*   subsequence one, include the element in subsequence 2, or skip it (dont' add it to either subsequence).  At the next element
*   you again have the same three choices, and so on.  To illustrate this with an example:
*                                                         [10, 20, 30]
*                                                          ^
*                         Add to S1                                         Add to S2                                               Skip
*                         s1 | s2                                            s1 | s2                                               s1 | s2
*                        ---------                                          ---------                                             ---------
*                         10 |                                                  | 10                                                  |   
*
*                                                        [10, 20, 30]
*                                                             ^
*           Add to S1    Add to S2         Skip                Add to S1    Add to S2         Skip                            Add to S1    Add to S2      Skip
*           s1 | s2       s1 | s2         s1 | s2              s1 | s2       s1 | s2         s1 | s2                          s1 | s2       s1 | s2      s1 | s2
*          ---------     ---------       ---------            ---------     ---------       ---------                        ---------     ---------    ---------
*       10, 20 |          10 | 20        10  |                20  | 10          | 10, 20        |  10                         20 |             | 20         |   
*
*                                                        [10, 20, 30]
*                                                                 ^
*   Add to S1           Add to S1       Add to S1           Add to S1       Add to S1           Add to S1                   Add to S1       Add to S1       Add to S1 
*   s1: 10, 20, 30      s1: 10, 30      s1: 10, 30          s1: 20, 30      s1: 30              s1: 30                      s1: 20, 30      s1: 30          s1: 30
*   s2: -               s2: 20          s2: -               s2: 10          s2: 10, 20          s2: 10                      s2: -           s2: 20          s2: -
*
*   Add to S2           Add to S2       Add to S2           Add to S2       Add to S2           Add to S2                   Add to S2       Add to S2       Add to S2
*   s1: 10, 20          s1: 10          s1: 10              s1: 20          s1: -               s1: -                       s1: 20          s1: -           s1: -
*   s2: 30              s2: 20, 30      s2: 30              s2: 10, 30      s2: 10, 20, 30      s2: 10, 30                  s2: 30          s2: 20, 30      s2: 30
*
*   Skip                Skip            Skip                Skip            Skip                Skip                        Skip            Skip            Skip
*   s1: 10, 20          s1: 10          s1: 10              s1: 20          s1: -               s1: -                       s1: 20          s1: -           s1: -
*   s2: -               s2: 20          s2: -               s2: 10          s2: 10, 20          s2: 10                      s2: -           s2: 20          s2: -
*
*   Three of these scenarios result in a situation in which the GCD of both subsequences are equal:
*       (1) - s1: -, s2: -
*       (2) - s1: 10, s2: 20, 30
*       (3) - s1: 20, 30, s2: 10
*   Since the problem is asking for solutions with non-empty subsequences, subtracting 1 from the result gives us 2, the correct
*   answer for this case.
*
*   We don't have a handy @cache decorator in C++, and I'm not interested in writing a hash functino for pair<int, int> to use
*   an unordered_map, so this fails on time limit exceeded.
*/

#include <numeric>          //  for std::gcd
#include <vector>           //  for std::vector

using namespace std;

namespace Solution1
{
    class Solution {
        static constexpr int MOD = 1e9 + 7;

    public:
        int dosomething(int index, vector<int>& nums, int gcd1, int gcd2 )
        {
            if (index == nums.size())
            {
                if (gcd1 == gcd2)
                {
                    return 1;
                }
                else
                {
                    return 0;
                }
            }

            int total = 0;
            //  Skip chosing
            total = (total + dosomething(index + 1, nums, gcd1, gcd2 )) % MOD;

            // Include in Subsequence 1
            total = (total + dosomething(index + 1, nums, gcd(gcd1, nums[index]), gcd2)) % MOD;

            // Include in Subsequence 2
            total = (total + dosomething(index + 1, nums, gcd1, gcd(gcd2, nums[index]))) % MOD;

            return total;
        }

        int subsequencePairCount(vector<int>& nums) {
            return (dosomething(0, nums, 0, 0) - 1) % MOD;
        }
    };
}
