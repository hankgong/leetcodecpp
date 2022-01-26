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
https://leetcode-cn.com/contest/weekly-contest-212/problems/slowest-key/
*/

class Solution {
public:
    char slowestKey(vector<int>& R, string K) {
        R.insert(R.begin(), 0);

        int curMax = -1;
        int curChr = 0;
        for (int i = 1; i < R.size(); ++i) {
            LLOG(R[i] - R[i - 1], K[i - 1]);
            if (R[i] - R[i - 1] > curMax) {
                curChr = K[i - 1];
                curMax = R[i] -  R[i - 1];
            } else if (R[i] - R[i - 1] == curMax && K[i - 1] > curChr ) {
                curChr = K[i - 1];
                curMax = R[i] -  R[i - 1];
            }
        }
        return curChr;
    }
};

TEST_CASE("testing the factorial function")
{
    Solution s;
    vector<int> v;

    v = {9, 29, 49, 50};
    CHECK(s.slowestKey(v, "cbcd"));

    v = {12, 23, 36, 46, 62};
    CHECK(s.slowestKey(v, "spuda"));
}


TEST_CASE("another test")
{
    Solution s;
    vector<int> v;

    v = {9, 29, 49, 50};
    CHECK(s.slowestKey(v, "cbcd"));

    v = {12, 23, 36, 46, 62};
    CHECK(s.slowestKey(v, "spuda"));
}