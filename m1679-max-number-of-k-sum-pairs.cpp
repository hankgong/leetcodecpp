#define DEBUG
#include "hutility.hpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using namespace std;

/**
https://leetcode.com/problems/max-number-of-k-sum-pairs/
*/

class Solution {
public:
    int maxOperations_doublepointer(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ret=0;
        int l=0, r=nums.size()-1;
        while(l<r) {
            if(nums[l]+nums[r]>k) {
                --r;
            } else if(nums[l]+nums[r]<k) {
                ++l;
            } else {
                ++l;
                --r;
                ++ret;
            }
        }
        return ret;
    }

    int maxOperations(vector<int>& nums, int k) {
        int ret = 0;
        unordered_map<int,int> nm;

        for (int i = 0; i < nums.size(); ++i) {
            if (nm.count(k-nums[i]) && nm[k-nums[i]]>0) {
                ret++;
                nm[k-nums[i]]--;
            } else {
                nm[nums[i]]++;
            }

            LLOG(nm);
            // if (nm.count(k-nums[i])) {
            //     if(nums[i] != k-nums[i] && nm[nums[i]]>0 && nm[k-nums[i]]>0) {
            //         ret++;
            //         nm[nums[i]]--;
            //         nm[k-nums[i]]--;
            //     }
            //     if(nums[i] == k-nums[i] && nm[nums[i]]>1) {
            //         ret++;
            //         nm[nums[i]]-=2;
            //     }
            // }            
        }
        return ret;
    }
};

TEST_CASE("Doctest cases")
{
    Solution sol;

    vector<int> nums;
    int k;

    nums = {1,2,3,4};
    k = 5;
    CHECK(sol.maxOperations_doublepointer(nums, k) == 2);

    nums = {3,1,3,4,3};
    k = 6;
    CHECK(sol.maxOperations_doublepointer(nums, k) == 1);
}
