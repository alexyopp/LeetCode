// 0274 - H-Index.cpp : This file contains the 'main' function. Program execution begins and ends there.
//  Given an array of integers citations where citations[i] is the number of citations a researcher
//  received for their ith paper, return the researcher's h-index.
//
//  According to the definition of h-index on Wikipedia: The h-index is defined as the maximum value
//  of h such that the given researcher has published at least h papers that have each been cited at
//  least h times.
//
//  Example 1:
//
//  Input: citations = [3, 0, 6, 1, 5]
//  Output: 3
//  Explanation: [3, 0, 6, 1, 5] means the researcher has 5 papers in total and each of them had
//               received 3, 0, 6, 1, 5 citations respectively.  Since the researcher has 3 papers
//               with at least 3 citations each and the remaining two with no more than 3 citations
//               each, their h-index is 3.
//
//  Example 2:
//
//  Input: citations = [1, 3, 1]
//  Output: 1
//
//  Constraints:
//
//  n == citations.length
//  1 <= n <= 5000
//  0 <= citations[i] <= 1000

#include <iostream>
#include <vector>

#include "Solution1.h"
#include "Solution2.h"
#include "Solution3.h"

int main()
{
    Solution1 solution1;
    Solution2 solution2;
    Solution3 solution3;

    std::vector<int> citations;

    // Case 1
    citations = { 3, 0, 6, 1, 5 };
    std::cout << solution3.hIndex(citations) << std::endl;

    // Case 2
    citations = { 1, 3, 1 };
    std::cout << solution3.hIndex(citations) << std::endl;
}
