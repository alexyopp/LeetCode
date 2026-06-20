//****************************************************************************************************************************/
/*  You want to build "n" new buildings in a city.  The new buildings will be built in a line and are labeled from 1 to n.
*   However, there are city restrictions on the heights of the new buildings:
*       The height of each building must be a non-negative integer.
*       The height of the first building must be 0.
*       The height difference between any two adjacent buildings cannot exceed 1.
*   Additionally, there are city restrictions on the maximum height of specific buildings.  These restrictions are given as a 2D
*   integer array "restrictions" where restrictions[i] = [idi, maxHeighti] indicates that building idi must have a height less
*   than or equal to maxHeighti.
*
*   It is guaranteed that each building will appear at most once in restrictions, and building 1 will not be in restrictions.
*
*   Return the maximum possible height of the tallest building.
*
*   Example 1:
*
*          **********         *********        **********
*          **********         *********        **********
*    5     **********         *********        **********
*          **********         *********        **********
*          **********         *********        **********
*    4     **********         *********        **********
*          **********         *********        **********
*          **********         *********        **********
*    3     **********         *********        **********
*          **********         *********        **********
*          **********         *********        **********
*    2     **********         *#######*        *########*
*          **********         *#######*        *########*
*          **********         *#######*        *########*
*    1     ***********#######**#######**######**########*
*          ***********#######**#######**######**########*
*          ***********#######**#######**######**########*
*    0     @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
*                1       2        3        4        5    
*
*   Input: n = 5, restrictions = [[2, 1], [4, 1]]
*   Output: 2
*   Explanation: The * area in the image indicates the maximum allowed height for each building, per restrictions.
*   We can build the buildings with heights [0, 1, 2, 1, 2], and the tallest building has a height of 2.
*
*   Example 2:
*
*          *******************************************************
*          *******************************************************
*    5     ***********************************************#######*
*          ***********************************************#######*
*          ***********************************************#######*
*    4     *************************************########**#######*
*          *************************************########**#######*
*          *************************************########**#######*
*    3     *****************************######**########**#######*
*          *****************************######**########**#######*
*          *****************************######**########**#######*
*    2     ********************#######**######**########**#######*
*          ********************#######**######**########**#######*
*          ********************#######**######**########**#######*
*    1     ***********#######**#######**######**########**#######*
*          ***********#######**#######**######**########**#######*
*          ***********#######**#######**######**########**#######*
*    0     @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
*                1       2        3        4        5        6
*
*   Input : n = 6, restrictions = []
*   Output : 5
*   Explanation : The * area in the image indicates the maximum allowed height for each building, per restrictions
*   We can build the buildings with heights [0, 1, 2, 3, 4, 5], and the tallest building has a height of 5.
*
*   Example 3:
*
*          **********         *****************          *********                  *********         
*          **********         *****************          *********                  *********         
*    5     ************************************          *********         *#######**********         
*          ************************************          *********         *#######**********         
*          ************************************          *********         *#######**********         
*    4     ************************************          *#######**#######**#######**#######*         
*          ************************************          *#######**#######**#######**#######*         
*          ************************************          *#######**#######**#######**#######*         
*    3     *****************************######**########**#######**#######**#######**#######**#######*
*          *****************************######**########**#######**#######**#######**#######**#######*
*          *****************************######**########**#######**#######**#######**#######**#######*
*    2     ********************#######**######**########**#######**#######**#######**#######**#######*
*          ********************#######**######**########**#######**#######**#######**#######**#######*
*          ********************#######**######**########**#######**#######**#######**#######**#######*
*    1     ***********#######**#######**######**########**#######**#######**#######**#######**#######*
*          ***********#######**#######**######**########**#######**#######**#######**#######**#######*
*          ***********#######**#######**######**########**#######**#######**#######**#######**#######*
*    0     @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
*                1       2        3        4        5        6        7        8        9        10
*
*   Input: n = 10, restrictions = [[5, 3], [2, 5], [7, 4], [10, 3]]
*   Output: 5
*   Explanation: The * area in the image indicates the maximum allowed height for each building, per restrictions.
*   We can build the buildings with heights [0, 1, 2, 3, 3, 4, 4, 5, 4, 3], and the tallest building has a height of 5.
*
*   Constraints:
*
*   2 <= n <= 10^9
*   0 <= restrictions.length <= min(n-1, 10^5)
*   2 <= idi <= n
*   idi is unique.
*   0 <= maxHeighti <= 10^9
*/

#include <iostream>     // for std::cout, std::endl
#include <tuple>        // for std::tuple

#include "Helpers.h"

#include "Solution1.h"

int main()
{
    int n;
    std::vector<vector<int>> restrictions;
    int expectedOutput;

    // Create an instance of the solution so we can call the member function
    Solution1::Solution solution;
    // Small wrapper that forwards the input to the instance method
    auto maxBuildingCallable = [&solution](int n, std::vector<std::vector<int>> restrictions) { return solution.maxBuilding(n, restrictions); };

    // Case 1
    n = 5;
    restrictions = { {2, 1}, {4, 1} };
    expectedOutput = 2;
    std::cout << "Case 1: " << (Helpers::RunTestCase(maxBuildingCallable, std::make_tuple(n, restrictions), expectedOutput) ? "PASS" : "FAIL") << "\n";

    // Case 2
    n = 6;
    restrictions = {};
    expectedOutput = 5;
    std::cout << "Case 2: " << (Helpers::RunTestCase(maxBuildingCallable, std::make_tuple(n, restrictions), expectedOutput) ? "PASS" : "FAIL") << "\n";

    // Case 3
    n = 10;
    restrictions = { {5, 3}, {2, 5}, {7, 4}, {10, 3} };
    expectedOutput = 5;
    std::cout << "Case 3: " << (Helpers::RunTestCase(maxBuildingCallable, std::make_tuple(n, restrictions), expectedOutput) ? "PASS" : "FAIL") << "\n";
}
