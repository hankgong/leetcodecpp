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
https://leetcode.com/problems/beautiful-arrangement/
*/

class Solution {
public:
    int total;
    int cnt;

    int countArrangement(int N) {
        total = N;
        cnt = 0;
        vector<int> vis(total+1, 0);
        vector<int> p;
        dfs(1, p, vis);
        return cnt;
    }

    void dfs(int pos, vector<int> &path, vector<int> &vis) {
        if (total+1 == pos) {
            cnt++;
            LLOG(path);
            return;
        }

        for(int i=1; i<=total; ++i) {
            // LLOG(i, pos, vis, path);
            if ((i%pos == 0 || pos%i == 0) && !vis[i]) {
                path.push_back(i);
                vis[i] = 1;

                dfs(pos+1, path, vis);
                path.pop_back();
                vis[i] = 0;
            }
        }
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    // LOG(s.countArrangement(2));
    LOG(s.countArrangement(10));


    return 0;
}
