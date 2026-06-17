//****************************************************************************************************************************/
// You are given a string "s" consisting of lowercase English letters and the special characters: '*', '#', and '%'.  You are
// also given an integer "k".  Build a new string result by processing s according to the following rules from left to right:
//     If the letter is a lowercase English letter append it to result.
//     A '*' removes the last character from result, if it exists.
//     A '#' duplicates the current result and appends it to itself.
//     A '%' reverses the current result.
// Return the kth character of the final string result.  If k is out of the bounds of result, return '.'.
//
// Example 1:
//
// Input: s = "a#b%*", k = 1
// Output: "a"
// Explanation:
//     i    s[i]     Operation                Current result
// ---------------------------------------------------------
//     0    'a'     Append 'a'                     "a"
//     1    '#'     Duplicate result               "aa"
//     2    'b'     Append 'b'                     "aab"
//     3    '%'     Reverse result                 "baa"
//     4    '*'     Remove the last character      "ba"
//
//     The final result is "ba".  The character at index k = 1 is 'a'.
//
// Example 2:
//
// Input: s = "cd%#*#", k = 3
// Output: "d"
// Explanation:
//     i    s[i]     Operation                Current result
// ---------------------------------------------------------
//     0    'c'    Append 'c'                   "c"
//     1    'd'    Append 'd'                   "cd"
//     2    '%'    Reverse result               "dc"
//     3    '#'    Duplicate result             "dcdc"
//     4    '*'    Remove the last character    "dcd"
//     5    '#'    Duplicate result             "dcddcd"
//
//     The final result is "dcddcd".  The character at index k = 3 is 'd'.
//
// Example 3:
//
// Input: s = "z*#", k = 0
// Output: "."
// Explanation:
//
//     i    s[i]     Operation                Current result
// ---------------------------------------------------------
//     0    'z'      Append 'z'                  "z"
//     1    '*'      Remove the last character   ""
//     2    '#'      Duplicate the string        ""
//
//     The final result is "".  Since index k = 0 is out of bounds, the output is '.'.
//
// Constraints:
//
// 1 <= s.length <= 10^5
// s consists of only lowercase English letters and special characters '*', '#', and '%'.
// 0 <= k <= 10^15
// The length of result after processing s will not exceed 10^15.

#include <iostream>     // for std::cout, std::endl
#include <string>       // for std::string
#include <tuple>        // for std::make_tuple

#include "Helpers.h"

#include "Solution1.h"
#include "Solution2.h"

int main()
{
    std::string s;
    long long k;
    char expectedOutput;

    // Create an instance of the solution so we can call the member function
    Solution2::Solution solution;
    // Small wrapper that forwards the string to the instance method
    auto processStrCallable = [&solution](std::string s, long long k) { return solution.processStr(s, k); };

    // Case 1
    s = "a#b%*";
    k = 1;
    expectedOutput = 'a';
    std::cout << "Case 1: " << (Helpers::RunTestCase(processStrCallable, std::make_tuple(s, k), expectedOutput) ? "PASS" : "FAIL") << "\n";

    // Case 2
    s = "cd%#*#";
    k = 3;
    expectedOutput = 'd';
    std::cout << "Case 2: " << (Helpers::RunTestCase(processStrCallable, std::make_tuple(s, k), expectedOutput) ? "PASS" : "FAIL") << "\n";

    // Case 3
    s = "z*#";
    k = 0;
    expectedOutput = '.';
    std::cout << "Case 3: " << (Helpers::RunTestCase(processStrCallable, std::make_tuple(s, k), expectedOutput) ? "PASS" : "FAIL") << "\n";

    // Case 4
    s = "%edx#n#lkc####uom##qg#%#b#ek%##%%ocr#m%#fv%i%%#n#u%%#n#q%v#rwvd##t###%#%%%o*##r#gr*gz#dm%ez";
    k = 4780;
    expectedOutput = 'd';
    std::cout << "Case 4: " << (Helpers::RunTestCase(processStrCallable, std::make_tuple(s, k), expectedOutput) ? "PASS" : "FAIL") << "\n";

    // Case 5
    s = "%#*gm#xib";
    k = 2;
    expectedOutput = 'g';
    std::cout << "Case 5: " << (Helpers::RunTestCase(processStrCallable, std::make_tuple(s, k), expectedOutput) ? "PASS" : "FAIL") << "\n";
}
