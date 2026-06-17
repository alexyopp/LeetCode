#pragma once

/* Is it not the same as yesterday, but then get the k-th element?  Maybe the size leads to difficulties?
*  For each character in string s
*      if *, remove the last character from result (check for empty result first)
*      if #, append result to itself (result = result + result)
*      if %, reverse result
*      else, append character to result
*  Return the k-th elemetn of the result, . if it's out of bounds.
*
*  Indeed; that exceeds the memory limit.  Which, though the memory limit isn't specified, given that k can be so large, it
*  stands to reason that the working string could be even larger (lots of duplications of large strings), causing it to exceed
*  its maximum allowable size.
*
*  So how can we manage?  The size trouble comes from the duplications, so, rather than append a duplicate string, we could
*  store them.  Or, even just store how many duplicates there are, and save ourselves some space.
*  We get into trouble with the other operations then.  Maybe come back to the duplicate count idea; let's think through the
*  multiple strings idea first.
*  Okay, so say we have string [0]abcd; we get a duplciate operation, now we have two strings, [0]abcd, [1]abcd.  * removes the
*  last elment of the last string, so now we hae [0]abcd, [1]abc.  % reverses the string, so we have [1]cba, [0]dcba.  What do
*  some more duplications look like?  [1]cba, [0]dcba, [-1]cbadcba, [-2]cbadcbacbadcba.  And reverse that; [-2]abcdabcabcdabc, 
*  [-1]abcdabc, [0]abcd, [1]abc
*  If we track the relative order of the string (currently forward or currently reversed) then we can add strings to the front
*  or back of our list of strings, so nothing has to move around.
*
*  This gets more complicated, so I don't think we can get away with just keeping the count of repeated strings, right?  If we
*  keep duplicating and removing, then we end up with too many different strings:
*  Take abcd#*#*#*#*
*  abcd, abcdabcd, abcdabc, abcdabcabcdabc, abcdabcabcdab, abcdabcabcdababcdabcabcdab
*  I guess removal is when we need to store a new string, so we'd store:
*  [0]: abcd, duplicated 1
*  [1]: abcd, duplicated 1, -1 char
*  [2]: [0] + [1], duplicated 1
*  And it gets more complicated if we start adding characters to reversed string.  Bah, I can't quite wrap my head around it,
*  but the list of strings should be enough.
* 
* Memory limit still exceeded!  So, math is definitely the solution, as I expected, but I can't quite figure it out.  I'll leave
* this solution here, even though it doesn't technically pass the test.
*/

#include <algorithm>        // for std::reverse
#include <string>           // for std::string
#include <vector>           // for std::vector

using namespace std;

namespace Solution1
{
    class Solution {
    public:
        char processStr(string s, long long k) {
            std::vector<std::string> strings{};
            size_t numStrings{ 0 };
            size_t lengthFinalString{ 0 };
            bool reversed{ false };

            for (auto character : s)
            {
                if (character == '*')
                {
                    // If we have at least one string
                    if (numStrings > 0)
                    {
                        size_t lastString = reversed ? 0 : numStrings - 1;

                        // Pop off the back of it
                        strings[lastString].pop_back();
                        --lengthFinalString;

                        // If that was the last of this current string, pop it off the back of our list of strings and reset our
                        // counts
                        if (lengthFinalString == 0)
                        {
                            strings.pop_back();
                            --numStrings;
                            if (numStrings == 0)
                            {
                                reversed = false;
                            }
                            else
                            {
                                lengthFinalString = strings[lastString].size();
                            }
                        }
                    }
                }
                else if (character == '#')
                {
                    string newString{};

                    if (reversed)
                    {
                        auto curStringR = strings.crbegin();
                        auto lastStringR = strings.crend();
                        while (curStringR != lastStringR)
                        {
                            newString += *curStringR;
                            ++curStringR;
                        }

                        if (newString.size() > 0)
                        {
                            strings.insert(strings.begin(), newString);
                            ++numStrings;
                            lengthFinalString = newString.size();
                        }
                    }
                    else
                    {
                        auto curString = strings.cbegin();
                        auto lastString = strings.cend();
                        while (curString != lastString)
                        {
                            newString += *curString;
                            ++curString;
                        }

                        if (newString.size() > 0)
                        {
                            strings.push_back(newString);
                            ++numStrings;
                            lengthFinalString = newString.size();
                        }
                    }
                }
                else if (character == '%')
                {
                    if (numStrings > 0)
                    {
                        // Reverse each of the strings in place
                        for (auto& element : strings)
                        {
                            std::reverse(element.begin(), element.end());
                        }

                        // Need to track that we're in a reversed state (or no longer reversed if we are already currently)
                        reversed = !reversed;
                        size_t lastString = reversed ? 0 : numStrings - 1;
                        lengthFinalString = strings[lastString].size();
                    }
                }
                else
                {
                    size_t lastString = reversed ? 0 : numStrings - 1;

                    if (numStrings > 0)
                    {
                        strings[lastString].push_back(character);
                        ++lengthFinalString;
                    }
                    else
                    {
                        string s(1, character);
                        strings.push_back(s);
                        lengthFinalString = 1;
                        numStrings = 1;
                    }
                }
            }

            for (auto element : strings)
            {
                if (k < element.size())
                {
                    return element.at(k);
                }
                else
                {
                    k -= element.size();
                }
            }

            return '.';
        }
    };
}
