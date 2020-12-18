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
#include "../hutility.hpp"

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
https://leetcode.com/problems/sqrtx/
*/

class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return 0;
        int l = 1, r = x;

        while (l<r) {
            long m = l + (r-l+1)/2;

            if (m*m > x) {
                r = m -1;
            } else {
                l = m;
            }
        }

        return l;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    LOG(s.mySqrt(4));
    LOG(s.mySqrt(8));
    LOG(s.mySqrt(9));
    LOG(s.mySqrt(0));
    LOG(s.mySqrt(1));
    LOG(s.mySqrt(2));
    LOG(s.mySqrt(3));
    LOG(s.mySqrt(2147395599));


    return 0;
}
