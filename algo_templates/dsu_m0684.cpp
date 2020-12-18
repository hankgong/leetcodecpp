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
https://leetcode-cn.com/problems/redundant-connection
*/
class Solution {
public:
    static const int N = 1005;
    int pre[N];
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        init();
        vector<int> ret;
        int n = edges.size();
        int u, v;
        for (int i = 0; i < n; ++i) {
            u = edges[i][0], v = edges[i][1];
            if (join(u, v)) {
                ret.push_back(u);
                ret.push_back(v);
                return ret;
            }
        }
        return ret;
    } 

    void init() {
        for (int i = 0; i < N; ++i) {
            pre[i] = i;
        }
    }

    int find(int x) {
        // if (x == pre[x]) return x;
        // return pre[x] = find(pre[x]);
        int r = x;
        while(pre[r] != r) r=pre[r];

        int i = x, j;
        while(i!=r) {
            j = pre[i];
            pre[i] = r;
            i=j;
        }

        return r;
    }

    bool join(int x, int y) {
        int p1 = find(x), p2 = find(y);
        if (p1!=p2) {
            pre[p1] = p2;
            return false;
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    vector<vector<int>> edges;

    edges={{1,2}, {1,3}, {2,3}};
    LOG(s.findRedundantConnection(edges));

    edges={{1,2}, {2,3}, {3,4}, {1,4}, {1,5}};
    LOG(s.findRedundantConnection(edges));


    return 0;
}
