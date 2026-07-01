#pragma once

/*  Stumped, so took a look at NeetCode's (YouTube) solution.  I was on the right track, at least.  The idea is to BFS from all
*   of the thieves simultaneously to fill in the minimum distance to any thief at each cell.  Then use the heap idea to find the
*   best path.
*/

#include <algorithm>    //  for std::min
#include <deque>        //  for std::deque
#include <map>          //  for std::map
#include <queue>        //  for std::priority_queue
#include <set>          //  for std::set
#include <utility>      //  for std::pair
#include <vector>       //  for std::vector

using namespace std;

namespace Solution2
{
    class Solution {
    public:
        struct Cell
        {
            int x;
            int y;
            int distanceFromNearestThief;

            Cell(int x, int y, int distance) : x(x), y(y), distanceFromNearestThief(distance) {}
            bool operator < (const Cell& rhs) const
            {
                return this->distanceFromNearestThief < rhs.distanceFromNearestThief;
            }
        };

        bool cellInBounds(pair<int, int> cell, const int n)
        {
            return ((cell.first >= 0 && cell.first < n) && (cell.second >= 0 && cell.second < n));
        }

        void precomputeThiefDistance(const int n, const vector<vector<int>>& grid, map<pair<int, int>, int>& outDistances)
        {
            outDistances.clear();

            // Prime our cellsToProcess with all the thieves.
            deque<Cell> cellsToProcess;
            for (int y = 0; y < n; ++y)
            {
                for (int x = 0; x < n; ++x)
                {
                    if (grid[y][x] == 1)
                    {
                        cellsToProcess.push_back({ x, y, 0 });
                        outDistances[{x, y}] = 0;
                    }
                }
            }

            // Process all of the cells for their distance to the nearest thief (adds the neighbors of every thief, followed by the neighbors of the neighbors, etc.)
            while (!cellsToProcess.empty())
            {
                Cell curCell = cellsToProcess.front();
                cellsToProcess.pop_front();
                vector<pair<int, int>> neighbors{ {curCell.x + 1, curCell.y}, {curCell.x - 1, curCell.y}, {curCell.x, curCell.y + 1}, {curCell.x, curCell.y - 1} };
                for (auto cell : neighbors)
                {
                    if (cellInBounds(cell, n) && !outDistances.contains(cell))
                    {
                        outDistances[cell] = curCell.distanceFromNearestThief + 1;
                        cellsToProcess.push_back({cell.first, cell.second, curCell.distanceFromNearestThief + 1});
                    }
                }
            }
        }

        int maximumSafenessFactor(vector<vector<int>>& grid) {
            const int n = grid.size();      // grid is square, so there are n rows and cols

            // Store the distances to the nearest thief at every cell for quick lookup.
            map<pair<int, int>, int> distances;

            precomputeThiefDistance(n, grid, distances);

            priority_queue<Cell> choices;
            choices.push({ 0, 0, distances[{0,0}] });

            set<pair<int, int>> visited;
            visited.insert({ 0, 0 });

            while (!choices.empty())
            {
                Cell curCell = choices.top();
                choices.pop();

                if (curCell.x == n - 1 && curCell.y == n - 1)
                {
                    return curCell.distanceFromNearestThief;
                }

                vector<pair<int, int>> neighbors{ {curCell.x + 1, curCell.y}, {curCell.x - 1, curCell.y}, {curCell.x, curCell.y + 1}, {curCell.x, curCell.y - 1} };
                for (auto cell : neighbors)
                {
                    if (cellInBounds(cell, n) && !visited.contains(cell))
                    {
                        visited.insert({ cell.first, cell.second });
                        choices.push({ cell.first, cell.second, min(distances[{cell.first, cell.second}], curCell.distanceFromNearestThief) });
                    }
                }
            }

            //  Should never reach here.
            return 0;
        }
    };
}
