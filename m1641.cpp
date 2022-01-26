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
https://leetcode-cn.com/problems/count-sorted-vowel-strings/
*/

class Solution {
public:
    int countVowelStrings(int n) {
        vector<int> dp(5, 1);

        for(int i=0; i<n; ++i) {
            dp[0]=dp[0]+dp[1]+dp[2]+dp[3]+dp[4];
            dp[1]=dp[1]+dp[2]+dp[3]+dp[4];
            dp[2]=dp[2]+dp[3]+dp[4];
            dp[3]=dp[3]+dp[4];
            dp[4]=dp[4];            
        }
        
        return dp[0];
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;

    LOG(sol.countVowelStrings(1));
    LOG(sol.countVowelStrings(2));
    LOG(sol.countVowelStrings(33));
    LOG(sol.countVowelStrings(50));


    return 0;
}
