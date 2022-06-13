#define DEBUG
#include "hutility.hpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using namespace std;

/**
https://leetcode.com/problems/permutations/
*/

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ret;
        int n = nums.size();
        vector<int> vis(n, 0);
        vector<int> path;

        function<void(int, vector<int>&)> dfs = [&](int pos, vector<int>& path) {
            if (pos == n) {
                ret.push_back(path);
                return;
            }

            for(int i=0; i<n; ++i) {
                if (!vis[i]) {
                    path.push_back(nums[i]);
                    vis[i] = 1;
                    dfs(pos+1, path);
                    vis[i] = 0;
                    path.pop_back();
                }
            }    
        };

        dfs(0, path);
        return ret;
    }

    vector<vector<int>> permute_loop(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ret = {{}};
        vector<vector<int>> cur;

        for (int i = 0; i < n; ++i) {
            cur = ret;
            ret = {};
            for (int j=0; j < cur.size(); ++j) {
                for (int k = 0; k<=cur[j].size(); ++k) {
                    vector<int> t = cur[j];
                    t.insert(t.begin()+k, nums[i]);
                    ret.push_back(t);
                }
            }
        }
        return ret;
    }

    vector<vector<int>> permute_stl(vector<int>& nums) {
        vector<vector<int>> ret;

        sort(nums.begin(), nums.end());

        do {
            ret.push_back(nums);
        } while(next_permutation(nums.begin(), nums.end()));
            
        return ret;

    }
};

TEST_CASE("Doctest cases")
{
    Solution sol;

    vector<int> nums;

    nums = {1,2,3};
    CHECK(sol.permute(nums) == vector<vector<int>>{{1,2,3},{1,3,2},{2,1,3},{2,3,1},{3,1,2},{3,2,1}});

    nums = {0,1};
    CHECK(sol.permute(nums) == vector<vector<int>>{{0,1},{1,0}});

    nums = {1};
    CHECK(sol.permute(nums) == vector<vector<int>>{{1}});
}
