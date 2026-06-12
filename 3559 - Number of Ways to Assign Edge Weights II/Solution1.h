#pragma once

#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <stack>

using namespace std;

// Using a depth-first search to build the tree, since we used BFS yesterday (Problem 3558)
// And going to do an iterative version, since I'm sure the problem is going to involve huge numbers of nodes.
//
// So, that being done, give a query ([1,4]), can we assume there is only one path between nodes 1 and 4?  The
// problem defines our edges as representing an undirected tree, and trees are acyclic, so yes, there is only one path.
//
// So then we need the distance between nodes 1 and 4..  It's just a complexity on yesterday's problem, where we were
// just solving a single query, 0 to the deepest node.  So, one solution would be to do DFS from the start node to the
// target node to get us our distance, and then we use the same math as yesterday to return the answer for that query.
// Then repeat that for each query.
//
// That seems to be inefficient (covering the same areas over and over again), so how can we solve this in parts and
// reuse those solutions to solve bigger queries?
//
// Running out of time, so using impoldev's (YouTube) solution
// Oh no!  It fails on time complexity.  Pivoted to codestroywithMIK's (YouTube) solution.

static const long MODULUS = pow(10, 9) + 7;

// tree's elements are [nodeID, level, parentID, adjacency list]
struct Node
{
    int distanceFromRoot;
    int parentID;
    vector<int> neighbors;
};

void dfsIterative(unordered_map<int, Node>& tree, int startNodeID)
{
    if (tree.find(startNodeID) == tree.cend())
    {
        // start node not in the tree
        return;
    }

    unordered_set<int> visited;
    stack<int> s;
    tree[startNodeID].distanceFromRoot = 0;
    tree[startNodeID].parentID = -1;
    s.push(startNodeID);

    while (!s.empty())
    {
        int curNodeID = s.top();
        s.pop();

        if (!visited.count(curNodeID))
        {
            visited.insert(curNodeID);
            for (int neighborID : tree.at(curNodeID).neighbors)
            {
                if (!visited.count(neighborID))
                {
                    tree[neighborID].distanceFromRoot = tree[curNodeID].distanceFromRoot + 1;
                    tree[neighborID].parentID = curNodeID;
                    s.push(neighborID);
                }
            }
        }
    }

    // This doesn't account for any disconnected nodes, but I don't think that's an issue with this problem.  If we
    // wanted to consider that case, we could loop through the adjacencies, checking for any unvisited nodes and
    // adding processing them.
}

//int lowestCommonAncestor(const unordered_map<int, Node>& tree, int nodeA_ID, int nodeB_ID)
//{
//    // Move A closer to the root, until it is the same distance from the root as B
//    while (tree.at(nodeA_ID).distanceFromRoot > tree.at(nodeB_ID).distanceFromRoot)
//    {
//        nodeA_ID = tree.at(nodeA_ID).parentID;
//    }
//
//    // Move B closer to the root, until it is the same distance from the root as A
//    while (tree.at(nodeA_ID).distanceFromRoot < tree.at(nodeB_ID).distanceFromRoot)
//    {
//        nodeB_ID = tree.at(nodeB_ID).parentID;
//    }
//
//    while (nodeA_ID != nodeB_ID)
//    {
//        nodeA_ID = tree.at(nodeA_ID).parentID;
//        nodeB_ID = tree.at(nodeB_ID).parentID;
//    }
//
//    return nodeA_ID;
//}

int lowestCommonAncestor(const unordered_map<int, Node>& tree, const vector<vector<int>>& ancestorTable, int u, int v)
{
    if (tree.at(u).distanceFromRoot < tree.at(v).distanceFromRoot)
    {
        swap(u, v);
    }

    int k = tree.at(u).distanceFromRoot - tree.at(v).distanceFromRoot;
    int columns = log2(ancestorTable.size()) + 1;

    for (int i = 0; i < columns; ++i)
    {
        if (k & (1 << i))
        {
            u = ancestorTable[u][i];
        }
    }

    if (u == v)
    {
        return u;
    }

    for (int i = columns - 1; i >= 0; --i)
    {
        if (ancestorTable[u][i] == -1)
        {
            continue;
        }

        if (ancestorTable[u][i] != ancestorTable[v][i])
        {
            u = ancestorTable[u][i];
            v = ancestorTable[v][i];
        }
    }

    return ancestorTable[u][0];
}

// Modular Exponentiation Method
long long modPow(long long base, long long exponent, long long modulus)
{
    long result = 1;  // x^0 = 1

    base %= modulus;

    while (exponent > 0)
    {
        // If exponent is odd, multiply the result by the current base and modulo it
        if (exponent & 1)
        {
            result = (result * base) % modulus;
            --exponent;
        }
        // exponent is even, sqaure the base and half the exponent
        else
        {
            base = (base * base) % modulus;
            exponent >>= 1;
        }
    }

    return result;
}

vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
    vector<int> results;

    // Build the node adjacencies from the list of edges.  Change nodes to be 0-based index instead of 1-based index
    //  Edge is in the form of [u, v]
    unordered_map<int, Node> tree;
    for (auto edge : edges)
    {
        tree[edge[0]-1].neighbors.push_back(edge[1]-1);
        tree[edge[1]-1].neighbors.push_back(edge[0]-1);    // tree is specified as undirected
    }

    dfsIterative(tree, 0);

    int n = edges.size() + 1;
    int columns = log2(n) + 1;
    vector<vector<int>> ancestorTable(n, vector<int>(columns, -1));
    for (auto [key, node] : tree)
    {
        ancestorTable[key][0] = node.parentID;
    }
    
    for (int i = 1; i < columns; ++i)
    {
        for (int node = 0; node < n; ++node)
        {
            if (ancestorTable[node][i - 1] != -1)
            {
                ancestorTable[node][i] = ancestorTable[ancestorTable[node][i - 1]][i - 1];
            }
        }
    }

    for (auto query : queries)
    {
        int nodeA_ID = query.at(0)-1;
        int nodeB_ID = query.at(1)-1;
        int lcaID = lowestCommonAncestor(tree, ancestorTable, nodeA_ID, nodeB_ID);
        int nodeADistanceFromLCA = tree.at(nodeA_ID).distanceFromRoot - tree.at(lcaID).distanceFromRoot;
        int nodeBDistanceFromLCA = tree.at(nodeB_ID).distanceFromRoot - tree.at(lcaID).distanceFromRoot;
        int distance = nodeADistanceFromLCA + nodeBDistanceFromLCA;

        if (distance == 0)
        {
            results.push_back(0);
        }
        else
        {
            results.push_back(static_cast<int>(modPow(2, distance - 1, MODULUS)));
        }
    }

    return results;
}
