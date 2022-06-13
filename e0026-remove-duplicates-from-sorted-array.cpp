#define DEBUG
#include "hutility.hpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using namespace std;

/**
https://leetcode.com/problems/remove-duplicates-from-sorted-array/
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        int idx = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[idx - 1] != nums[i]) {
                nums[idx++] = nums[i];
            }
        }
        return idx;
    }
};

TEST_CASE("test results")
{
    Solution sol;
    vector<int> nums;
    nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    CHECK(sol.removeDuplicates(nums) == 5);
    CHECK(nums == vector<int>{0, 1, 2, 3, 4, 2, 2, 3, 3, 4});

    nums = {0};
    CHECK(sol.removeDuplicates(nums) == 1);
    CHECK(nums == vector<int>{0});

    nums = {};
    CHECK(sol.removeDuplicates(nums) == 0);
    CHECK(nums == vector<int>{});

    nums = {1, 2, 3};
    CHECK(sol.removeDuplicates(nums) == 3);
    CHECK(nums == vector<int>{1, 2, 3}); 
    
    nums={1,1,2};
    CHECK(sol.removeDuplicates(nums) == 2);
}
