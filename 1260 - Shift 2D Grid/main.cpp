//*****************************************************************************************************************************/
/*  Given a 2D grid of size "m" x "n" and an integer "k", you need to shift the grid k times.  In one shift operation:
*       Element at grid[i][j] moves to grid[i][j + 1].
*       Element at grid[i][n - 1] moves to grid[i + 1][0].
*       Element at grid[m - 1][n - 1] moves to grid[0][0].
*   Return the 2D grid after applying shift operation k times.
*
*   Example 1:
*
*       ┌         ┐        ┌         ┐
*       | 1  2  3 |        | 9  1  2 |
*       |         |        |         |
*       | 4  5  6 |   ->   | 3  4  5 |
*       |         |        |         |
*       | 7  8  9 |        | 6  7  8 |
*       └         ┘        └         ┘

*   Input: grid = [[1,2,3],[4,5,6],[7,8,9]], k = 1
*   Output: [[9,1,2],[3,4,5],[6,7,8]]
*
*   Example 2:
*
*       ┌            ┐        ┌            ┐        ┌            ┐        ┌            ┐        ┌            ┐
*       | 3  8  1  9 |        |13  3  8  1 |        |21 13  3  8 |        | 0 21 13  3 |        |12  0 21 13 |
*       |            |        |            |        |            |        |            |        |            |
*       |19  7  2  5 |   ->   | 9 19  7  2 |   ->   | 1  9 19  7 |   ->   | 8  1  9 19 |   ->   | 3  8  1  9 |
*       |            |        |            |        |            |        |            |        |            |
*       | 4  6 11 10 |        | 5  4  6 11 |        | 2  5  4  6 |        | 7  2  5  4 |        |19  7  2  5 |
*       |            |        |            |        |            |        |            |        |            |
*       |12  0 21 13 |        |10 12  0 21 |        |11 10 12  0 |        | 6 11 10 12 |        | 4  6 11 10 |
*       └            ┘        └            ┘        └            ┘        └            ┘        └            ┘
*
*   Input: grid = [[3,8,1,9],[19,7,2,5],[4,6,11,10],[12,0,21,13]], k = 4
*   Output: [[12,0,21,13],[3,8,1,9],[19,7,2,5],[4,6,11,10]]
*
*   Example 3:
*
*   Input: grid = [[1,2,3],[4,5,6],[7,8,9]], k = 9
*   Output: [[1,2,3],[4,5,6],[7,8,9]]
*
*   Constraints:
*
*   m == grid.length
*   n == grid[i].length
*   1 <= m <= 50
*   1 <= n <= 50
*   -1000 <= grid[i][j] <= 1000
*   0 <= k <= 100
*/

#include <iostream>     //  for std::cout, std::endl
#include <tuple>        //  for std::make_tuple, std::tuple
#include <vector>       //  for std::vector

#include "Helpers.h"

#include "Solution1.h"

int main()
{
    std::vector<std::vector<int>> grid;
    int k;
    std::vector<std::vector<int>> expectedOutput;

    // Create an instance of the solution so we can call the member function
    Solution1::Solution solution;
    // Small wrapper that forwards the input to the instance method
    auto shiftGridCallable = [&solution](std::vector<std::vector<int>> grid, int k) { return solution.shiftGrid(grid, k); };

    // Case 1
    grid = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    k = 1;
    expectedOutput = {{9, 1, 2}, {3, 4, 5}, {6, 7, 8}};
    std::cout << "Case 1: " << (Helpers::RunTestCase(shiftGridCallable, std::make_tuple(grid, k), expectedOutput) ? "PASS" : "FAIL") << "\n";

    // Case 2
    grid = {{3, 8, 1, 9}, {19, 7, 2, 5}, {4, 6, 11, 10}, {12, 0, 21, 13}};
    k = 4;
    expectedOutput = {{12, 0, 21, 13}, {3, 8, 1, 9}, {19, 7, 2, 5}, {4, 6, 11, 10}};
    std::cout << "Case 2: " << (Helpers::RunTestCase(shiftGridCallable, std::make_tuple(grid, k), expectedOutput) ? "PASS" : "FAIL") << "\n";

    // Case 3
    grid = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    k = 9;
    expectedOutput = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    std::cout << "Case 3: " << (Helpers::RunTestCase(shiftGridCallable, std::make_tuple(grid, k), expectedOutput) ? "PASS" : "FAIL") << "\n";
}
