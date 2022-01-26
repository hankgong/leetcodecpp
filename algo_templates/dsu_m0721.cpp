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
https://leetcode-cn.com/problems/accounts-merge/
*/

class Solution {
public:
    static const int N = 1010;
    int p[N];
    unordered_map<string, int> father;
    vector<vector<string>> res;

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();

        for (int i = 0; i < n; ++i) {
            p[i] = i;
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 1; j < accounts[i].size(); ++j) {
                string email = accounts[i][j];
                if(father.count(email)) {
                    p[i] = p[find(father[email])];
                    // p[find(father[email])] = p[i];
                } else {
                    father[email] = i;
                }

                for (int i=0; i< n; ++i) {
                    cout << p[i] << " ";
                }
                cout << endl;
            }
        }

        LLOG(father);

        unordered_map<int, set<string>> m;

        for(int i=0; i<n; i++) {
            int t = find(i);

            for (int j = 1; j < accounts[i].size(); ++j) {
                m[t].insert(accounts[i][j]);
            }
        }

        for(auto &p:m) {
            vector<string> ans;
            ans.push_back(accounts[p.first][0]);
            for(string email: p.second) {
                ans.push_back(email);
            }
            res.push_back(ans);
        }

        return res;
    }

    int find(int a) {
        if (p[a] != a) {
            p[a] = find(p[a]);
        }

        return p[a];
    }

};

int main(int argc, char const *argv[])
{
    Solution s;

    vector<vector<string>> accounts;

    // accounts={{"John", "johnsmith@mail.com", "john00@mail.com"}, {"John", "johnnybravo@mail.com"}, {"John", "johnsmith@mail.com", "john_newyork@mail.com"}, {"Mary", "mary@mail.com"}};
    // LOG(s.accountsMerge(accounts));

    accounts={{"David","David0@m.co","David1@m.co"},{"David","David3@m.co","David4@m.co"},{"David","David4@m.co","David5@m.co"},{"David","David2@m.co","David3@m.co"},{"David","David1@m.co","David2@m.co"}};
    LOG(s.accountsMerge(accounts));


    return 0;
}
