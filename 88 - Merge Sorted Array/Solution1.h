#pragma once

#include "SolutionBase.h"

class Solution1 : public SolutionBase
{
public:
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n)
    {
        //  While j < n
        //      If nums1[i] > nums2[j]
        //          Shift all elements in nums1 (i onwards) to the right by 1
        //              k = m + n - 1
        //              While k > i
        //                  nums1[k] = nums1[k-1]
        //                  --k
        //          nums1[i] = nums2[j]
        //          ++i, ++j
        //      Else
        //          ++i

        int i = 0;
        int j = 0;
        int k = m + n;
        while (j < n)
        {
            if (i >= m + j)
            {
                nums1[i] = nums2[j];
                ++i;
                ++j;
            }
            else if (nums1[i] <= nums2[j])
            {
                ++i;
            }
            else
            {
                // Shift all elements in nums1 (i onwards) to the right by 1
                k = m + n - 1;
                while (k > i)
                {
                    nums1[k] = nums1[k - 1];
                    --k;
                }

                nums1[i] = nums2[j];
                ++i;
                ++j;
            }
        }
    }
};
