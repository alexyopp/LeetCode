#pragma once

#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

bool isWordDelimiter(string::const_iterator c)
{
    switch (*c)
    {
    case ' ':
    case '!':
    case '?':
    case '\'':
    case ',':
    case ';':
    case '.':
        return true;
    default:
        return false;
    }
}

string mostCommonWord(string paragraph, vector<string>& banned) {
    // Ensure we end with a delimiter
    paragraph += ".";
    
    string curHighestWord{ "" };
    int curHighestCount{ 0 };

    // Build set of banned words (constant time lookup of a word, rather that interating through the banned vector)
    // Per problem description, banned words are already normalized.
    set<string> bannedWords;
    for (auto bannedWord : banned)
    {
        bannedWords.insert(bannedWord);
    }

    map<string, int> words;
    int curWordCount{ 0 };

    // For each character
    string curWord;
    for (auto iter = paragraph.cbegin(); iter != paragraph.cend(); ++iter)
    {
        // If we've reached the end of a word
        if (isWordDelimiter(iter))
        {
            // And we actually have a word (and we didn't run into consecutive delimiters)
            if (curWord.size() > 0)
            {
                ++words[curWord];
                curWordCount = words[curWord];

                if ((curWordCount > curHighestCount) &&
                    (bannedWords.count(curWord) == 0))
                {
                    curHighestWord = curWord;
                    curHighestCount = curWordCount;
                }

                // Reset curWord
                curWord = "";
            }
        }
        else
        {
            curWord += tolower(*iter);
        }
    }

    return curHighestWord;
}
