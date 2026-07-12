//*****************************************************************************************************************************/
/*  Given an array of integers "arr", replace each element with its rank.  The rank represents how large the element is.  The
*   rank has the following rules:
*       Rank is an integer starting from 1.
*       The larger the element, the larger the rank. If two elements are equal, their rank must be the same.
*       Rank should be as small as possible.
*
*   Example 1:
*
*   Input: arr = [40,10,20,30]
*   Output: [4,1,2,3]
*   Explanation: 40 is the largest element.  10 is the smallest.  20 is the second smallest.  30 is the third smallest.
*
*   Example 2:
*
*   Input: arr = [100,100,100]
*   Output: [1,1,1]
*   Explanation: Same elements share the same rank.
*
*   Example 3:
*
*   Input: arr = [37,12,28,9,100,56,80,5,12]
*   Output: [5,3,4,2,8,6,7,1,3]
*
*   Constraints:
*   
*   0 <= arr.length <= 10^5
*   -10^9 <= arr[i] <= 10^9
*/

#include <iostream>     //  for std::cout, std::endl
#include <vector>       //  for std::vector

#include "Helpers.h"

#include "Solution1.h"

int main()
{
    std::vector<int> arr;
    std::vector<int> expectedOutput;

    // Create an instance of the solution so we can call the member function
    Solution1::Solution solution;
    // Small wrapper that forwards the input to the instance method
    auto arrayRankTransformCallable = [&solution](std::vector<int> arr) { return solution.arrayRankTransform(arr); };

    // Case 1
    arr = { 40, 10, 20, 30 };
    expectedOutput = {4, 1, 2, 3};
    std::cout << "Case 1: " << (Helpers::RunTestCase(arrayRankTransformCallable, arr, expectedOutput) ? "PASS" : "FAIL") << "\n";

    // Case 2
    arr = { 100, 100, 100 };
    expectedOutput = {1, 1, 1};
    std::cout << "Case 2: " << (Helpers::RunTestCase(arrayRankTransformCallable, arr, expectedOutput) ? "PASS" : "FAIL") << "\n";

    // Case 3
    arr = { 37, 12, 28, 9, 100, 56, 80, 5, 12 };
    expectedOutput = {5, 3, 4, 2, 8, 6, 7, 1, 3};
    std::cout << "Case 3: " << (Helpers::RunTestCase(arrayRankTransformCallable, arr, expectedOutput) ? "PASS" : "FAIL") << "\n";

}
