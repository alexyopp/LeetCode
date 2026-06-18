//****************************************************************************************************************************/
/*  Given two numbers, "hour" and "minutes", return the smaller angle (in degrees) formed between the hour and the minute hand.
*    Answers within 10^-5 of the actual value will be accepted as correct.
*
*    Example 1:
*
*                 @@@@@@@@@            
*             @@@@@       @@@@@        
*          @@@                @@@      
*        *@@                     @@    
*       @@                        @@   
*      @@                @         @@  
*     @@                @           @@ 
*     @@               @             @ 
*     @@              @              @@
*     @@              @              @@
*     @@              @              @ 
*     @@              @             @@ 
*      @@             @            @@  
*       @@            @            @@  
*        @@@          @          @@    
*          @@@        @        @@@     
*            @@@@     @    @@@@        
*                @@@@@@@@@@@           
* 
*    Input: hour = 12, minutes = 30
*    Output: 165
*
*    Example 2:
*
*                 @@@@@@@@@
*             @@@@@       @@@@@
*          @@@                @@@
*        *@@                     @@
*       @@                        @@
*      @@                          @@
*     @@                            @@
*     @@                             @
*     @@              @@@@@          @@
*     @@              @   @@@@       @@
*     @@              @      @@@     @@
*     @@              @             @@
*      @@             @            @@
*       @@            @            @@
*        @@@          @          @@
*          @@@        @        @@@
*            @@@@     @    @@@@
*                @@@@@@@@@@@
*
*    Input: hour = 3, minutes = 30
*    Output: 75
*
*    Example 3:
*
*                 @@@@@@@@@
*             @@@@@       @@@@@
*          @@@                @@@
*        *@@                     @@
*       @@                        @@
*      @@                          @@
*     @@                            @@
*     @@                             @
*     @@              @@@@@@@@@@@@@  @@
*     @@                  @@@@       @@
*     @@                             @@
*     @@                            @@
*      @@                          @@
*       @@                         @@
*        @@@                     @@
*          @@@                 @@@
*            @@@@          @@@@
*                @@@@@@@@@@@
*
*    Input: hour = 3, minutes = 15
*    Output: 7.5
*
*    Constraints:
*
*    1 <= hour <= 12
*    0 <= minutes <= 59
*/

#include <iostream>     // for std::cout, std::endl

#include "Helpers.h"

#include "Solution1.h"
#include "Solution2.h"

int main()
{
    int hour;
    int minutes;;
    double expectedOutput;

    // Create an instance of the solution so we can call the member function
    Solution2::Solution solution;
    // Small wrapper that forwards the string to the instance method
    auto angleClockCallable = [&solution](int hour, int minutes) { return solution.angleClock(hour, minutes); };

    // Case 1
    hour = 12;
    minutes = 30;
    expectedOutput = 165;
    std::cout << "Case 1: " << (Helpers::RunTestCase(angleClockCallable, std::make_tuple(hour, minutes), expectedOutput) ? "PASS" : "FAIL") << "\n";

    // Case 2
    hour = 3;
    minutes = 30;
    expectedOutput = 75;
    std::cout << "Case 2: " << (Helpers::RunTestCase(angleClockCallable, std::make_tuple(hour, minutes), expectedOutput) ? "PASS" : "FAIL") << "\n";

    // Case 3
    hour = 3;
    minutes = 15;
    expectedOutput = 7.5;
    std::cout << "Case 3: " << (Helpers::RunTestCase(angleClockCallable, std::make_tuple(hour, minutes), expectedOutput) ? "PASS" : "FAIL") << "\n";

    // Case 4
    hour = 1;
    minutes = 57;
    expectedOutput = 76.5;
    std::cout << "Case 4: " << (Helpers::RunTestCase(angleClockCallable, std::make_tuple(hour, minutes), expectedOutput) ? "PASS" : "FAIL") << "\n";
}
