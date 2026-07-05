#pragma once

/*  So, the board can be up to 100x100 in size, and since the question is asking for the number of paths to be mod 10^9 + 7, I'm
*   guessing it would be time prohibitive to iterate through all the possible paths.  Is there a way to mathematically calculate
*   the number of paths?  Assuming there isn't an obstacle, and we're not on the top row or left column, we always have three
*   choices for the next step (left, up-left, up).  2x2 = 3 paths,  3x3 = 8, 4x4 = more than I think I can reliably count.
*
*   I've run out of time, so I'm referencing impoldev's (YouTube) solution.  Build the grid, with each cell storing the maximum
*   value and the number of paths that led to that maximum value.  For a given cell, check its neighbors that could have led to
*   it (from right, bottom-right, and bottom) to calculate its values.  As such, iterate backwards through the grid, starting at
*   the last column of the last row (the S position on the board).
*/

#include <algorithm>    //  for std::max
#include <string>       //  for std::string
#include <utility>      //  for std::pair
#include <vector>       //  for std::vector

using namespace std;

namespace Solution1
{
    class Solution {
    public:
        vector<int> pathsWithMaxScore(vector<string>& board) {
            const int MOD = pow(10, 9) + 7;
            const int rows = board.size();
            const int cols = board[0].size();
            vector<vector<pair<int, int>>> data(rows, vector<pair<int, int>>(cols, { -1, 0 }));
            data[rows - 1][cols - 1] = { 0, 1 };

            for (int y = rows - 1; y >= 0; --y)
            {
                for (int x = cols - 1; x >= 0; --x)
                {
                    int curBoardValue{ 0 };
                    if (board[y][x] == 'S') { continue; }
                    else if (board[y][x] == 'X') { continue; }
                    else if (board[y][x] == 'E') { /* Do nothing */ }
                    else { curBoardValue = (board[y][x] - '0'); }

                    int maxValue = -1;
                    int pathCount = 0;

                    for (auto [changeX, changeY] : directions)
                    {
                        int newX = x + changeX;
                        int newY = y + changeY;
                        if (newX >= cols || newY >= rows) { continue; }
                        pair<int, int> curData = data[newY][newX];
                        if (curData.first == -1) { continue; }
                        if (curData.first > maxValue)
                        {
                            maxValue = curData.first;
                            pathCount = curData.second;
                        }
                        else if (curData.first == maxValue)
                        {
                            pathCount = (pathCount + curData.second) % MOD;
                        }
                    }

                    if (maxValue != -1)
                    {
                        data[y][x] = { maxValue + curBoardValue, pathCount };
                    }
                }
            }

            if (data[0][0].first != -1) { return vector<int>{data[0][0].first, data[0][0].second}; }
            else { return vector<int>{0, 0}; }
        }

    private:
        vector<pair<int, int>> directions = { {1, 0}, {0, 1}, {1, 1} };
    };
}