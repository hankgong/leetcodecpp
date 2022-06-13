#define DEBUG
#include "hutility.hpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using namespace std;

/**
https://leetcode.com/problems/majority-element/
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }

    int majorityElement1(vector<int>& nums) {
        int halfSize = nums.size() / 2;
        map<int, int> cntm;

        int ret = nums[0];
        for (auto n : nums) {
            if (cntm.find(n) != cntm.end()) {
                cntm[n] += 1;
                if (cntm[n] >= halfSize) {
                    ret = n;
                }
            } else {
                cntm[n] = 1;
            }
        }
        return ret;
    }
};

TEST_CASE("Doctest cases")
{
    Solution sol;

    vector<int> nums;

    nums = {3,2,3};
    CHECK(sol.majorityElement(nums) == 3);

    nums = {2,2,1,1,1,2,2};
    CHECK(sol.majorityElement(nums) == 2);
}
