#pragma once

/*  Solution1 is a bit trivial, since the standard library is doing the work.  In an interview setting, I'd likely be asked to
*   implement string::find() myself, so why don't I do that.
*
*   For each pattern, iterate through the string until we find the start of the pattern, then iterate through the word and
*   pattern to ensure they match.
*/

#include <string>       //  for std::string
#include <vector>       //  for std::vector

using namespace std;

namespace Solution2
{
    class Solution {
    public:
        int numOfStrings(vector<string>& patterns, string word) {
            int numFoundPatterns = 0;
            for (auto pattern : patterns)
            {
                auto patternCharIter = pattern.cbegin();
                for (auto wordCharIter = word.cbegin(); wordCharIter != word.cend(); ++wordCharIter)
                {
                    if (*wordCharIter == *patternCharIter)
                    {
                        auto wordCharIterMatch = wordCharIter;
                        while (wordCharIterMatch != word.cend() &&
                               patternCharIter != pattern.cend() &&
                               *wordCharIterMatch == *patternCharIter)
                        {
                            ++wordCharIterMatch;
                            ++patternCharIter;
                        }
                        if (patternCharIter == pattern.cend())
                        {
                            ++numFoundPatterns;
                            break;
                        }
                        else
                        {
                            patternCharIter = pattern.cbegin();
                        }
                    }
                }
            }
            return numFoundPatterns;
        }
    };
}
