#pragma once

/*  If we have a starting digit (starts at 1), we can build a number as a string by adding one to the digit and appending that
*   to the number string (giving us 12).  Do that until we get a number greater than the high number.  Then shift the starting
*   digit (now 2), and repeat the process.  Once we've done this for every starting digit (1-9), we've found all the
*   numbers, so sort the found numbers, and return that list.
*
*   Fast but heavy.
*/

#include <algorithm>    //  for std::sort
#include <string>       //  for std::stoi, std::string, std::to_string
#include <vector>       //  for std::vector

using namespace std;

namespace Solution1
{
    class Solution {
    public:
        vector<int> sequentialDigits(int low, int high) {
            vector<int> answers;
            for (int startingDigit = 1; startingDigit < 10; ++startingDigit)
            {
                string numberString = to_string(startingDigit);
                for (int sequentialDigit = startingDigit + 1; sequentialDigit < 10; ++sequentialDigit)
                {
                    numberString.append(to_string(sequentialDigit));
                    int number = stoi(numberString);
                    if (number >= low && number <= high)
                    {
                        answers.push_back(number);
                    }
                }
            }

            sort(answers.begin(), answers.end());
            return answers;
        }
    };
}
