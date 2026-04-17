#pragma once

#include "SolutionBase.h"

class Solution2 : public SolutionBase
{
public:
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n)
    {
        //  i = m-1, j = n-1, k = m + n - 1
        //  While j >= 0
        //      if i < 0
        //          
        //      if (nums2[j] >= nums1[i])
        //          nums1[k] = nums2[j]
        //          --j, --k
        //      else
        //          nums1[k] = nums1[i]
        //          --i, --k

        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;

        while (j >= 0)
        {
            if (i < 0 || nums2[j] >= nums1[i])
            {
                nums1[k] = nums2[j];
                --j;
                --k;
            }
            else
            {
                nums1[k] = nums1[i];
                --i;
                --k;
            }
        }
    }
};
