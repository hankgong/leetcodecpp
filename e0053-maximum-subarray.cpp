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

#define LLOG(...) cout<<"L"<<left<<setw(4)<<__LINE__;LOG(__VA_ARGS__)
#else
#define LOG(...) do {} while(0)
#define LLOG(...) do {} while(0)
#endif

/**
https://leetcode.com/problems/maximum-subarray/
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);

        dp[0] = nums[0];
        int ret = nums[0];

        for(int i=1; i<n; ++i) {
            dp[i] = max(dp[i-1]+nums[i], nums[i]);
            ret = max(ret, dp[i]);
        }

        return ret;
    }

    int maxSubArray_official(vector<int>& nums) {
        int pre=0, maxAns = nums[0];

        for(auto &x: nums) {
            LLOG(x, pre, pre+x);
            pre = max(pre+x, x);
            maxAns = max(maxAns, pre);
        }

        return maxAns;
    }
};

TEST_CASE("test results")
{
    Solution sol;

    vector<int> nums;

    nums={-2,1,-3,4,-1,2,1,-5,4};
    CHECK(sol.maxSubArray(nums) == 6);
}