#define DEBUG
#include "hutility.hpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using namespace std;

/**
https://leetcode.com/problems/sum-of-absolute-differences-in-a-sorted-array/
*/

class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n=nums.size();

        vector<int> prefixs(n+1, 0);
        vector<int> ret;


        for(int i=1; i<n+1; ++i){
            prefixs[i] = prefixs[i-1]+nums[i-1];
        }
        int total = prefixs[n];
        // LLOG(prefixs);

        for (int i=0; i<n; ++i) {
            ret.push_back((i+1)*nums[i] - prefixs[i+1] + total-prefixs[i+1]-(n-i-1)*nums[i]);
        }
        return ret;
    }
};

TEST_CASE("Doctest cases")
{
    Solution sol;

    vector<int> nums;

    nums = {2,3,5};
    CHECK(sol.getSumAbsoluteDifferences(nums) == vector<int>{4,3,5});

    nums = {1,4,6,8,10};
    CHECK(sol.getSumAbsoluteDifferences(nums) == vector<int>{24,15,13,15,21});
}
