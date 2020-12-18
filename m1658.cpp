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
https://leetcode-cn.com/problems/minimum-operations-to-reduce-x-to-zero/
*/

class Solution {
public:
    int minOperations_pre_suffix(vector<int>& nums, int x) {
        unordered_map<int, int> prefixdict;
        unordered_map<int, int> suffixdict;

        int psum = 0;
        int ssum = 0;
        prefixdict[psum] = 0;
        suffixdict[psum] = 0;
        for (int i = 0; i < nums.size(); ++i) {
            psum += nums[i];
            ssum += nums[nums.size()-1-i];
            if (psum <= x) prefixdict[psum] = i+1;
            if (ssum <= x) suffixdict[psum] = i+1;
        }

        int ret = INT_MAX;
        for ( auto &[k, v] : prefixdict) {
            if (suffixdict.count(x-k) && (v + suffixdict[x-k] <= nums.size())) {
                ret = min(ret, v + suffixdict[x-k]);
            }
        }

        return (ret == INT_MAX) ? -1:ret;
    }

    int minOperations(vector<int>& nums, int x) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int y = sum - x;
        int n = nums.size();

        int ret = -1;

        int left = 0, right = 0;
        int curs = 0;
        while(left < n) {
            if (right < n) curs += nums[right++];
            while (left < n && curs > y) curs -= nums[left++];
            if (curs == y) ret = max(ret, right-left);
            if (right == n) left++;
        }

        return ret == -1 ? -1 : n - ret;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    vector<int> nums;

    nums={1,1,4,2,3};
    LOG(s.minOperations(nums, 5));

    nums={5,6,7,8,9};
    LOG(s.minOperations(nums, 4));

    nums={3,2,20,1,1,3};
    LOG(s.minOperations(nums, 10));

    nums={1,1};
    LOG(s.minOperations(nums, 3));


    return 0;
}
