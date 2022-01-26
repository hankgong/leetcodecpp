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

#define LLOG(...) cout<<"L"<<std::left<<setw(4)<<__LINE__;LOG(__VA_ARGS__)
#else
#define LOG(...) do {} while(0)
#define LLOG(...) do {} while(0)
#endif

/**
https://leetcode-cn.com/problems/ways-to-split-array-into-three-subarrays/
*/

class Solution {
public:
    int waysToSplit(vector<int>& nums) {
        vector<int> psum;
        int n = nums.size();

        int tsum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            tsum += nums[i];
            psum.push_back(tsum);
        }

        long long ans = 0;
        for(int i=0; i<nums.size(); ++i) {
            if (psum[i]*3>tsum) break;

            //binary search from here
            int left = i+1, right = n-1;

            //right boundary
            while(left<right){
                int mid = left + (right-left+1)/2;

                if (psum[mid]-psum[i] > psum[n-1]-psum[mid]) {
                    right = mid-1;
                } else {
                    left = mid;
                }
            }

            //left boundary
            int ll = i+1, rr = n-1;
            while(ll<rr) {
                int mid = ll + (rr-ll)/2;

                if (psum[mid]-psum[i] < psum[i]) {
                    ll = mid+1;
                } else {
                    rr = mid;
                }
            }

            LLOG(i, ll, left);
            if (left>=ll) ans += (left-ll+1);
        }
        return ans % (int)(1e9+7);
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;

    vector<int> nums;

    nums={1,2,2,2,5,0};
    LOG(sol.waysToSplit(nums));

    nums={3,2,1};
    LOG(sol.waysToSplit(nums));

    nums={1,1,1};
    LOG(sol.waysToSplit(nums));


    return 0;
}
