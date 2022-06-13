#define DEBUG
#include "hutility.hpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using namespace std;

/**
https://leetcode.com/problems/two-sum/
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> tmap;
        vector<int> ret;

        for (int i=0; i<nums.size(); i++) {
            if (tmap.find(target - nums[i]) != tmap.end()) {
                ret.push_back(tmap[target-nums[i]]);
                ret.push_back(i);
                return ret;
            }

            tmap[nums[i]] = i;
        }
        return ret;
    }
};

TEST_CASE("Doctest cases")
{
    Solution sol;

    vector<int> nums;
    int target;

    nums = {2,7,11,15};
    target = 9;
    CHECK(sol.twoSum(nums, target) == vector<int>{0,1});

    nums = {3,2,4};
    target = 6;
    CHECK(sol.twoSum(nums, target) == vector<int>{1,2});

    nums = {3,3};
    target = 6;
    CHECK(sol.twoSum(nums, target) == vector<int>{0,1});
}
