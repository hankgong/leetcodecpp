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

#define LLOG(...) cout<<"L"<<std::left<<setw(4)<<__LINE__;LOG(__VA_ARGS__)
#else
#define LOG(...) do {} while(0)
#define LLOG(...) do {} while(0)
#endif


/**
https://leetcode.com/problems/remove-duplicates-from-sorted-array/
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        int idx = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[idx - 1] != nums[i]) {
                nums[idx++] = nums[i];
            }
        }
        return idx;
    }
};

TEST_CASE("test results")
{
    Solution sol;
    vector<int> v;
    v = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    CHECK(sol.removeDuplicates(v) == 5);
    CHECK(v == vector<int>{0, 1, 2, 3, 4, 2, 2, 3, 3, 4});

    v = {0};
    CHECK(sol.removeDuplicates(v) == 1);
    CHECK(v == vector<int>{0});

    v = {};
    CHECK(sol.removeDuplicates(v) == 0);
    CHECK(v == vector<int>{});

    v = {1, 2, 3};
    CHECK(sol.removeDuplicates(v) == 3);
    CHECK(v == vector<int>{1, 2, 3}); 
}
