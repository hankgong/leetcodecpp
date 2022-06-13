#define DEBUG
#include "hutility.hpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using namespace std;

/**
https://leetcode.com/problems/4sum/
*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret;

        for (int i = 0; i < n-3; ++i) {
            if (i>0 && nums[i]==nums[i-1]) continue;
            for(int j=i+1; j<n-2; ++j) {
                if (j>i+1 && nums[j] == nums[j-1]) continue;
                int l=j+1, r = n-1;
                int t = target-nums[i]-nums[j];
                
                while (l < r) {
                    int c = nums[l] + nums[r];
                                        
                    if (c < t) {
                        l++;
                    } else if (c>t) {
                        r--;
                    } else {
                        ret.push_back({nums[i], nums[j], nums[l], nums[r]});
                        while (l<r && nums[l]==nums[++l]);
                        while (l<r && nums[r]==nums[--r]);
                    }
                }
            }
        }
        return ret;
    }
};

TEST_CASE("Doctest cases")
{
    Solution sol;

    vector<int> nums;
    int target;

    nums = {1,0,-1,0,-2,2};
    target = 0;
    CHECK(sol.fourSum(nums, target) == vector<vector<int>>{{-2,-1,1,2},{-2,0,0,2},{-1,0,0,1}});

    nums = {2,2,2,2,2};
    target = 8;
    CHECK(sol.fourSum(nums, target) == vector<vector<int>>{{2,2,2,2}});
}
