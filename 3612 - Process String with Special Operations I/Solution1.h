#pragma once

//  For each character in string s
//      if *, remove the last character from result (check for empty result first)
//      if #, append result to itself (result = result + result)
//      if %, reverse result
//      else, append character to result

#include <string>
#include <algorithm>      // for swap

using namespace std;

namespace Solution1
{
    class Solution {
    public:
        string processStr(string s) {
            string result{};
            for (auto character : s)
            {
                if (character == '*')
                {
                    if (result.size() > 0)
                    {
                        result.pop_back();
                    }
                }
                else if (character == '#')
                {
                    result = result + result;
                }
                else if (character == '%')
                {
                    // size() == 0, 1 means there's nothing to reverse
                    if (result.size() > 1)
                    {
                        auto startIter = result.begin();
                        auto endIter = result.end() - 1;
                        while (endIter - startIter > 0)
                        {
                            iter_swap(startIter, endIter);
                            ++startIter;
                            --endIter;
                        }
                    }
                }
                else
                {
                    result += character;
                }
            }

            return result;
        }
    };
}
