#pragma once

#include "SolutionBase.h"

class Solution1 : public SolutionBase
{
public:
    int hIndex(std::vector<int>& citations)
    {
        // Naive solution:
        //  Start with h-index of 0
        //  Test for h-index of 1 (iterate through citations, to find 1 value of 1)
        //      If found, h-index++, else we're done
        //  Repeat for h-index of 2, 3, etc.

        int hIndex = 0;
        int foundPapersOfTestHIndex = 0;
        int i = 0;
        while (i < citations.size())
        {
            if (citations[i] >= hIndex + 1)
            {
                ++foundPapersOfTestHIndex;
            }

            if (foundPapersOfTestHIndex == hIndex + 1)
            {
                ++hIndex;

                // Reset the loop
                i = 0;
                foundPapersOfTestHIndex = 0;
                continue;
            }

            ++i;
        }

        return hIndex;
    }
};
