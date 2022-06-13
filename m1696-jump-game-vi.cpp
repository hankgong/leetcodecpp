#define DEBUG
#include "hutility.hpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using namespace std;

/**
https://leetcode.cn/problems/jump-game-vi/
*/

class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n, INT_MIN);

        dp[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            for(int j=1; j<=k; ++j) {
                if (i-j >=0) dp[i]=max(dp[i-j], dp[i]);
                LLOG(i, j);
            }
            dp[i] += nums[i];
            LLOG(dp);
        }

        return dp[n-1];
    }
};

TEST_CASE("Doctest cases")
{
    Solution sol;

    vector<int> nums;
    int k;

    nums = {1,-1,-2,4,-7,3};
    k = 2;
    CHECK(sol.maxResult(nums, k) == 7);

    nums = {10,-5,-2,4,0,3};
    k = 3;
    CHECK(sol.maxResult(nums, k) == 17);

    nums = {1,-5,-20,4,-1,3,-6,-3};
    k = 2;
    CHECK(sol.maxResult(nums, k) == 0);
}
