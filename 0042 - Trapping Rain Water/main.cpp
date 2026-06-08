//  Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water
//  it can trap after raining.
//
//  Example 1:
//
//     =
//     =
//     =
//     =
//  3  =                                                             @@@@@@@@@
//     =                                                             @@@@@@@@@
//     =                                                             @@@@@@@@@
//     =                                                             @@@@@@@@@
//     =                                                             @@@@@@@@@
//  2  =                         @@@@@@@@@+++++++++++++++++++++++++++@@@@@@@@@@@@@@@@@@+++++++++@@@@@@@@@
//     =                         @@@@@@@@@+++++++++++++++++++++++++++@@@@@@@@@@@@@@@@@@+++++++++@@@@@@@@@
//     =                         @@@@@@@@@+++++++++++++++++++++++++++@@@@@@@@@@@@@@@@@@+++++++++@@@@@@@@@
//     =                         @@@@@@@@@+++++++++++++++++++++++++++@@@@@@@@@@@@@@@@@@+++++++++@@@@@@@@@
//     =                         @@@@@@@@@+++++++++++++++++++++++++++@@@@@@@@@@@@@@@@@@+++++++++@@@@@@@@@
//  1  =       @@@@@@@@@+++++++++@@@@@@@@@@@@@@@@@@+++++++++@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//     =       @@@@@@@@@+++++++++@@@@@@@@@@@@@@@@@@+++++++++@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//     =       @@@@@@@@@+++++++++@@@@@@@@@@@@@@@@@@+++++++++@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//     =       @@@@@@@@@+++++++++@@@@@@@@@@@@@@@@@@+++++++++@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//     =       @@@@@@@@@+++++++++@@@@@@@@@@@@@@@@@@+++++++++@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//  0  ================================================================================================================
//
//  Input: height = [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]
//  Output: 6
//  Explanation: The above elevation map (black section) is represented by array[0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1].
//  In this case, 6 units of rain water (blue section) are being trapped.
//
//  Example 2:
//
//  Input: height = [4, 2, 0, 3, 2, 5]
//  Output : 9
//
//  Constraints:
//
//  n == height.length
//  1 <= n <= 2 * 10^4
//  0 <= height[i] <= 10^5

#include <iostream>
#include <vector>

//#include "Solution1.h"
//#include "Solution2.h"
//#include "Solution3.h"
#include "Solution4.h"

int main()
{
    std::vector<int> height;

    // Case 1
    height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    std::cout << trap(height) << std::endl;

    // Case 2
    height = { 4, 2, 0, 3, 2, 5 };
    std::cout << trap(height) << std::endl;

    // Case 3
    height = { 0, 1, 2, 3, 4, 5 };
    std::cout << trap(height) << std::endl;

    // Case 4
    height = { 5, 4, 3, 2, 1 };
    std::cout << trap(height) << std::endl;

    // Case 5
    height = { 5, 1, 0, 0, 1, 5 };
    std::cout << trap(height) << std::endl;

    // Case 6
    height = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 5 };
    std::cout << trap(height) << std::endl;

    // Case 7
    height = { 4, 2, 3 };
    std::cout << trap(height) << std::endl;

    // Case 8
    height = { 1, 2, 1, 2, 3, 1, 0, 1, 2, 0, 1, 0 };
    std::cout << trap(height) << std::endl;
}
