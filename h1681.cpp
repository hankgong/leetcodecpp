#define DEBUG
#include "hutility.hpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using namespace std;

/**
https://leetcode.com/problems/minimum-incompatibility/
*/

class Solution {
public:
  int minimumIncompatibility(vector<int>& nums, int k) {
    const int n = nums.size(); 
    const int c = n / k;
    int dp[1 << 16][16];
    // memset(dp, 0x7f, sizeof(dp));
    memset(dp, 1, sizeof(dp));
    for (int i = 0; i < n; ++i) dp[1 << i][i] = 0;
    for (int s = 0; s < 1 << n; ++s)
      for (int i = 0; i < n; ++i) {
        if ((s & (1 << i)) == 0) continue;
        for (int j = 0; j < n; ++j) {
          if ((s & (1 << j))) continue;
          const int t = s | (1 << j);
          if (__builtin_popcount(s) % c == 0) {
            dp[t][j] = min(dp[t][j], dp[s][i]);
          } else if (nums[j] > nums[i]) {           
            dp[t][j] = min(dp[t][j], 
                           dp[s][i] + nums[j] - nums[i]);            
          }
          // cout << s<< " " <<i<< " "<<j <<"------------------------" << endl;
          for(int s=0; s<(1<<n); ++s) {
            for (int j=0; j<n; ++j) {
                // cout <<dp[s][j]<<", ";
            }
            // cout << endl;
          }
        }        
    }
    int ans = *min_element(begin(dp[(1 << n) - 1]), 
                           end(dp[(1 << n) - 1]));
    return ans > 1e9 ? - 1 : ans;
  }
};


TEST_CASE("Doctest cases")
{
    Solution sol;

    vector<int> nums;
    int k;

    nums = {1,2,1,4};
    k = 2;
    CHECK(sol.minimumIncompatibility(nums, k) == 4);

    nums = {6,3,8,1,3,1,2,2};
    k = 4;
    CHECK(sol.minimumIncompatibility(nums, k) == 6);

    nums = {5,3,3,6,3,3};
    k = 3;
    CHECK(sol.minimumIncompatibility(nums, k) == -1);
}
