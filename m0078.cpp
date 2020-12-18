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

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> v;
    v = {1, 2, 3};
    println(s.subsets(v));

    return 0;
}
