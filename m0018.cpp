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
https://leetcode-cn.com/problems/4sum/
*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret;

        for (int i = 0; i < n-3; ++i) {
            if (i>0 && nums[i]==nums[i-1]) continue;
            for(int j=i+1; j<n-2; ++j) {
                if (j>i+1 && nums[j] == nums[j-1]) continue;
                int l=j+1, r = n-1;
                int t = target-nums[i]-nums[j];
                
                while (l < r) {
                    int c = nums[l] + nums[r];
                                        
                    if (c < t) {
                        l++;
                    } else if (c>t) {
                        r--;
                    } else {
                        ret.push_back({nums[i], nums[j], nums[l], nums[r]});
                        while (l<r && nums[l]==nums[++l]);
                        while (l<r && nums[r]==nums[--r]);
                    }
                }
            }
        }
        return ret;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    nums={-2,-1,-1,1,1,2,2};
    LOG(s.fourSum(nums, 0));

    return 0;
}
