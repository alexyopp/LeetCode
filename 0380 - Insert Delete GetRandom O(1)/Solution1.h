#pragma once

#include <unordered_map>
#include <vector>

// Fails on Case 2, but input set is too large to actually test, so I have no idea why.
// After getting Solution2 to work, the problem must be in the remove logic

class RandomizedSet {
public:
    RandomizedSet() {

    }

    bool insert(int val) {
        if (set.contains(val))
        {
            return false;
        }
        else
        {
            setRef.push_back(val);
            int setRefIdx = static_cast<int>(setRef.size() - 1);
            set.insert({ val, setRefIdx });
            return true;
        }
    }

    bool remove(int val) {
        if (set.contains(val))
        {
            // Remove val from set (saving it's setRefIdx before we do.
            int setRefIdx = set[val];
            set.erase(val);

            // "Move" the last element of setRef to fill the space previously occupied by val
            int lastElement = setRef[setRef.size() - 1];
            setRef[setRefIdx] = lastElement;
            setRef.pop_back();

            // Update that element's setRefIdx (Edge Case: we've actually removed the last element)
            if (set.size() > 0)
            {
                set[lastElement] = setRefIdx;
            }
            
            return true;
        }
        else
        {
            return false;
        }
    }

    int getRandom() {
        int setSize = setRef.size();

        return setRef[rand() % setSize];
    }

private:
    std::unordered_map<int, int> set;
    std::vector<int> setRef;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
