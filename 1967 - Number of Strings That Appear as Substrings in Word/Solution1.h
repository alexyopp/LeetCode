#pragma once

/*  The std::string contains functions I need to search for a pattern in a string; just call those, iterating through patterns
*   to check each one.
*/

#include <string>       //  for std::string
#include <vector>       //  for std::vector

using namespace std;

namespace Solution1
{
    class Solution {
    public:
        int numOfStrings(vector<string>& patterns, string word) {
            int numFoundPatterns = 0;
            for (auto pattern : patterns)
            {
                if (word.find(pattern) != string::npos)
                {
                    ++numFoundPatterns;
                }
            }
            return numFoundPatterns;
        }
    };
}
