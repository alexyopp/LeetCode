#pragma once

/*  For the first value in the array, we can choose any number between l and r (inclusive); that is, "n" choices.  For the next
*   value, we can chooose any value other than the last one we chose, so we have n-1 choices.  For the next value, we are more
*   limited; we can only choose a value that is greater than the last choice, if our first choice was larger than it, or less
*   than our last choice if our first choice was smaller than it.
*       a = {1...n} = n numbers
*       b = !a      = n-1 numbers
*       c = a-b > 0 ? {b+1...n} : {1...b-1}
*   n can be large, but ever large n will be composed of the smaller n (i.e., given the same l and r, the arrays for n=3 will be
*   a subset of the arrays for n=5).  The length between l and r is obviously a factor.  The minimum is 1, and increasing n with
*   length = 1 does not impace the number of arrays it generates.  Does this hold for larger length's?
*       Take Example 2 to build on:
*           n = 3, l = 1, r = 3
*           [1, 2, 1], [1, 3, 1], [1, 3, 2]
*           [2, 1, 2], [2, 1, 3], [2, 3, 1], [2, 3, 2]
*           [3, 1, 2], [3, 1, 3], [3, 2, 3]
*
*           n = 4, l = 1, r = 3
*           [1, 2, 1, 2], [1, 2, 1, 3], [1, 3, 1, 2], [1, 3, 1, 3], [1, 3, 2, 3]
*           [2, 1, 2, 1], [2, 1, 3, 1], [2, 1, 3, 2], [2, 3, 1, 2], [2, 3, 1, 3], [2, 3, 2, 1], [2, 3, 2, 3]
*           [3, 1, 2, 1], [3, 1, 3, 1], [3, 1, 3, 2], [3, 2, 3, 1], [3, 2, 3, 2]
*
*           n = 5, l = 1, r = 3
*           [1, 2, 1, 2, 1], [1, 2, 1, 3, 1], [1, 2, 1, 3, 2], [1, 3, 1, 2, 1], [1, 3, 1, 3, 1], [1, 3, 1, 3, 2], [1, 3, 2, 3, 1], [1, 3, 2, 3, 2]
*           [2, 1, 2, 1, 2], [2, 1, 3, 1, 2], [2, 1, 3, 1, 3], [2, 1, 3, 2, 3], [2, 3, 1, 2, 1], [2, 3, 1, 3, 1], [2, 3, 1, 3, 2], [2, 3, 2, 1, 2], [2, 3, 2, 1, 3], [2, 3, 2, 3, 1], [2, 3, 2, 3, 2]
*           [3, 1, 2, 1, 2], [3, 1, 2, 1, 3], [3, 1, 3, 1, 2], [3, 1, 3, 1, 3], [3, 1, 3, 2, 3], [3, 2, 3, 1, 2], [3, 2, 3, 1, 3], [3, 2, 3, 2, 3]
*
*           n = 6, l = 1, r = 3
*           [1, 2, 1, 2, 1, 2], [1, 2, 1, 2, 1, 3], [1, 2, 1, 3, 1, 2], [1, 2, 1, 3, 1, 3], [1, 2, 1, 3, 2, 3], [1, 3, 1, 2, 1, 2], [1, 3, 1, 2, 1, 3], [1, 3, 1, 3, 1, 2], [1, 3, 1, 3, 1, 3], [1, 3, 1, 3, 2, 3], [1, 3, 2, 3, 1, 2], [1, 3, 2, 3, 1, 3], [1, 3, 2, 3, 2, 3]
*           [2, 1, 2, 1, 2, 1], [2, 1, 2, 1, 3, 1], [2, 1, 2, 1, 3, 2], [2, 1, 3, 1, 2, 1], [2, 1, 3, 1, 3, 1], [2, 1, 3, 1, 3, 2], [2, 1, 3, 2, 3, 1], [2, 1, 3, 2, 3, 2], [2, 3, 1, 2, 1, 2], [2, 3, 1, 2, 1, 3], [2, 3, 1, 3, 1, 2], [2, 3, 1, 3, 2, 1], [2, 3, 1, 3, 2, 3], [2, 3, 2, 1, 2, 1], [2, 3, 2, 1, 3, 1], [2, 3, 2, 1, 3, 2], [2, 3, 2, 3, 1, 3], [2, 3, 2, 3, 2, 3]
*           [3, 1, 2, 1, 2, 1], [3, 1, 2, 1, 3, 1], [3, 1, 2, 1, 3, 2], [3, 1, 3, 1, 2, 1], [3, 1, 3, 1, 3, 1], [3, 1, 3, 1, 3, 2], [3, 1, 3, 2, 3, 1], [3, 1, 3, 2, 3, 2], [3, 2, 3, 1, 2, 1], [3, 2, 3, 1, 3, 1], [3, 2, 3, 1, 3, 2], [3, 2, 3, 2, 3, 1], [3, 2, 3, 2, 3, 2]
*
*   So, if the length is constant, increasing n from 3->6 yields 10 (3+4+3) -> 17 (5+7+5) -> 27 (8+11+8) -> 44 (13+18+13) solutions.
*   So, it looks like as n increases, the number of solutions is the number of solutions for n-2 + n-1.  How can we calculate
*   that, thought?
*           3       5       8       13      21?
*           4       7       11      18      29?
*           3       5       8       13      21?
*       ---------------------------------
*           10      17      27      44      71?
*       ---------------------------------
*       n=  3       4       5       6       7
*     len=  2       2       2       2       2
*
*   Okay, so how do we find the number of solutions for the different lengths?
*
*       n = 3, l = 1, r = 2
*           [1, 2, 1]
*           [2, 1, 2]
*
*       n = 3, l = 1, r = 3
*           [1, 2, 1], [1, 3, 1], [1, 3, 2]
*           [2, 1, 2], [2, 1, 3], [2, 3, 1], [2, 3, 2]
*           [3, 1, 2], [3, 1, 3], [3, 2, 3]
*
*       n = 3, l = 1, r = 4
*           [1, 2, 1], [1, 3, 1], [1, 3, 2], [1, 4, 1], [1, 4, 2], [1, 4, 3]
*           [2, 1, 2], [2, 1, 3], [2, 1, 4], [2, 3, 1], [2, 3, 2], [2, 4, 1], [2, 4, 2], [2, 4, 3]
*           [3, 1, 2], [3, 1, 3], [3, 1, 4], [3, 2, 3], [3, 2, 4], [3, 4, 1], [3, 4, 2], [3, 4, 3]
*           [4, 1, 2], [4, 1, 3], [4, 1, 4], [4, 2, 3], [4, 2, 4], [4, 3, 4]
*
*       n = 3, l = 1, r = 5
*           [1, 2, 1], [1, 3, 1], [1, 3, 2], [1, 4, 1], [1, 4, 2], [1, 4, 3], [1, 5, 1], [1, 5, 2], [1, 5, 3], [1, 5, 4]
*           [2, 1, 2], [2, 1, 3], [2, 1, 4], [2, 1, 5], [2, 3, 1], [2, 3, 2], [2, 4, 1], [2, 4, 2], [2, 4, 3], [2, 5, 1], [2, 5, 2], [2, 5, 3], [2, 5, 4]
*           [3, 1, 2], [3, 1, 3], [3, 1, 4], [3, 1, 5], [3, 2, 3], [3, 2, 4], [3, 2, 5], [3, 4, 1], [3, 4, 2], [3, 4, 3], [3, 5, 1], [3, 5, 2], [3, 5, 3], [3, 5, 4]
*           [4, 1, 2], [4, 1, 3], [4, 1, 4], [4, 1, 5], [4, 2, 3], [4, 2, 4], [4, 2, 5], [4, 3, 4], [4, 3, 5], [4, 5, 1], [4, 5, 2], [4, 5, 3], [4, 5, 4]
*           [5, 1, 2], [5, 1, 3], [5, 1, 4], [5, 1, 5], [5, 2, 3], [5, 2, 4], [5, 2, 5], [5, 3, 4], [5, 3, 5], [5, 4, 5]
*
*   So, if the n is constant, increasing length from 2->4 yields (length 1) 2 (1+1) -> (length 2) 10 (3+4+3) -> (length 3) 28 (6+8+8+6) -> (length 4) 60 (10+13+14+13+10)
*   The pattern is that the outer edges increase by a factor of the previous value + 1, so 1 (+2) -> 3 (+3) -> 6 (+4) -> 10, presumably the next would be (+5) -> 15
*   The center is harder to crack.  0 -> 4 -> 16 -> 40.  or if we look at the individual rows, 0 -> 4 -> 8,8 -> 13, 14, 13
*   We want to figure this out in terms of length, so put those together:
*       0       4       16      40
*       1       2       3       4
*          +4      +12     +24      +?
*
*   That looks like a pattern; to get 16, we could take 2^2 + 2^3 and to get 24, we could take 2^3 + 2^4.  So the next in the
*   pattern would be 2^4+2^5 = 56.  Add the two edges (15), and we end up with 86 solutions for n=3, length = 5.
*
*   So, putting all that together:
*       1       3       6       10      15?
*                               13      ?
*                       8               ?
*               4               14      ?  56?
*                       8               ?
*                               13      ?
*       1       3       6       10      15?
*     -----------------------------
*       2       10      28      60      86?
*    ______________________________
*     n=3       3       3       3       3
*   len=1       2       3       4       5
* 
*   That seems way too low.  What about...
*       1           3           6               10              20?
*                                               13\             ?\
*                               8\                 \            ? \
*        (+4)       4 (+12)       16 (+24)      14  40 (+48)    ?   88?
*                               8/                 /            ? /
*                                               13/             ?/
*       1           3           6               10              20?
*     ----------------------------------------------------------------------
*       2           10          28              60              128?
*    ----------------------------------------------------------------------------
*     n=3           3           3               3               3
*   len=1           2           3               4               5
*
*   That definitely more on the order of what we're looking for.
*
*   So, how do we put this all together and calculate something like n=4, length=4?
*   I dunno, and I've been staring at this long enough.  To impoldev (YouTube)!
*
*   Take Example 1 (n=3, l=4, r=5)
*   If we look at each option in terms of a decision tree, we get the following:
*                           []
*                      /         \
*                   [4]           [5]                           i = 0, we choose our first value
*                  /   \         /   \
*            [4, 5]     X       X     [5, 4]                    i = 1, we choose our second value, can't repeat the first value
*           /      \                 /      \
*          X        [4, 5, 4]       X        [5, 4, 5]          i = 2, we choose our third value, can't repeat the second value and can't continue the trajectory
*
*   Since the tree is symmetric, we only need to concern ourselves with building half of the tree; we'll just multiply our
*   result by 2 to get the full answer.  So, since the pattern must be up-down-up (down-up-down), let's just decide to only care
*   about one decision at each level (i); let's abritrarily decide that we will take "up" choices at odd levels and "down"
*   choices at even levels.  (Could have chosen "down" at odd and "up" at even, instead)
*   So, at i=1, discard any "down" choices
*                  /   \         /   \
*            [4, 5]    -X-      X    -[5, 4]-                    i = 1, keep "up" choices
*           /      \                 /      \
*
*   Leaving us with:
*                  /             /   \
*            [4, 5]             X                                i = 1, keep "up" choices
*           /      \                                             Notice the entire subtree of [5, 4] is gone.
*
*   Doing the same with "down" choices at i=2 leaves with a final tree of:
*                           []
*                      /         \
*                   [4]           [5]                           i = 0, we choose our first value
*                  /             /
*            [4, 5]             X                               i = 1, we choose our second value, can't repeat the first value
*                  \
*                   [4, 5, 4]                                   i = 2, we choose our third value, can't repeat the second value and can't continue the trajectory
*
*   At i=2, we only have one valid array, so our result is 1.  Multiply our result by 2 gives us the full answer of 2.
* 
*   Just to explore n=3, l=4, r=6...
*                  [4]                                                                                      [5]                                                                                     [6]
*             /     |                                 \                                      /               |                 \                                       /                             |      \
*            X    [4, 5]                               [4, 6]                          [5, 4]                X                  [5, 6]                           [6, 4]                            [6, 5]    X
*                /  |  \                         /       |       \                 /      |      \                         /       |       \                 /      |      \                      /   |   \
*       [4, 5, 4]   X   [4, 5, 6]        [4, 6, 4]   [4, 6, 5]    X               X   [5, 4, 5]   [5, 4, 6]        [5, 6, 4]   [5, 6, 5]    X               X   [6, 4, 5]   [6, 4, 6]    [6, 5, 4]    X    [6, 5, 6]
*
*   And after removing half our tree ("down" choices at i=1, "up" choices at i=2):
*                  [4]                                                                                      [5]                                                                                     [6]
*                   |                                 \                                                      |                 \              
*                 [4, 5]                               [4, 6]                                                X                  [5, 6]        
*                /  |                            /       |                                                                 /       |       \  
*       [4, 5, 4]   X                    [4, 6, 4]   [4, 6, 5]                                                     [5, 6, 4]   [5, 6, 5]    X 
*
*   At i=3, we have 5 results, multiplying by 2 gives us the full answer of 10.
*
*   So, how to build the tree in a useful way?  Build a DP (dynamic programming) grid, with the different sizes as the rows and
*   different ending values as the columns, and the number of valid arrays we can built with those inputs
*
*                    (0)     (1)     (2)
*                     4       5       6       (ending values)
*              ---------------------------
*     (i=0)  1 |      1       1       1
*     (i=1)  2 |      0       1       2        at i=1, we are keeping "up" choices, but 4 is the lowest value, so there are no arrays that could have been built with an "up" choice of 4, but to end with an "up" choice of 5, we have [4, 5], and to end with an "up" value of 6, we have [4, 6] and [5, 6].  This is the sum of the values in the previous row and all the columns up to the previous column
*     (i=2)  3 |      3       2       0        at i=2, we are keeping "down" choices, so the number of arrays that can end in 4 being a "down" choice is the sum of the previous rows columns after the current column (this correlates, as the available arrays are [4, 5, 4], [4, 6, 4], and [5, 6, 4].  For arrays ending in 5, we have [4, 6, 5], [5, 6, 5].
*   (array sizes)
*
*   At n=3, we sum the results of that row to get 5.  Multiply by 2 gives us a full solution of 10.
*
*   The number of values we have could be huge, so it's not efficient to iterate the entire previous row to come up with the
*   result.  Instead, use "previx sum".  It works by having a value, call it "prev" initially set to 0.  At our first index,
*   prev=0, so, given the first row:
*                    (0)     (1)     (2)
*                     4       5       6       (ending values)
*              ---------------------------
*     (i=0)  1 |      1       1       1
*     (i=1)  2 |      0       1       2         we can set (0, 1) to 0, because prev=0.  Then add the value of the previous row, current column, so prev becomes 1.  Place prev in the next cell and then we add the previous row/column value to prev and get 2.  Place prev in the next cell, and add the value of the previous row, current column, so prev becomes 3
*     (i=2)  3 |      3                         prev is 3, so set the curent cell to 3.  
*   (array sizes)

* 
*/

#include <vector>       //  for std::vector

using namespace std;

namespace Solution1
{
    class Solution {
    public:
        int zigZagArrays(int n, int l, int r) {
            int MOD = (pow(10, 9)) + 7;
            // Normalize the values; (4..6) is the same as (0..2)
            r -= l;
            vector<vector<int>> dp(n, std::vector<int>(r + 1));
            for (int j = 0; j < r + 1; ++j)
            {
                dp[0][j] = 1;
            }

            for (int i = 1; i < n; ++i)
            {
                int prev = 0;
                if (i % 2 == 1) // odd
                {
                    for (int j = 0; j < r + 1; ++j)
                    {
                        dp[i][j] = prev % MOD;
                        prev = prev % MOD + dp[i - 1][j] % MOD;
                    }
                }
                else
                {
                    for (int j = r; j >= 0; --j)
                    {
                        dp[i][j] = prev % MOD;
                        prev = prev % MOD + dp[i - 1][j] % MOD;
                    }
                }
            }
            int result{ 0 };
            for (auto value : dp[n - 1])
            {
                result = (result + value) % MOD;
            }
            return (result * 2) % MOD;
        }
    };
}
