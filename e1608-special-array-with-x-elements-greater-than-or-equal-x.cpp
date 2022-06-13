#define DEBUG
#include "hutility.hpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using namespace std;

/**
https://leetcode.cn/problems/special-array-with-x-elements-greater-than-or-equal-x/
*/

class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int l = nums.size();

        for (int i=0; i<l; ++i)
        {
            if ((l-i) <= nums[i]){
                return l-i;     // return the first instance
            } else if ((l-i) == nums[i] + 1) {
                return -1;      // special case handling
            }
        }

        return -1;
    }
};

TEST_CASE("Doctest cases")
{
    Solution sol;

    vector<int> nums;

    nums = {3,5};
    CHECK(sol.specialArray(nums) == 2);

    nums = {0,0};
    CHECK(sol.specialArray(nums) == -1);

    nums = {0,4,3,0,4};
    CHECK(sol.specialArray(nums) == 3);
}
