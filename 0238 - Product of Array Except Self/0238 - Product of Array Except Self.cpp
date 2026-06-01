// 0238 - Product of Array Except Self.cpp : This file contains the 'main' function. Program execution begins and ends there.
//  Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].
//
//  The product of any prefix or suffix of nums is guaranteed to fit in a 32 - bit integer.
//
//  You must write an algorithm that runs in O(n) time and without using the division operation.
//
//  Example 1:
//
//  Input: nums = [1, 2, 3, 4]
//  Output: [24, 12, 8, 6]
//
//  Example 2:
//
//  Input: nums = [-1, 1, 0, -3, 3]
//  Output: [0, 0, 9, 0, 0]
//
//
//  Constraints:
//
//  2 <= nums.length <= 10^5
//  -30 <= nums[i] <= 30
//  The input is generated such that answer[i] is guaranteed to fit in a 32 - bit integer.
//
//    Follow up : Can you solve the problem in O(1) extra space complexity ? (The output array does not count as extra space for space complexity analysis.)

#include <iostream>
#include <vector>
#include <string>

//#include "Solution1.h"
//#include "Solution2.h"
#include "Solution3.h"

int main()
{
    std::vector<int> nums;
    std::vector<int> answer;

    // Case 1
    nums = { 1, 2, 3, 4 };
    answer = productExceptSelf(nums);

    std::cout << "[";
    for (auto elem : answer) {
        std::cout << elem << ", ";
    }
    std::cout << std::endl;

    // Case 2
    nums = { -1, 1, 0, -3, 3 };
    answer = productExceptSelf(nums);

    std::cout << "[";
    for (auto elem : answer) {
        std::cout << elem << ", ";
    }
    std::cout << std::endl;
}
