#pragma once

/*  Utilizing impoldev's (YouTube) solution.  For finding a minimum path, we can leverage Dijkstra's algorithm, and the maximum
*   minimum is a clue to use binary search.  First, build an adjacency list, where a node's connections are stored in pairs with
*   the cost first and the destination second.  If a node is offline, we can skip adding it to the adjacency list.  Then, build
*   a node distances list, where the first element is 0 (distance to node 0 is 0) and the distances for every other node is k+1.
*       distances = [0, 11, 11, 11]
*   Now, imagine the edge costs are mapped onto a number line, with the the minimum and maximum costs being our bounds.  For
*   Example 1:
*
*           L        M           R
*           |--|--|--|--|--|--|--|
*           3  4  5  6  7  8  9  10
*
*   Get the midpoint (rounded down).  Run Dijsktra's to check if this is a valid minimum weight in the shortest path from the
*   source to the destination.  Dijkstra's uses a heap, so push the first node (0 weight, 0 id).  Enter the loop and look at
*   node 0's connections.  Both of the connection weights are less than our guessed minimum weight (3, 5 < 6), so neither is
*   valid; the algorithm returns false.  So now we need to update our midpoint.  R = M-1 and M gets chosen between L and R.
*
*           L  M  R
*           |--|--|--|--|--|--|--|
*           3  4  5  6  7  8  9  10
*
*   Check the connections again.  The connection to node 1 is 5, so our choice of 4 as a minimum weight is still valid.  Check
*   that the accumulated distance to node 1 is less than the determined node distance (distances[1]).  5 is less than 11, so we
*   update the distances list with this new data (distances = [0, 5, 11, 11]).  This connection gets added to our heap.  The
*   other connection (to node 2) has a minimum weight of 3, which is less than our choice of minimum weight (4), so we don't do
*   anything more.  Continuing to iterate, the only item left in our heap is the connection between node 1 and node 3.  It's
*   weight is 10, so it is larger than our minimum weight choice, but the accumulated weight is greater than the value in
*   distances, distances isn't updated.  Our algorithm again returns false.
*
*   Reduce minimum weight choice again.
*
*           R
*           M
*           L
*           |--|--|--|--|--|--|--|
*           3  4  5  6  7  8  9  10
*
*   The previous iteration occurs again, but this time we can add the connection between node 0 and 2.  This gets us to the
*   point where we end up with the final node in the heap, so when we pop it, we can return true (valid path found) and we know
*   that M is the minimum edge cost of all the paths.  And since we want to find the largest minimum, we increment our L.  Since
*   now R < L, our search is complete, and we can return M.
*/

#include <algorithm>    //  for std::max, std::min
#include <climits>      //  for INT_MAX
#include <map>          //  for std::map
#include <queue>        //  for std::priority_queue
#include <utility>      //  for std::pair
#include <vector>       //  for std::vector

using namespace std;

namespace Solution2
{
    class Solution {
    public:
        bool isPathValid(const int limit, const map<int, vector<pair<int, int>>>& adjacencies, const int N, const long long k)
        {
            priority_queue<pair<int, int>> pq;
            pq.push({ 0, 0 });

            vector<long long> distances(N, k + 1);
            distances[0] = 0;

            while (!pq.empty())
            {
                long long weight = pq.top().first;
                int nodeID = pq.top().second;
                pq.pop();

                if (nodeID == N - 1) { return true; }
                if (weight > distances[nodeID]) { continue; }

                if (adjacencies.contains(nodeID))
                {
                    for (auto [neighborWeight, neighborID] : adjacencies.at(nodeID))
                    {
                        if (neighborWeight < limit) { continue; }
                        long long accumulatedWeight = weight + neighborWeight;
                        if (accumulatedWeight < distances[neighborID])
                        {
                            distances[neighborID] = accumulatedWeight;
                            pq.push({ accumulatedWeight, neighborID });
                        }
                    }
                }
            }

            return false;
        }

        int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
            const int N = online.size();
            int leftBound = INT_MAX;
            int rightBound = 0;

            map<int, vector<pair<int, int>>> adjacencies;
            for (auto edge : edges)
            {
                int sourceNodeID = edge[0];
                int destNodeID = edge[1];
                int weight = edge[2];

                if (!online[sourceNodeID] || !online[destNodeID]) { continue; }

                adjacencies[sourceNodeID].push_back({ weight, destNodeID });
                leftBound = min(leftBound, weight);
                rightBound = max(rightBound, weight);
            }

            int largestMinimumEdgeWeight = -1;
            while (leftBound <= rightBound)
            {
                int midpoint = leftBound + ((rightBound - leftBound) / 2);
                if (isPathValid(midpoint, adjacencies, N, k))
                {
                    largestMinimumEdgeWeight = midpoint;
                    leftBound = midpoint + 1;
                }
                else
                {
                    rightBound = midpoint - 1;
                }
            }

            return largestMinimumEdgeWeight;
        }
    };
}
