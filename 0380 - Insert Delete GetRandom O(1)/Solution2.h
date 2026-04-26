#pragma once

#include <unordered_map>
#include <vector>

// Fails on Case 2, but input set is too large to actually test, so I have no idea why.

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
            set.insert({ val, setRef.size() });
            setRef.push_back(val);
            return true;
        }
    }

    bool remove(int val) {
        if (set.contains(val))
        {
            int setRefIdx = set[val];
            int lastElement = setRef[setRef.size() - 1];
            setRef[setRefIdx] = lastElement;
            setRef.pop_back();
            set[lastElement] = setRefIdx;
            set.erase(val);

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
