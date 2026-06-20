#pragma once

/*  A naive solution would involve going through the array multiple times, adding a level each time we can, until no level can
*   be added.  resrictions isn't sorted, so turn it into some other data structure that we can reference by building id, like a 
*   map.  If we add the 0 height restriction for n=1 to it, then it'll be complete.  And the the algorithm can look something
*   like:
*       while !noLevelAdded
*           current height = 0
*           for each n building
*               if height == current height AND
*               if sortedRestrictions[n] > current height AND
*               if left building height = current height AND
*               if right building height = current height
*                   curent height += 1
*                   noLevelAdded = false
*
*   So, just to illustrate with example 1 (assume sortedRestrictions is built):
*       (current height = 0)
*           n = 1
*               height[1] = 0, sortedRestrictions[1] == 0, no level added
*           n = 2
*               height[2] = 0, sortedRestrictions[2] == 1, height[1] = 0, height[3] = 0, add level (height[2] = 1)
*           n = 3
*               height[3] = 0, sortedRestrictions[3] == X, height[2] = 1, height[4] = 0, add level (height[3] = 1)
*           n = 4
*               height[4] = 0, sortedRestrictions[4] == 1, height[3] = 1, height[5] = 0, add level (height[4] = 1)
*           n = 5
*               height[5] = 0, sortedRestrictions[5] == X, height[4] = 1, height[6] = X, add level (height[5] = 1)
*       (current height = 1)
*           n = 1
*               height[1] = 0, no level added
*           n = 2
*               height[2] = 1, sortedRestrictions[2] == 1, no level added
*           n = 3
*               height[3] = 1, sortedRestrictions[3] == X, height[2] = 1, height[4] = 1, add level (height[3] = 2)
*           n = 4
*               height[4] = 1, sortedRestrictions[4] == 1, no level added
*           n = 5
*               height[5] = 1, sortedRestrictions[5] == X, height[4] = 1, height[6] = X, add level (height[5] = 1)
*       (current height = 2)
*           n = 1
*               height[1] = 0, no level added
*           n = 2
*               height[2] = 1, no level added
*           n = 3
*               height[3] = 2, sortedRestrictions[3] == X, height[2] = 1, no level added
*           n = 4
*               height[4] = 1, no level added
*           n = 5
*               height[5] = 2, sortedRestrictions[5] == X, height[4] = 1, no level added
*       return current height (2)
*
*   With a huge number of buildings (10^9), there's no way that's cost/space efficient enough.
*
*   The city restrictions place some stringent rules.  n=1 can only be 0.  n=2 can only be 1, n=3 can only be 2, etc.  If we
*   forget the adjacency rules for now, what does that look like?
*   cityRes = { {1, 0}, {2, 1}, {3, 2}, {4, 3}, {5, 4} }  (can be expressed as n-1)
*   res     = { { ,  }, {2, 1}, { ,  }, {4, 1}, { ,  } }
*
*   Okay, so if we sort restrictions, then {{2, 1}, {4, 1}} has an implicit restriction of {3, 2} between those.  What if we
*   filled in those implicit restrictions?  The edges would be obvious implicit restrictions to add; {1,0} will always be there;
*   {n, n-1}, assuming there isn't already one for n would be another.  That raises an interesting point, that a restriction
*   could be higher than would actually be possible (say {4, 10}, but 4 could only ever be 3, under optimal circumstances).
*   If we take two adjacent restrictions, subtract their building id so we know their distances (n2 - n1) = 2.  Then, the height
*   at the first adjacency (n1, 1) + the distance would be the maximum possible height at that restriction.  If we take the
*   minimum between the two, we get the actual restriction of that location.  Note that this is determining restrictions going
*   left to right, but we need to do it a second time, going right to left, so that the restrictions are taking into account
*   left and right adjacencies.
*
*   So that gets us left, right, and each restriction's ACTUAL restriction.  Since heights increase by 1 in adjacency, it stands
*   to reason that each building would want to be as high as possible, so that its adjacent building could be as high as
*   possible.  So if all of our restrictions are maxed out, then how do we determine if one of the buildings between them get
*   higher (or if they themselves reach their potential)?  It's going to be either end, or the midpoint between them (as it will
*   grow as much as possible before having to start decreasing to meet the right restriction).  So, we're starting at the left
*   height, going along n2-n1 steps to get to right height.
*
*   Okay, let's say we have restrictions {1, 0}, {2, 0}, {5, 0}.  Between {2, 0} and {5, 0}, distance is 5-2=3, left height is
*   0, and right height is 0. 0+2 would take us from 2 to 5 (if 5 didn't have a restriction).  0+2 would take us from 5 to 2 (if
*   2 didn't have a restriction).  So if we just did half that travel, and meet in the middle, then we'd have the maximum
*   between them; (0+3) / 2 = 1.5, (0+3) / 2 = 1.5, and, droping the fraction that is our maximum height between 2 and 5.
*
*   Take {2, 1} and {4, 1}; (1+2) / 2 = 1.5, (1+2) / 2 = 1.5; nope, that's not it, as mour maximum height here is 2.
*
*   This feels like the right track, though.  We figured out the actual restrictions with the distance, what about finding the
*   restrictions for the max height at an unknown position?  So, the building is somehwere betwee n1 and n2, and we're
*   expressing that distance as d = n2 - n1.  We found n2's maximum height by adding the distance to the starting height.  So if
*   we do the same for this building at an unknown position, we could say its height is x - n1 + leftHeight and, from the other
*   side, we have n2 - x + rightHeight.  That gives us two equations for the height at some position x; so put them in terms of
*   x instead.
*               xHeight = x - n1 + n1Height,        xHeight = n2 - x + n2Height
*               0 = x - n1 + n1Height - xHeight,    0 = n2 - x + n2Height - xHeight
*               x = n1 - n1Height + xHeight,        x = n2 + n2Height - xHeight
*                   n1 - n1Height + xHeight = n2 + n2Height - xHeight
*                   2xHeight = n2 + n2Height - n1 + n1Height
*                   xHeight = (n2 + n2Height - n1 + n1Height) / 2
*                   Reorganizing the terms slightly, 
*                       xHeight = (distance + n1Height + n2Height) / 2
*
*   For {2, 1} and {4, 1}, (2 + 1 + 1) / 2 = 2
*   For {2, 0} and {5, 0}, (3 + 0 + 0) / 2 = 1.5 (1 in integer division)
*   For {2, 1} and {5, 4}, (3 + 1 + 4) / 2 = 4
*
*   So that looks like it!
*/

#include <algorithm>    //  for std::sort
#include <vector>       // for std::vector

using namespace std;

namespace Solution1 {
    class Solution {
    public:
        int maxBuilding(int n, vector<vector<int>>& restrictions) {
            // Add the initial resrtiction
            restrictions.push_back({ 1, 0 });
            
            // Sort restrictions
            sort(restrictions.begin(), restrictions.end());

            // Add the final restriction, if necessary
            auto lastElement = restrictions.end() - 1;
            if ((*lastElement).at(0) != n)
            {
                restrictions.push_back({n, n-1});
            }

            // Iterate through the restrictions, determining the genuine restriction.
            for (int i = 1; i < restrictions.size(); ++i)
            {
                int distance = restrictions[i][0] - restrictions[i - 1][0];
                restrictions[i][1] = min(restrictions[i][1], distance + restrictions[i - 1][1]);
            }
            for (int i = restrictions.size() - 2; i >= 0; --i)
            {
                int distance = restrictions[i+1][0] - restrictions[i][0];
                restrictions[i][1] = min(restrictions[i][1], distance + restrictions[i + 1][1]);
            }

            // Run through restrictions, determining the local maximum between each restriction, saving the global maximum.
            int result = 0;
            for (int i = 1; i < restrictions.size(); ++i)
            {
                int distance = restrictions[i][0] - restrictions[i - 1][0];
                int leftHeight = restrictions[i - 1][1];
                int rightHeight = restrictions[i][1];

                int currentMaximum = (distance + leftHeight + rightHeight) / 2;

                result = max(result, currentMaximum);
            }

            return result;
        }
    };
}
