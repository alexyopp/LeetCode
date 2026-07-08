#pragma once

/*  Must like Problem 3754, only we're solving it several times for different substrings.  So that means we can't just remove
*   the zeroes, as we need them in place to get the correct substrings.  So, instead, we'll just iterate over the substring and
*   use math to assemble x.
*
*   Problem there is x gets too big, so, instead of building it as a number, build it as a string too.  But then how do we get
*   it back to a number to do the multiplication with sum?  This seems like a dead end.
*
*   And really, this is going to fail on time limit exceeded anyway, as iterating over 10^5 digits 10^5 queries is ALOT.
*/

#include <cmath>        //  for std::pow
#include <string>       //  for std::string
#include <vector>       //  for std::vector

using namespace std;

namespace Solution1
{
    class Solution {
    public:
        vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
            const int MOD = static_cast<int>(pow(10, 9) + 7);
            vector<int> answers;

            for (auto query : queries)
            {
                int leftIdx = query[0];
                int rightIdx = query[1];

                string substring = s.substr(leftIdx, rightIdx - leftIdx + 1);
                string xString{};
                long long sum{ 0 };
                for (auto iter = substring.cbegin(); iter != substring.cend(); ++iter)
                {
                    if (*iter != '0')
                    {
                        xString.push_back(*iter);
                        sum = (sum + (*iter - '0')) % MOD;
                    }
                }

                if (xString.back() == '0') { answers.push_back(0); }
                else
                {
                    // Somehow turn xString back into a number % MOD?
                    //answers.push_back((x * sum) % MOD);
                }
            }
            return answers;
        }
    };
}
