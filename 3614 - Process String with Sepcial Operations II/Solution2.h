#pragma once

//  For each character in string s
//      if *, remove the last character from result (check for empty result first)
//      if #, append result to itself (result = result + result)
//      if %, reverse result
//      else, append character to result

// Got solution from impoldev (YouTube)
//  First check if k is going to be in bounds
//      calculate the length of the final string, if k is larger, then we can early out
//  Next, iterate backwards through the operations string
//      If *, we removed a character, so increment our length to put it back
//      If #, we duplicated the string, so halve our length to take off the second half
//          If our k was in the second half, take off the length to normalize it
//              Take example abcdabcd, k = 6 (pointing at the c).  After we halve, abcd, k = 6
//              Subtract length, 6-4 = 2, the index of the c in the first half
//      If %, we reversed the string, so the length stays the same, but our k might have been relocated
//          Take example abcd, k=2.  After reversal, dcba, k=1
//          Length - 1 (to get to the last index) and then subract k
//          If we reverse back, abcd, k=2
//      else, we added a character, so decrement our length to take it off
//          But, before we do that, check if our k = length - 1.  If so, that's our character
//              Take example abcd, k = 3, length = 4; 4-1 = 3, k = 3, d is our character


#include <string>

using namespace std;

namespace Solution2
{
    class Solution {
    public:
        long long getLength(string s)
        {
            long long length{ 0 };
            for (auto character : s)
            {
                if (character == '*')
                {
                    if (length > 0)
                    {
                        length -= 1;
                    }
                }
                else if (character == '#')
                {
                    length *= 2;
                }
                else if (character == '%')
                {
                    // Reversing the string does not affect the length, do nothing.
                }
                else
                {
                    length += 1;
                }
            }

            return length;
        }

        char processStr(string s, long long k) {
            long long length = getLength(s);
            if (k >= length)
            {
                return '.';
            }

            for (auto revIter = s.crbegin(); revIter != s.crend(); ++revIter)
            {
                if (*revIter == '*' && length > 0)
                {
                    length += 1;
                }
                else if (*revIter == '#')
                {
                    length /= 2;
                    if (k >= length)
                    {
                        k -= length;
                    }
                }
                else if (*revIter == '%')
                {
                    k = length - 1 - k;
                }
                else
                {
                    if (k == length - 1)
                    {
                        return *revIter;
                    }

                    length -= 1;
                }
            }

            // Should never reach here.
            return '.';
        }
    };
}
