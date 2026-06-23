//****************************************************************************************************************************/
/*  You are given three integers "n", "l", and "r".  A ZigZag array of length n is defined as follows:
*       Each element lies in the range [l, r].
*       No two adjacent elements are equal.
*       No three consecutive elements form a strictly increasing or strictly decreasing sequence.
*
*   Return the total number of valid ZigZag arrays.  Since the answer may be large, return it modulo 10^9 + 7.  A sequence is
*   said to be strictly increasing if each element is strictly greater than its previous one (if exists).  A sequence is said to
*   be strictly decreasing if each element is strictly smaller than its previous one (if exists).
*   
*   Example 1:
*
*   Input: n = 3, l = 4, r = 5
*   Output: 2
*   Explanation:
*       There are only 2 valid ZigZag arrays of length n = 3 using values in the range [4, 5]:
*           [4, 5, 4]
*           [5, 4, 5]​​​​​​​
*
*   Example 2:
*
*   Input: n = 3, l = 1, r = 3
*   Output: 10
*   Explanation:
*       There are 10 valid ZigZag arrays of length n = 3 using values in the range [1, 3]:
*           [1, 2, 1], [1, 3, 1], [1, 3, 2]
*           [2, 1, 2], [2, 1, 3], [2, 3, 1], [2, 3, 2]
*           [3, 1, 2], [3, 1, 3], [3, 2, 3]
*       All arrays meet the ZigZag conditions.
*
*   Constraints:
*
*   3 <= n <= 2000
*   1 <= l < r <= 2000
*/

#include <iostream>     //  for std::cout, std::endl
#include <tuple>        //  for std::tuple

#include "Helpers.h"

#include "Solution1.h"

int main()
{
    int n;
    int l;
    int r;
    int expectedOutput;

    // Create an instance of the solution so we can call the member function
    Solution1::Solution solution;
    // Small wrapper that forwards the input to the instance method
    auto zigZagArraysCallable = [&solution](int n, int l, int r) { return solution.zigZagArrays(n, l, r); };

    // Case 1
    n = 3;
    l = 4;
    r = 5;
    expectedOutput = 2;
    std::cout << "Case 1: " << (Helpers::RunTestCase(zigZagArraysCallable, std::make_tuple(n, l, r), expectedOutput) ? "PASS" : "FAIL") << "\n";

    // Case 2
    n = 3;
    l = 1;
    r = 3;
    expectedOutput = 10;
    std::cout << "Case 2: " << (Helpers::RunTestCase(zigZagArraysCallable, std::make_tuple(n, l, r), expectedOutput) ? "PASS" : "FAIL") << "\n";
}
