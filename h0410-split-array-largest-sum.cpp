#define DEBUG
#include "hutility.hpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using namespace std;

/**
https://leetcode.cn/problems/split-array-largest-sum/
*/

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int l = 0, r = 0;
        for (int i = 0; i < nums.size(); ++i) {
            r += nums[i];
            l = max(l, nums[i]);
        }

        while (l < r) {
            int mid = l + (r - l) / 2;
            LLOG(l, mid, r);

            int grpLeft = m;
            int curSum = mid;
            for (int i = 0; i < nums.size(); ++i) {
                LLOG(curSum, grpLeft);

                if (curSum - nums[i] < 0) {
                    curSum = mid;
                    --grpLeft;

                }
                curSum -= nums[i];

            }

            LLOG(grpLeft);
            if (grpLeft > 0) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        return l;
    }
};

TEST_CASE("Doctest cases")
{
    Solution sol;

    vector<int> nums;
    int m;

    nums = {7,2,5,10,8};
    m = 2;
    CHECK(sol.splitArray(nums, m) == 18);

    nums = {1,2,3,4,5};
    m = 2;
    CHECK(sol.splitArray(nums, m) == 9);

    nums = {1,4,4};
    m = 3;
    CHECK(sol.splitArray(nums, m) == 4);
}
