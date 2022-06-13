#define DEBUG
#include "hutility.hpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using namespace std;

/**
https://leetcode.com/problems/permutations-ii/
*/

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ret;
        int n = nums.size();
        vector<int> vis(n, 0);
        vector<int> path;

        sort(nums.begin(), nums.end());

        function<void(int, vector<int>&)> dfs = [&](int pos, vector<int>& path) {
            if (pos == n) {
                ret.push_back(path);
                return;
            }

            for(int i=0; i<n; ++i) {
                if (vis[i]) continue;
                if (i>0 && nums[i] == nums[i-1] && !vis[i-1]) continue;

                path.push_back(nums[i]);
                vis[i] = 1;
                dfs(pos+1, path);
                vis[i] = 0;
                path.pop_back();
            }    
        };

        dfs(0, path);
        return ret;
    }

    vector<vector<int>> permuteUnique_dfs(vector<int>& nums) {
        vector<vector<int>> ret;
        int n = nums.size();
        vector<int> vis(n, 0);
        vector<int> path;

        function<void(int, vector<int>&)> dfs = [&](int pos, vector<int>& path) {
            if (pos == n) {
                ret.push_back(path);
                return;
            }

            unordered_set<int> s;
            for(int i=0; i<n; ++i) {
                if (!vis[i] && s.insert(nums[i]).second) {
                    path.push_back(nums[i]);
                    vis[i] = 1;
                    dfs(pos+1, path);
                    vis[i] = 0;
                    path.pop_back();
                }
                // LLOG(s);
            }    
        };

        dfs(0, path);
        return ret;
    }

    vector<vector<int>> permuteUnique_stl(vector<int>& nums) {
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

    nums = {1,1,2};
    CHECK(sol.permuteUnique(nums) == vector<vector<int>>{{1,1,2},{1,2,1},{2,1,1}});

    nums = {1,2,3};
    CHECK(sol.permuteUnique(nums) == vector<vector<int>>{{1,2,3},{1,3,2},{2,1,3},{2,3,1},{3,1,2},{3,2,1}});
}
