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

*/

class Solution {
public:
    int minimumJumps_bfs(vector<int>& forbidden, int a, int b, int x) {
        unordered_set<int> fs(forbidden.begin(), forbidden.end());
        unordered_set<int> bs(forbidden.begin(), forbidden.end());
        int maxDist=6000;

        queue<pair<int, bool>> q;
        q.emplace(0, false);

        int cnt=0;
        while(!q.empty()) {
            int l = q.size();
            while(l--){
                auto [i, j] = q.front(); q.pop();
                if (i==x) return cnt;
                if (i>maxDist) continue;

                int fwd=i+a;
                if (!fs.count(fwd)) {
                    q.emplace(fwd, false);
                    fs.insert(fwd);
                }

                int bck=i-b;
                if(bck>0 && !bs.count(bck) && !j) {
                    q.emplace(bck, true);
                    bs.insert(bck);
                }
            }
            cnt++;
        }

        LLOG(q);
        return -1;
    }

    int minimumJumps_dfs(vector<int>& forbidden, int a, int b, int x) {
        unordered_set<int> visf(forbidden.begin(), forbidden.end());
        unordered_set<int> visb(forbidden.begin(), forbidden.end());
        int ret=INT_MAX;

        const int kMaxDist=6000;
        function<void(int, int, bool)> dfs = [&](int curp, int step, bool fwd) {
            LLOG(curp);
            if(curp==x) {
                ret = min(ret, step);
                LLOG("OK");
                return;
            }
            if (curp>kMaxDist || curp<0) return;

            if (!visf.count(curp+a)) {
                visf.insert(curp+a);
                dfs(curp+a, step+1, true);
            }

            if (curp-b>0 && fwd && !visb.count(curp-b)){
                visb.insert(curp-b);
                dfs(curp-b, step+1, false);
            }
        };

        dfs(0, 0, true);

        return ret;
    }
};

int main()
{
    Solution s;

    vector<int> forbidden;

    forbidden= {};
    LOG(s.minimumJumps_dfs(forbidden, 1, 2, 10));

    forbidden={14,4,18,1,15};
    LOG(s.minimumJumps_bfs(forbidden, 3, 15, 9));

    forbidden={8,3,16,6,12,20};
    LOG(s.minimumJumps_bfs(forbidden, 15, 13, 11));

    forbidden={1,6,2,14,5,17,4};
    LOG(s.minimumJumps_bfs(forbidden, 16, 9, 7));

}