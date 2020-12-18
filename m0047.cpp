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
https://leetcode-cn.com/problems/permutations-ii/
*/

class Solution {
public:
    vector<vector<int>> permuteUnique_dfs1(vector<int>& nums) {
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

int main(int argc, char const *argv[])
{
    Solution s;


    return 0;
}
