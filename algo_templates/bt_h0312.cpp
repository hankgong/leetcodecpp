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

*/

class Solution {
public:
     int maxCoins(vector<int>& nums) {
        vector<int> a(nums.size()+2, 1);

        for(int i = 0; i < nums.size(); i++){
            a[i+1] = nums[i];
        }

        vector<vector<int>> vis(a.size(), vector<int>(a.size(), 0));

        return helper(a, 0, a.size()-1, vis);
    }

    int helper(vector<int> & a, int i, int j, vector<vector<int>>& memo){
        // 如果记忆有，直接返回
        LLOG(i, j);
        if(memo[i][j] != 0){
            return memo[i][j];
        }
        
        int ret = 0;
        for(int k = i+1; k < j; k++){
            ret = max(ret, helper(a, i, k, memo) + a[i] * a[k] * a[j] + helper(a, k, j, memo));
        }
        
        // 记忆
        return memo[i][j] = ret;
    }

};

int main(int argc, char const *argv[])
{
    Solution s;

    vector<int> nums;

    nums={3,1,5,8};
    LOG(s.maxCoins(nums));


    return 0;
}
