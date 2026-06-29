//****************************************************************************************************************************/
/*  Given an array of strings "patterns" and a string "word", return the number of strings in patterns that exist as a substring
*   in word.
*   A substring is a contiguous sequence of characters within a string.
*
*   Example 1:
*
*   Input: patterns = ["a","abc","bc","d"], word = "abc"
*   Output: 3
*   Explanation:
*       - "a" appears as a substring in "abc".
*       - "abc" appears as a substring in "abc".
*       - "bc" appears as a substring in "abc".
*       - "d" does not appear as a substring in "abc".
*       3 of the strings in patterns appear as a substring in word.
*
*   Example 2:
*
*   Input: patterns = ["a","b","c"], word = "aaaaabbbbb"
*   Output: 2
*   Explanation:
*       - "a" appears as a substring in "aaaaabbbbb".
*       - "b" appears as a substring in "aaaaabbbbb".
*       - "c" does not appear as a substring in "aaaaabbbbb".
*       2 of the strings in patterns appear as a substring in word.
*
*   Example 3:
*
*   Input: patterns = ["a","a","a"], word = "ab"
*   Output: 3
*   Explanation: Each of the patterns appears as a substring in word "ab".
*
*   Constraints:
*
*   1 <= patterns.length <= 100
*   1 <= patterns[i].length <= 100
*   1 <= word.length <= 100
*   patterns[i] and word consist of lowercase English letters.
*/

#include <iostream>     //  for std::cout, std::endl
#include <tuple>        //  for std::make_tuple, std::tuple
#include <vector>       //  for std::vector

#include "Helpers.h"

#include "Solution1.h"
#include "Solution2.h"

int main()
{
    std::vector<std::string> patterns;
    string word;
    int expectedOutput;

    // Create an instance of the solution so we can call the member function
    Solution2::Solution solution;
    // Small wrapper that forwards the input to the instance method
    auto numOfStringsCallable = [&solution](std::vector<std::string> patterns, std::string word) { return solution.numOfStrings(patterns, word); };

    // Case 1
    patterns = { "a", "abc", "bc", "d" };
    word = { "abc" };
    expectedOutput = 3;
    std::cout << "Case 1: " << (Helpers::RunTestCase(numOfStringsCallable, std::make_tuple(patterns, word), expectedOutput) ? "PASS" : "FAIL") << "\n";

    // Case 2
    patterns = { "a", "b", "c" };
    word = { "aaaaabbbbb" };
    expectedOutput = 2;
    std::cout << "Case 2: " << (Helpers::RunTestCase(numOfStringsCallable, std::make_tuple(patterns, word), expectedOutput) ? "PASS" : "FAIL") << "\n";

    // Case 3
    patterns = { "a","a","a" };
    word = { "ab" };
    expectedOutput = 3;
    std::cout << "Case 3: " << (Helpers::RunTestCase(numOfStringsCallable, std::make_tuple(patterns, word), expectedOutput) ? "PASS" : "FAIL") << "\n";

    // Case 4
    patterns = { "dojsf", "v", "hetnovaoigv", "ksvqfdojsf", "hetnovaoig", "yskjs", "sfr", "msurztkvppptsluk", "ndxffbkkvejuakduhdcfsdbgbt", "znhdgtwzbnh", "h", "ocaualfiscmbpnfalypmtdppymw", "w", "o", "sfjksvqfdo", "odqvzuc", "bozawheajcmlewptgssueylcxhx", "bno", "jhmarzsphxduvdktzqjiz", "j", "sfrjhetnov", "vxv", "ksvqfd", "ognwvqtadalmav", "yqbspvfwmvhycmghabigl", "qyfaiazgdqaw", "ojsfrj", "ojsfrjhetn", "fdojs", "do", "ovaoig", "k", "vrh", "jsfrjhetnovaoigvgk" };
    word = { "csfjksvqfdojsfrjhetnovaoigvgk" };
    expectedOutput = 19;
    std::cout << "Case 4: " << (Helpers::RunTestCase(numOfStringsCallable, std::make_tuple(patterns, word), expectedOutput) ? "PASS" : "FAIL") << "\n";

}
