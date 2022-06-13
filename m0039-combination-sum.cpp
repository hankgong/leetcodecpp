#define DEBUG
#include "hutility.hpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using namespace std;

/**
https://leetcode.com/problems/combination-sum/
*/

class Solution {
public:
    vector<vector<int>> combinationSum_dfs(vector<int>& candidates, int target) {
        vector<vector<int>> ret;
        vector<int> path;

        sort(candidates.begin(), candidates.end()); //pruning

        function<void(int, int)> dfs = [&](int curs, int start) {
            if (curs > target) {
                return;
            } else if (curs == target) {
                ret.push_back(path);
                return;
            } else {
                for (int i = start; i < candidates.size(); ++i) {
                    if (curs + candidates[i] > target) break;   //pruning

                    path.push_back(candidates[i]);
                    dfs(curs+candidates[i], i);
                    path.pop_back();
                }
            }
        };

        dfs(0, 0);
        return ret;
    }

    vector<vector<int>> combinationSum_dp(vector<int>& candidates, int target) {
        unordered_map<int, set<vector<int>>> dict;

        for(int i=1; i<=target; ++i) {
            for (auto &c : candidates) {
                if (c == i) dict[i].insert({c});
                else if (i > c) {
                    for (auto tv : dict[i-c]) { //objects stored in set are constant objects
                        tv.push_back(c);
                        sort(tv.begin(), tv.end());
                        dict[i].insert(tv);
                    }
                }
            } 
        }

        vector<vector<int>> ret;
        for ( auto &it : dict[target]) ret.push_back(it);
        return ret;
    }
};

TEST_CASE("Doctest cases")
{
    Solution sol;

    vector<int> candidates;
    int target;

    candidates = {2,3,6,7};
    target = 7;
    CHECK(sol.combinationSum_dfs(candidates, target) == vector<vector<int>>{{2,2,3},{7}});

    candidates = {2,3,5};
    target = 8;
    CHECK(sol.combinationSum_dfs(candidates, target) == vector<vector<int>>{{2,2,2,2},{2,3,3},{3,5}});

    candidates = {2};
    target = 1;
    CHECK(sol.combinationSum_dfs(candidates, target) == vector<vector<int>>{});
}
