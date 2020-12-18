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
https://leetcode-cn.com/contest/biweekly-contest-38/problems/widest-vertical-area-between-two-points-containing-no-points/
*/

class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& ps) {
        vector<int> xs;
        for (int i = 0; i < ps.size(); ++i) {
            xs.push_back(ps[i][0]);
        }

        sort(xs.begin(), xs.end());

        int ret = 0;
        for (int i = 0; i < xs.size() - 1; ++i) {
            ret = max(ret, xs[i + 1] - xs[i]);
        }

        return ret;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<vector<int>> v;
    v = {{8, 7}, {9, 9}, {7, 4}, {9, 7}};

    println(s.maxWidthOfVerticalArea(v));

    v =  {{3, 1}, {9, 0}, {1, 0}, {1, 4}, {5, 3}, {8, 8}};
    println(s.maxWidthOfVerticalArea(v));

    return 0;
}
