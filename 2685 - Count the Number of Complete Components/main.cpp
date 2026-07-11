//*****************************************************************************************************************************/
/*  You are given an integer "n".  There is an undirected graph with n vertices, numbered from 0 to n - 1.  You are given a 2D
*   integer array "edges" where edges[i] = [ai, bi] denotes that there exists an undirected edge connecting vertices ai and bi.
*   Return the number of complete connected components of the graph.  A connected component is a subgraph of a graph in which
*   there exists a path between any two vertices, and no vertex of the subgraph shares an edge with a vertex outside of the
*   subgraph.  A connected component is said to be complete if there exists an edge between every pair of its vertices.
*
*   Example 1:
*
*               (0)--(1)    (3)
*       (5)       \  /       |
*                 (2)       (4)
*
*   Input: n = 6, edges = [[0,1],[0,2],[1,2],[3,4]]
*   Output: 3
*   Explanation: From the picture above, one can see that all of the components of this graph are complete.
*
*   Example 2:
*
*       (0)--(1)    (5)
*         \  /         \
*         (2)      (4)--(3)
*
*   Input: n = 6, edges = [[0,1],[0,2],[1,2],[3,4],[3,5]]
*   Output: 1
*   Explanation: The component containing vertices 0, 1, and 2 is complete since there is an edge between every pair of two
*       vertices.  On the other hand, the component containing vertices 3, 4, and 5 is not complete since there is no edge
*       between vertices 4 and 5.  Thus, the number of complete components in this graph is 1.
*
*   Constraints:
*
*   1 <= n <= 50
*   0 <= edges.length <= n * (n - 1) / 2
*   edges[i].length == 2
*   0 <= ai, bi <= n - 1
*   ai != bi
*   There are no repeated edges.
*/

#include <iostream>     //  for std::cout, std::endl
#include <tuple>        //  for std::make_tuple, std::tuple
#include <vector>       //  for std::vector

#include "Helpers.h"

#include "Solution1.h"
#include "Solution2.h"

int main()
{
    int n;
    std::vector<std::vector<int>> edges;
    int expectedOutput;

    // Create an instance of the solution so we can call the member function
    Solution2::Solution solution;
    // Small wrapper that forwards the input to the instance method
    auto countCompleteComponentsCallable = [&solution](int n, vector<vector<int>> edges) { return solution.countCompleteComponents(n, edges); };

    // Case 1
    n = 6;
    edges = { {0,1} ,{0,2},{1,2},{3,4} };
    expectedOutput = 3;
    std::cout << "Case 1: " << (Helpers::RunTestCase(countCompleteComponentsCallable, std::make_tuple(n, edges), expectedOutput) ? "PASS" : "FAIL") << "\n";

    // Case 2
    n = 6;
    edges = { {0,1} ,{0,2},{1,2},{3,4},{3,5} };
    expectedOutput = 1;
    std::cout << "Case 2: " << (Helpers::RunTestCase(countCompleteComponentsCallable, std::make_tuple(n, edges), expectedOutput) ? "PASS" : "FAIL") << "\n";

    // Case 3
    n = 4;
    edges = { {1,0} ,{2,0},{3,1},{3,2} };
    expectedOutput = 0;
    std::cout << "Case 3: " << (Helpers::RunTestCase(countCompleteComponentsCallable, std::make_tuple(n, edges), expectedOutput) ? "PASS" : "FAIL") << "\n";

}
