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
https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
*/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ret;

        int l = 0, r = nums.size() -1 ;

        // while (l < r) {
        //     int m = l + (r-l)/2;

        //     if (nums[m] <= target) {
        //         l = m + 1;
        //     } else {
        //         r = m;
        //     }
        // }

        while (l < r) {
            int m = l + (r-l+1)/2;

            if (nums[m]>=target) {
                r = m - 1;
            } else {
                l = m;
            }
        }

        LOG(l, r);
        return ret;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    vector<int> nums;

    nums={5,7,7,8,8,10};
    LOG(s.searchRange(nums, 8));


    return 0;
}
