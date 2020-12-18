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

// Author: Huahua
class Solution {
public:
  int minimumIncompatibility(vector<int>& nums, int k) {
    const int n = nums.size(); 
    const int c = n / k;
    int dp[1 << 16][16];
    // memset(dp, 0x7f, sizeof(dp));
    memset(dp, 1, sizeof(dp));
    for (int i = 0; i < n; ++i) dp[1 << i][i] = 0;
    for (int s = 0; s < 1 << n; ++s)
      for (int i = 0; i < n; ++i) {
        if ((s & (1 << i)) == 0) continue;
        for (int j = 0; j < n; ++j) {
          if ((s & (1 << j))) continue;
          const int t = s | (1 << j);
          if (__builtin_popcount(s) % c == 0) {
            dp[t][j] = min(dp[t][j], dp[s][i]);
          } else if (nums[j] > nums[i]) {           
            dp[t][j] = min(dp[t][j], 
                           dp[s][i] + nums[j] - nums[i]);            
          }
          cout << s<< " " <<i<< " "<<j <<"------------------------" << endl;
          for(int s=0; s<(1<<n); ++s) {
            for (int j=0; j<n; ++j) {
                cout <<dp[s][j]<<", ";
            }
            cout << endl;
          }
        }        
    }
    int ans = *min_element(begin(dp[(1 << n) - 1]), 
                           end(dp[(1 << n) - 1]));
    return ans > 1e9 ? - 1 : ans;
  }
};

int main(int argc, char const *argv[])
{
    Solution s;

    vector<int> nums;
    nums={1,2,1,4};
    LOG(s.minimumIncompatibility(nums, 2));

    // nums={6,3,8,1,3,1,2,2};
    // LOG(s.minimumIncompatibility(nums, 4));


    return 0;
}
