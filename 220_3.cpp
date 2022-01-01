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
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n, INT_MIN);

        dp[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            for(int j=1; j<=k; ++j) {
                if (i-j >=0) dp[i]=max(dp[i-j], dp[i]);
                LLOG(i, j);
            }
            dp[i] += nums[i];
            LLOG(dp);
        }

        return dp[n-1];
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;

    vector<int> nums;

    nums={1,-1,-2,4,-7,3};
    LOG(sol.maxResult(nums, 2));

    nums={10,-5,-2,4,0,3};
    LOG(sol.maxResult(nums, 3));

    nums={1,-5,-20,4,-1,3,-6,-3};
    LOG(sol.maxResult(nums, 2));


    return 0;
}
