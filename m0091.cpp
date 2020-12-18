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
https://leetcode-cn.com/problems/decode-ways/
*/

class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp;
        dp.resize(s.size()+1);

        dp[0] = 1;
        dp[1] = 1*(s[0] == '0' ? 0:1);

        for(int i=1; i<s.size(); ++i) {
            int t1 = stoi(s.substr(i, 1));
            int t2 = stoi(s.substr(i-1, 2));
            bool hasZero = (s[i-1] == '0');
            dp[i+1] = dp[i]*(t1>0?1:0) + dp[i-1]*((t2<= 26 && t2>0 && !hasZero) ? 1 : 0); 
        }
        return dp[s.size()];
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    LOG(s.numDecodings("12"));
    LOG(s.numDecodings("226"));
    LOG(s.numDecodings("227"));
    LOG(s.numDecodings("0"));
    LOG(s.numDecodings("1"));
    LOG(s.numDecodings("2101"));


    return 0;
}
