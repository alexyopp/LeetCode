//****************************************************************************************************************************/
/*  You are given an array of positive integers "nums".  You need to select a subset of nums which satisfies the following
*   condition:
*       You can place the selected elements in a 0-indexed array such that it follows the pattern:
*           [x, x2, x4, ..., xk/2, xk, xk/2, ..., x4, x2, x]
*       (Note that k can be be any non-negative power of 2). For example, [2, 4, 16, 4, 2] and [3, 9, 3] follow the pattern
*       while [2, 4, 8, 4, 2] does not.
*
*   Return the maximum number of elements in a subset that satisfies these conditions.
*
*   Example 1:
*
*   Input: nums = [5,4,1,2,2]
*   Output: 3
*   Explanation: We can select the subset {4,2,2}, which can be placed in the array as [2,4,2] which follows the pattern and
*                2^2 == 4. Hence the answer is 3.
*
*   Example 2:
*
*   Input: nums = [1,3,2,4]
*   Output: 1
*   Explanation: We can select the subset {1}, which can be placed in the array as [1] which follows the pattern. Hence the
*                answer is 1. Note that we could have also selected the subsets {2}, {3}, or {4}, there may be multiple subsets
*                which provide the same answer. 
*
*   Constraints:
*
*   2 <= nums.length <= 10^5
*   1 <= nums[i] <= 10^9
*/

#include <iostream>     //  for std::cout, std::endl
#include <vector>       //  for std::vector

#include "Helpers.h"

#include "Solution1.h"

int main()
{
    std::vector<int> nums;
    int expectedOutput;

    // Create an instance of the solution so we can call the member function
    Solution1::Solution solution;
    // Small wrapper that forwards the input to the instance method
    auto maximumLengthCallable = [&solution](std::vector<int> nums) { return solution.maximumLength(nums); };

    // Case 1
    nums = { 5, 4, 1, 2, 2 };
    expectedOutput = 3;
    std::cout << "Case 1: " << (Helpers::RunTestCase(maximumLengthCallable, nums, expectedOutput) ? "PASS" : "FAIL") << "\n";

    // Case 2
    nums = { 1, 3, 2, 4 };
    expectedOutput = 1;
    std::cout << "Case 2: " << (Helpers::RunTestCase(maximumLengthCallable, nums, expectedOutput) ? "PASS" : "FAIL") << "\n";

    // Case 3
    nums = { 4, 36, 81, 16, 25 };
    expectedOutput = 1;
    std::cout << "Case 3: " << (Helpers::RunTestCase(maximumLengthCallable, nums, expectedOutput) ? "PASS" : "FAIL") << "\n";

    // Case 4
    nums = { 15, 15, 225, 225, 50625, 50625 };
    expectedOutput = 5;
    std::cout << "Case 4: " << (Helpers::RunTestCase(maximumLengthCallable, nums, expectedOutput) ? "PASS" : "FAIL") << "\n";

    // Case 5
    nums = { 197136, 438, 380, 820, 20151121, 466, 262, 93025, 351, 461, 531, 822649, 68644, 561, 54756, 907, 599076, 879844, 461, 921600, 2704, 280, 391, 736164, 434, 725904, 234256, 324, 960, 694, 697225, 616225, 743044, 456976, 191844, 546, 568, 212521, 434, 349281, 955, 142129, 605, 732, 955, 965, 516961, 281961, 27556, 820, 152881, 264, 167, 992016, 896, 349281, 369, 333, 835, 415, 690, 268324, 879844, 476100, 858, 582, 22, 234256, 27889, 561, 466489, 188356, 74529, 268324, 314721, 369, 921600, 922, 46, 367, 759333136, 937024, 907, 174, 981, 93025, 123201, 30276, 234, 835, 26, 212521, 546, 366025, 110889, 516961, 176400, 719, 931225, 166, 67, 582, 992016, 87, 18, 418609, 262, 268435456, 672400, 136, 30276, 413449, 338724, 52, 744769, 415, 811801, 444, 822649, 136161, 64009, 4477456, 20151121, 438, 158, 862, 52, 672400, 128, 996, 57289761, 93025, 110889, 461, 724201, 899, 16384, 57289761, 922, 736164, 7311616, 93025, 901, 2704, 245025, 774, 777796321, 743044, 54756, 123201, 401956, 7569, 495, 456976, 518, 852, 481636, 248, 916636176, 591, 418609, 690, 167, 481636, 305, 862, 4489, 484, 931225, 377, 737881, 268435456, 732, 22, 863, 59049, 11664, 851, 212521, 342102016, 366025, 27889, 377, 899, 694, 960, 380, 298116, 859, 962361, 444, 280, 901, 605, 535824, 252, 128164, 850084, 134689, 907, 351, 68644, 4489, 144400, 136048896, 87, 461, 351, 495, 697225, 7569, 158, 591, 2116, 785, 314721, 26, 719, 305, 18496, 647, 234, 108, 822649, 136161, 338724, 965, 912025, 217156, 808201, 535824, 298116, 802816, 110889, 152881, 981, 333, 401956, 16384, 11664, 996, 518, 643, 850084, 78400, 623201296, 634, 811801, 64009, 212521, 46, 24964, 907, 273, 802816, 725904, 61504, 912025, 737881, 367, 724201, 172225, 172225, 599076, 136, 420, 466489, 568, 69696, 69696, 174, 968, 253, 128, 647, 808201, 616225, 938, 531, 108, 134689, 774, 123201, 305, 188356, 4477456, 333, 104976, 273, 324, 342102016, 217156, 822649, 420, 59049, 391, 333, 413449, 18496, 24964, 859, 777796321, 962361, 110889, 78400, 63504, 938, 305, 937024, 74529, 18, 863, 253, 852, 63504, 197136, 643, 123201, 166, 7311616, 484, 248, 67, 683, 243, 785, 358, 104976, 896, 2116, 916636176, 136048896, 322624, 744769, 176400, 245025, 759333136, 243, 191844, 322624, 351, 851, 27556, 683, 466, 264, 676, 676, 142129, 281961, 358, 61504, 252, 144400, 634, 128164, 968, 623201296, 476100, 858 };
    expectedOutput = 5;
    std::cout << "Case 5: " << (Helpers::RunTestCase(maximumLengthCallable, nums, expectedOutput) ? "PASS" : "FAIL") << "\n";
}
