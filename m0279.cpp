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
#include "hutility.hpp"

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
https://leetcode-cn.com/problems/perfect-squares/
*/

class Solution {
public:
    int numSquares(int n) {
        vector<int> sqrNums;

        for (int i = 1; i <= sqrt(n); ++i) {
            sqrNums.push_back(i*i);
        }

        vector<int> dp(n+1, n);
        dp[0] = 0;

        for (int i = 1; i <= n; ++i) {
            for(int j=0; j<sqrNums.size(); ++j) {
                if (sqrNums[j] <= i) {
                    dp[i] = min(dp[i-sqrNums[j]]+1, dp[i]);
                } else {
                    break;
                }
            }
        }

        return dp[n];
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    LOG(s.numSquares(1));
    LOG(s.numSquares(2));
    LOG(s.numSquares(12));
    LOG(s.numSquares(13));


    return 0;
}
