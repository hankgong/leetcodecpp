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
https://leetcode-cn.com/problems/top-k-frequent-elements/
*/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        auto cmp = [](const pair<int, int>&m, pair<int, int>&n) {
            return m.second < n.second;
        };

        unordered_map<int, int> tmap;
        for (auto &v: nums) {
            tmap[v]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> q(cmp);

        // int num, count;
        for (auto e : tmap) {
            if (q.size() == k) {
                if (q.top().second < e.second) {
                    q.pop();
                    q.emplace(e.first, e.second);
                }
            } else {
                q.emplace(e.first, e.second);
            }
        }

        printdata(q);

        vector<int> ret;
        while(!q.empty()) {
            ret.push_back(q.top().first);
            q.pop();
        }
        return ret;
    }

    vector<int> topKFrequent_sort(vector<int>& nums, int k) {
        unordered_map<int, int> m;

        for (int i = 0; i < nums.size(); ++i) {
            ++m[nums[i]];
        }

        sort(nums.begin(), nums.end(), [&](int& x, int& y) {
            return m[x] > m[y] || (m[x] == m[y] && x < y);
        });

        LOG(m, nums);

        vector<int> ret = {nums[0]};
        int j = 0;
        for (int i = 1; i < nums.size(); ++i) {
            if (j<k-1 && ret.back() != nums[i]) {
                ret.push_back(nums[i]);
                ++j;
            }
        }
        return ret;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    vector<int> nums;

    nums={3, 1,1,1,2,2};
    LOG(s.topKFrequent(nums, 2));

    nums={1};
    LOG(s.topKFrequent(nums, 1));

    nums={3,2,3,1,2,4,5,5,6,7,7,8,2,3,1,1,1,10,11,5,6,2,4,7,8,5,6};
    LOG(s.topKFrequent(nums, 10));


    return 0;
}
