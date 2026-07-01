#pragma once

/*  This solution is abandoned; leaving it here for future reference of my thought process.
*/

/*  First instinct is to calculate the safeness factor of each cell, so when it comes time to decide which cell to choose next
*   on the path, we can just choose the safest.  That's probably more work than actually needs doing, though, as we'd be
*   calculating the safeness of cells that we may never come close to visiting.  So, instead, when considering a possible next
*   cell to move to, just calculate the distance between it and any thieves in the grid (per constraints, there is always at
*   least one).  How do we drive direction to the goal node?  I guess that happens naturally, as we are always picking a
*   neighbor.
*
*   Thinking this through, I don't think it actually does save time, because we end up calculating a safeness value for a cell
*   multiple times:
*       At 0,0, we calculate 0,1 and 1,0.  Say we choose 1,0, so we move there, then calculate for 1, 1 and 2, 1.  Say we choose
*       1, 1, so we move there and then calculate 1, 0, 2, 1, 1, 2, and 0, 1.  1, 0 and 0, 1 have already been calculated.
*   We could store these values as we calculate them in a data structure (same size as the input grid) that saves us
*   recalculating, but now I'm seeing a problem of getting caught in a cycle and never reaching the end.  Since we're traveling
*   a diagonal path, can we limit our choices to just the right or bottom neighbors?  I don't think so; I feel like thieves
*   could be strategically placed to push us into a dead end., where a different choice further back would lead to a more
*   optimal path.  But, if we push our possible choices onto a heap, and we just pick the best possible choice off of it, then
*   if we end up in a weaker position, we reverse back to what was a better choice.
*/

#include <algorithm>    //  for std::max
#include <cmath>        //  for std::abs
#include <queue>        //  for std::priority_queue
#include <vector>       //  for std::vector

using namespace std;

namespace Solution1
{
    class Solution {
    public:
        struct Thief
        {
            int x;
            int y;

            Thief(int x, int y) : x(x), y(y) {}
        };

        struct CellChoice
        {
            int distanceFromNearestThief;
            int x;
            int y;

            CellChoice(int distance, int x, int y) : distanceFromNearestThief(distance), x(x), y(y) {}
            bool operator < (const CellChoice& rhs) const
            {
                return this->distanceFromNearestThief < rhs.distanceFromNearestThief;
            }
        };

        int maxSafenessFactorOfCell(int x, int y, const vector<Thief>& thieves)
        {
            int safenessFactor{ 0 };
            for (auto thief : thieves)
            {
                safenessFactor = max(safenessFactor, abs(thief.x - x) + abs(thief.y - y));
            }

            return safenessFactor;
        }

        int maximumSafenessFactor(vector<vector<int>>& grid) {
            const int n = grid.size();      // grid is square, so there are n rows and cols

            vector<Thief> thieves;
            for (int y = 0; y < n; ++y)
            {
                for (int x = 0; x < n; ++x)
                {
                    if (grid[y][x] == 1)
                    {
                        thieves.push_back({ x, y });
                    }
                }
            }

            //  Since we're using 0 as uninitialized, we'll have to check if a cell we're moving into is a thief first (so we
            //  don't constantly recalculate a thief's distance from itself.  ** That's going to involve a lot of extra,
            //  duplicated work; if we just calculated the distance from a thief at every cell, even though we did it for cells
            //  we may never consider, it must be more optimal than checking a cell against every thief the first time we need
            //  to calculate its distance.  So, since we can have a number of thieves, how can we efficiently calculate the
            //  distance from every theif at every cell, whithout a huge nest of loops?
            vector<vector<int>> distanceFromThieves(n, vector<int>(n, 0));

            priority_queue<CellChoice> maxHeap;

            int maxSafenessFactor{ maxSafenessFactorOfCell(0, 0, thieves) };

            CellChoice curCell{ maxSafenessFactor, 0, 0};
            /*while (curCell.x != n - 1 && curCell.y != n - 1)
            {

            }*/

            return 0;
        }
    };
}
