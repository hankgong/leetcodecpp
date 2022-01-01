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
https://leetcode-cn.com/problems/pascals-triangle/
*/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows == 0) return {};
        if (numRows == 1) return {{1}};

        vector<vector<int>> ret = {{1}};

        for (int i = 1; i < numRows; ++i) {
            vector<int> lastRow = ret.back();
            lastRow.insert(lastRow.begin(), 0);
            lastRow.push_back(0);

            vector<int> toadd;
            for (int i = 0; i < lastRow.size()-1; ++i) {
                toadd.push_back(lastRow[i]+lastRow[i+1]);
            }
            ret.push_back(toadd);
        }

        return ret;
    }
};

TEST_CASE("test results")
{
    Solution sol;

    CHECK(sol.generate(1) == vector<vector<int>>{{1}});
    CHECK(sol.generate(2) == vector<vector<int>>{{1}, {1, 1}});
    CHECK(sol.generate(3) == vector<vector<int>>{{1}, {1, 1}, {1, 2, 1}});
    CHECK(sol.generate(4) == vector<vector<int>>{{1}, {1, 1}, {1, 2, 1}, {1, 3, 3, 1}});
}
