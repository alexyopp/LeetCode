#pragma once

#include <vector>

using namespace std;

// Doesn't qutie work

int trap(vector<int>& height) {
    // Anything not on the heightmap is height 0;
    int leftIdx = 0;
    int rightIdx = 0;
    int units = 0;
    int potentialUnitsThisValley = 0;
    while (leftIdx < height.size())
    {
        if (height[leftIdx] > 0)
        {
            // Potential valley
            potentialUnitsThisValley = 0;
            rightIdx = leftIdx + 1;
            while (rightIdx < height.size())
            {
                // Still in a valley
                if (height[rightIdx] < height[leftIdx])
                {
                    potentialUnitsThisValley += height[leftIdx] - height[rightIdx];
                    ++rightIdx;
                }
                // We've reached the other side of the valley
                else
                {
                    units += potentialUnitsThisValley;
                    leftIdx = rightIdx;
                    break;
                }
            }

            // We've reached the end of the map without ending this valley.
            if (rightIdx == height.size())
            {
                ++leftIdx;
                rightIdx = leftIdx;
            }
        }
        else
        {
            ++leftIdx;
        }
    }

    return units;
}
