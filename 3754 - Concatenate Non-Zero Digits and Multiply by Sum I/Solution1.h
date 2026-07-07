#pragma once

/*  We could do some math to get the digits, but it seems simpler to turn it into a string and then iterate through it.  If a
*   a digit is non-zero, add it to our x string and our sum; if it is zero, skip it.  Once we're through the number, turn x into
*   a number, multiply it by sum, and there's our answer.
*   Or, why not save space on the second string, and just remove the zeroes from nString?
*   And we can't iterate through a string and remove items while we do so, so we can either remove all the zeroes and then
*   iterate through the string to get our values, or we can abandon the string and instead build a vector of ints to store the
*   number in, then we can go with the original plan to iterate through it, removing zeroes and adding nonzeroes as we go.
*
*   I'll stick with the string.
*
*   It's heavy but quick.
*/

#include <memory>       //  for std::remove
#include <string>       //  for std::stoi, std::string, std::to_string

using namespace std;

namespace Solution1
{
    class Solution {
    public:
        long long sumAndMultiply(int n) {
            // Early out
            if (n == 0) { return 0; }

            string xString = std::to_string(n);
            auto newEnd = remove(xString.begin(), xString.end(), '0');
            xString.erase(newEnd, xString.end());

            int x = stoi(xString);
            long long sum{ 0 };
            auto iter = xString.cbegin();
            while (iter != xString.cend())
            {
                sum += *iter - '0';
                ++iter;
            }

            return x * sum;
        }
    };
}
