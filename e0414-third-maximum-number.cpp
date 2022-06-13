#define DEBUG
#include "hutility.hpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using namespace std;

/**
https://leetcode.com/problems/third-maximum-number/
*/

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long x = LONG_MIN;
        long y = LONG_MIN;
        long z = LONG_MIN;
        int uniqc = 0;

        for (int i=0; i<nums.size(); i++) {
            if (nums[i] > x && nums[i] >y && nums[i] > z) {
                z = y;
                y = x;
                x = nums[i];
            } else if (nums[i] < x && nums[i] >y && nums[i] > z) {
                z = y;
                y = nums[i];
            } else if (nums[i] < x && nums[i] < y && nums[i] > z) {
                z = nums[i];
            }

        }

        if (z != LONG_MIN) {
            return z;
        } else {
            return x;
        }
    }
};

TEST_CASE("Doctest cases")
{
    Solution sol;

    vector<int> nums;

    nums = {3,2,1};
    CHECK(sol.thirdMax(nums) == 1);

    nums = {1,2};
    CHECK(sol.thirdMax(nums) == 2);

    nums = {2,2,3,1};
    CHECK(sol.thirdMax(nums) == 1);

    nums = {1, 2, 2, 5, 3, 5};
    CHECK(sol.thirdMax(nums) == 2);

    nums = {1,2,-2147483648};
    CHECK(sol.thirdMax(nums) == -2147483648);
}
