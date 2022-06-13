#define DEBUG
#include "hutility.hpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using namespace std;

/**
https://leetcode.com/problems/perfect-squares/
*/

class Solution {
public:
    int numSquares(int n) {
        vector<int> sqrNums;

        for (int i = 1; i <= sqrt(n); ++i) {
            sqrNums.push_back(i*i);
        }

        vector<int> dp(n+1, n);
        dp[0] = 0;

        for (int i = 1; i <= n; ++i) {
            for(int j=0; j<sqrNums.size(); ++j) {
                if (sqrNums[j] <= i) {
                    dp[i] = min(dp[i-sqrNums[j]]+1, dp[i]);
                } else {
                    break;
                }
            }
        }

        return dp[n];
    }
};

TEST_CASE("Doctest cases")
{
    Solution sol;

    int n;

    n = 12;
    CHECK(sol.numSquares(n) == 3);

    n = 13;
    CHECK(sol.numSquares(n) == 2);
}
