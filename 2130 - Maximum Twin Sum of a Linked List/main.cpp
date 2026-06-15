//*********************************************************************************************************************
// In a linked list of size "n", where n is even, the ith node (0-indexed) of the linked list is known as the twin of
// the (n-1-i)th node, if 0 <= i <= (n/2)-1.  For example, if n = 4, then node 0 is the twin of node 3, and node 1 is
// the twin of node 2.  These are the only nodes with twins for n = 4.  The twin sum is defined as the sum of a node
// and its twin.  Given the head of a linked list with even length, return the maximum twin sum of the linked list.
//
// Example 1:
//
// Input: head = [5, 4, 2, 1]
// Output: 6
// Explanation:
//     Nodes 0 and 1 are the twins of nodes 3 and 2, respectively.  All have twin sum = 6.
//     There are no other nodes with twins in the linked list.
//     Thus, the maximum twin sum of the linked list is 6.
//
// Example 2:
//
// Input: head = [4, 2, 2, 3]
// Output: 7
// Explanation:
//     The nodes with twins present in this linked list are :
//          -Node 0 is the twin of node 3 having a twin sum of 4 + 3 = 7.
//          -Node 1 is the twin of node 2 having a twin sum of 2 + 2 = 4.
//     Thus, the maximum twin sum of the linked list is max(7, 4) = 7.
//
// Example 3:
//
// Input: head = [1, 100000]
// Output: 100001
// Explanation:
//     There is only one node with a twin in the linked list having twin sum of 1 + 100000 = 100001.
//
// Constraints:
//
//     The number of nodes in the list is an even integer in the range[2, 105].
//     1 <= Node.val <= 105

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

#include "Helpers.h"

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
    int output;
    ListNode* head{ nullptr };

    // Create an instance of the solution so we can call the member function
    Solution1::Solution solution;
    // Small wrapper that forwards the ListNode* to the instance method
    auto pairSumCallable = [&solution](ListNode* h) { return solution.pairSum(h); };

    // Case 1
    input = { 5, 4, 2, 1 };
    output = 6;
    createList(input, &head);
    std::cout << "Case 1: " << (Helpers::RunTestCase(pairSumCallable, head, output) ? "PASS" : "FAIL") << "\n";
    destroyList(head);

    // Case 2
    input = { 4, 2, 2, 3 };
    output = 7;
    createList(input, &head);
    std::cout << "Case 2: " << (Helpers::RunTestCase(pairSumCallable, head, output) ? "PASS" : "FAIL") << "\n";
    destroyList(head);

    // Case 3
    input = { 1, 100000 };
    output = 100001;
    createList(input, &head);
    std::cout << "Case 3: " << (Helpers::RunTestCase(pairSumCallable, head, output) ? "PASS" : "FAIL") << "\n";
    destroyList(head);
}
