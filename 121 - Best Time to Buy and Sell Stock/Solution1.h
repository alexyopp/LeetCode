#pragma once

#include "SolutionBase.h"

class Solution1 : public SolutionBase
{
public:
    int maxProfit(std::vector<int>& prices) {
        // Brute force - might work, but LeetCode times out
        //  Early out if there are no prices, no profit and if there's only 1 day of prices, no profit.
        if (prices.size() <= 1)
        {
            return 0;
        }

        int bestProfit = prices[1] - prices[0];
        int bestI = 0;
        int bestJ = 1;
        int curProfit;

        for (int i = 0; i < prices.size(); ++i)
        {
            for (int j = i + 1; j < prices.size(); ++j)
            {
                curProfit = prices[j] - prices[i];
                if (curProfit > bestProfit)
                {
                    bestProfit = curProfit;
                    bestI = i;
                    bestJ = j;
                }
            }
        }

        if (bestProfit < 0)
        {
            bestProfit = 0;
        }

        return bestProfit;
    }
};
