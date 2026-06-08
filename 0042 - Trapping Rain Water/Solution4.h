#pragma once

#include <vector>
#include <algorithm>

using namespace std;

int trap(vector<int>& height) {
    int units = 0;

    auto iterLeft = height.cbegin();
    auto iterRight = height.cend() - 1;

    int maxLeft = *iterLeft;
    int maxRight = *iterRight;

    while (iterLeft != iterRight)
    {
        if (maxLeft <= maxRight)
        {
            ++iterLeft;
            units += max((maxLeft - *iterLeft), 0);

            if (*iterLeft > maxLeft)
            {
                maxLeft = *iterLeft;
            }
        }
        else
        {
            --iterRight;
            units += max((maxRight - *iterRight), 0);

            if (*iterRight > maxRight)
            {
                maxRight = *iterRight;
            }
        }
    }

    return units;
}
