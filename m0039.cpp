#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <unordered_set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <climits>
#include "hutility.hpp"

using namespace std;

#define DEBUG
#ifdef DEBUG
void LOG() {cout << endl;}
template<typename Head, typename... Args>
void LOG(const Head& head, const Args&... args )
{
    cout << head << " ";
    LOG(args...);
}

#define LLOG(...) cout<<"L"<<left<<setw(4)<<__LINE__;LOG(__VA_ARGS__)
#else
#define LOG(...) do {} while(0)
#define LLOG(...) do {} while(0)
#endif

/**
https://leetcode-cn.com/problems/combination-sum/
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

int main(int argc, char const *argv[])
{
    Solution s;

    vector<int> candidates;

    candidates={2,3,6,7};
    LOG(s.combinationSum_dp(candidates, 7));

    candidates={2,3,5};
    LOG(s.combinationSum_dp(candidates, 8));


    return 0;
}
