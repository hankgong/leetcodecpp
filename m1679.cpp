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
https://leetcode-cn.com/problems/max-number-of-k-sum-pairs/
*/

class Solution {
public:
    int maxOperations_doublepointer(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ret=0;
        int l=0, r=nums.size()-1;
        while(l<r) {
            if(nums[l]+nums[r]>k) {
                --r;
            } else if(nums[l]+nums[r]<k) {
                ++l;
            } else {
                ++l;
                --r;
                ++ret;
            }
        }
        return ret;
    }

    int maxOperations(vector<int>& nums, int k) {
        int ret = 0;
        unordered_map<int,int> nm;

        for (int i = 0; i < nums.size(); ++i) {
            if (nm.count(k-nums[i]) && nm[k-nums[i]]>0) {
                ret++;
                nm[k-nums[i]]--;
            } else {
                nm[nums[i]]++;
            }

            LLOG(nm);
            // if (nm.count(k-nums[i])) {
            //     if(nums[i] != k-nums[i] && nm[nums[i]]>0 && nm[k-nums[i]]>0) {
            //         ret++;
            //         nm[nums[i]]--;
            //         nm[k-nums[i]]--;
            //     }
            //     if(nums[i] == k-nums[i] && nm[nums[i]]>1) {
            //         ret++;
            //         nm[nums[i]]-=2;
            //     }
            // }            
        }
        return ret;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    vector<int> nums;

    nums={1,2,3,4};
    LOG(s.maxOperations(nums, 5));

    nums={3,1,3,4,3};
    LOG(s.maxOperations(nums, 6));

    return 0;
}
