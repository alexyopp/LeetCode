#pragma once

/*  My math solution for yesterday was off, as my counting arrays was incorrect (for example, n=4,length=2 only has 16
*   solutions; the others undoubtedly have errors as well.)
*   Looking at the hints, I have never heard of matrix exponentiation, so I guess today is the day to learn, from impoldev
*   (YouTube), as usual.
*
*   Given input n=3, l=4, r=6
*   Say we choose a 4 first; it's the lowest number, so the next choice must be up.  Say next we choose a 5; depending on the
*   previous choice, we could go up or down.  Say we choose a 6; it is the largest number, so the next choice must be down.
*
*   Build a matrix to store the relationsip between these different states.  Fill it such that for the number chosen (say 4), if
*   the next number can be up, fill in that cell with a one.  If it can't, fill it with 0.  So, do 4 first; since it's our
*   smallest number, the 4↓ row is entirely zeroes (there is no down choice from 4).  For 4↑, 4↓ is not a valid choice, but both
*   5↓ and 6↓ are valid choices, so those cells get a 1.  Next do 5; 5↓ can only be a 4↑, and 5↑ can only be a 6↓.  Do the same
*   for 6.
*
*                           4↓  5↓  6↓  4↑  5↑  6↑
*                           0   1   2   3   4   5  (j)
*                   ------------------------------
*                   4↓ 0 |                       
*                   5↓ 1 |              1        
*                   6↓ 2 |              1   1    
*                   4↑ 3 |      1   1            
*                   5↑ 4 |          1            
*                   6↑ 5 |                       
*                     (i)
*
*   To refer into the matrix, if we are going down, we can just use i and j; if we are going up, we have to add the number of
*   items (call it I) to those indices to get tot he up values. ( 1 (5↓) + 3 (r-l+1) = 4 (5↑) )
*
*   All of this information can be collapsed into a single row with matrix multiplication.  Build a DP grid with one row and an
*   amount of columns equal to the number of items times 2 (6 in our example).
*           DP Grid = [1, 1, 1, 1, 1, 1]
*
*   Build a result array, where the first element is the result of multiplying the DP Grid with the first column of the matrix,
*   the second element is the result of multiplying the DP Grid with the second column of the matrix, and so on.
*           result = [(1*0) + (1*0) + (1*0) + (1*0) + (1*0) + (1*0) = 0,
*                     (1*0) + (1*0) + (1*0) + (1*1) + (1*0) + (1*0) = 1,
*                     (1*0) + (1*0) + (1*0) + (1*1) + (1*1) + (1*0) = 2,
*                      etc.]
*
*           result = [0, 1, 2, 2, 1, 0]
*   This is our DP Array for n=2; there are 0 valid ZigZag arrays ending with 4↓, one ending with 5↓, two ending with 6↓, etc.
*   To get to n=3, multiply the DP Array by the base matrix again.  This gives us:
*           DP Array = [0, 2, 3, 3, 2, 0]
*   The sum of these values is the number of valid ZigZag arrays at n=3.
*
*   So the formula is DP Array x Base Matrix ^ n-1.  n-1 instead of n because the DP Grid is built with 1s to kick the algorithm
*   off.
*   But, we can't just do the multiplication, since that would be a O(n) and our n of 10^9 will exceed time limits.  Instead use
*   Fast Pow, which runs in O(log(n)).
*/

#include <vector>       //  for std::vector

using namespace std;

namespace Solution1
{
    class Solution {
    public:
        const int MOD = (pow(10, 9)) + 7;

        vector<vector<long long>> matrixMultiplication(vector<vector<long long>> a, vector<vector<long long>> b)
        {
            long long numRows = a.size();
            long long numCols = a[0].size();

            std::vector<std::vector<long long>> result(numRows, std::vector<long long>(numCols, 0));
            for (long long i = 0; i < numRows; ++i)
            {
                for (long long j = 0; j < numCols; ++j)
                {
                    for (long long k = 0; k < numCols; ++k)
                    {
                        result[i][j] = (result[i][j] + (a[i][k] * b[k][j] % MOD)) % MOD;
                    }
                }
            }

            return result;
        }

        vector<vector<long long>> powerMultiplication(vector<vector<long long>> base, long long exp, vector<vector<long long>> res)
        {
            /*  Exceeds time complexity for large "n"
            for (long long i = 0; i < exp; ++i)
            {
                res = matrixMultiplication(res, base);
            }
            return res;
            */

            while (exp)
            {
                if (exp % 2 == 1)
                {
                    res = matrixMultiplication(res, base);
                }
                base = matrixMultiplication(base, base);
                exp /= 2;
            }

            return res;
        }

        int zigZagArrays(int n, int l, int r) {
            int items = r - l + 1;
            int size = 2 * items;

            std::vector<std::vector<long long>> matrix(size, std::vector<long long>(size, 0));

            for (int i = 0; i < items; ++i)
            {
                for (int j = 0; j < i; ++j)
                {
                    matrix[i][j + items] = 1;   // move DOWN to j, next go UP
                }
                for (int j = i+1; j < items; ++j)
                {
                    matrix[i + items][j] = 1;   // move UP to j, next go DOWN
                }
            }

            std::vector<std::vector<long long>> dp(1, std::vector<long long>(size, 1));
            dp = powerMultiplication(matrix, n - 1, dp);

            int result{ 0 };
            for (auto value : dp[0])
            {
                result = (result + value) % MOD;
            }
            return result;
        }
    };
}
