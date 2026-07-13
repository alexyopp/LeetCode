//*****************************************************************************************************************************/
/*  An integer has sequential digits if and only if each digit in the number is one more than the previous digit.  Return a
*   sorted list of all the integers in the range [low, high] inclusive that have sequential digits.
*
*   Example 1:
*
*   Input: low = 100, high = 300
*   Output: [123,234]
*
*   Example 2:
*
*   Input: low = 1000, high = 13000
*   Output: [1234,2345,3456,4567,5678,6789,12345]
*
*   Constraints:
*
*   10 <= low <= high <= 10^9
*/

#include <iostream>     //  for std::cout, std::endl
#include <tuple>        //  for std::make_tuple, std::tuple
#include <vector>       //  for std::vector

#include "Helpers.h"

#include "Solution1.h"
#include "Solution2.h"

int main()
{
    int low;
    int high;
    std::vector<int> expectedOutput;

    // Create an instance of the solution so we can call the member function
    Solution2::Solution solution;
    // Small wrapper that forwards the input to the instance method
    auto sequentialDigitsCallable = [&solution](int low, int high) { return solution.sequentialDigits(low, high); };

    // Case 1
    low = 100;
    high = 300;
    expectedOutput = { 123, 234 };
    std::cout << "Case 1: " << (Helpers::RunTestCase(sequentialDigitsCallable, std::make_tuple(low, high), expectedOutput) ? "PASS" : "FAIL") << "\n";

    // Case 2
    low = 1000;
    high = 13000;
    expectedOutput = { 1234, 2345, 3456, 4567, 5678, 6789, 12345 };
    std::cout << "Case 2: " << (Helpers::RunTestCase(sequentialDigitsCallable, std::make_tuple(low, high), expectedOutput) ? "PASS" : "FAIL") << "\n";

    // Case 3
    low = 234;
    high = 2314;
    expectedOutput = { 234, 345, 456, 567, 678, 789, 1234 };
    std::cout << "Case 3: " << (Helpers::RunTestCase(sequentialDigitsCallable, std::make_tuple(low, high), expectedOutput) ? "PASS" : "FAIL") << "\n";

}
