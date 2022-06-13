#define DEBUG
#include "hutility.hpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using namespace std;

/**
https://leetcode.com/problems/ways-to-make-a-fair-array/
*/

class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int n = nums.size();
        //add a number for index 0
        vector<int> ev(n+1, 0), ov(n+1, 0);

        for(int i=0; i<n; ++i) {
            if (i%2==0) {
                ev[i+1] = ev[i]+nums[i];
                ov[i+1] = ov[i];
            } else {
                ov[i+1] = ov[i]+nums[i];
                ev[i+1] = ev[i];
            }
        }
        LLOG(ev, ov);

        int ret=0;
        for(int i=1; i<=n; ++i) {
            int e = ev[i-1] + ov[n] - ov[i];
            int o = ov[i-1] + ev[n] - ev[i];
            LLOG(e, o);
            if (e==o) ret++;
        }
        return ret;
    }

    int waysToMakeFair_mine(vector<int>& nums) {
        unordered_map<int, int> em, om;
        int n = nums.size();
        int se=0, so=0;
        for (int i = 0; i < n; ++i) {
            if (i % 2==0) {
                se += nums[i];
            } else {
                so += nums[i];
            }
            em[i] = se;
            om[i] = so;
        }

        em[-1] = 0;
        om[-1] = 0;
        LLOG(em, om);

        int ret = 0;
        // if (em[n-1]-nums[0] == om[n-1]) ret++;
        for(int i = 0; i<n; ++i) {
            int u = em[i-1] + (om[n-1]-om[i]);
            int v = om[i-1] + (em[n-1]-em[i]);

            LLOG(u, v);
            if (u==v) ret++;
        }
        return ret;
    }
};

TEST_CASE("Doctest cases")
{
    Solution sol;

    vector<int> nums;

    nums = {2,1,6,4};
    CHECK(sol.waysToMakeFair(nums) == 1);

    nums = {1,1,1};
    CHECK(sol.waysToMakeFair(nums) == 3);

    nums = {1,2,3};
    CHECK(sol.waysToMakeFair(nums) == 0);
}
