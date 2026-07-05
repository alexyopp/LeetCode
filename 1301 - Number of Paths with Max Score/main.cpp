//****************************************************************************************************************************/
/*  You are given a square "board" of characters.  You can move on the board starting at the bottom right square marked with the
*   character 'S'.  You need to reach the top left square marked with the character 'E'.  The rest of the squares are labeled
*   either with a numeric character 1, 2, ..., 9 or with an obstacle 'X'.  In one move you can go up, left or up-left
*   (diagonally) only if there is no obstacle there.  Return a list of two integers: the first integer is the maximum sum of
*   numeric characters you can collect, and the second is the number of such paths that you can take to get that maximum sum,
*   taken modulo 10^9 + 7.  In case there is no path, return [0, 0].
*
*   Example 1:
*
*       ┌-----┬-----┬-----┐
*       |     |     |     |
*       |  E  |  2  |  3  |
*       |     |     |     |
*       ├-----┼-----┼-----┤
*       |     |     |     |
*       |  2  |  X  |  2  |
*       |     |     |     |
*       ├-----┼-----┼-----┤
*       |     |     |     |
*       |  2  |  1  |  S  |
*       |     |     |     |
*       └-----┴-----┴-----┘
*
*   Input: board = ["E23","2X2","12S"]
*   Output: [7,1]
*
*   Example 2:
*
*       ┌-----┬-----┬-----┐
*       |     |     |     |
*       |  E  |  1  |  2  |
*       |     |     |     |
*       ├-----┼-----┼-----┤
*       |     |     |     |
*       |  1  |  X  |  1  |
*       |     |     |     |
*       ├-----┼-----┼-----┤
*       |     |     |     |
*       |  2  |  1  |  S  |
*       |     |     |     |
*       └-----┴-----┴-----┘
*
*   Input: board = ["E12","1X1","21S"]
*   Output: [4,2]
*
*   Example 3:
*
*       ┌-----┬-----┬-----┐
*       |     |     |     |
*       |  E  |  1  |  1  |
*       |     |     |     |
*       ├-----┼-----┼-----┤
*       |     |     |     |
*       |  X  |  X  |  X  |
*       |     |     |     |
*       ├-----┼-----┼-----┤
*       |     |     |     |
*       |  1  |  1  |  S  |
*       |     |     |     |
*       └-----┴-----┴-----┘
*
*   Input: board = ["E11","XXX","11S"]
*   Output: [0,0]
*
*   Constraints:
*
*   2 <= board.length == board[i].length <= 100
*/

#include <iostream>     //  for std::cout, std::endl
#include <string>       //  for std::string
#include <vector>       //  for std::vector

#include "Helpers.h"

#include "Solution1.h"

int main()
{
    int n;
    std::vector<std::string> board;
    std::vector<int> expectedOutput;

    // Create an instance of the solution so we can call the member function
    Solution1::Solution solution;
    // Small wrapper that forwards the input to the instance method
    auto pathsWithMaxScoreCallable = [&solution](std::vector<std::string> board) { return solution.pathsWithMaxScore(board); };

    // Case 1
    board = { "E23", "2X2", "12S" };
    expectedOutput = { 7, 1 };
    std::cout << "Case 1: " << (Helpers::RunTestCase(pathsWithMaxScoreCallable, board, expectedOutput) ? "PASS" : "FAIL") << "\n";

    // Case 2
    board = { "E12", "1X1", "21S" };
    expectedOutput = { 4, 2 };
    std::cout << "Case 2: " << (Helpers::RunTestCase(pathsWithMaxScoreCallable, board, expectedOutput) ? "PASS" : "FAIL") << "\n";

    // Case 3
    board = { "E11", "XXX", "11S" };
    expectedOutput = { 0, 0 };
    std::cout << "Case 3: " << (Helpers::RunTestCase(pathsWithMaxScoreCallable, board, expectedOutput) ? "PASS" : "FAIL") << "\n";

}
