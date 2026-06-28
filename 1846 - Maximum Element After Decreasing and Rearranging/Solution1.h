#pragma once

/*  First step is obviously to sort the array, since it needs to be in increasing order.  Next, the first element has to be 1,
*   so reduce it to that if it isn't already (per the constraints, arr values can only be positive integers).  Then our next
*   element can only be, at most, one greater than our current element.  We can only reduce, not increase, so, if the value is
*   greater than what we need it to be (arr[i]+1), reduce it to that value.  Otherwise, ignore it.  Repeat for the rest of arr.
*   Now, the greatest value should be the last value in arr.
*/

#include <algorithm>    //  for std::sort
#include <vector>       //  for std::vector

using namespace std;

namespace Solution1
{
    class Solution {
    public:
        int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
            sort(arr.begin(), arr.end());
            size_t n = arr.size();
            if (arr[0] != 1)
            {
                arr[0] = 1;
            }

            for (int i = 1; i < n; ++i)
            {
                if (arr[i] > arr[i - 1])
                {
                    arr[i] = arr[i - 1] + 1;
                }
            }

            return arr[n - 1];
        }
    };
}
