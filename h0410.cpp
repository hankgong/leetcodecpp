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
https://leetcode-cn.com/problems/split-array-largest-sum/
*/

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int l = 0, r = 0;
        for (int i = 0; i < nums.size(); ++i) {
            r += nums[i];
            l = max(l, nums[i]);
        }

        while (l < r) {
            int mid = l + (r - l) / 2;
            LLOG(l, mid, r);

            int grpLeft = m;
            int curSum = mid;
            for (int i = 0; i < nums.size(); ++i) {
                LLOG(curSum, grpLeft);

                if (curSum - nums[i] < 0) {
                    curSum = mid;
                    --grpLeft;

                }
                curSum -= nums[i];

            }

            LLOG(grpLeft);
            if (grpLeft > 0) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        return l;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> nums;

    nums = {7, 2, 5, 10, 8};
    LOG(s.splitArray(nums, 2));


    return 0;
}
