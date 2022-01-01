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

#define LLOG(...) cout<<"L"<<left<<setw(4)<<__LINE__;LOG(__VA_ARGS__)
#else
#define LOG(...) do {} while(0)
#define LLOG(...) do {} while(0)
#endif

/**
https://leetcode-cn.com/problems/plus-one/
*/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int c = 1;
        vector<int> ret;

        for(int i=digits.size()-1; i>=0; --i) {
            digits[i] += c;
            c = digits[i]/10;
            ret.insert(ret.begin(), digits[i]%10);
        }

        if (c) ret.insert(ret.begin(), c);
        return ret;
    }
};

TEST_CASE("test results")
{
    Solution sol;
    vector<int> digits;

    digits= {1, 2, 3};
    CHECK(sol.plusOne(digits) == vector<int>{1, 2, 4});

    digits= {9, 9, 9};
    CHECK(sol.plusOne(digits) == vector<int>{1, 0, 0, 0});

    digits={4,3,2,1};
    CHECK(sol.plusOne(digits) == vector<int>{4, 3, 2, 2});
}
