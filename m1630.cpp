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
#include <typeinfo>
#include "hutility.hpp"

using namespace std;

#define println(msg) cout << (msg) << endl
#define println2(m1, m2) cout << (m1) << " " << (m2) << endl
#define println3(m1, m2, m3) cout << (m1) << " " << (m2) << " " << (m3) << endl
#define println4(m1, m2, m3, m4) cout << (m1) << " " << (m2) << " " << (m3) << " " << (m4) << endl
#define println5(m1, m2, m3, m4, m5) cout << (m1) << " " << (m2) << " " << (m3) << " " << (m4) << " " << (m5)<< endl


/**
https://leetcode-cn.com/contest/weekly-contest-212/problems/arithmetic-subarrays/
*/

class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int m = l.size();

        vector<bool> ret;
        for (int i = 0; i < m; ++i) {
            vector<int> nn = vector<int>(nums.begin() + l[i], nums.begin() + r[i] + 1);
            println(nn);
            if (nn.size() <= 2) {
                ret.push_back(true);
            } else {
                sort(nn.begin(), nn.end());
                int del = nn[1] - nn[0];
                bool ok = true;
                for (int j = 0; j < nn.size() - 1; ++j) {
                    if (nn[j + 1] - nn[j] != del) {
                        ok = false;
                        break;
                    }
                }
                ret.push_back(ok);
            }

        }

        return ret;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    vector<int> n, l, r;

    n = {4, 6, 5, 9, 3, 7};
    l = {0, 0, 2};
    r = {2, 3, 5};
    println(s.checkArithmeticSubarrays(n, l, r));

    n = { -12, -9, -3, -12, -6, 15, 20, -25, -20, -15, -10};
    l = {0, 1, 6, 4, 8, 7};
    r = {4, 4, 9, 7, 9, 10};
    println(s.checkArithmeticSubarrays(n, l, r));

    return 0;
}
