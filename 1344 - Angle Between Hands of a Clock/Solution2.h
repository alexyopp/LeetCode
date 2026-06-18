#pragma once

/*  impoldev (YouTube) solution; the alternative mathematical reasoning intersted me, so here it is.
*
*   Hour Hand:
*   6 hours covers 180°, so 1 hour covers 180°/6 = 30°
*   1 hour == 60 minutes, so 60 minutes = 30° and 1 minute covers 30°/60 = 0.5°.
*   So, the hour hand degrees off 0 is number of hours * 30° + minutes * 0.5°.
*
*   Minute Hand:
*   30 minutes covers 180°, so 1 minute covers 180°/30 = 6°.
*   So the minutes hand degrees off 0 is minutes * 6°.
*
*   Call angle1 the absolute difference between hours and minutes.  Call angle2 the diference between 360° and angle1.  Return
*   the minimum between angle1 and angle2.
*/

#include <algorithm>    // for std::min
#include <cstdlib>      // for std::abs

using namespace std;

namespace Solution2
{
    class Solution {
    public:
        static constexpr double maxDegrees{ 360.0 };
        static constexpr double maxAngle{ maxDegrees / 2 };     // 360° / 2 = 180°
        static constexpr double hoursPerMaxAngle{ 6.0 };
        static constexpr double minutesPerMaxAngle{ 30.0 };
        static constexpr double hourHandDegreesPerHour{ maxAngle / hoursPerMaxAngle };                  // 180° / 6 = 30°
        static constexpr double minutesPerHour{ 60.0 };
        static constexpr double hourHandDegreesPerMinute{ hourHandDegreesPerHour / minutesPerHour };    // 30° / 60 = 0.5°
        static constexpr double minuteHandDegreesPerHour{ maxAngle / minutesPerMaxAngle };              // 180° / 30 = 6°

        double angleClock(int hour, int minutes) {
            double degreesHourHand = (hour * hourHandDegreesPerHour) + (minutes * hourHandDegreesPerMinute);
            double degreesMinuteHand = minutes * minuteHandDegreesPerHour;
            double absoluteDifference = abs(degreesHourHand - degreesMinuteHand);

            return min(absoluteDifference, maxDegrees - absoluteDifference);
        }
    };
}
