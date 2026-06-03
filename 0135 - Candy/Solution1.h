#pragma once

#include <vector>

using namespace std;

// find local minimum
//  three iterators (left, center, right)
//  increment each's candy as appropriate

//  [1, 0, 2]
//      i = 0, left = ?, center = ?, right = ratings[0] = 1, assign 1 candy (each child must have at least one)
//      i = 1, left = ? center = ratings[0], right = ratings[1], assign 2 candies (1 to right, since each child must have at least one, 1 to center, since it has a higher rating than right)
//      i = 2, left = ratings[0], center = ratings[1], right = ratings[2], assign 2 candies (2 to right, since it has a higher rating than center, which currently has 1)
//
//      What if left is increased?  then we have to go back to check that doesn't affect any of its previous neighbors

//  [1, 2, 2]
//      i = 0, asign 1 to [0]
//      i = 1, assign 2 to [1]
//      i = 2, assign 1 to [2]

//  [4, 3, 2, 1]
//      i = 0, assign 1 to [0]
//      i = 1, assign 1 to [0], 1 to [1]
//      i = 2, assign 1 to [0], 1 to [1], 1 to [2]
//      i = 3, assign 1 to [0], 1 to [1], 1 to [2], 1 to [3]

//  for each i
//      if ratings[i] > ratings[i-1]
//          assigned[i] = assigned[i-1] + 1
//      else
//          assigned[i] = 1
//          iterate backwards, updating previous values
//          cur = i
//          back = i-1
//          while back >=0
//              if ratings[cur] < ratings[back]
//                  assigned[back] = assigned[cur] + 1
//              else // ratings[cur] >= ratings[back]
//                  done iterating backwards
//              cur = back
//              back -= 1

//  [1, 0, 2]
//      i = 0, else case, assigned[0] = 1
//      i = 1, else case, assigned[1] = 1, assigned[0] = 2
//      i = 2, if case, assigned[2] = 2

//  [1, 2, 2]
//      i = 0, else case, assigned[0] = 1
//      i = 1, if case, assigned[1] = 2
//      i = 2, else case, assigned[2] = 1

// [4, 4, 3, 3, 2, 1]
//      i = 0, else case, assigned[0] = 1
//      i = 1, else case, assigned[1] = 1, assigned[0] = 1 (no change)
//      i = 2, else case, assigned[2] = 1, assigned[1] = 2, assigned[0] = 1 (no change)
//      i = 3, else case, assigned[3] = 1, assigned[2] = 1 (no change), assigned[1] = 2 (no change), assigned[0] = 1 (no change)
//      i = 4, else case, assigned[4] = 1, assigned[3] = 2, assigned[2] = 1 (no change), assigned[1] = 2 (no change), assigned[0] = 1 (no change)
//      i = 5, else case, assigned[5] = 1, assigned[4] = 2, assigned[3] = 3, assigned[2] = 1 (no change), assigned[1] = 2 (no change), assigned[0] = 1 (no change)

int candy(vector<int>& ratings) {
    vector<int> assigned(ratings.size());

    // Initial case.
    int assignedCount = 1;
    assigned[0] = 1;

    for (int i = 1; i < ratings.size(); ++i)
    {
        if (ratings[i] > ratings[i - 1])
        {
            assignedCount += assigned[i - 1] + 1;
            assigned[i] = assigned[i - 1] + 1;
        }
        else  // ratings[i] <= ratings[i-1]
        {
            ++assignedCount;
            assigned[i] = 1;

            // Iterate backwards to update previous values
            int curPos = i;
            int prevPos = i - 1;
            while (prevPos >= 0)
            {
                if (ratings[curPos] < ratings[prevPos] &&
                    assigned[curPos] >= assigned[prevPos])
                {
                    assignedCount += assigned[curPos] + 1 - assigned[prevPos];
                    assigned[prevPos] = assigned[curPos] + 1;
                }
                else  // ratings[curPos] >= ratings[prevPos]
                {
                    break;
                }
                curPos = prevPos;
                --prevPos;
            }
        }
    }

    return assignedCount;
}
