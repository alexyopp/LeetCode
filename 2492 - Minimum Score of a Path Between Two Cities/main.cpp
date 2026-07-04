//****************************************************************************************************************************/
/*  You are given a positive integer "n" representing n cities numbered from 1 to n.  You are also given a 2D array "roads"
*   where roads[i] = [ai, bi, distancei] indicates that there is a bidirectional road between cities ai and bi with a distance
*   equal to distancei.  The cities graph is not necessarily connected.
*
*   The score of a path between two cities is defined as the minimum distance of a road in this path.
*
*   Return the minimum possible score of a path between cities 1 and n.
*
*   Note:
*       A path is a sequence of roads between two cities.
*       It is allowed for a path to contain the same road multiple times, and you can visit cities 1 and n multiple times along
*           the path.
*       The test cases are generated such that there is at least one path between 1 and n.
*
*   Example 1:
*
*               (1)
*            7 /   \ 9
*           (4)-----(2)
*               5    | 6
*                   (3)
*
*   Input: n = 4, roads = [[1,2,9],[2,3,6],[2,4,5],[1,4,7]]
*   Output: 5
*   Explanation: The path from city 1 to 4 with the minimum score is: 1 -> 2 -> 4. The score of this path is min(9,5) = 5.
*   It can be shown that no other path has less score.
*
*   Example 2:
*
*           (1)
*        4 /   \ 2
*        (3)    (2)
*       7 |
*        (4)
*
*   Input: n = 4, roads = [[1,2,2],[1,3,4],[3,4,7]]
*   Output: 2
*   Explanation: The path from city 1 to 4 with the minimum score is: 1 -> 2 -> 1 -> 3 -> 4. The score of this path is
*       min(2,2,4,7) = 2.
*
*   Constraints:
*
*   2 <= n <= 10^5
*   1 <= roads.length <= 10^5
*   roads[i].length == 3
*   1 <= ai, bi <= n
*   ai != bi
*   1 <= distancei <= 10^4
*   There are no repeated edges.
*   There is at least one path between 1 and n.
*/

#include <iostream>     //  for std::cout, std::endl
#include <tuple>        //  for std::tuple
#include <vector>       //  for std::vector

#include "Helpers.h"

#include "Solution1.h"

int main()
{
    int n;
    std::vector<std::vector<int>> roads;
    int expectedOutput;

    // Create an instance of the solution so we can call the member function
    Solution1::Solution solution;
    // Small wrapper that forwards the input to the instance method
    auto minScoreCallable = [&solution](int n, vector<vector<int>> roads) { return solution.minScore(n, roads); };

    // Case 1
    n = 4;
    roads = { {1, 2, 9} , {2, 3, 6}, {2, 4, 5}, {1, 4, 7} };
    expectedOutput = 5;
    std::cout << "Case 1: " << (Helpers::RunTestCase(minScoreCallable, std::make_tuple(n, roads), expectedOutput) ? "PASS" : "FAIL") << "\n";

    // Case 2
    n = 4;
    roads = { {1, 2, 2}, {1, 3, 4}, {3, 4, 7} };
    expectedOutput = 2;
    std::cout << "Case 2: " << (Helpers::RunTestCase(minScoreCallable, std::make_tuple(n, roads), expectedOutput) ? "PASS" : "FAIL") << "\n";
}
