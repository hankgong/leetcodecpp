#define DEBUG
#include "hutility.hpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using namespace std;

/**
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ret = 0;
        for (int i = 0; i < prices.size() - 1; i++) {
            ret += max(0, prices[i + 1] - prices[i]);
        }
        return ret;
    }
};

TEST_CASE("Doctest cases")
{
    Solution sol;

    vector<int> prices;

    prices = {7,1,5,3,6,4};
    CHECK(sol.maxProfit(prices) == 7);

    prices = {1,2,3,4,5};
    CHECK(sol.maxProfit(prices) == 4);

    prices = {7,6,4,3,1};
    CHECK(sol.maxProfit(prices) == 0);
}

