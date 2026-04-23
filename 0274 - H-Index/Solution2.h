#pragma once

#include "SolutionBase.h"

#include <algorithm>

class Solution2: public SolutionBase
{
public:
    int hIndex(std::vector<int>& citations)
    {
        // Count it out; as we find a 
        std::sort(citations.begin(), citations.end(), [](int a, int b) { return a > b; });

        int i = 0;
        int j = 1;

        while (j < citations.size())
        {
            if (citations[i] != citations[j])
            {
                if (citations[i] <= j)
                {
                    return citations[i];
                }
                else
                {
                    i = j;
                }
            }

            ++j;
        }

        // Catch the last group
        if (i != citations.size() - 1)
        {
            if (citations[i] <= (j - 1))
            {
                return citations[i];
            }
        }

        //  Failing too many other cases ([1], [100], [0, 0, 2], etc.)

        return 0;
    }
};
