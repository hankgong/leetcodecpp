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
https://leetcode.com/problems/spiral-matrix-ii/
*/

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ret;
        for (int i = 0; i < n; ++i) {
            ret.push_back(vector<int>(n, 0));
        }

        vector<vector<int>> ops = {{0, 1}, {1, 0}, {0, -1}, { -1, 0}};
        int curOps = 0;

        int cnt = 0;
        int i = 0, j = 0;
        while (cnt < n * n) {
            // println5(i, j, curOps, ops[curOps % 4][0], ops[curOps % 4][1]);
            ret[i][j] = cnt + 1;
            cnt++;
            int ti = i + ops[curOps % 4][0];
            int tj = j + ops[curOps % 4][1];
            if (ti < 0 || ti >= n || tj < 0 || tj >= n || ret[ti][tj] != 0 ) {
                curOps++;
            }
            i += ops[curOps % 4][0];
            j += ops[curOps % 4][1];
        }
        return ret;
    }
};

TEST_CASE("test results")
{
    Solution sol;
    CHECK(sol.generateMatrix(1) == vector<vector<int>>{{1}});
    CHECK(sol.generateMatrix(2) == vector<vector<int>>{{1, 2}, {4, 3}});
    CHECK(sol.generateMatrix(3) == vector<vector<int>>{{1, 2, 3}, {8, 9, 4}, {7, 6, 5}});
    CHECK(sol.generateMatrix(5) == vector<vector<int>>{{1, 2, 3, 4, 5}, {16, 17, 18, 19, 6}, {15, 24, 25, 20, 7}, {14, 23, 22, 21, 8}, {13, 12, 11, 10, 9}});
}
