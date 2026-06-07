#pragma once

#include <vector>
#include <string>
#include <cctype>
#include <algorithm>

using namespace std;

bool IsLetterLog(const string& log)
{
    // The first whitespace splits the log identifier and the contents
    size_t posSplit = log.find(' ');

    // contents guaranteed to have at least one word, so just check the first value of contents to determine the log type
    if (isdigit(log[posSplit + 1]))
    {
        return false;
    }
    else
    {
        return true;
    }
}

vector<string> reorderLogFiles(vector<string>& logs) {
    vector<string> digitLogs;
    vector<string> letterLogs;

    for (int i = 0; i < logs.size(); ++i)
    {
        if (IsLetterLog(logs[i]))
        {
            letterLogs.push_back(logs[i]);
        }
        else
        {
            digitLogs.push_back(logs[i]);
        }
    }

    sort(letterLogs.begin(), letterLogs.end(),
        [](const string& lhs, const string& rhs)
        {
            // The first whitespace splits the log identifier and the contents
            size_t posSplit = lhs.find(' ');
            string lIdentifier = lhs.substr(0, posSplit);
            string lContents = lhs.substr(posSplit + 1, lhs.size());

            posSplit = rhs.find(' ');
            string rIdentifier = rhs.substr(0, posSplit);
            string rContents = rhs.substr(posSplit + 1, lhs.size());

            if (lContents == rContents)
            {
                return lIdentifier < rIdentifier;
            }
            else
            {
                return lContents < rContents;
            }
        });

    // Add digit logs to the end of the result
    for (auto log : digitLogs)
    {
        letterLogs.push_back(log);
    }

    return letterLogs;
}
