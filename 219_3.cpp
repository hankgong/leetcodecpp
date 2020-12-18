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

*/

class Solution {
public:
    int stoneGameVII(vector<int>& stones) {
        vector<vector<int>>dp(stones.size(), vector<int>(stones.size(),0));
        vector<int>sums(stones.size() + 1, 0);
        for(int i = 0;i < stones.size();++i)
            sums[i + 1] = sums[i] + stones[i];
        for(int i = dp.size() - 2;i >= 0;--i){
            for(int j = i + 1;j < dp[i].size();++j){
                dp[i][j] = max(sums[j + 1] - sums[i + 1] - dp[i + 1][j], sums[j] - sums[i] - dp[i][j - 1]);
                LLOG(i, j, dp);
            }

        }
        return dp.front().back();
    }

    int stoneGameVII_gametheory(vector<int>& stones) {
        int n = stones.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int i = 1; i < n; ++i) {
            for(int j=i; j < n; ++j) {
                int a = j-i;
                int b = j;

                if (a+1==b) {
                    dp[a][b] = max(stones[a], stones[b]);
                } else if (a+2==b) {
                    if (stones[a] < stones[b]) {
                        dp[a][b] = min(stones[b], stones[b-1]);
                    } else {
                        dp[a][b] = min(stones[a], stones[a+1]);
                    }
                } else {
                    int selectB = min(stones[a]+dp[a+1][b-1], stones[b-1]+dp[a][b-2]);
                    int selectA = min(stones[a+1]+dp[a+2][b], stones[b]+dp[a+1][b-1]);
                    dp[a][b] = max(selectA, selectB);
                }
                LLOG(i, j, a, b, dp);
            }
        }

        return dp[0][n-1];
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    vector<int> stones;

    stones={5,3,1,4,2};
    LOG(s.stoneGameVII(stones));


    return 0;
}
