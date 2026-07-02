#pragma once

/*  Seems like this would involve a Dijkstra's algorithm, where we prefer choices with cell state 0, but can accept choices with
*   cell state 1 as many times as we have health.  Dijkstra's algorithm will have us push the starting node (cell [0, 0]) onto a
*   priority queue, and then start a loop where we pop the top element from the queue, subtract 1 from our health if our popped
*   element has a value of 1, and push its neighbors.  If our health drops to 0, return false, or if we reach the final position
*   (m-1, n-1), return true.
*
*   We hit a problem when we need to backtrack, though, as we need to restore the health we lost along the dead end route.  If
*   we stored the path we'd taken so far, then we could backtrack to that element's neighbor.  Would the particular neighbor
*   matter?  I can't think up an example that does, but it feels like it should.
*
*   But the priority queue doesn't work like that; if there was an equally good option back in the past as there is now, it
*   might choose that.  What if instead of tracking the value at each step, we track what the health would be.  We can then set
*   the health to what it should be when we pop off the priority queue, because we had calculated it at that step already.
*/

#include <cmath>        //  for std::abs
#include <queue>        //  for std::priority_queue
#include <vector>       //  for std::vector

using namespace std;

namespace Solution1
{
    class Solution {
    public:
        class Cell{
        public:
            int x;
            int y;
            int value;

            Cell(int x, int y, int value) : x(x), y(y), value(value) {}
            bool operator < (const Cell& rhs) const { return this->value < rhs.value; }
        };

        bool cellInBounds(int curX, int curY, int maxX, int maxY)
        {
            return ((curX >= 0 && curX <= maxX) && (curY >= 0 && curY <= maxY));
        }

        bool areNeighbors(int aX, int aY, int bX, int bY)
        {
            if (abs(bX - aX) + abs(bY - aY) == 1) { return true; }
            else { return false; }
        }

        int numCols(const vector<vector<int>>& grid, int curRow)
        {
            if (curRow >= 0 && curRow < grid.size()) { return grid[curRow].size() - 1; }
            else { return 0; }
        }

        bool findSafeWalk(vector<vector<int>>& grid, int health) {
            int numRows = grid.size();

            priority_queue<Cell> pq;
            pq.push({ 0, 0, health - grid[0][0] });
            grid[0][0] = -1;

            while (!pq.empty())
            {
                Cell curCell = pq.top();
                pq.pop();
                health = curCell.value;
                if (health <= 0)
                {
                    return false;
                }

                if (curCell.x == numCols(grid, numRows - 1) && curCell.y == numRows - 1)
                {
                    return true;
                }

                for (auto& d : dir)
                {
                    int dj = curCell.x + d[0];
                    int di = curCell.y + d[1];
                    if (cellInBounds(dj, di, numCols(grid, di), numRows - 1) && grid[di][dj] != -1)
                    {
                        pq.push({ dj, di, health - grid[di][dj] });
                        grid[di][dj] = -1;
                    }
                }
            }
            return false;
        }

    private:
        // Directions for moving to neighboring cells: right, left, down, up
        vector<vector<int>> dir = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
    };
}
