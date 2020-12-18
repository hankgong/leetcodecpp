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
https://leetcode-cn.com/problems/combination-sum-ii/
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

int main(int argc, char const *argv[])
{
    Solution s;

    vector<int> candidates;

    candidates={10,1,2,7,6,1,5};
    LOG(s.combinationSum2(candidates, 8));


    return 0;
}
