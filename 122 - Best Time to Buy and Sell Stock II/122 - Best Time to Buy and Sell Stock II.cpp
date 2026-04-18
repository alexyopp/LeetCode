// 122 - Best Time to Buy and Sell Stock II.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

#include "Solution1.h"

int main()
{
    Solution1 solution1;

    std::vector<int> nums;

    // Case 1
    nums = { 7, 1, 5, 3, 6, 4 };
    std::cout << solution1.maxProfit(nums) << std::endl;

    // Case 2
    nums = { 1, 2, 3, 4, 5 };
    std::cout << solution1.maxProfit(nums) << std::endl;

    // Case 3
    nums = { 7, 6, 4, 3, 1 };
    std::cout << solution1.maxProfit(nums) << std::endl;
}
