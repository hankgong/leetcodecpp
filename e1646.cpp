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
https://leetcode-cn.com/contest/weekly-contest-214/problems/get-maximum-in-generated-array/
*/

class Solution {
public:
    int getMaximumGenerated(int n) {
        vector<int> v(101, 0);

        if (n==0) return 0;
        if (n==1) return 1;

        int ret = 1;

        v[0] = 0;
        v[1] = 1;

        for (int i = 2; i<= n; ++i) {
            if (i % 2 == 0) {
                v[i] = v[i/2];
            } else {
                v[i] = v[i/2] + v[i/2+1];
            }
            ret = max(v[i], ret);
        }

        LOG(v);

        return ret;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    // LOG(s.getMaximumGenerated(0));
    // LOG(s.getMaximumGenerated(1));
    // LOG(s.getMaximumGenerated(2));
    // LOG(s.getMaximumGenerated(3));
    // LOG(s.getMaximumGenerated(4));
    // LOG(s.getMaximumGenerated(5));
    // LOG(s.getMaximumGenerated(6));
    LOG(s.getMaximumGenerated(100));


    return 0;
}
