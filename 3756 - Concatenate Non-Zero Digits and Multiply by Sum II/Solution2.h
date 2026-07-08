#pragma once

/*  impoldev (YouTube) to the rescue.  If we build a prefix sum for the string, we can know what the sum at any index.  To get
*   the sum of the range, we just take the sum at the right bound and subtract the sum at the index just previous to the left
*   bound.  This gets the sum in O(1) time complexity.
*   Do a similar thing for x; build a prefix array, storing the value of x at each index.  To get the value of x at any index,
*   we're not subtracting the right bound's value from the index previous to the left bound mathematically (i.e., 123 - 12 =
*   111), but, rather lexicographically (i.e., 123 - 12 = 3).  So we need to know how many tens to multiply the left value by to
*   get the correct x.  So, as we build the prefix x, build another array that stores the number of non-zero digits.  Using the
*   same prefix strategy of taking the right bound value and subtracting the value previous to the left bound gives us the
*   number of 10s we need, so multiply our prefix x by that, subtract it from the prefix x rightbound and we have our x.
*   Multiply the x and the sum together and we have our answer for that query.
*/

#include <string>       //  for std::string
#include <vector>       //  for std::vector

using namespace std;

namespace Solution2
{
    const int MOD = 1e9 + 7;
    const int MAX_N = 100001;
    long long pow10[MAX_N];

    // Build the 10^x array once to use for all test cases
    int init = []() {
        pow10[0] = 1;
        for (int i = 1; i < MAX_N; ++i) {
            pow10[i] = (pow10[i - 1] * 10) % MOD;
        }
        return 0;
        }();

    class Solution {
    public:
        vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
            // We know how big these arrays need to be, so dynamically growing them is a waste of time.
            // We make the arrays one larger than the string so that when we need to pull the prefix value previous to our left
            // bound, we have something to pull.
            int n = s.size();
            vector<int> sum(n+1, 0);
            vector<long long> x(n + 1, 0);
            vector<int> digitCount(n + 1, 0);

            for (int i = 0; i < n; ++i)
            {
                int digit = s[i] - '0';
                sum[i+1] = sum[i] + digit;
                x[i + 1] = digit > 0 ? (x[i] * 10 + digit) % MOD : x[i];
                digitCount[i + 1] = digitCount[i] + (digit > 0);
            }

            int m = queries.size();
            vector<int> answers(m, 0);
            for (int i = 0; i < m; ++i)
            {
                int leftIdx = queries[i][0];        // Since we built our array with an additional 0 value at the start, we can just use the leftIdx on our prefix arrays
                int rightIdx = queries[i][1] + 1;   // But we need to compensate here for that, so the right index of the query is actually associated with the next value in our prefix arrays
                int num10s = digitCount[rightIdx] - digitCount[leftIdx];
                long long xValue = (x[rightIdx] - x[leftIdx] * pow10[num10s] % MOD + MOD) % MOD;        // why the + MOD?
                long long sumValue = sum[rightIdx] - sum[leftIdx];
                answers[i] = (xValue * sumValue) % MOD;
            }

            return answers;
        }
    };
}
