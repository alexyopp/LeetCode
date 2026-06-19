#pragma once

/*  Seems rather straightforward.  We start at altitude 0, add the first value of gains, save that as our max altitude.  Take
*   the next value of gains, add it to our current altitude, compare that to our previous max altitude, take whichever is
*   higher.  We get to the end of gains, we have our answer.
*/

#include <vector>       // for std::vector

using namespace std;

namespace Solution1 {
    class Solution {
    public:
        int largestAltitude(vector<int>& gain) {
            int curAltitude = 0;
            int maxAltitude = 0;
            for (int i = 0; i < gain.size(); ++i)
            {
                curAltitude += gain[i];
                maxAltitude = std::max(maxAltitude, curAltitude);
            }

            return maxAltitude;
        }
    };
}

