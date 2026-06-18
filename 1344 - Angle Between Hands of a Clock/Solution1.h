#pragma once

/*  Per the examle images, the hour hand is not static on its hour location, but a fraction of the way between its current value
*   and its next value.  So, for example, hour = 3, minutes = 0, the hands are exactly on 3 and 0 (respectively), but hour = 3,
*   minutes = 30, the hour hand will be halfway between 3 and 4, while the minute hand is exactly on 6 clock position (180°).
*   So, minutes degrees off zero is expressed as (minutes / 60) * 360.
    Then hours degrees off zero is expressed as ((hours / 12) * 360) + ((minutes / 60) * (360 / 12)).
    If we then take whichever is the larger and subtract the other from it, we have the smallest angle between.

    But that fails to take into account crossing the 0/360 position.  The biggest angle between the two is 180, so if the angle
    we get is greater than that, just subtract it from 360 to get the inverse angle.
*/

using namespace std;

namespace Solution1
{
    class Solution {
    public:
        static constexpr double minutesPerRotation{ 60.0 };
        static constexpr double hoursPerRotation{ 12.0 };
        static constexpr double degreesPerRotation{ 360.0 };
        static constexpr double degreesPerHour{ degreesPerRotation / hoursPerRotation };
        static constexpr double maxAngle{ 180.0 };

        double angleClock(int hour, int minutes) {
            if (hour == 12)
            {
                hour = 0;
            }

            double minutesPercent = minutes / minutesPerRotation;
            double hoursPercent = hour / hoursPerRotation;

            double minutesDegrees = minutesPercent * degreesPerRotation;
            double hoursDegrees = (hoursPercent * degreesPerRotation) + (minutesPercent * degreesPerHour);

            double angleToAngle;
            if (hoursDegrees > minutesDegrees)
            {
                angleToAngle = hoursDegrees - minutesDegrees;
            }
            else
            {
                angleToAngle = minutesDegrees - hoursDegrees;
            }

            if (angleToAngle > maxAngle)
            {
                return degreesPerRotation - angleToAngle;
            }
            else
            {
                return angleToAngle;
            }
        }
    };
}
