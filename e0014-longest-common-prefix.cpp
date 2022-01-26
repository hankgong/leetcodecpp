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
https://leetcode.com/problems/longest-common-prefix/
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) {
            return "";
        }

        LOG(strs);

        string ret = "";
        for (int i = 0; i < strs[0].size(); i++) {
            for (int j = 1; j < strs.size(); j++) {
                if (strs[j][i] != strs[0][i]) {
                    return ret;
                }
                // if (strs[j].substr(0, i+1) != strs[0].substr(0, i+1)) {
                //     // return strs[0].substr(0, i);
                //     return ret;
                // }
            }
            ret = strs[0].substr(0, i + 1);
        }

        return ret;
    }
};

TEST_CASE("testing the factorial function")
{
    Solution sol;

    vector<string> v;
    v = {"flower", "flow", "flight"};
    CHECK(sol.longestCommonPrefix(v) == "fl");

    v = {"flower", "flower", "flower"};
    CHECK(sol.longestCommonPrefix(v) == "flower");

    v = {"", "flower", "flower"};
    CHECK(sol.longestCommonPrefix(v) == "");

    v =  {"dog", "racecar", "car"};
    CHECK(sol.longestCommonPrefix(v) == "");
}
