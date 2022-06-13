#define DEBUG
#include "hutility.hpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using namespace std;

/**
https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) {
            return 0;
        }

        int curMin = prices[0];
        int ret = 0;
        for (int i = 0; i < prices.size(); ++i)
        {
            curMin = min(curMin, prices[i]);
            ret = max(ret, prices[i] - curMin);
        }
        return ret;
    }
};

TEST_CASE("Doctest cases")
{
    Solution sol;

    vector<int> prices;

    prices = {7,1,5,3,6,4};
    CHECK(sol.maxProfit(prices) == 5);

    prices = {7,6,4,3,1};
    CHECK(sol.maxProfit(prices) == 0);
}

