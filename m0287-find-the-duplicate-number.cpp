#define DEBUG
#include "hutility.hpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using namespace std;

/**
https://leetcode.com/problems/find-the-duplicate-number/
*/

class Solution {
public:
    int findDuplicate1(vector<int>& nums) {

        int l = 1, r = nums.size() - 1;

        while (l < r) {
            int m = l + (r - l) / 2;
            LOG(l, m, r);
            int cnt = 0;

            for (int i = 0; i < nums.size(); ++i) {
                if (nums[i] <= m) {
                    cnt++;
                }
            }

            if (cnt > m) {
                r = m;
            } else {
                l = m + 1;
            }
        }

        return l;
    }

    int findDuplicate(vector<int>& nums) {

        int l = 1, r = nums.size() - 1;

        while (l + 1 < r) {
            int m = l + (r - l) / 2;
            LOG(l, m, r);
            int cnt = 0;

            for (int i = 0; i < nums.size(); ++i) {
                if (nums[i] <= m) {
                    cnt++;
                }
            }

            if (cnt > m) {
                r = m;
            } else {
                l = m;
            }
        }

        int c = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == l) c++;
        }
        LOG(l, r);

        if (c > 1)
            return l;
        else
            return r;
    }
};

TEST_CASE("Doctest cases")
{
    Solution sol;

    vector<int> nums;

    nums = {1,3,4,2,2};
    CHECK(sol.findDuplicate(nums) == 2);

    nums = {3,1,3,4,2};
    CHECK(sol.findDuplicate(nums) == 3);
}
