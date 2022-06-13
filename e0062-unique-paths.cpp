#define DEBUG
#include "hutility.hpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using namespace std;

/**
https://leetcode.com/problems/unique-paths/
*/

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp;

        for (int i = 0; i < n; ++i) {
            dp.push_back(vector<int>(m, 0));
        }

        for (int i = 0; i < n; ++i) {
            dp[i][0] = 1;
        }

        for (int j = 0; j < m; ++j) {
            dp[0][j] = 1;
        }

        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < m; ++j) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        return dp[n - 1][m - 1];
    }
};

TEST_CASE("Doctest cases")
{
    Solution sol;

    int m;
    int n;
    
    CHECK(sol.uniquePaths(3, 2) == 3);
    CHECK(sol.uniquePaths(3, 1) == 1);
    CHECK(sol.uniquePaths(1, 10) == 1);

    m = 3;
    n = 7;
    CHECK(sol.uniquePaths(m, n) == 28);

    m = 3;
    n = 2;
    CHECK(sol.uniquePaths(m, n) == 3);
}
