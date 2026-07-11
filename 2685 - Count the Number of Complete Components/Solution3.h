#pragma once

/*  impoldev's (YouTube) solution is basically the same, but a little more readable.
*/

#include <set>          //  for std::set
#include <stack>        //  for std::stack
#include <vector>       //  for std::vector

using namespace std;

namespace Solution2
{
    class Solution {
    public:
        void dfs(int nodeID, const vector<set<int>>& nodeConnections, vector<int>& component, set<int>& seen) {
            seen.insert(nodeID);
            component.push_back(nodeID);
            for (auto neighbor : nodeConnections[nodeID])
            {
                if (!seen.contains(neighbor))
                {
                    dfs(neighbor, nodeConnections, component, seen);
                }
            }
        }

        int countCompleteComponents(int n, vector<vector<int>>& edges) {
            //  Build the list of each node's connections
            vector<set<int>> nodeConnections(n);
            for (auto edge : edges)
            {
                nodeConnections[edge[0]].insert(edge[1]);
                nodeConnections[edge[1]].insert(edge[0]);
            }

            set<int> seen;
            vector<int> component;
            int numCompleteComponents{ 0 };
            for (int nodeId = 0; nodeId < n; ++nodeId)
            {
                if (!seen.contains(nodeId))
                {
                    //  Build the list of nodes in the component belonging to nodei
                    component.clear();
                    dfs(nodeId, nodeConnections, component, seen);
                    int numNodesInComponent = component.size();
                    bool isComplete{ true };
                    for (int i = 0; i < numNodesInComponent; ++i)
                    {
                        for (int j = i + 1; j < numNodesInComponent; ++j)
                        {
                            if (nodeConnections[component[j]].contains(component[i]))
                            {
                                isComplete = false;
                                break;
                            }
                        }

                        if (!isComplete) { break; }
                    }
                }

            return numCompleteComponents;
        }
    };
}
