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
执行用时：
0 ms
, 在所有 C++ 提交中击败了
100.00%
的用户
内存消耗：
6.4 MB
, 在所有 C++ 提交中击败了
71.03%
的用户
*/

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ret = {0};

        for (int i = 0; i < n; ++i) {
            int l = ret.size();
            // println3(ret, i, 1 << i);
            for (int j = 0; j < l; ++j) {
                ret.push_back((1 << i) + ret[l - 1 - j]);
            }
        }
        return ret;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    println(s.grayCode(1));
    println(s.grayCode(2));

    return 0;
}
