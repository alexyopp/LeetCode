#pragma once

#include <vector>

using namespace std;

//  Brute force
//  For each level of the height map, run through it, filling in the valleys
//  If we run a level and don't find any valleys to fill, we're done.

// Exceeds time limit; that's fair for a brute force attempt.

int trap(vector<int>& height) {
    int units = 0;
    int currentLevel = 1;

    // Find the maximum level
    int maxLevel = 0;
    for (auto level : height)
    {
        if (level > maxLevel)
        {
            maxLevel = level;
        }
    }

    while (currentLevel <= maxLevel)
    {
        int leftIdx = 0;
        int rightIdx = 0;

        //  Loop through heightmap
        while (leftIdx < height.size())
        {
            //  We are only filling at the current level, so we look for a valley with sides >= level and an interior < level.
            if (height[leftIdx] >= currentLevel)
            {
                rightIdx = leftIdx + 1;
                while (rightIdx < height.size())
                {
                    if (height[rightIdx] < currentLevel)
                    {
                        ++rightIdx;
                    }
                    else
                    {
                        //  We've found the end of the valley.  Fill it in.
                        //  leftIdx is at our left wall, so our filling starts with the next index.
                        ++leftIdx;
                        while (leftIdx < rightIdx)
                        {
                            ++height[leftIdx];
                            ++units;
                            ++leftIdx;
                        }

                        // This valley is complete.  LeftIdx == RightIdx; go look for another valley.
                        break;
                    }
                }

                // If rightIdx falls of the heightmap, this isn't a valley, but a cliff.
                if (rightIdx == height.size())
                {
                    // Since we're going by level, there's no interior valley to worry about, so we can just reset our loop.
                    break;
                }
            }
            else
            {
                ++leftIdx;
            }
        }

        ++currentLevel;
    }

    return units;
}
