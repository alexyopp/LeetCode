//****************************************************************************************************************************/
/*  Given a string "s" consisting only of characters 'a', 'b' and 'c', return the number of substrings containing at least one
*   occurrence of all these characters a, b and c.
*
*   Example 1:
*
*   Input: s = "abcabc"
*   Output: 10
*   Explanation: The substrings containing at least one occurrence of the characters a, b and c are:
*                   "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (again).
*
*   Example 2:
*
*   Input: s = "aaacb"
*   Output: 3
*   Explanation: The substrings containing at least one occurrence of the characters a, b and c are:
*                   "aaacb", "aacb" and "acb".
*
*   Example 3:
*
*   Input: s = "abc"
*   Output: 1
*
*   Constraints:
*
*   3 <= s.length <= 5 x 10^4
*   s only consists of a, b or c characters.
*/

#include <iostream>     //  for std::cout, std::endl

#include "Helpers.h"

#include "Solution1.h"

int main()
{
    std::string s;
    int expectedOutput;

    // Create an instance of the solution so we can call the member function
    Solution1::Solution solution;
    // Small wrapper that forwards the input to the instance method
    auto numberOfSubstringsCallable = [&solution](std::string s) { return solution.numberOfSubstrings(s); };

    // Case 1
    s = "abcabc";
    expectedOutput = 10;
    std::cout << "Case 1: " << (Helpers::RunTestCase(numberOfSubstringsCallable, s, expectedOutput) ? "PASS" : "FAIL") << "\n";

    // Case 2
    s = "aaacb";
    expectedOutput = 3;
    std::cout << "Case 2: " << (Helpers::RunTestCase(numberOfSubstringsCallable, s, expectedOutput) ? "PASS" : "FAIL") << "\n";

    // Case 3
    s = "abc";
    expectedOutput = 1;
    std::cout << "Case 3: " << (Helpers::RunTestCase(numberOfSubstringsCallable, s, expectedOutput) ? "PASS" : "FAIL") << "\n";

    // Case 4
    s = "aaabcaa";
    expectedOutput = 11;
    std::cout << "Case 4: " << (Helpers::RunTestCase(numberOfSubstringsCallable, s, expectedOutput) ? "PASS" : "FAIL") << "\n";
}
