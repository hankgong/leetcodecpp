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
https://leetcode-cn.com/problems/friend-circles/
*/

class Solution {
public:
    static const int N = 202;
    int pre[N];

    int findCircleNum(vector<vector<int>>& M) {
        init();

        int n = M.size();

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (M[i][j] == 1) {
                    LLOG(i, j);
                    join(i, j);
                }
            }
        }

        // for (int i = 0; i < n; ++i) {
        //     cout << pre[i] << " ";
        // }
        // cout << endl;

        set<int> res;
        for (int i = 0; i < n; ++i) {
            int r = find(i);
            if (!res.count(r)) {
                res.insert(r);
            }
        }

        LLOG(res);
        return res.size();
    }

    void init() {
        for (int i = 0; i < N; ++i) {
            pre[i] = i;
        }
    }

    int find(int x) {
        int r = x;
        while (pre[r] != r) {
            r = pre[r];
        }

        int i = x, j;
        while(pre[i] != r) {
            j = pre[i];
            pre[i] = r;
            i = j;
        }

        return r;
    }

    bool join(int x, int y) {
        int p1 = find(x), p2 = find(y);
        if (p1 != p2) {
            pre[p1] = p2;
            return false;
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    vector<vector<int>> M;

//    M={{1,1,0},
// {1,1,0},
// {0,0,1}};
//    LOG(s.findCircleNum(M));

//    M={{1,1,0},
// {1,1,1},
// {0,1,1}};
//    LOG(s.findCircleNum(M));

//    M={{1,1,0,0},
//       {1,1,1,0},
//       {1,1,1,1},
//       {0,1,1,1}};
//    LOG(s.findCircleNum(M));

    M = {{1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, {0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0}, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0}, {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0}, {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0}, {1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0}, {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0}, {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0}, {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}};
    LOG(s.findCircleNum(M));
    return 0;
}
