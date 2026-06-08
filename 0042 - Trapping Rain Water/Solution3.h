#pragma once

#include <vector>
#include <algorithm>

using namespace std;

int trap(vector<int>& height) {
    int units = 0;

    int curMaxLeft = 0;
    vector<int> maxLeft(height.size());
    for (int i = 0; i < height.size(); ++i)
    {
        if (height[i] > curMaxLeft)
        {
            curMaxLeft = height[i];

        }
        maxLeft[i] = curMaxLeft;
    }

    int curMaxRight = 0;
    vector<int> maxRight(height.size());
    for (int i = height.size() - 1; i >= 0; --i)
    {
        if (height[i] > curMaxRight)
        {
            curMaxRight = height[i];

        }
        maxRight[i] = curMaxRight;
    }

    for (int i = 0; i < height.size(); ++i)
    {
        units += max((min(maxLeft[i], maxRight[i]) - height[i]), 0);
    }

    return units;
}
