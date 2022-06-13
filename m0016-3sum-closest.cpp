#define DEBUG
#include "hutility.hpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using namespace std;

/**
https://leetcode.cn/problems/3sum-closest/
*/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int len = nums.size();
        int ret = nums[0] + nums[1] + nums[2];
        sort(nums.begin(), nums.end());

        for (int i = 0; i < len - 2; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int t = target - nums[i];
            int l = i + 1, r = len - 1;

            while (l < r) {
                int s = nums[l] + nums[r];
                // int d = ;
                LOG(i, nums[l], nums[r], ret);

                if (abs(t - s) < abs(ret - target)) {
                    ret = nums[i] + nums[l] + nums[r];
                }
                if ( s == t) {
                    return target;
                } else if (s < t) {
                    ++l;
                } else {
                    --r;
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

    nums = {-1,2,1,-4};
    target = 1;
    CHECK(sol.threeSumClosest(nums, target) == 2);

    nums = {0,0,0};
    target = 1;
    CHECK(sol.threeSumClosest(nums, target) == 0);
}
