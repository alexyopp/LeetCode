#pragma once

#include <vector>

using namespace std;

// Brute force
// Passes 35 / 40 test cases (fails on big input)

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int circuitLength = gas.size();
    int tankAmount = 0;
    int currentPosition = 0;
    int startingPosition = 0;
    for (startingPosition; startingPosition < circuitLength; ++startingPosition)
    {
        tankAmount = 0;
        currentPosition = startingPosition;
        while (true)
        {
            tankAmount += gas[currentPosition];
            if (tankAmount >= cost[currentPosition])
            {
                tankAmount -= cost[currentPosition];
                currentPosition = (currentPosition + 1) % circuitLength;
            }
            else
            {
                break;
            }

            if (currentPosition == startingPosition)
            {
                return currentPosition;
            }
        }
    }

    return -1;
}
