//****************************************************************************************************************************/
/*  You are given an integer "n".  Form a new integer "x" by concatenating all the non-zero digits of n in their original order.
*   If there are no non-zero digits, x = 0.  Let "sum" be the sum of digits in x.  Return an integer representing the value of
*   x * sum.
*
*   Example 1:
*
*   Input: n = 10203004
*   Output: 12340
*   Explanation:
*       The non-zero digits are 1, 2, 3, and 4. Thus, x = 1234.
*       The sum of digits is sum = 1 + 2 + 3 + 4 = 10.
*       Therefore, the answer is x * sum = 1234 * 10 = 12340.
*
*   Example 2:
*
*   Input: n = 1000
*   Output: 1
*   Explanation:
*       The non-zero digit is 1, so x = 1 and sum = 1.
*       Therefore, the answer is x * sum = 1 * 1 = 1.
*
*   Constraints:
*
*   0 <= n <= 10^9
*/

#include <iostream>     //  for std::cout, std::endl

#include "Helpers.h"

#include "Solution1.h"

int main()
{
    int n;
    long long expectedOutput;

    // Create an instance of the solution so we can call the member function
    Solution1::Solution solution;
    // Small wrapper that forwards the input to the instance method
    auto sumAndMultiplyCallable = [&solution](int n) { return solution.sumAndMultiply(n); };

    // Case 1
    n = 10203004;
    expectedOutput = 12340;
    std::cout << "Case 1: " << (Helpers::RunTestCase(sumAndMultiplyCallable, n, expectedOutput) ? "PASS" : "FAIL") << "\n";

    // Case 2
    n = 1000;
    expectedOutput = 1;
    std::cout << "Case 2: " << (Helpers::RunTestCase(sumAndMultiplyCallable, n, expectedOutput) ? "PASS" : "FAIL") << "\n";

    // Case 3
    n = 0;
    expectedOutput = 0;
    std::cout << "Case 3: " << (Helpers::RunTestCase(sumAndMultiplyCallable, n, expectedOutput) ? "PASS" : "FAIL") << "\n";

}
