#pragma once

// First need to find the maximum depth
// If depth is 1
//      Edge 1 Weight = 1
//      Num solutions = 1
// If depth is 2
//      Edge 1 Weight = 1, Edge 2 Weight = 2    // Move one 2 around
//      Edge 1 Weight = 2, Edge 1 Weight = 1
//      Num solutions = 2
// If depth is 3
//      Edge 1 Weight = 1, Edge 2 Weight = 1, Edge 3 Weight = 1     // # of edges
// 
//      Edge 1 Weight = 1, Edge 2 Weight = 2, Edge 3 Weight = 2     // Move two 2's around
//      Edge 1 Weight = 2, Edge 2 Weight = 1, Edge 3 Weight = 2
//      Edge 1 Weight = 2, Edge 2 Weight = 2, Edge 3 Weight = 1
//      Num Solutions = 4
// If depth is 4
//      Edge 1 Weight = 1, Edge 2 Weight = 1, Edge 3 Weight = 1, Edge 4 Weight = 2  // Move one 2 around
//      Edge 1 Weight = 1, Edge 2 Weight = 1, Edge 3 Weight = 2, Edge 4 Weight = 1
//      Edge 1 Weight = 1, Edge 2 Weight = 2, Edge 3 Weight = 1, Edge 4 Weight = 1
//      Edge 1 Weight = 2, Edge 2 Weight = 1, Edge 3 Weight = 1, Edge 4 Weight = 1
// 
//      Edge 1 Weight = 1, Edge 2 Weight = 2, Edge 3 Weight = 2, Edge 4 Weight = 2  // Move three 2's around
//      Edge 1 Weight = 2, Edge 2 Weight = 1, Edge 3 Weight = 2, Edge 4 Weight = 2
//      Edge 1 Weight = 2, Edge 2 Weight = 2, Edge 3 Weight = 1, Edge 4 Weight = 2
//      Edge 1 Weight = 2, Edge 2 Weight = 2, Edge 3 Weight = 2, Edge 4 Weight = 1
//      Num solutions = 8
// If depth is 5
//      Edge 1 Weight = 1, Edge 2 Weight = 1, Edge 3 Weight = 1, Edge 4 Weight = 1, Edge 5 Weight = 1   // # of edges
// 
//      Edge 1 Weight = 1, Edge 2 Weight = 1, Edge 3 Weight = 1, Edge 4 Weight = 2, Edge 5 Weight = 2   // Move two 2's around
//      Edge 1 Weight = 1, Edge 2 Weight = 1, Edge 3 Weight = 2, Edge 4 Weight = 1, Edge 5 Weight = 2
//      Edge 1 Weight = 1, Edge 2 Weight = 2, Edge 3 Weight = 1, Edge 4 Weight = 1, Edge 5 Weight = 2
//      Edge 1 Weight = 2, Edge 2 Weight = 1, Edge 3 Weight = 1, Edge 4 Weight = 1, Edge 5 Weight = 2
// 
//      Edge 1 Weight = 1, Edge 2 Weight = 1, Edge 3 Weight = 2, Edge 4 Weight = 2, Edge 5 Weight = 1
//      Edge 1 Weight = 1, Edge 2 Weight = 2, Edge 3 Weight = 1, Edge 4 Weight = 2, Edge 5 Weight = 1
//      Edge 1 Weight = 2, Edge 2 Weight = 1, Edge 3 Weight = 1, Edge 4 Weight = 2, Edge 5 Weight = 1
// 
//      Edge 1 Weight = 1, Edge 2 Weight = 2, Edge 3 Weight = 2, Edge 4 Weight = 1, Edge 5 Weight = 1
//      Edge 1 Weight = 2, Edge 2 Weight = 1, Edge 3 Weight = 2, Edge 4 Weight = 1, Edge 5 Weight = 1
// 
//      Edge 1 Weight = 2, Edge 2 Weight = 2, Edge 3 Weight = 1, Edge 4 Weight = 1, Edge 5 Weight = 1
// 
//      Edge 1 Weight = 1, Edge 2 Weight = 2, Edge 3 Weight = 2, Edge 4 Weight = 2, Edge 5 Weight = 2   // Move four 2's around
//      Edge 1 Weight = 2, Edge 2 Weight = 1, Edge 3 Weight = 2, Edge 4 Weight = 2, Edge 5 Weight = 2
//      Edge 1 Weight = 2, Edge 2 Weight = 2, Edge 3 Weight = 1, Edge 4 Weight = 2, Edge 5 Weight = 2
//      Edge 1 Weight = 2, Edge 2 Weight = 2, Edge 3 Weight = 2, Edge 4 Weight = 1, Edge 5 Weight = 2
//      Edge 1 Weight = 2, Edge 2 Weight = 2, Edge 3 Weight = 2, Edge 4 Weight = 2, Edge 5 Weight = 1
//      Num solutions = 16
//
//// A pattern is definitely presenting itself.
// I'm realizing I'm trying to solve this mathematicaly, rather than programmatically, but the math solution would
// obviously be faster, assuming it actually pans out.
// 
// Looking at Depth=5, we have 1 solution for the number of edges, 5 solutions for all evens but one, and then
// (1+2+3+4) solutions for the rest.  Depth=3, we have 1 solutions for the number of edges, 3 solutions for all evens
// but one, and then 0 other solutions.  What if we think of 5 in terms of subsets of 3?  So, ignoring edges 1 and 2,
// we treat edges 3, 4, 5 as itself; that would give us four solutions.  If we ignore the one solution for the number
// of edges (so we count 3 solutions then), does that gives us the right answer?
// Expanding that out:
//  (12)(345) = 3
//  (13)(245) = 3
//  (14)(235) = 3
//  (15)(234) = 3
//  (23)(145) = 3
//  (24)(135) = 3
//  (25)(134) = 3
//  (34)(125) = 3
//  (35)(124) = 3
//  (45)(123) = 3
//
//  Did I miss some?  Let me try counting 5 this way:
//      Edge 1 Weight = 1, Edge 2 Weight = 1, Edge 3 Weight = 1, Edge 4 Weight = 2, Edge 5 Weight = 2   // Keep 12 as 1, move two 2s around 345
//      Edge 1 Weight = 1, Edge 2 Weight = 1, Edge 3 Weight = 2, Edge 4 Weight = 1, Edge 5 Weight = 2
//      Edge 1 Weight = 1, Edge 2 Weight = 1, Edge 3 Weight = 2, Edge 4 Weight = 2, Edge 5 Weight = 1
// 
//      Edge 1 Weight = 1, Edge 2 Weight = 1, Edge 3 Weight = 1, Edge 4 Weight = 2, Edge 5 Weight = 2   // Keep 13 as 1, move two 2s around 245
//      Edge 1 Weight = 1, Edge 2 Weight = 2, Edge 3 Weight = 1, Edge 4 Weight = 1, Edge 5 Weight = 2
//      Edge 1 Weight = 1, Edge 2 Weight = 2, Edge 3 Weight = 1, Edge 4 Weight = 2, Edge 5 Weight = 1
//
//      Yes, there, we already have a duplicate; 11122 and 11122
//
// So back to the first idea:
// Depth=3 solutions can be expressed as 1 + d, Depth=5, as 1 + d + (d-1 + d-2 + ... d-d), does Depth=7 feel like
// 1 + 7 + (6+5+4+3+2+1)?  That feels small.
// Depth=2 solutions can be expresed as n, Depth=4, as 2d, or maybe 2^(d-1)?  The second one seems more likely.  I'm
// not excited at the idea of running through Depth=6 just to test that out.  Maybe we can think it out quickly;
// I want to move a single 2 around, 6 edges, so that gives me 6 solutions.  moving five 2's around 6 edges gives 6
// solutions, so that's already 2*d and we definitely have more.  Would moving three 2's around 6 edges give twenty
// solutions, making 2^(d-1) pan out?  Feels maybe high?
//
// Well, enough of that, I guess.
//
// I was on the right track!  Look at the pattern of # of solutions!  1, 2, 4, 8, 16, 32...!  so, 2^(d-1)  works for
// even and odd depths!  2^(1-1) = 1, 2^(2-1) = 2, 2^(3-1) = 4, 2^(4-1) = 8, ...
//
// Okay, so then how do we find the depth?
//  Breadth-first search, or Depth first search

#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

static const long MODULUS = pow(10, 9) + 7;

int bfs(const unordered_map<int, std::vector<int>>& adjacencies, int startNodeID)
{
    if (adjacencies.find(startNodeID) == adjacencies.cend())
    {
        // start node not in the graph
        return 0;
    }

    unordered_set<int> visited;
    queue<pair<int, int>> q;        // nodeId, depth
    int maxDepth{ 0 };

    visited.insert(startNodeID);
    q.push({ startNodeID, 0 });

    while (!q.empty())
    {
        pair<int, int> node = q.front();
        q.pop();

        for (int neighbor : adjacencies.at(node.first))
        {
            if (!visited.count(neighbor))
            {
                visited.insert(neighbor);
                q.push({ neighbor, node.second + 1 });
                maxDepth = max(node.second + 1, maxDepth);
            }
        }
    }

    return maxDepth;
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

int assignEdgeWeights(vector<vector<int>>& edges) {

    // Build the list of adjacencies from the list of edges
    unordered_map<int, std::vector<int>> adjacencies;
    for (auto edge : edges)
    {
        adjacencies[edge[0]].push_back(edge[1]);
        adjacencies[edge[1]].push_back(edge[0]);
    }

    int depth = bfs(adjacencies, 1);

    return static_cast<int>(modPow(2, depth-1, MODULUS));
}
