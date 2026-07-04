#pragma once

/*  Since we can go back over the same road, any road that's on the graph can be in the path, so whatever the smallest one is is
*   our answer.  My first thought was then to just iterate over the roads looking for the smallest, but since not all of the
*   cities necessarily connect, we have to limit ourselves to the roads that connect to city 1.  So, really what needs doing is
*   a tree traversal, starting at 1, finding the shortest distance road.  A depth-first traversal seems simplest; visit all of
*   a node's first children, then its second, mark a node as visited so we don't keep re-adding it to our list of nodes to
*   traverse.
*
*   It's heavy and slow, so worth looking at a more refined solution in the future.
*/

#include <algorithm>    //  for std::min
#include <climits>      //  for INT_MAX
#include <map>          //  for std::map
#include <set>          //  for std::set
#include <stack>        //  for std::stack
#include <vector>       //  for std::vector

using namespace std;

namespace Solution1
{
    class Solution {
    public:
        int minScore(int n, vector<vector<int>>& roads) {
            // Build the tree
            map<int, map<int,int>> tree;
            for (auto road : roads)
            {
                int cityA = road[0];
                int cityB = road[1];
                int distance = road[2];

                tree[cityA][cityB] = distance;
                tree[cityB][cityA] = distance;
            }

            // Traverse the tree, looking for the shortest distance
            set<int> visited;
            stack<int> treeTraversal;
            treeTraversal.push(1);
            visited.insert(1);
            int minDistance = INT_MAX;
            while (!treeTraversal.empty())
            {
                int curCity = treeTraversal.top();
                treeTraversal.pop();

                for (auto connectedCity : tree[curCity])
                {
                    minDistance = min(minDistance, connectedCity.second);
                    if (!visited.contains(connectedCity.first))
                    {
                        visited.insert(connectedCity.first);
                        treeTraversal.push(connectedCity.first);
                    }
                }
            }

            return minDistance;
        }
    };
}
