#pragma once

/*  First problem is to assemble all the possible paths.  We can then discount paths that travel through offline nodes (can
*   probably actually eliminate them as we are assembling the possible paths library).  Then iterate over the remaining paths
*   to remove the ones with too great a cost (again, can probably eliminate these as we assemble the possible paths library).
*   This leaves us with just the valid paths, so get each's minimum edge cost (can probably track that as we assemble the
*   library), and then get the maximum of the list of minimums.
*
*   This exceeds the time limit, so I'll need something more efficient, but I'll leave this in place for future reference.
*/

#include <algorithm>    //  for std::max, std::min
#include <cassert>      //  for assert
#include <climits>      //  for INT_MAX
#include <map>          //  for std::map
#include <stack>        //  for std::stack
#include <utility>      //  for std::pair
#include <vector>       //  for std::vector

using namespace std;

namespace Solution1
{
    class Solution {
    public:
        struct PathTraversal
        {
            int nodeID;
            long long costToGetHere;
            int minimumEdgeCostSoFar;

            PathTraversal(int nodeID, long long cost, int minEdge) : nodeID(nodeID), costToGetHere(cost), minimumEdgeCostSoFar(minEdge) {}
        };

        struct Node
        {
        public:
            map<int, int> connections;
        };

        int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
            // Build a map of the nodes and their connections
            map<int, Node> nodes;
            for (auto edge : edges)
            {
                if (!nodes.contains(edge[0]))
                {
                    nodes.insert({ edge[0], Node()});
                }

                assert(!nodes[edge[0]].connections.contains(edge[1]));
                nodes[edge[0]].connections.insert({ {edge[1], edge[2]} });
            }

            const size_t N = online.size();

            // Traverse the tree, building the list of valid paths.
            stack<PathTraversal> path;
            path.push({ 0, 0, INT_MAX });

            int maxEdge = -1;
            while (!path.empty())
            {
                PathTraversal curState = path.top();
                path.pop();

                if (curState.nodeID == N - 1)
                {
                    maxEdge = max(maxEdge, curState.minimumEdgeCostSoFar);
                }

                for (auto child : nodes[curState.nodeID].connections)
                {
                    // Only push online nodes and ndoes that won't exceed our maximum cost.
                    if (online[child.first] && (curState.costToGetHere + child.second <= k))
                    {
                        path.push({ child.first, curState.costToGetHere + child.second, min(curState.minimumEdgeCostSoFar, child.second)});
                    }
                }
            }

            return maxEdge;
        }
    };
}
