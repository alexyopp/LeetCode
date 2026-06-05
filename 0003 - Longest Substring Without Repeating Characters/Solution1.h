#pragma once

#include <string>
#include <set>

using namespace std;

// Move two iterators through the string; left starts a substring, right moves until it finds a duplicate.
//  Once it does, check the length of the substring against the longest found so far.
//  That done, we could naively set left and right to left+1, but we already know left+1 -> right -1 (at least) is a valid sequence
//  So, to check the next substring, length+1, decrement length count, check against right
//  Once right reaches the end of the string, we've finished processing

//  To check against duplicates, we can manage a set that stores characters found so far
//  When we reset, we simply remove the character at leftIter (before it gets incremented).
int lengthOfLongestSubstring(string s) {
    // Early out for empty strings.
    if (s.size() == 0)
    {
        return 0;
    }

    // Initialize the loop; s.size() is at least 1, and that can't repeat with itself.
    
    set<char> charactersInSubstring;
    auto iterLeft = s.cbegin();
    auto iterRight = s.cbegin() + 1;
    int longestLength = 1;
    int curLength = 1;
    charactersInSubstring.insert(*iterLeft);

    while (iterRight != s.cend())
    {
        if (charactersInSubstring.count(*iterRight) == 0)
        {
            charactersInSubstring.insert(*iterRight);
            ++iterRight;
            ++curLength;
        }
        else
        {
            if (curLength > longestLength)
            {
                longestLength = curLength;
            }
            charactersInSubstring.erase(*iterLeft);
            ++iterLeft;
            --curLength;
        }
    }

    // iterRight is at the end, but we're still maybe processing a string
    if (curLength > longestLength)
    {
        longestLength = curLength;
    }

    return longestLength;
}
