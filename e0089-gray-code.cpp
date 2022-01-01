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

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

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

#define LLOG(...) cout<<"L"<<std::left<<setw(4)<<__LINE__;LOG(__VA_ARGS__)
#else
#define LOG(...) do {} while(0)
#define LLOG(...) do {} while(0)
#endif

/**
https://leetcode.com/problems/gray-code/
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

TEST_CASE("test results")
{
    Solution sol;
    CHECK(sol.grayCode(1) == vector<int>{0, 1});
    CHECK(sol.grayCode(2) == vector<int>{0, 1, 3, 2});
}
