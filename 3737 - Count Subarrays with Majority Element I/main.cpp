//****************************************************************************************************************************/
/*  You are given an integer array "nums" and an integer "target".  Return the number of subarrays of nums in which target is
*   the majority element.  The majority element of a subarray is the element that appears strictly more than half of the times
*   in that subarray.
*
*   Example 1:
*
*   Input: nums = [1,2,2,3], target = 2
*   Output: 5
*   Explanation:
*       Valid subarrays with target = 2 as the majority element:
*           nums[1..1] = [2]
*           nums[2..2] = [2]
*           nums[1..2] = [2,2]
*           nums[0..2] = [1,2,2]
*           nums[1..3] = [2,2,3]
*       So there are 5 such subarrays.
*
*   Example 2:
*
*   Input: nums = [1,1,1,1], target = 1
*   Output: 10
*   Explanation:
​​​​​​​*        All 10 subarrays have 1 as the majority element.
*
*   Example 3:
*
*   Input: nums = [1,2,3], target = 4
*   Output: 0
*   Explanation:
*       target = 4 does not appear in nums at all. Therefore, there cannot be any subarray where 4 is the majority element. Hence the answer is 0.
*
*   Constraints:
*
*   1 <= nums.length <= 1000
*   1 <= nums[i] <= 10^​​​​​​​9
*   1 <= target <= 10^9
*/

#include <iostream>     //  for std::cout, std::endl
#include <tuple>        //  for std::tuple
#include <vector>       //  for std::vector

#include "Helpers.h"

#include "Solution1.h"

int main()
{
    std::vector<int> nums;
    int target;
    int expectedOutput;

    // Create an instance of the solution so we can call the member function
    Solution1::Solution solution;
    // Small wrapper that forwards the input to the instance method
    auto countMajoritySubarraysCallable = [&solution](std::vector<int> nums, int target) { return solution.countMajoritySubarrays(nums, target); };

    // Case 1
    nums = { 1, 2, 2, 3 };
    target = 2;
    expectedOutput = 5;
    std::cout << "Case 1: " << (Helpers::RunTestCase(countMajoritySubarraysCallable, std::make_tuple(nums, target), expectedOutput) ? "PASS" : "FAIL") << "\n";

    // Case 2
    nums = { 1, 1, 1, 1 };
    target = 1;
    expectedOutput = 10;
    std::cout << "Case 2: " << (Helpers::RunTestCase(countMajoritySubarraysCallable, std::make_tuple(nums, target), expectedOutput) ? "PASS" : "FAIL") << "\n";

    // Case 3
    nums = { 1, 2, 3 };
    target = 4;
    expectedOutput = 0;
    std::cout << "Case 3: " << (Helpers::RunTestCase(countMajoritySubarraysCallable, std::make_tuple(nums, target), expectedOutput) ? "PASS" : "FAIL") << "\n";
}
