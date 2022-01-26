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
https://leetcode-cn.com/problems/valid-parentheses/
*/

class Solution {
public:
    bool isValid(string s) {
        stack<char> ss;

        for (auto &c : s) {
            if (c == '[' || c== '{' || c=='(') {
                ss.push(c);
            } else {
                if (ss.empty()) return false;
                if (c == ']' && ss.top() != '[') return false; 
                if (c == '}' && ss.top() != '{') return false; 
                if (c == ')' && ss.top() != '(') return false; 
                ss.pop();
            }

        }

        return ss.empty();
    }
};

TEST_CASE("testing the factorial function")
{
    Solution sol;
    CHECK(sol.isValid("()") == true);
    CHECK(sol.isValid("()[]{}") == true);
    CHECK(sol.isValid("(]") == false);
    CHECK(sol.isValid("([)]") == false);
    CHECK(sol.isValid("{[]}") == true);
    CHECK(sol.isValid("]") == false);
}
