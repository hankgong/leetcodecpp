#define DEBUG
#include "hutility.hpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using namespace std;

/**
https://leetcode.com/problems/stone-game-vi/
*/

class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        int n = aliceValues.size();
        vector<pair<int, int>> sums;

        for (int i = 0; i < n; ++i) {
            sums.push_back(make_pair(bobValues[i]+aliceValues[i], i));
        }

        sort(sums.begin(), sums.end());
        // LLOG(sums);

        int ret = 0;
        for(int i=0; i<n; ++i) {
            if (i%2==0) {
                ret += aliceValues[sums[n-1-i].second];
            } else {
                ret -= bobValues[sums[n-1-i].second];
            }
        }
        
        LLOG(ret);
        if (ret >0)
            return 1;
        else if (ret == 0) 
            return 0;
        else
            return -1;
    }
};

TEST_CASE("Doctest cases")
{
    Solution sol;

    vector<int> aliceValues;
    vector<int> bobValues;

    aliceValues = {1,3};
    bobValues = {2,1};
    CHECK(sol.stoneGameVI(aliceValues, bobValues) == 1);

    aliceValues = {1,2};
    bobValues = {3,1};
    CHECK(sol.stoneGameVI(aliceValues, bobValues) == 0);

    aliceValues = {2,4,3};
    bobValues = {1,6,7};
    CHECK(sol.stoneGameVI(aliceValues, bobValues) == -1);
}
