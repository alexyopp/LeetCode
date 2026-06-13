#pragma once

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

//  For each word
//      For each letter
//          Look up its value (map? Could do math to get the index, but the map would be small and fast, so why not?
//          Add that value to the current word's sum
//      word's sum mod 26
//      Look up sum's char value (again, could do math, or just use a small, fast map?)
//      Add it to solution string
//

const unsigned int NUMBER_OF_CHARACTERS = 26;

string mapWordWeights(vector<string>& words, vector<int>& weights) {
    unordered_map<char, int> weightLookup;
    for (int i = 0; i < NUMBER_OF_CHARACTERS; ++i)
    {
        weightLookup.insert({ 'a' + i, weights[i] });
    }

    unordered_map<int, char> reverseValue;
    for (int i = 0; i < NUMBER_OF_CHARACTERS; ++i)
    {
        weightLookup.insert({ i, 'z' - i, });
    }

    string result{};
    for (auto word : words)
    {
        int wordSum{ 0 };
        for (auto character : word)
        {
            wordSum += weightLookup.at(character);
        }

        wordSum %= NUMBER_OF_CHARACTERS;
        result += reverseValue.at(wordSum);
    }

    return result;
}
