#pragma once

/*  Per the hints, we can use DFS to find every node in a component, and then check that each node in a component connects to
*   every other node in the component.
*
*   This works, but is slow and heavy.
*/

#include <set>          //  for std::set
#include <stack>        //  for std::stack
#include <vector>       //  for std::vector

using namespace std;

namespace Solution2
{
    class Solution {
    public:
        int countCompleteComponents(int n, vector<vector<int>>& edges) {
            //  Build the list of each node's connections
            vector<set<int>> nodeConnections(n);
            for (auto edge : edges)
            {
                nodeConnections[edge[0]].insert(edge[1]);
                nodeConnections[edge[1]].insert(edge[0]);
            }

            set<int> visited;
            vector<int> component;
            int numCompleteComponents{ 0 };
            for (int i = 0; i < n; ++i)
            {
                if (visited.contains(i)) { continue; }
                visited.insert(i);

                //  Build the list of nodes in the component belonging to nodei
                component.clear();
                stack<int> dfsStack;
                dfsStack.push(i);
                while (!dfsStack.empty())
                {
                    auto nodeId = dfsStack.top();
                    dfsStack.pop();
                    component.push_back(nodeId);
                    for (auto neighbor : nodeConnections[nodeId])
                    {
                        if (!visited.contains(neighbor))
                        {
                            dfsStack.push(neighbor);
                            visited.insert(neighbor);
                        }
                    }
                }

                //  Run through the nodes of the component, checking that there is an edge between all of them
                int j{ 0 };
                int k{ 1 };
                bool isComplete{ true };
                while (j < k && k < component.size())
                {
                    if (!nodeConnections[component[j]].contains(component[k]))
                    {
                        isComplete = false;
                        break;
                    }
                    ++k;
                    if (k == component.size())
                    {
                        ++j;
                        k = j + 1;
                    }
                }

                if (isComplete) { ++numCompleteComponents; }
            }

            return numCompleteComponents;
        }
    };
}
