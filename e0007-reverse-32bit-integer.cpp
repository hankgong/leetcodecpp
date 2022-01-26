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
#include <unordered_set>
#include <assert.h>
#include "hutility.hpp"
#include <climits>

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
https://leetcode.com/problems/reverse-integer/
*/

class Solution {
public:
    int reverse(int x) {
        long ret = 0;

        while (x!=0) {
            int n = x%10;
            x=x/10;

            if (ret<INT_MIN/10 || (ret==INT_MIN/10 && n<-8)) return 0;
            if (ret>INT_MAX/10 || (ret==INT_MAX/10 && n> 7)) return 0;

            ret = ret*10+n;
        }

        return ret;
    }

    int reverse_mine(int x) {
        if (x == INT_MIN) return 0;
        bool neg = (x<0)? true:false;
        x = (neg == true)? -x:x;

        cout << INT_MIN << " " << INT_MAX << endl;

        long ret = 0;
        while (x != 0) {
            int d = x % 10;
            x = x/10;
            
            ret = 10*ret + d;
        }

        if ((neg == true && -ret < -pow(2, 31)) || (neg == false && ret > pow(2, 31) -1)) {
            return 0;
        } else {
            return (neg == true)?-ret:ret;
        }
    }
};

TEST_CASE("testing the factorial function")
{
    Solution sol;
    CHECK(sol.reverse(1534236469) == 0);
    CHECK(sol.reverse(-2147483648) == 0);
    CHECK(sol.reverse(-321) == -123);
}
