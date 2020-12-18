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
https://leetcode-cn.com/problems/missing-number/
*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
        }
        return n * (n + 1) / 2 - sum;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    vector<int> nums;

    nums = {3, 0, 1};
    LOG(s.missingNumber(nums));

    nums = {0, 1};
    LOG(s.missingNumber(nums));

    nums = {9, 6, 4, 2, 3, 5, 7, 0, 1};
    LOG(s.missingNumber(nums));

    nums = {0};
    LOG(s.missingNumber(nums));


    return 0;
}
