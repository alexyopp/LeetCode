#pragma once

#include <vector>

using namespace std;

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int totalDifference = 0;
    for (int i = 0; i < gas.size(); ++i)
    {
        totalDifference += gas[i] - cost[i];
    }

    if (totalDifference >= 0)  //guaranteed a solution
    {
        int runningTotal = 0;
        int startingPosition = 0;
        for (int i = 0; i < gas.size(); ++i)
        {
            if (runningTotal < 0)
            {
                runningTotal = 0;
                startingPosition = i;
            }
            runningTotal += gas[i] - cost[i];
        }

        return startingPosition;
    }
    else  // guaranteed no solution
    {
        return -1;
    }
}
