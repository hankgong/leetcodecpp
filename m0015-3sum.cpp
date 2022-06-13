#define DEBUG
#include "hutility.hpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using namespace std;

/**
https://leetcode.cn/problems/3sum/
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        vector<vector<int>> ret;

        for(int i=0; i<n-2; ++i){
            if (i>0 && nums[i] == nums[i-1]) continue;
            int l = i+1, r = n-1;
            int t = -nums[i];
            while (l < r) {
                int c = nums[l] + nums[r];
                if (c<t) {
                    l++;  
                } else if (c>t) {
                    r--;
                } else { //c == t
                    ret.push_back({nums[i], nums[l], nums[r]});
                    while (l<r && nums[l] == nums[++l]);
                    while (l<r && nums[r] == nums[--r]);
                }
            }
        }
        return ret;
    }
    
    vector<vector<int>> threeSum1(vector<int>& nums) {
        int len = nums.size();
        vector<vector<int>> ret;
        if (len < 3) return {};
        sort(nums.begin(), nums.end());

        for (int i = 0; i < len - 2; ++i) {
            if (nums[i] > 0) break;
            if (i > 0 && nums[i] == nums[i - 1]) continue; // remove the repeating ones

            int target = -nums[i];
            int l = i + 1, r = len - 1;
            while (l < r) {
                if (nums[l] + nums[r] == target) {
                    ret.push_back({nums[i], nums[l], nums[r]});

                    ++l;
                    --r;
                    while (l < r && nums[l] == nums[l - 1]) ++l;
                    while (l < r && nums[r] == nums[r + 1]) --r;
                } else if (nums[l] + nums[r] < target) {
                    ++l;
                } else {
                    --r;
                }
            }
        }
        return ret;
    }

    vector<vector<int>> threeSum2(vector<int>& nums) {
        int l = nums.size();
        vector<vector<int>> ret;
        if ( l < 3) return {};
        sort(nums.begin(), nums.end());

        for (int i = 0; i < l - 2; ++i ) {
            if (i > 0 && nums[i - 1] ==  nums[i]) {
                LOG("skip ", i);
                continue;
            }
            int target = -nums[i];
            unordered_map<int, int> smap;
            for (int j = i + 1; j < l; ++j) {
                if (0 == smap.count(target - nums[j])) {
                    smap[nums[j]] = 0;
                } else {
                    if (smap[target - nums[j]] == 0) {
                        ret.push_back({nums[i], nums[j], -nums[i] - nums[j]});
                        smap[target - nums[j]] = 1;
                    }
                }
                LOG(smap);
            }
            LOG(ret);
        }
        return ret;
    }
};

TEST_CASE("Doctest cases")
{
    Solution sol;

    vector<int> nums;

    nums = {-1,0,1,2,-1,-4};
    CHECK(sol.threeSum(nums) == vector<vector<int>>{{-1,-1,2},{-1,0,1}});

    nums = {};
    CHECK(sol.threeSum(nums) == vector<vector<int>>{});

    nums = {0};
    CHECK(sol.threeSum(nums) == vector<vector<int>>{});
}
