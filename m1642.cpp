#include <iostream>
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

#define println(msg) cout << (msg) << endl
#define println2(m1, m2) cout << (m1) << " " << (m2) << endl
#define println3(m1, m2, m3) cout << (m1) << " " << (m2) << " " << (m3) << endl
#define println4(m1, m2, m3, m4) cout << (m1) << " " << (m2) << " " << (m3) << " " << (m4) << endl
#define println5(m1, m2, m3, m4, m5) cout << (m1) << " " << (m2) << " " << (m3) << " " << (m4) << " " << (m5)<< endl


/**
https://leetcode.com/problems/furthest-building-you-can-reach/
*/

class Solution_ {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int> pq;

        for (int i = 0; i < heights.size() - 1; ++i) {
            int d = heights[i + 1] - heights[i];

            if (d > 0) pq.push(-d);
            if (pq.size() > ladders) {
                bricks += pq.top();
                pq.pop();
            }

            println(pq);

            if (bricks < 0)
                return i;
        }
        return heights.size() - 1;
    }
};


// brutal force DFS
class Solution {
public:
    int ans = 0;

    void dfs(vector<int>&n, int b, int l, int s) {
        //boundary checking
        if (ans == n.size() - 1) return;
        if (s == n.size() - 1) {
            ans = n.size() - 1;
            return;
        }

        for (int i = s; i < n.size(); ++i) {
            ans = max(ans, i);
            if (n[i] == 0) continue;
            if (n[i] <= b) dfs(n, b - n[i], l, i + 1);
            if (l > 0) dfs(n, b, l - 1, i + 1);
            break;
        }
    };

    int furthestBuilding(vector<int>& H, int B, int L) {
        vector<int> nums;

        for (int i = 0; i < H.size() - 1; ++i) {
            nums.push_back(max(0, H[i + 1] - H[i]));
        }
        nums.push_back(0);
        dfs(nums, B, L, 0);

        return ans;
    }
};


int main(int argc, char const *argv[])
{
    Solution_ s;

    vector<int> v;
    v = {4, 12, 2, 7, 3, 18, 20, 3, 19};

    // priority_queue<int, vector<int>, greater<int>> tq;
    // priority_queue<int> tq;
    // for (int i = 0; i < v.size(); ++i) {
    //     tq.push(v[i]);
    // }

    // cout << tq << endl;
    // println2(tq, tq.top());

    println(s.furthestBuilding(v, 10, 2));

    return 0;
}
