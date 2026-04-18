#pragma once

#include "SolutionBase.h"

#include <algorithm>

class Solution2 : public SolutionBase
{
public:
    int maxProfit(std::vector<int>& prices)
    {
        int i = 0;
        int j = 1;
        int bestProfit = 0;

        while (j < prices.size())
        {
            if (prices[i] < prices[j])
            {
                bestProfit = std::max(bestProfit, prices[j] - prices[i]);
            }
            else
            {
                i = j;
            }
            ++j;
        }

        return bestProfit;
    }
};
