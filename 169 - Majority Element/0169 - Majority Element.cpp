// 0169 - Majority Element.cpp : This file contains the 'main' function. Program execution begins and ends there.
//  Given an array nums of size n, return the majority element.
//
//  The majority element is the element that appears more than ⌊n / 2⌋ times.  You may assume that
//  the majority element always exists in the array.
//
//  Example 1:
//
//  Input: nums = [3, 2, 3]
//  Output: 3
//
//  Example 2:
//
//  Input: nums = [2, 2, 1, 1, 1, 2, 2]
//  Output: 2
//
//  Constraints:
//
//  n == nums.length
//  1 <= n <= 5 * 10^4
//  -10^9 <= nums[i] <= 10^9
//  The input is generated such that a majority element will exist in the array.
//
//  Follow-up: Could you solve the problem in linear time and in O(1) space ?

#include <iostream>
#include <vector>

#include "Solution1.h"
#include "Solution2.h"

int main()
{
    Solution1 solution1;
    Solution2 solution2;

    std::vector<int> nums;
    int majorityElement = 0;

    // Case 1
    nums = { 3, 2, 3 };
    majorityElement = solution2.majorityElement(nums);
    std::cout << majorityElement << std::endl;

    // Case 2
    nums = { 2, 2, 1, 1, 1, 2, 2 };
    majorityElement = solution2.majorityElement(nums);
    std::cout << majorityElement << std::endl;
}
