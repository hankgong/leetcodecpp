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
https://leetcode.com/problems/cracking-the-safe/
*/

class Solution {
public:

    string crackSafe(int n, int k) {
        string ans;

        if (n==1) {
            for(int i = 0; i<k; ++i) {
                ans += i+'0';
            }
            return ans;
        }

        unordered_map<string, unordered_set<string>> vis;
        vector<string> d;
        string zero(n-1, '0');

        dfs(zero, vis, d, k);

        LOG(d);

        for(int i = d.size()-1; i>=0; --i) {
            if (i == d.size() - 1) {
                ans = d[i];
            } else {
                ans += d[i].substr(n-1);
            }
        }

        return ans;
    }

    void dfs(const string& u, unordered_map<string, unordered_set<string>>& vis, vector<string>& d, int k) {
        string s = u.substr(1);
        for (int i = 0; i < k; ++i) {
            string v = s;
            v += i + '0';
            if (vis[u].count(v)) continue;
            vis[u].insert(v);

            dfs(v, vis, d, k);
            d.push_back(u+to_string(i));
        }
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    LOG(s.crackSafe(2, 2));


    return 0;
}
