//****************************************************************************************************************************/
/*  Given an array "intervals" where intervals[i] = [li, ri] represent the interval [li, ri), remove all intervals that are
*   covered by another interval in the list.  The interval [a, b) is covered by the interval [c, d) if and only if c <= a and
*   b <= d.  Return the number of remaining intervals.
*
*   Example 1:
*
*   Input: intervals = [[1,4],[3,6],[2,8]]
*   Output: 2
*   Explanation: Interval [3,6] is covered by [2,8], therefore it is removed.
*
*   Example 2:
*
*   Input: intervals = [[1,4],[2,3]]
*   Output: 1
*
*   Constraints:
*   
*   1 <= intervals.length <= 1000
*   intervals[i].length == 2
*   0 <= li < ri <= 10^5
*   All the given intervals are unique.
*/

#include <iostream>     //  for std::cout, std::endl
#include <vector>       //  for std::vector

#include "Helpers.h"

#include "Solution1.h"

int main()
{
    std::vector<std::vector<int>> intervals;
    int expectedOutput;

    // Create an instance of the solution so we can call the member function
    Solution1::Solution solution;
    // Small wrapper that forwards the input to the instance method
    auto removeCoveredIntervalsCallable = [&solution](std::vector<std::vector<int>> intervals) { return solution.removeCoveredIntervals(intervals); };

    // Case 1
    intervals = { {1, 4}, {3, 6}, {2, 8} };
    expectedOutput = 2;
    std::cout << "Case 1: " << (Helpers::RunTestCase(removeCoveredIntervalsCallable, intervals, expectedOutput) ? "PASS" : "FAIL") << "\n";

    // Case 2
    intervals = { {1, 4}, {2, 3} };
    expectedOutput = 1;
    std::cout << "Case 2: " << (Helpers::RunTestCase(removeCoveredIntervalsCallable, intervals, expectedOutput) ? "PASS" : "FAIL") << "\n";
}
