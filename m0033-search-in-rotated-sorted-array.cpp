#define DEBUG
#include "hutility.hpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using namespace std;

/**
https://leetcode.cn/problems/search-in-rotated-sorted-array/
*/

class Solution {
public:
    int search1(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;

        while (l <= r) {
            int m = l + (r - l) / 2;
            LOG(l, m, r, nums[m], target);
            if (nums[m] == target) return m;

            if (nums[0] <= nums[m]) { //left partion in order
                if (target >= nums[0] && target < nums[m]) {
                    r = m - 1;
                } else {
                    l = m + 1;
                }
            } else { //right partion in order
                if (target > nums[m] && target <= nums[nums.size() - 1]) {
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            }
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;

        while (l + 1 < r) {
            int m = l + (r - l) / 2;
            // println5(l, m, r, nums[m], target);
            // if (nums[m] == target) return m;

            if (nums[0] < nums[m]) { //left partion in order
                if (target >= nums[0] && target < nums[m]) {
                    r = m;
                } else {
                    l = m;
                }
            } else { //right partion in order
                if (target > nums[m] && target <= nums[nums.size() - 1]) {
                    l = m;
                } else {
                    r = m;
                }
            }
        }

        LOG(l, r, nums[l], nums[r]);
        if (nums[l] == target) return l;
        if (nums[r] == target) return r;
        return -1;
    }
};

TEST_CASE("Doctest cases")
{
    Solution sol;

    vector<int> nums;
    int target;

    nums = {4,5,6,7,0,1,2};
    target = 0;
    CHECK(sol.search1(nums, target) == 4);

    nums = {4,5,6,7,0,1,2};
    target = 3;
    CHECK(sol.search1(nums, target) == -1);

    nums = {1};
    target = 0;
    CHECK(sol.search1(nums, target) == -1);
}
