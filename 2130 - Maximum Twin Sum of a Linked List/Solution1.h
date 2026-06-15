#pragma once

/** * Definition for singly-linked list. * **/
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// If we knew the length of the list, and we could acess each element, then we could calculate the sum at each i
//  iSum = list[i] + list[listSize - i]
// Running halfway through the list will give us all the sums, we just keep track of the highest as we go.
//
// Since we don't have random access into the list, we could build a data structure, storing values of the list in it,
// and then going back to add them together.  Would require a data structure of size n.
//
// What about modifying the List nodes to suit our needs?
// Run through the list once to get its size, n.
// Then, run through the list once, up to n/2.  Now, as we continue running to the end, change the list node to point
// at the previous node instead of the next node.
// So the list would now be (->), (->), (<-), (<-)
// Now we run through the list a third time, but with iterators at each end (so pointing at each other's twin).  Add
// their sum, compare to the highest so far.  When we reach the middle, stop iterating, return our solution.
//
// Since n can be very large (10^5), it seems like it'd be worth saving all that space in memory, especially if all it
// costs is another run throught the list.

#include <algorithm>        // for max

using namespace std;

namespace Solution1
{
    class Solution {
    public:
        int pairSum(ListNode* head) {

            // Get the size of the list
            int listSize = 0;
            ListNode* cur = head;
            while (cur != nullptr)
            {
                ++listSize;
                cur = cur->next;
            }

            // Get to just before the midpoint of the list
            cur = head;
            for (int i = 0; i < (listSize / 2) - 1; ++i)
            {
                cur = cur->next;
            }

            // From here on out, change the node to point at the previous node, instead of the next node.
            ListNode* prev = cur;           // i-1
            cur = cur->next;                // i
            ListNode* next = cur->next;     // i+1

            while (cur != nullptr)
            {
                // Overwrite the node's next pointer to point at the previous (reverse) node, the work we actually want to do
                cur->next = prev;

                // In prepartion for the next loop, set the previous pointer to point at the current node
                prev = cur;

                // Move our current node to the next (forward) node
                cur = next;

                // Save the pointer to the next (forward) node in a temp, so we know how to continue forward traversal
                if (cur != nullptr)
                {
                    next = cur->next;
                }
            }

            // Now we can iterate through the list a final time, with the two iterators approaching each other, comparing the
            // sum of the value to the maximum we've found so far.  As we go, get the nodes pointing back the way they should.
            int maxSum{ 0 };
            int curSum{ 0 };
            cur = prev;                 // i
            prev = prev->next;          // i-1
            next = nullptr;             // i+1

            for (int i = 0; i < listSize / 2; ++i)
            {
                curSum = head->val + cur->val;
                maxSum = max(curSum, maxSum);
                head = head->next;

                cur->next = next;
                next = cur;
                cur = prev;
                prev = cur->next;
            }

            return maxSum;
        }
    };
}
