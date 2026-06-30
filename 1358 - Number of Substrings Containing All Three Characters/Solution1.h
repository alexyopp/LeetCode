#pragma once

/*  Brute force would have us iterate through every substring, checking that each element exists in it.  So, start at the first
*   character in "s", check all those substrings.  Then go to the second character in s, check those substrings, etc.  We can be
*   a little smarter, though, if we recognize that, once we've found an instance of each of the three characters, any other
*   substring that follows would also be a match; e.g., "abcaaaa", once we detect the first three characters satisfy, we know
*   that "abca", "abcaa", "abcaaa", and "abcaaaa" will all match as well.  There's defintiley a way to be still a little smarter
*   by iterating through the string until we find an instance of all three characters, counting how many of each we find along
*   the way.  This way, we could determine how many strings starting before our matches contain our matches; e.g, "aaabc", we
*   count one a, a second a, a third a, then one b, and one c means we have a match, so we know that "aaabc" and "aabc" are
*   matches as well as "abc".  So, the algorithm looks like:
*       leftIter = s.begin()
*       rightIter = s.begin()
        while rightIter != s.end()
*           if s[i] == 'a', ++aCount
*           if s[i] == 'b', ++bCount
*           if s[i] == 'c', ++cCount
*           if (aCount >= bCount >= cCount >= 1)
*               substringsCount += s.size()-i;
*               while leftIter != rightIter
*                   if s[i] == 'a', --aCount
*                   if s[i] == 'b', --bCount
*                   if s[i] == 'c', --cCount
                    if (aCount >= bCount >= cCount >= 1)
*                       substringsCount += s.size()-i;
*                   ++leftIter
*           ++rightIter
*
*   Actually, we want that inner loop to iterate until we no longer have a matching set, so the outer loop can resume, looking
*   for the now missing character.
*/

#include <string>       //  for std::string

using namespace std;

namespace Solution1
{
    class Solution {
    public:
        int numberOfSubstrings(string s) {
            int numSubstrings{ 0 };
            int aCount{ 0 };
            int bCount{ 0 };
            int cCount{ 0 };
            auto leftIter = s.cbegin();
            auto rightIter = s.cbegin();
            char curChar{};
            while (rightIter != s.cend())
            {
                curChar = *rightIter;
                if      (curChar == 'a') { ++aCount; }
                else if (curChar == 'b') { ++bCount; }
                else if (curChar == 'c') { ++cCount; }
                else { throw; }

                if (aCount >= 1 && bCount >= 1 && cCount >= 1)
                {
                    numSubstrings += s.cend() - rightIter;

                    while (aCount > 0 && bCount > 0 && cCount > 0)
                    {
                        curChar = *leftIter;
                        if      (curChar == 'a') { --aCount; }
                        else if (curChar == 'b') { --bCount; }
                        else if (curChar == 'c') { --cCount; }
                        else { throw; }

                        if (aCount >= 1 && bCount >= 1 && cCount >= 1)
                        {
                            numSubstrings += s.cend() - rightIter;
                        }
                        ++leftIter;
                    }
                }
                ++rightIter;
            }

            return numSubstrings;
        }
    };
}
