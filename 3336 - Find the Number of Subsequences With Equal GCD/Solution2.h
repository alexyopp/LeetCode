#pragma once

/*  To the Editorial!
*
*   Let "n" be the length of nums.  Let "m" be the maximum element in nums.  For any two positive integers "a" and "b",
*       gcd(a,b) <= min(a, b)
*   So, GCD of neither sequence can exceed m.
*   Let dp[i][j][k] be the number of way sto process the first i elements, where j is the GCD of sequence1 and k is the GCD of
*   sequence2.
*   dp[0][0][0] = 1
*   Consider the i-th element of nums; for every state dp[i-1][j][k], there are three choices
*       Add nums[i] to sequence 1
*           GCD of sequence 1 becomes gcd(j, nums[i]), GCD of sequence 2 remains the same
*       Add nums[i] to sequence 2
*           GCD of sequence 1 remains the same, GCD of sequence 2 becomes gcd(k, nums[i])
*       Do not add to either sequence
*           GCD of both sequences remains the same
*   After processing all n elements, summing dp[n][i][i] from i=1 to i = m gives the result.
*
*   Since dp[i] only depends on dp[i-1], we don't need a whole 3D array, just the last column.
*/

#include <numeric>          //  for std::gcd
#include <vector>           //  for std::vector

using namespace std;

namespace Solution2
{
    class Solution {
        static constexpr int MOD = 1e9 + 7;

    public:
        int subsequencePairCount(vector<int>& nums) {
            int m = *max_element(nums.begin(), nums.end());
            int n = nums.size();

            vector<vector<int>> dp(m + 1, vector<int>(m + 1));
            dp[0][0] = 1;

            for (int num : nums) {
                vector<vector<int>> ndp(m + 1, vector<int>(m + 1));
                for (int j = 0; j <= m; j++) {
                    int divisor1 = gcd(j, num);
                    for (int k = 0; k <= m; k++) {
                        int val = dp[j][k];
                        if (val == 0) {
                            continue;
                        }
                        int divisor2 = gcd(k, num);
                        ndp[j][k] = (ndp[j][k] + val) % MOD;
                        ndp[divisor1][k] = (ndp[divisor1][k] + val) % MOD;
                        ndp[j][divisor2] = (ndp[j][divisor2] + val) % MOD;
                    }
                }
                dp.swap(ndp);
            }

            int ans = 0;
            for (int j = 1; j <= m; j++) {
                ans = (ans + dp[j][j]) % MOD;
            }

            return ans;
        }
    };
}
