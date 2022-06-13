#define DEBUG
#include "hutility.hpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using namespace std;

/**
https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree/
*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        vector<int> left = vector<int> (len, 1), right = vector<int> (len, 1);

        for (int i = 1; i < len; ++i) {
            left[i] = nums[i - 1] * left[i - 1];
            right[len - 1 - i] = nums[len - i] * right[len - i];
        }
        LOG(left, right);

        for (int i = 0; i < len; ++i) {
            left[i] = left[i] * right[i];
        }
        return left;
    }
};

TEST_CASE("Doctest cases")
{
    Solution sol;

    vector<int> nums;

    nums = {1,2,3,4};
    CHECK(sol.productExceptSelf(nums) == vector<int>{24,12,8,6});

    nums = {-1,1,0,-3,3};
    CHECK(sol.productExceptSelf(nums) == vector<int>{0,0,9,0,0});
}
