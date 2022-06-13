#define DEBUG
#include "hutility.hpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using namespace std;

/**
https://leetcode.com/problems/missing-number/
*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
        }
        return n * (n + 1) / 2 - sum;
    }
};


TEST_CASE("Doctest cases")
{
    Solution sol;

    vector<int> nums;

    nums = {3,0,1};
    CHECK(sol.missingNumber(nums) == 2);

    nums = {0,1};
    CHECK(sol.missingNumber(nums) == 2);

    nums = {9,6,4,2,3,5,7,0,1};
    CHECK(sol.missingNumber(nums) == 8);
}



