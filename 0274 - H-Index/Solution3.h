#pragma once

#include "SolutionBase.h"

class Solution3 : public SolutionBase
{
public:
    int hIndex(std::vector<int>& citations)
    {
        // Store the number of papers with X citations (anything with more than citations.size() notations gets put into acitations.size() + 1 bucket)
        // Iterate through to fill the new array
        //  So [1, 2, 3, 4, 7] -> [1, 1, 1, 1, 0, 1] (one paper with one citation, one paper with two citations, ..., zero papers with five citations, one paper with six or more citations)
        // Highest possible H-Index is citations.size() (if all papers have citations.size() or more citations)
        // Iterate backwards through the new array, counting papers as we go
        //      if paperCount >= i, return i
        //      else updatePaper count, --i
        // If we get to the end, H-Index is zero

        std::vector<int> papers(citations.size() + 1);

        for (int i = 0; i < citations.size(); ++i)
        {
            int numCitations = citations[i];
            if (numCitations >= citations.size())
            {
                ++papers[citations.size()];
            }
            else
            {
                ++papers[citations[i]];
            }
        }

        int papersCount = 0;
        for (int i = citations.size(); i >= 0; --i)
        {
            papersCount += papers[i];
            if (papersCount >= i)
            {
                return i;
            }
        }

        return 0;
    }
};
