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

*/

class Solution {
public:
    int cnt;
    int all8queen(){
        cnt = 0;

        vector<int> locations;
        vector<int> vis(64, 0);

        dfs(0, locations, vis);
    }

    void dfs(int nqs, vector<int> &locs, vector<int> &vis) {
        if (8 == nqs) {
            cnt++;
            for (int i = 0; i<locs.size(); ++i) {
                cout << "(" << locs[i]/8+1 << ", " << locs[i]%8+1 <<")";
            }
            cout << endl;
            return;
        }

        for (int i = 0; i<8; i++) {
            int r = nqs;
            int c = i;

            bool ok = true;
            for (int j = 0; j< locs.size(); j++) {
                if (vis[i] || r == locs[j]/8 || c == locs[j]%8 || abs(r-locs[j]/8) == abs(c-locs[j]%8)) {
                    ok = false;
                    break;
                }
            }

            if (true == ok) {
                locs.push_back(nqs*8+i);
                vis[i] = 1;

                dfs(nqs+1, locs, vis);
                locs.pop_back();
                vis[i] = 0;
            }
        }
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    s.all8queen();

    return 0;
}
