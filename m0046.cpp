#include <iostream>
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

#define println(msg) cout << (msg) << endl
#define println2(m1, m2) cout << (m1) << " " << (m2) << endl
#define println3(m1, m2, m3) cout << (m1) << " " << (m2) << " " << (m3) << endl
#define println4(m1, m2, m3, m4) cout << (m1) << " " << (m2) << " " << (m3) << " " << (m4) << endl
#define println5(m1, m2, m3, m4, m5) cout << (m1) << " " << (m2) << " " << (m3) << " " << (m4) << " " << (m5)<< endl


/**
https://leetcode-cn.com/problems/permutations/
*/

class Solution {
public:
    vector<vector<int>> permute_dfs(vector<int>& nums) {
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

int main(int argc, char const *argv[])
{
    Solution s;

    vector<int> v;
    v = {1, 2, 3};
    s.permute(v);

    return 0;
}
