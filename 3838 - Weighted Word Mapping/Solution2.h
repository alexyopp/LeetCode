#pragma once

#include <string>
#include <vector>

using namespace std;

// Turns out the math is faster the the map lookups!

const unsigned int NUMBER_OF_CHARACTERS = 26;

string mapWordWeights(vector<string>& words, vector<int>& weights) {
    string result{};
    for (auto word : words)
    {
        int wordSum{ 0 };
        for (auto character : word)
        {
            wordSum += weights.at(character - 'a');
        }

        wordSum %= NUMBER_OF_CHARACTERS;
        result += ('z' - wordSum);
    }

    return result;
}
