#define DEBUG
#include "hutility.hpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using namespace std;

/**
https://leetcode.com/problems/arithmetic-subarrays/
*/

class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int m = l.size();

        vector<bool> ret;
        for (int i = 0; i < m; ++i) {
            vector<int> nn = vector<int>(nums.begin() + l[i], nums.begin() + r[i] + 1);
            LOG(nn);
            if (nn.size() <= 2) {
                ret.push_back(true);
            } else {
                sort(nn.begin(), nn.end());
                int del = nn[1] - nn[0];
                bool ok = true;
                for (int j = 0; j < nn.size() - 1; ++j) {
                    if (nn[j + 1] - nn[j] != del) {
                        ok = false;
                        break;
                    }
                }
                ret.push_back(ok);
            }

        }

        return ret;
    }
};

TEST_CASE("Doctest cases")
{
    Solution sol;

    vector<int> nums;
    vector<int> l;
    vector<int> r;

    nums = {4,6,5,9,3,7};
    l = {0,0,2};
    r = {2,3,5};
    CHECK(sol.checkArithmeticSubarrays(nums, l, r) == vector<bool>{true,false,true});

    nums = {-12,-9,-3,-12,-6,15,20,-25,-20,-15,-10};
    l = {0,1,6,4,8,7};
    r = {4,4,9,7,9,10};
    CHECK(sol.checkArithmeticSubarrays(nums, l, r) == vector<bool>{false,true,false,false,true,true});
}
