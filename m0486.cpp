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
https://leetcode-cn.com/problems/predict-the-winner/
*/

class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        dp[n-1][n-1]=nums[n-1];
        for(int i=0; i<n; ++i) dp[i][i]=nums[i];

        for(int i=n-2; i>=0; --i) {
            for(int j=i+1; j<n; ++j) {
                LLOG(dp, i, j, nums[i]-dp[i+1][j], nums[j]-dp[i][j-1]);
                dp[i][j] = max(nums[i]-dp[i+1][j], nums[j]-dp[i][j-1]);
            }
        }
        return (dp.front().back()>=0);
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    vector<int> nums;

    nums= {1, 5, 20, 7};
    LOG(s.PredictTheWinner(nums));


    return 0;
}
