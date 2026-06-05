// 0003 - Longest Substring Without Repeating Characters.cpp : This file contains the 'main' function. Program execution begins and ends there.
//  Given a string s, find the length of the longest substring without duplicate characters.
//
//  Example 1:
//  
//  Input: s = "abcabcbb"
//  Output: 3
//  Explanation: The answer is "abc", with the length of 3. Note that "bca" and "cab" are also correct answers.
//
//  Example 2:
//
//  Input: s = "bbbbb"
//  Output: 1
//  Explanation: The answer is "b", with the length of 1.
//
//  Example 3:
//
//  Input: s = "pwwkew"
//  Output: 3
//  Explanation: The answer is "wke", with the length of 3.
//  Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
//
//  Constraints:
//
//  0 <= s.length <= 5 * 10^4
//  s consists of English letters, digits, symbols and spaces.

#include <iostream>
#include <string>

#include "Solution1.h"

int main()
{
    std::string s;

    // Case 1
    s = "abcabcbb";
    std::cout << lengthOfLongestSubstring(s) << std::endl;

    // Case 2
    s = "bbbbb";
    std::cout << lengthOfLongestSubstring(s) << std::endl;

    // Case 3
    s = "pwwkew";
    std::cout << lengthOfLongestSubstring(s) << std::endl;

    // Case 4
    s = "au";
    std::cout << lengthOfLongestSubstring(s) << std::endl;
}
