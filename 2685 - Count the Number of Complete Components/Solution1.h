#pragma once

/*  Say a component has m nodes; for it to be complete, each of those nodes will need m-1 connections.  An edge indicates those
*   two elements are in a component.  So, iterate through the edges, building a map of nodes and their connections.  Then, if we
*   iterate over our nodes, check that the number of connections of a node is equivalent to that of each node it connects to.
*   Need to avoid duplicated counting, though; if Node 0 and Node 1 are in a component, checking Node 0 means we don't need to
*   check Node 1.  Constraints aren't huge, so maybe we can just, as we're iterating through the edges, build a list of
*   components; if neither side of an edge is already part of a component, it becomes a new component.  If one of them belongs
*   to an existing component, they both get added.  Then we just iterate through the components, and check that each node's
*   connections equal m-1.  That will work, though it may not be the most efficient way.
*   Maybe I was on the right track before; when I check a node's connections have the same number of connections as it, I can
*   build a list of nodes that I'm checking, and then just not check those again.
*
*   Issue with that; a node can have the right number of connections, but to the wrong nodes.
*/

#include <set>          //  for std::set
#include <vector>       //  for std::vector

using namespace std;

namespace Solution1
{
    class Solution {
    public:
        int countCompleteComponents(int n, vector<vector<int>>& edges) {
            //  Build the list of connections of each node
            vector<set<int>> nodeConnections(n);
            for (auto edge : edges)
            {
                int a = edge[0];
                int b = edge[1];
                nodeConnections[a].insert(b);
                nodeConnections[b].insert(a);
            }

            //  Check that a node's connections have as many connections as it does.
            int numCompleteComponents{ 0 };
            set<int> checkedNode;
            for (int i = 0; i < n; ++i)
            {
                if (checkedNode.contains(i)) { continue; }
                checkedNode.insert(i);
                int numConnections = nodeConnections[i].size();
                bool isComplete{ true };
                for (auto connection : nodeConnections[i])
                {
                    if (checkedNode.contains(connection) ||
                        numConnections != nodeConnections[connection].size())
                    {
                        isComplete = false;
                        break;
                    }
                    checkedNode.insert(connection);
                }

                if (isComplete) { ++numCompleteComponents; }
            }

            return numCompleteComponents;
        }
    };
}