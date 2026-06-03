// 0134 - Gas Station.cpp : This file contains the 'main' function. Program execution begins and ends there.
//  There are n children standing in a line.  Each child is assigned a rating value given in the integer array ratings.
//
//  You are giving candies to these children subjected to the following requirements:
//      Each child must have at least one candy.
//      Children with a higher rating get more candies than their neighbors.
//  Return the minimum number of candies you need to have to distribute the candies to the children.
//
//  Example 1:
//
//  Input: ratings = [1, 0, 2]
//  Output: 5
//  Explanation: You can allocate to the first, second and third child with 2, 1, 2 candies respectively.
//
//  Example 2:
//
//  Input : ratings = [1, 2, 2]
//  Output : 4
//  Explanation : You can allocate to the first, second and third child with 1, 2, 1 candies respectively.
//                The third child gets 1 candy because it satisfies the above two conditions.
//
//  Constraints :
//
//  n == ratings.length
//  1 <= n <= 2 * 10^4
//  0 <= ratings[i] <= 2 * 10^4

#include <iostream>
#include <vector>

//#include "Solution1.h"
#include "Solution2.h"

int main()
{
    std::vector<int> ratings;

    // Case 1
    ratings = { 1, 0, 2 };
    std::cout << "Output: " << candy(ratings) << std::endl;

    // Case 2
    ratings = { 1, 2, 2 };
    std::cout << "Output: " << candy(ratings) << std::endl;

    // MyCase 3
    ratings = { 4, 3, 2, 1 };
    std::cout << "Output: " << candy(ratings) << std::endl;

    // MyCase 4
    ratings = { 4, 4, 3, 3, 2, 1 };
    std::cout << "Output: " << candy(ratings) << std::endl;

    // Case 3
    ratings = { 1, 3, 4, 5, 2 };
    std::cout << "Output: " << candy(ratings) << std::endl;
}
