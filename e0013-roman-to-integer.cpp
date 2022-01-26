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
https://leetcode.com/problems/roman-to-integer/
*/

class Solution {
public:
    int romanToInt(string s) {
        map<char, int> roman = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
            {'C', 100}, {'D', 500}, {'M', 1000}
        };

        int ret = 0;
        int i = 0;
        while (i < s.size() - 1) {
            if (roman[s[i]] < roman[s[i + 1]]) {
                ret += roman[s[i + 1]] - roman[s[i]];
                i = i + 2;
            } else {
                ret += roman[s[i]];
                i++;
                // LOG(ret, i, s[i]);
            }
        }

        if (i == s.size() - 1) {
            ret += roman[s[i]];
        }

        return ret;
    }
};

TEST_CASE("testing the factorial function")
{
    Solution sol;
    CHECK(sol.romanToInt("III") == 3);
    CHECK(sol.romanToInt("IV") == 4);
    CHECK(sol.romanToInt("IX") == 9);
    CHECK(sol.romanToInt("LVIII") == 58);
    CHECK(sol.romanToInt("MCMXCIV") == 1994);
}
