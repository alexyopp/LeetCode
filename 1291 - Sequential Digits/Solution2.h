#pragma once

/*  The Editorial suggested Sliding Window approach: initialize a sample string "123456789", which contains all possible
*   sequential digit numbers as substrings.  Iterate over all possible string lengths from length of low to length of high.
*   This has the advantage of building the list in sequential order, so there's no need to sort answers.
*/

#include <string>       //  for std::stoi, std::string, std::to_string
#include <vector>       //  for std::vector

using namespace std;

namespace Solution2
{
    class Solution {
    public:
        vector<int> sequentialDigits(int low, int high) {
            string sample = "123456789";
            vector<int> answers;

            int lowLength = to_string(low).length();
            int highLength = to_string(high).length();
            for (int length = lowLength; length < highLength + 1; ++length)
            {
                for (int startIdx = 0; startIdx < 10 - length; ++startIdx)
                {
                    int number = stoi(sample.substr(startIdx, length));
                    if (number >= low && number <= high) { answers.push_back(number); }
                }
            }

            return answers;
        }
    };
}
