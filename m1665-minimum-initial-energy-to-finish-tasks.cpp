#define DEBUG
#include "hutility.hpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using namespace std;

/**
https://leetcode.com/problems/minimum-initial-energy-to-finish-tasks/
*/

class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), [](const auto&u, const auto& v) {
            return u[1]-u[0]>v[1]-v[0];
        });

        function<bool(int k)> isOK = [&](int k) {
            for (auto & t: tasks) {
                if (k<t[1]) return false;
                k -= t[0];
            }
            return true;
        };

        int l=0, r=2e9;
        while(l<r) {
            int mid = l+(r-l)/2;

            if (isOK(mid))
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }

    int minimumEffort_sort_greedy(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), [](const auto& u, const auto& v) {
            return u[1] - u[0] > v[1] - v[0];
        });

        int p = 0;
        int suma = 0;
        for(const auto& t: tasks) {
            p = max(p, suma+t[1]);
            suma += t[0];
        }
        return p;
    }

    int minimumEffort_pq(vector<vector<int>>& tasks) {
        priority_queue<task> q;

        for(auto t:tasks) {
            task tmp(t[0], t[1]);
            q.push(tmp);
        }

        int ret = 0, left=0;
        while(!q.empty()) {
            task t = q.top();
            if (left >= t.m) {
                left -= t.a;
            } else {
                ret += (t.m-left);
                left = t.m - t.a;
            }
            q.pop();
        }
        return ret;
    }

    struct task
    {
        int a, m;
        task(int a, int m) : a(a), m(m){}
        bool operator<(const task& t) const {
            // if (t.m - t.a == m-a) return m < t.m;
            return m-a < t.m-t.a;
        }
    };
};

TEST_CASE("Doctest cases")
{
    Solution sol;

    vector<vector<int>> tasks;

    tasks = {{1,2},{2,4},{4,8}};
    CHECK(sol.minimumEffort(tasks) == 8);

    tasks = {{1,3},{2,4},{10,11},{10,12},{8,9}};
    CHECK(sol.minimumEffort(tasks) == 32);

    tasks = {{1,7},{2,8},{3,9},{4,10},{5,11},{6,12}};
    CHECK(sol.minimumEffort(tasks) == 27);
}
