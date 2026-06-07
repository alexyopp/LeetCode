#pragma once

#include <vector>
#include <string>
#include <list>
#include <set>
#include <algorithm>

using namespace std;

void subDivideLog(const string& log, string& label, string& content)
{
    auto iter = log.cbegin();
    while (*iter != ' ')
    {
        label += *iter;
        ++iter;
    }

    // Move past the whitespace seperating the label from the contents.
    ++iter;

    while (iter != log.cend())
    {
        content += *iter;
        ++iter;
    }
}

bool isLetterLog(const string& log)
{
    string label;
    string contents;
    subDivideLog(log, label, contents);

    switch (contents[0])
    {
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
        return false;
    default:
        return true;
    }
}

vector<string> reorderLogFiles(vector<string>& logs) {
    vector<string> digitLogs;
    vector<string> letterLogs;

    for (auto log : logs)
    {
        if (isLetterLog(log))
        {
            letterLogs.push_back(log);
        }
        else
        {
            digitLogs.push_back(log);
        }
    }

    sort(letterLogs.begin(), letterLogs.end(),
        [](const string& lhs, const string& rhs)
        {
            string lId;
            string lContents;
            subDivideLog(lhs, lId, lContents);
            string rId;
            string rContents;
            subDivideLog(rhs, rId, rContents);

            if (lContents == rContents)
            {
                return lId < rId;
            }
            else
            {
                return lContents < rContents;
            }
        });

    vector<string> orderedLogs;
    for (auto letterLog : letterLogs)
    {
        orderedLogs.push_back(letterLog);
    }
    for (auto digitLog : digitLogs)
    {
        orderedLogs.push_back(digitLog);
    }

    return orderedLogs;
}
