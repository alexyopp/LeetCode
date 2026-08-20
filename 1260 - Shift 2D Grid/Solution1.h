#pragma once

/*  The problem is circular, meaning that if k > m*n, we only really need to do the shift k % m*n times to get the same result.
*   Simplest approach would be to shift every item one space, then repeat k times, but that's not exactly efficient.  Another
*   savings can be found if k is a multiple of n, then we shifting entire rows, rather than individual elements.
*
*   That' still all going to be to too inefficient.  Since we have random access, why not just start at the 0,0 and put that
*   element where it's supposed to go, then put the element that used to be at that position where it's supposed to go, etc.
*   Once we end up back at 0,0, we've visited every element and put them all where they should go.  We just need to figure out
*   the math based on m, n, and k.  k % m*n is defenitely the first step.  k / n gives us the row position, and k % n gives us
*   the columnb position.  So, 0,0 will get placed at k / n, k % n.
*
*   It's hard keeping track of the row/column relationship.  What about treating the 2D array as if it were a 1D array?  Ah, and
*   that makes me realize we can't just loop until we get back to 0,0, because if k is a multiple of m, we'd just do the first
*   element of each row before ending up back at 0,0.
*/

#include <utility>      //  for std::swap
#include <vector>       //  for std::vector

using namespace std;

namespace Solution1
{
    class Solution {
    public:
        vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
            int m = grid.size();
            int n = grid[0].size();
            k = k % (m * n);
            int curRow{ 0 };
            int curCol{ 0 };
            int rowShift{ k / n };
            int colShift{ k % n };
            int nextRow = curRow + rowShift;
            int nextCol = curCol + colShift;
            int curElement = grid[curRow][curCol];

            for (int i = 0; i < m * n; ++i)
            {
                if (nextCol >= n)
                {
                    nextCol -= n;
                    ++nextRow;
                }
            }

            do
            {
                swap(curElement, grid[curRow + rowShift][nextCol]);
                curRow = nextRow;
                curCol = nextCol;

            } while (!(curRow == 0 && curCol == 0));

            return grid;
        }
    };
}
