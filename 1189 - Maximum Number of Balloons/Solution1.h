#pragma once

/*  Sort the list, then sort the target word, and go character by character of the target word, seeing how many copies we have
*   in text.
*   That does involve counting things over and over again.  If we run through the text once, we can just count all the
*   characters the once, store those counts in a map.  And then when we iterate through the targetString, we see how many of
*   each there is.
*   But, iterating through targetString, again, we'd be counting over several of the same characters again.  If we again use a
*   map of the counts, then we can just iterate over the map, no need for duplicated work.
*
*   After solving this, I considered impoldev's (YouTube) approach, but his gains came from hardcoding the target string
*   ("balloon").  To keep the solution generalized, I think I'd still need the second map.
*/

#include <algorithm>    //  for std::min
#include <climits>      //  for INT_MAX
#include <map>          //  for std::map
#include <string>       //  for std::string

using namespace std;

namespace Solution1
{
    class Solution {
    public:
        int maxNumberOfBalloons(string text) {
            string targetString = "balloon";

            // Count all the characters in text
            map<char, int> textCharacterCount;
            for (auto character : text)
            {
                ++textCharacterCount[character];
            }

            // Count all the characters in targetString
            map<char, int> targetCharacterCount;
            for (auto character : targetString)
            {
                ++targetCharacterCount[character];
            }

            int maxNumberTargetString = INT_MAX;
            // Iterate over targetCharacterCount, comparing the count of each character in the targetString to what is in text
            for (auto [character, count] : targetCharacterCount)
            {
                if (textCharacterCount[character] < count)
                {
                    return 0;
                }
                else
                {
                    maxNumberTargetString = min(maxNumberTargetString, textCharacterCount[character] / count);
                }
            }

            return maxNumberTargetString;
        }
    };
}
