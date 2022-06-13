#define DEBUG
#include "hutility.hpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using namespace std;

/**
https://leetcode.com/problems/minimum-jumps-to-reach-home/
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

TEST_CASE("Doctest cases")
{
    Solution sol;

    vector<int> forbidden;
    int a;
    int b;
    int x;

    forbidden = {14,4,18,1,15};
    a = 3;
    b = 15;
    x = 9;
    CHECK(sol.minimumJumps_bfs(forbidden, a, b, x) == 3);

    forbidden = {8,3,16,6,12,20};
    a = 15;
    b = 13;
    x = 11;
    CHECK(sol.minimumJumps_bfs(forbidden, a, b, x) == -1);

    forbidden = {1,6,2,14,5,17,4};
    a = 16;
    b = 9;
    x = 7;
    CHECK(sol.minimumJumps_bfs(forbidden, a, b, x) == 2);

    forbidden = {162, 118, 178, 152, 167, 100, 40, 74, 199, 186, 26, 73, 200, 127, 30, 124, 193, 84, 184, 36, 103, 149, 153, 9, 54, 154, 133, 95, 45, 198, 79, 157, 64, 122, 59, 71, 48, 177, 82, 35, 14, 176, 16, 108, 111, 6, 168, 31, 134, 164, 136, 72, 98};
    LOG(sol.minimumJumps_dfs(forbidden, 29, 98, 80));
}
