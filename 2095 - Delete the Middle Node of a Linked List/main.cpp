//*********************************************************************************************************************
// You are given the head of a linked list.  Delete the middle node, and return the head of the modified linked list.
// The middle node of a linked list of size "n" is the ⌊n/2⌋th node from the start using 0-based indexing, where ⌊x⌋
// denotes the largest integer less than or equal to x.  For n = 1, 2, 3, 4, and 5, the middle nodes are 0, 1, 1, 2,
// and 2, respectively.
//
// Example 1:
//
//                  *
//  (1)->(3)->(4)->(7)->(1)->(2)->(6)
//   0    1    2    3    4    5    6
//
// Input: head = [1, 3, 4, 7, 1, 2, 6]
// Output: [1, 3, 4, 1, 2, 6]
// Explanation:
//     The above figure represents the given linked list.The indices of the nodes are written below.
//     Since n = 7, node 3 with value 7 is the middle node, which is marked with a star.
//     We return the new list after removing this node.
//
// Example 2:
//
//             *
//  (1)->(2)->(3)->(4)
//   0    1    2    3
//
// Input: head = [1, 2, 3, 4]
// Output: [1, 2, 4]
// Explanation:
//     The above figure represents the given linked list.
//     For n = 4, node 2 with value 3 is the middle node, which is marked with a star.
//
// Example 3:
//
//        *
//  (2)->(1)
//   0    1
//
// Input: head = [2, 1]
// Output: [2]
// Explanation:
//     The above figure represents the given linked list.
//     For n = 2, node 1 with value 1 is the middle node, which is marked with a star.
//     Node 0 with value 2 is the only node remaining after removing node 1.
//
// Constraints:
//
// The number of nodes in the list is in the range[1, 10^5].
// 1 <= Node.val <= 10^5

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

#include <iostream>
#include <vector>

#include "Solution1.h"

void createList(const std::vector<int>& values, ListNode** head)
{
    ListNode* next{ nullptr };
    for (auto iter = values.rbegin(); iter != values.rend(); ++iter)
    {
        *head = new ListNode(*iter, next);
        next = *head;
    }
}

void destroyList(ListNode* head)
{
    ListNode* next{ nullptr };
    while (head != nullptr)
    {
        next = head->next;
        delete head;
        head = next;
    }
}

int main()
{
    std::vector<int> input;
    std::vector<int> output;
    ListNode* head{ nullptr };
    ListNode* cur{ nullptr };

    // Create an instance of the solution so we can call the member function
    Solution1::Solution solution;

    // Case 1
    input = { 1, 3, 4, 7, 1, 2, 6 };
    output = {1, 3, 4, 1, 2, 6 };
    createList(input, &head);
    solution.deleteMiddle(head);
    std::cout << "[ ";
    cur = head;
    while (cur != nullptr)
    {
        std::cout << cur->val;
        if (cur->next != nullptr)
        {
            std::cout << ", ";
        }
        cur = cur->next;
    }
    std::cout << " ]" << std::endl;
    destroyList(head);

    // Case 2
    input = { 1, 2, 3, 4 };
    output = { 1, 2, 4 };;
    createList(input, &head);
    solution.deleteMiddle(head);
    std::cout << "[ ";
    cur = head;
    while (cur != nullptr)
    {
        std::cout << cur->val;
        if (cur->next != nullptr)
        {
            std::cout << ", ";
        }
        cur = cur->next;
    }
    std::cout << " ]" << std::endl;
    destroyList(head);

    // Case 3
    input = { 2, 1 };
    output = { 2 };
    createList(input, &head);
    solution.deleteMiddle(head);
    std::cout << "[ ";
    cur = head;
    while (cur != nullptr)
    {
        std::cout << cur->val;
        if (cur->next != nullptr)
        {
            std::cout << ", ";
        }
        cur = cur->next;
    }
    std::cout << " ]" << std::endl;
    destroyList(head);
}
