#pragma once

#include "SolutionBase.h"

class Solution2 : public SolutionBase
{
public:
    void rotate(std::vector<int>& nums, int k)
    {
        // Iterate through the area k steps at a time
        // [1, 2, 3, 4, 5, 6, 7], k = 3, n = size of array (7)
        //  int i = 0, 1 - > nums[i+k], so save the 4, put the 1 down there, then go to nums[i+k+k], save the 7, put down the 4, go to nums[(i+k+k+k) % n], put down the 7, pick up the 3, etc.
        //  Done iterating when we land back at nums[0]

        // [1, 2, 3, 4, 5, 6], k = 2, n = 6
        // int i = 0, 1-> nums[2], pick up 3, place 1, then go to nums[2+2%4 = 0], pick up 1, put down 3, ...endless loop.

        // FAILS on [1, 2, 3, 4, 5, 6 ], k = 3

        int n = nums.size();

        if ((k % n) == 0)
        {
            // Early out.
            return;
        }

        // Handle if n is a multiple of k
        if (n % k == 0 )
        {
            int i = 0;
            int n = nums.size();
            int targetIdx = k % n;
            int saveValA = nums[0];
            int saveValB = nums[1];
            int insertValA = nums[0];
            int insertValB = nums[1];

            while (i < n)
            {
                saveValA = nums[targetIdx];
                saveValB = nums[(targetIdx + 1) % n];
                nums[targetIdx] = insertValA;
                nums[(targetIdx + 1) % n] = insertValB;
                insertValA = saveValA;
                insertValB = saveValB;
                targetIdx = (targetIdx + k) % n;
                i += 2;
            }
        }
        else
        {
            int i = 0;
            int targetIdx = k % n;
            int saveVal = nums[0];
            int insertVal = nums[0];

            while (i < n)
            {
                saveVal = nums[targetIdx];
                nums[targetIdx] = insertVal;
                insertVal = saveVal;
                targetIdx = (targetIdx + k) % n;
                ++i;
            }
            nums[targetIdx] = insertVal;
        }
    }
};
