#pragma once

/** * Definition for singly-linked list. * **/
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

using namespace std;

// Need to know the size of the list, so we run through it once
// Then need to find a specific element, so we either run through it again, or we stored pointers to the node elements
// on our first way through.  Is potentially (10^5)/2 less operations better than using (10^5) more memory?  Probably
// not.

namespace Solution1
{
    class Solution {
    public:
        ListNode* deleteMiddle(ListNode* head) {
            if (head == nullptr)
            {
                // Early out for an empty list
                return nullptr;
            }

            ListNode* cur{ head };
            int n{ 0 };

            // Count the number of nodes in the list
            while (cur != nullptr)
            {
                ++n;
                cur = cur->next;
            }

            int middleIndex = n / 2;    // Integer division intentional

            // Edge case
            if (n == 1)         // Delete the only element in the list
            {
                delete head;
                return nullptr;
            }

            // General case
            // Count up to the node just before the middle node.
            cur = head;
            for (int i = 0; i < middleIndex - 1; ++i)
            {
                cur = cur->next;
            }

            ListNode* nodeToRemove = cur->next;

            if (n > 2)
            {
                cur->next = nodeToRemove->next;
            }
            else
            {
                cur->next = nullptr;
            }

            delete nodeToRemove;

            return head;
        }
    };
}
