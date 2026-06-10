#pragma once

//          *** My failed attempt to figure this out
// If nums was sorted, we'd pick the ends, removing possibilities as they are chosen
//                              Max - Min
//          Max2 - Min             or           Max - Min2
//  Max3 - Min  or Max2 - Min2          Max - Min3  or  Max2 - Min2
//
// So if we have a data structure that stores values and their indices, sort it by the values, we pick off the ends and
// use the indices to call back into nums.
//
// But, that doesn't work, because the positions are what we're chosing, meaning we could get several uses out of min
// and max.
// For example, in [2, 2, 2, 2, 1, 3, 4, 3, 5, 2], k = 4, we can take [0..7], [1..7], [2..7], [3..7], [4..7]
//
// The Maximum value in nums - the Minimum value in nums is optimal.  So, the next adjacent value to Min (in the
// opposite direction of Max) is obviously worse than choosing Min, so let's choose that until we hit the end of the
// array.
// So that means all of those are chosen and no longer viable.
// Does the math make sense that those will always be the best choice?  I think so; we sacrifice potential low values,
// but if we have a lower value subtracting from the highest possible value, that must be the best choice.
// Note that we can also take all the values adjacent to Max in the opposite direction of Min
// So, for the above example, these are all the choices we can make before we have to choose a new Max or Min:
// (in order of the algorithm's choosing)
//  [4..8], [3..8], [2..8], [1..8], [0..8], [4..9]
// BUT WAIT!  We can also take the combinations of adjacent indices!  So we also can take
//  [3..9], [2..9], [1..9], [0..9], ...
// So, the order the algorithm will likely work is:
// [4, 8]                           (choose our Max and Min value in the range [0...9]
// [3..8], [2..8], [1..8], [0..8]   (shift Min)
// [4..9]                           (shift Max)
// [3..9]                           (nudge Min and Max)
// [2..9], [1..9], [0..9]           (shift Min)
//                                  (shift Max - out of bounds - end the loop)
// 
// At this point, everything outside of Min and Max has been chosen, so we need to pick a new Min2 and Max2 located
// between Min and Max?
// Not so; only one would need to be inside, not both.  In terms of our algorithm, we can shift the internal choice up
// to the previous choice's index (note that we could first choose a Max and then internally a Min, so don't make
// assumptions there).  The external choice can work as before, though, as those are all new ranges
// So, continuing the above example, find the Max and Min in our new range [5...7]; Min2 = [5] = 2, Max2 = [6] = 4
// Which gives us the better sum?  Max2 - Min = 4 - 1 = 3, Max - Min2 = 5 - 3 = 2, so run with Max2 and Min
// [4..6]
// [3..6], [2..6], [1..6], [0..6]   (shift Min)
// [4..7]                           (shift Max)
//                                  (nudge Min and Max, Max goes out of bounds so end the loop)
// Choose the next option, inbetween Min and Max2; Min3 = Max3 = [5] = 3.  Max3 - prevousMin (Min) = 3 - 1 = 2, previousMax (Max2) - Min3 = 4 - 3 = 1
// [4..5]
//                                  (shift Min - goes out of bounds)
//                                  (shift Max - goues out of bounds)
//  Nope.  =(  How would I know to keep going with [5..9]?
//
// Instead of trying to be clever, what if I brute force it?  Let's go back to a smaller example, so we can make sure we get all of the combinations:
//  [0, 1, 2, 3, 4] - the values double as the indices, hopefully for clarity.
//  So the combos are:
//  [0, 1], [0, 2], [0, 3], [0, 4]
//  [1, 2], [1, 3], [1, 4]
//  [2, 3], [2, 4]
//  [3, 4]

// And their sums are:
//  1, 2, 3, 4
//  1, 2, 3
//  1, 2
//  1

// Can I just take the k best sums?  The sums would go into a data structure that I then sort by value, and take the top k values.
// It's going to be time inefficient; we're doing a bunch of additions we never need (for k = 1, that 9 additions wasted)
// It's going to be space inefficient; we're storing 9 values we won't ever need.
// But, it will solve it.

// No it won't, because remember we can get the same sum multiple times
//  [0, 2, 1, 4, 3]
//  Should give us the same sums
//  [0, 2], [0, 1], [0, 4], [0, 3]
//  [2, 1], [2, 4], [2, 3]
//  [1, 4], [1, 3]
//  [4, 3]

//  2, 1, 4, 3
//  1, 2, 1
//  3, 2
//  1

// But we can get multiple 4 results by taking the range (indices now) [2, 3], [1, 3], [0, 3], and [3, 4]

// If I go back to the index shift and nudge from above
// the problem stemmed from chooosing Min2/Max2.  All pairs < Min and > Max have been done (note that I seem to be
// assuming that Max is later than Min in the array, but that's not necessarily true). But all values > Min and < Max
// are available, and available with any value outside.  So, find Min2 and Max2 between [MinIdx, MaxIdx]
// in our example, that's Min2 = [5] = 2, Max2 = [6] = 4
// Running that down the algorithm gives us:
// [4..6]
// [3..6], [2..6], [1..6], [0..6]   (shift Min)
// [4..7]                           (shift Max)
//                                  (nudge Min and Max, Max goes out of bounds so end the loop)
// So now we've done all pairs < Min and > Max2
// Do we now do Max - Min2?
// [5..8]
//                                  (shift Min - out of bounds)
// [5..9]                           (shift Max)
//                                  (shift Min went out of bounds, so end the loop)

// So then we find Min3 and Max3 in the range >Min2 and <Max2, but there is none, so we've found all possible pairs?
// [4, 8]
// [3..8], [2..8], [1..8], [0..8]
// [4..9]
// [3..9]
// [2..9], [1..9], [0..9]
// [4..6]
// [3..6], [2..6], [1..6], [0..6]
// [4..7]
// [5..8]
// [5..9]

// Not even close; the range < Min is completely unexplored, as is > Max (i.e., making ranges out of just those values
// So maybe the answer is to look at those ranges next

//          *** Solution explanation
// Gave up, looked up the answer online.  Thanks to impoldev on YouTube for the solution.

// nums = [ 4, 2, 5, 1], k = 3
// Create a set to track which pairs have gone into our sum, and a max heap (pops the top value) to index pairs and their difference.
// setElement = (leftIndex, rightIndex), heapElement = (difference, leftIndex, rightIndex)
// 
// k > 0
// Which subarray do we choose?  Optimal first choice is obviously the entire array; it contins our optimal Max and Min values.
//  heap = { (4, 0, 3) }
//  Pop heap - (0, 3) not in set, so proceed, heap = {}, result += 4 => 4, set = { (0, 3) }, k -= 1 => 2
// 
// k > 0
// Which subarray do we choose next?  Next subarray choice will involve one less element than the previous, so we are choosing either
//  [0..2] or [1..3]
// heap = { (3, 0, 2), (4, 1, 3) }
//  Pop heap - (1, 3) not in set, so proceed, heap = { (3, 0, 2) }, result =+ 4 => 8, set = { (0, 3), (1, 3) }, k -= 1 => 1
//
// k > 0
//  Next do subarray's of 1 element fewer
//  (impoldev's example only did the 2-element subarrays of the previously chosen subarray, but I think you'd need to do them all)
//  [0..1], [1..2], [2..3], [3..4]
//  heap = { (3, 0, 2), (2, 0, 1), (3, 1, 2), (3, 2, 3), (4, 3, 4) }
//  Pop heap - (3, 4) not in set, so proceed, heap = { ... }, result += 4 => 12, set = { ... }, k -= 1 = 0
//
// k == 0, loop ends, we have our result.
//
// Time complexity of this is high (revisiting elements many times over)
//
// If we use a segment tree, we can reduce the lookup time.  A segment tree for this example would look like this:
//                                                  (0) [0..3], Max: 5, Min: 1
//                                      /                                           \
//                  (1) [0, 1], Max: 4, Min: 2                                  (2) [2, 3], Max: 5, Min: 1
//                  /                   \                                       /                   \
//  (3) [0], Max: 4, Min: 4         (4) [1], Max: 2, Min: 2         (5) [2], Max: 5, Min: 5     (6) [3], Max: 1, Min: 1
//
//  **What about for arrays with an odd-number of elements?
//
//  Query the tree for a value with a given range
//  For example, [0, 3]
//      Start at root (1); range matches, return Max:5, Min 1, difference = 4
//
//  For example, [1, 2]
//      Start the root (0), range partially overlaps ([0, 3]), process on the children
//          Left Child (1), range partially overlaps ([0, 1]), process on the children
//              Left Child (3), range is out of bounds, return Max: -Inf, Min: Inf
//              Right Child (4), range fully overlaps, return Max:2, Min:2
//          (1) can now determine Max: max(-Inf, 2) = 2, Min: min(Inf, 2) = 2
//          Right Child (2), range overlaps but doesn't match ([2, 3]), process on the children
//              Left child (5), range fully overlaps, return Max:5, Min: 5
//              Right child (6), range is out of bounds, return Max: -Inf, Min: Inf
//          (2) can now determine Max: max(5, -Inf) = 5, Min: min(5, Inf) = 5
//      (0) can now process children Max: max(5, 2) = 5, Min: min (2, 5) = 2, difference = 3
//

#include <vector>
#include <queue>
#include <set>

using namespace std;

class SegmentTree
{
public:
    SegmentTree(const vector<int>& a)
        : array(a), n(a.size())
    {
        tree.resize(4 * n);     // Why 4 * n?
        build(0, 0, n - 1);
    }

    pair<int, int> query(int l, int r)
    {
        return query(0, l, r, 0, n - 1);
    }
private:
    vector<pair<int, int>> tree;
    vector<int> array;
    int n;

    int left(int node) { return 2 * node + 1; }
    int right(int node) { return 2 * node + 2; }
    int mid(int l, int r) { return l + (r - l) / 2; }

    void build(int node, int start, int end)
    {
        if (start == end)
        {
            tree[node] = make_pair(array[start], array[start]);
        }
        else
        {
            int m = mid(start, end);
            build(left(node), start, m);
            build(right(node), m + 1, end);
            tree[node] = make_pair( max(tree[left(node)].first, tree[right(node)].first),
                                    min(tree[left(node)].second, tree[right(node)].second));
        }
    }

    pair<int, int> query(int node, int ql, int qr, int l, int r)
    {
        // Out of bounds
        if (ql > r || qr < l)
        {
            return make_pair(INT_MIN, INT_MAX);
        }

        // Completely overlapping
        if (ql <= l && qr >= r)
        {
            return tree[node];
        }

        // Partially overlapping
        int m = mid(l, r);
        auto leftRes = query(left(node), ql, qr, l, m);
        auto rightRes = query(right(node), ql, qr, m + 1, r);
        return make_pair( max(leftRes.first, rightRes.first),
                          min(leftRes.second, rightRes.second) );
    }

};

long long maxTotalValue(vector<int>& nums, int k) {
    long long result = 0;
    int n = nums.size();
    SegmentTree st(nums);
    priority_queue<tuple<int, int, int>> maxHeap;
    set<pair<int, int>> seen;

    // Start with the full array
    auto res = st.query(0, n - 1);

    // Push the result onto the heap
    maxHeap.push({ (res.first - res.second), 0, n - 1 });

    // Mark this range as seen
    seen.insert({ 0, n - 1 });

    while (k > 0)
    {
        k -= 1;
        if (maxHeap.empty())
        {
            result += 0;
        }
        else
        {
            auto [value, l, r] = maxHeap.top();
            maxHeap.pop();
            result += value;

            if (l + 1 < r && seen.count({ l + 1, r }) == 0)
            {
                res = st.query(l + 1, r);
                maxHeap.push({ res.first - res.second, l + 1, r });
                seen.insert({ l + 1, r });
            }

            if (r - 1 > l && seen.count({ l, r - 1 }) == 0)
            {
                res = st.query(l, r - 1);
                maxHeap.push({ res.first - res.second, l, r - 1 });
                seen.insert({ l, r - 1 });
            }
        }
    }

    return result;
}
