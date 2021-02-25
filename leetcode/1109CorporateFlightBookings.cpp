#include "stdafx.h"

/*
There are n flights, and they are labeled from 1 to n.
We have a list of flight bookings.  The i-th booking bookings[i] = [i, j, k] means that we booked k seats from flights labeled i to j inclusive.
Return an array answer of length n, representing the number of seats booked on each flight in order of their label.
*/

class Solution
{
public:
    // sloved by Partial Sum type 2
    vector<int> corpFlightBookings(vector<vector<int>> &bookings, int n)
    {
        vector<int> output(n + 1, 0);
        for (auto booking : bookings)
        {
            output[booking[0] - 1] += booking[2];
            output[booking[1]] -= booking[2];
        }
        for (int i = 1; i < n; i++)
        {
            output[i] += output[i - 1];
        }
        output.pop_back();
        return output;
    }
};

/**
 * Two types of partial sum problems
 * 
 * 1. given array a(1), a(2), ...a(n), each query give you numbers l and r you shhould print sum of al, a(a+1), ..., a(r)
 * You need to build another array s1, s2, ..., sn which si = a1 + a2 + ... + ai and answer is sr - sl - 1 .
 * 
 * 2. given array of numers l, r, v, print arrays, which is opposite of type 1
 * You should have another array p1, p2, ..., pn which, all of its members are initially 0, 
 * for each query, you should increase pl by v and decrease pr + 1 by v .
 */
