#define DEBUG
#include "hutility.hpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using namespace std;

/**
https://leetcode.cn/problems/subsets/
*/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ret = {{}};

        for (int i = 0; i < nums.size(); ++i) {
            int l = ret.size();
            for (int j = 0; j < l; ++j) {
                // println(ret[j]);
                vector<int> t = ret[j];
                t.push_back(nums[i]);
                ret.push_back(t);
            }
            // println(ret);
        }
        return ret;
    }

    vector<vector<int>> subsets_bt(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ret;
        vector<int> path;

        function<void(int pos)> dfs = [&](int pos) {
            if (pos == n) {
                ret.push_back(path);
                return;
            }

            dfs(pos+1);
            path.push_back(nums[pos]);
            dfs(pos+1);
            path.pop_back();
        };

        dfs(0);
        return ret;
    }
};

TEST_CASE("Doctest cases")
{
    Solution sol;

    vector<int> nums;

    nums = {1,2,3};
    CHECK(sol.subsets(nums) == vector<vector<int>>{{},{1},{2},{1,2},{3},{1,3},{2,3},{1,2,3}});

    nums = {0};
    CHECK(sol.subsets(nums) == vector<vector<int>>{{},{0}});
}
