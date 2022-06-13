#define DEBUG
#include "hutility.hpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using namespace std;

/**
https://leetcode.com/problems/maximum-subarray/
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);

        dp[0] = nums[0];
        int ret = nums[0];

        for(int i=1; i<n; ++i) {
            dp[i] = max(dp[i-1]+nums[i], nums[i]);
            ret = max(ret, dp[i]);
        }

        return ret;
    }

    int maxSubArray_official(vector<int>& nums) {
        int pre=0, maxAns = nums[0];

        for(auto &x: nums) {
            LLOG(x, pre, pre+x);
            pre = max(pre+x, x);
            maxAns = max(maxAns, pre);
        }

        return maxAns;
    }
};

TEST_CASE("Doctest cases")
{
    Solution sol;

    vector<int> nums;

    nums = {-2,1,-3,4,-1,2,1,-5,4};
    CHECK(sol.maxSubArray(nums) == 6);

    nums = {1};
    CHECK(sol.maxSubArray(nums) == 1);

    nums = {5,4,-1,7,8};
    CHECK(sol.maxSubArray(nums) == 23);
}