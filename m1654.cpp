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
https://leetcode-cn.com/problems/minimum-jumps-to-reach-home/
*/

class Solution {
public:
    int minimumJumps_bfs(vector<int>& forbidden, int a, int b, int x) {
        const int kMaxPosition = 6000;
        if (x == 0) return 0;

        int steps = 0;
        queue<pair<int, bool>> q{{{0, false}}};

        unordered_set<int> visa(forbidden.begin(), forbidden.end());
        unordered_set<int> visb(forbidden.begin(), forbidden.end());

        visa.insert(0);
        while (!q.empty()) {
            int size = q.size();

            while (size--) {
                auto [curpos, fwd] = q.front(); q.pop();

                if (curpos == x) return steps;
                if (curpos > kMaxPosition) continue; //why continue not break? because it just means current search not good, others in the queue might still good

                if (visa.insert(curpos + a).second) //if you want to use this, put this at the end of the conditions
                    q.emplace(curpos + a, true);

                if (curpos - b > 0 && fwd && visb.insert(curpos - b).second)
                    q.emplace(curpos - b, false);
            }

            ++steps;
        }

        return -1;
    }

    int minimumJumps_dfs(vector<int>& forbidden, int a, int b, int x) {
        const int kMaxPosition = 6000;
        if (x==0) return 0;

        int ret = INT_MAX;

        set<int> visa(forbidden.begin(), forbidden.end());
        set<int> visb(forbidden.begin(), forbidden.end());

        visa.insert(0);

        function<void(int, int, int)> dfs = [&](int num, int cnt, bool fwd) {
            // LLOG(cnt, num);
            if (num == x) {
                ret = min(cnt, ret);
                return;
            }

            if (num > kMaxPosition) return;

            if (visa.insert(num+a).second) {
                dfs(num + a, cnt + 1, true);
            }

            // combined as one vis logic 
            // if (num-b>0 && !visa.count(num-b) && && fwd) {
            if (num-b>0 && fwd && visb.insert(num-b).second) {
                dfs(num - b, cnt + 1, false);
            }

        };

        dfs(0, 0, true);
        return (ret == INT_MAX? -1: ret);
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    vector<int> forbidden;

    // forbidden = {};
    // LOG(s.minimumJumps_dfs(forbidden, 3, 1, 4));

    // vector<int> forbidden;

    // forbidden={14,5,18,1};
    // LOG(s.minimumJumps_dfs(forbidden, 4, 5, 15));

    // forbidden={8,3,16,6,12,20};
    // LOG(s.minimumJumps(forbidden, 15, 13, 11));

    // forbidden={1,6,2,14,5,17,4, 25};
    // LOG(s.minimumJumps(forbidden, 16, 9, 7));

    forbidden = {162, 118, 178, 152, 167, 100, 40, 74, 199, 186, 26, 73, 200, 127, 30, 124, 193, 84, 184, 36, 103, 149, 153, 9, 54, 154, 133, 95, 45, 198, 79, 157, 64, 122, 59, 71, 48, 177, 82, 35, 14, 176, 16, 108, 111, 6, 168, 31, 134, 164, 136, 72, 98};
    LOG(s.minimumJumps_dfs(forbidden, 29, 98, 80));


    return 0;
}
