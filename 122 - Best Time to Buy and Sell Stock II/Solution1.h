#pragma once

#include "SolutionBase.h"

class Solution1 : public SolutionBase
{
public:
    int maxProfit(std::vector<int>& prices)
    {
        int idx = 1;
        int profit = 0;

        while (idx < prices.size())
        {
            if (prices[idx-1] < prices[idx])
            {
                profit += prices[idx] - prices[idx-1];
            }
            ++idx;
        }

        return profit;
    }
};
