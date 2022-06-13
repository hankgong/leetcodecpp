#define DEBUG
#include "hutility.hpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using namespace std;

/**
https://leetcode.cn/problems/count-good-meals/
*/

class Solution {
public:
    int countPairs(vector<int>& deliciousness) {
        unordered_map<int,int> m;
        long ans =0;

        int maxE = 0;
        for (int i=0; i<deliciousness.size(); ++i) {
            m[deliciousness[i]]++;
            maxE = max(maxE, deliciousness[i]);
        }

        LLOG(m);
        for (int i=0; i<=log2(maxE)+1; ++i){
            int target = (1<<i);
            // unordered_set<int> visited;
            for(auto &t:m) {
                // if (visited.count(t.first)) continue;
                if (t.first*2 == target) {
                    // ans += t.second*(t.second-1)/2;
                    int p = (long)t.second*(long)(t.second-1);
                    p %= 1000000007;
                    ans += p;
                    ans %= 1000000007;
                } else if (m.count(target-t.first)) {
                    int p = (long)m[target-t.first]*(long)t.second;
                    p %= 1000000007;
                    ans += p;
                    ans %= 1000000007;
                    // visited.insert(target-t.first);
                }

                LLOG(target, t.first, ans);

                // visited.insert(t.first);
            }
        }

        return ans/2;
    }
};

TEST_CASE("Doctest cases")
{
    Solution sol;

    vector<int> deliciousness;

    deliciousness = {1,3,5,7,9};
    CHECK(sol.countPairs(deliciousness) == 4);

    deliciousness = {1,1,1,3,3,3,7};
    CHECK(sol.countPairs(deliciousness) == 15);
}

