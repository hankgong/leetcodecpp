#define DEBUG
#include "hutility.hpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using namespace std;

/**
https://leetcode.com/problems/predict-the-winner/
*/

class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        dp[n-1][n-1]=nums[n-1];
        for(int i=0; i<n; ++i) dp[i][i]=nums[i];

        for(int i=n-2; i>=0; --i) {
            for(int j=i+1; j<n; ++j) {
                LLOG(dp, i, j, nums[i]-dp[i+1][j], nums[j]-dp[i][j-1]);
                dp[i][j] = max(nums[i]-dp[i+1][j], nums[j]-dp[i][j-1]);
            }
        }
        return (dp.front().back()>=0);
    }
};

TEST_CASE("Doctest cases")
{
    Solution sol;

    vector<int> nums;

    nums = {1,5,2};
    CHECK(sol.PredictTheWinner(nums) == false);

    nums = {1,5,233,7};
    CHECK(sol.PredictTheWinner(nums) == true);
}
