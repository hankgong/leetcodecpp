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
#include "../hutility.hpp"

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
https://leetcode-cn.com/problems/permutations/
*/

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        const int N = nums.size();
        vector<vector<int>> res;

        vector<int> path;
        vector<int> vis(N, 0);
        dfs(nums, 0, vis, res, path);

        return res;
    }

    void dfs(vector<int>& nums, int pos, vector<int>& vis, vector<vector<int>>& res, vector<int>& path) {
        const int N = nums.size();
        LLOG(path, vis);
        if (pos == N) {
            res.push_back(path);
            return;
        }

        for (int i = 0; i < N; ++i) {
            if (!vis[i]) {
                vis[i] = 1;
                path.push_back(nums[i]);
                dfs(nums, pos+1, vis, res, path);
                path.pop_back();
                vis[i] = 0;
            }
        }
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    vector<int> nums;

    nums= {1, 2, 4};
    LOG(s.permute(nums));


    return 0;
}
