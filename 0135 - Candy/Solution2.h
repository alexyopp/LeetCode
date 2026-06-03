#pragma once

#include <vector>
#include <numeric>

using namespace std;

// Two passes, one making sure a higher rating has more than its left neighbor and one making sure a higher rating has moer than its right neighbor

int candy(vector<int>& ratings) {
    // Children receive a minimum of 1 candies.
    vector<int> assigned(ratings.size(), 1);

    for (int i = 1; i < ratings.size(); ++i)
    {
        if (ratings[i] > ratings[i - 1])
        {
            assigned[i] = assigned[i-1] + 1;
        }
    }

    for (int i = ratings.size() - 2; i >= 0; --i)
    {
        if (ratings[i] > ratings[i + 1])
        {
            assigned[i] = max(assigned[i], assigned[i+1]+1);
        }
    }

    int assignedCount = accumulate(cbegin(assigned), cend(assigned), 0);

    return assignedCount;
}
