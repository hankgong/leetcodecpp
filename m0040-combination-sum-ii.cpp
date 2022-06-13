#define DEBUG
#include "hutility.hpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using namespace std;

/**
https://leetcode.com/problems/combination-sum-ii/
*/

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ret;
        vector<int> path;
        sort(candidates.begin(), candidates.end());

        function<void(int, int)> dfs = [&](int curs, int start) {
            if (curs > target) return;
            if (curs == target) {
                ret.push_back(path); 
                return;
            }

            for(int i=start; i<candidates.size(); ++i) {
                if (i > start && candidates[i] == candidates[i-1]) continue;
                if (curs+candidates[i] > target) break;  //pruning
                path.push_back(candidates[i]);
                dfs(curs+candidates[i], i+1);   // Q39 is i here
                path.pop_back();
            }
        };

        dfs(0, 0);
        return ret;
    }

    vector<vector<int>> combinationSum2_mydfs(vector<int>& candidates, int target) {
        vector<vector<int>> ret;
        vector<int> vis(candidates.size(), 0);
        vector<int> path;
        sort(candidates.begin(), candidates.end());

        function<void(int, int)> dfs = [&](int curs, int start) {
            if (curs > target) return;
            if (curs == target) {
                ret.push_back(path); 
                return;
            }

            for(int i=start; i<candidates.size(); ++i) {
                if (vis[i]) continue;
                if (i > 0 && candidates[i] == candidates[i-1] && !vis[i-1]) continue;
                if (curs+candidates[i] > target) break;  //pruning
                vis[i] = 1;
                path.push_back(candidates[i]);
                dfs(curs+candidates[i], i);
                path.pop_back();
                vis[i] = 0;
            }
        };

        dfs(0, 0);
        return ret;
    }
};


TEST_CASE("Doctest cases")
{
    Solution sol;

    vector<int> candidates;
    int target;

    candidates = {10,1,2,7,6,1,5};
    target = 8;
    CHECK(sol.combinationSum2(candidates, target) == vector<vector<int>>{{1,1,6},{1,2,5},{1,7},{2,6}});

    candidates = {2,5,2,1,2};
    target = 5;
    CHECK(sol.combinationSum2(candidates, target) == vector<vector<int>>{{1,2,2},{5}});
}
