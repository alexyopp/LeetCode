//****************************************************************************************************************************/
/*  You are given a string "s" of length "m" consisting of digits.  You are also given a 2D integer array "queries", where
*   queries[i] = [li, ri].  For each queries[i], extract the substring s[li..ri].  Then, perform the following:
*       Form a new integer "x" by concatenating all the non-zero digits from the substring in their original order.  If there
*           are no non-zero digits, x = 0.
*       Let "sum" be the sum of digits in x.  The answer is x * sum.
*   Return an array of integers "answer" where answer[i] is the answer to the ith query.  Since the answers may be very large,
*   return them modulo 109 + 7.
*
*   Example 1:
*
*   Input: s = "10203004", queries = [[0,7],[1,3],[4,6]]
*   Output: [12340, 4, 9]
*   Explanation:
*       s[0..7] = "10203004"
*           x = 1234
*           sum = 1 + 2 + 3 + 4 = 10
*           Therefore, answer is 1234 * 10 = 12340.
*
*       s[1..3] = "020"
*           x = 2
*           sum = 2
*           Therefore, the answer is 2 * 2 = 4.
*
*       s[4..6] = "300"
*           x = 3
*           sum = 3
*           Therefore, the answer is 3 * 3 = 9.
*
*   Example 2:
*
*   Input: s = "1000", queries = [[0,3],[1,1]]
*   Output: [1, 0]
*   Explanation:
*       s[0..3] = "1000"
*           x = 1
*           sum = 1
*           Therefore, the answer is 1 * 1 = 1.
*
*       s[1..1] = "0"
*           x = 0
*           sum = 0
*           Therefore, the answer is 0 * 0 = 0.
*
*   Example 3:
*
*   Input: s = "9876543210", queries = [[0,9]]
*   Output: [444444137]
*   Explanation:
*       s[0..9] = "9876543210"
*           x = 987654321
*           sum = 9 + 8 + 7 + 6 + 5 + 4 + 3 + 2 + 1 = 45
*           Therefore, the answer is 987654321 * 45 = 44444444445.
*           We return 44444444445 modulo (109 + 7) = 444444137.
*
*   Constraints:
*
*   1 <= m == s.length <= 10^5
*   s consists of digits only.
*   1 <= queries.length <= 10^5
*   queries[i] = [li, ri]
*   0 <= li <= ri < m
*/

#include <iostream>     //  for std::cout, std::endl
#include <string>       //  for std::string
#include <tuple>        //  for std::make_tuple, std::tuple
#include <vector>       //  for std::vector

#include "Helpers.h"

#include "Solution1.h"
#include "Solution2.h"

int main()
{
    std::string s{};
    std::vector<std::vector<int>> queries;
    std::vector<int> expectedOutput;

    // Create an instance of the solution so we can call the member function
    Solution2::Solution solution;
    // Small wrapper that forwards the input to the instance method
    auto sumAndMultiplyCallable = [&solution](string s, std::vector<std::vector<int>> queries) { return solution.sumAndMultiply(s, queries); };

    // Case 1
    s = "10203004";
    queries = {{0, 7}, {1, 3}, {4, 6}};
    expectedOutput = {12340, 4, 9};
    std::cout << "Case 1: " << (Helpers::RunTestCase(sumAndMultiplyCallable, std::make_tuple(s, queries), expectedOutput) ? "PASS" : "FAIL") << "\n";

    // Case 2
    s = "1000";
    queries = {{0, 3}, {1, 1}};
    expectedOutput = {1, 0};
    std::cout << "Case 2: " << (Helpers::RunTestCase(sumAndMultiplyCallable, std::make_tuple(s, queries), expectedOutput) ? "PASS" : "FAIL") << "\n";

    // Case 3
    s = "9876543210";
    queries = {{0, 9}};
    expectedOutput = {444444137};
    std::cout << "Case 3: " << (Helpers::RunTestCase(sumAndMultiplyCallable, std::make_tuple(s, queries), expectedOutput) ? "PASS" : "FAIL") << "\n";
}
