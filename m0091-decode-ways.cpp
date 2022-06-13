#define DEBUG
#include "hutility.hpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using namespace std;

/**
https://leetcode.com/problems/decode-ways/
*/

class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp;
        dp.resize(s.size()+1);

        dp[0] = 1;
        dp[1] = 1*(s[0] == '0' ? 0:1);

        for(int i=1; i<s.size(); ++i) {
            int t1 = stoi(s.substr(i, 1));
            int t2 = stoi(s.substr(i-1, 2));
            bool hasZero = (s[i-1] == '0');
            dp[i+1] = dp[i]*(t1>0?1:0) + dp[i-1]*((t2<= 26 && t2>0 && !hasZero) ? 1 : 0); 
        }
        return dp[s.size()];
    }
};

TEST_CASE("Doctest cases")
{
    Solution sol;

    string s;

    s = "12";
    CHECK(sol.numDecodings(s) == 2);

    s = "226";
    CHECK(sol.numDecodings(s) == 3);

    s = "06";
    CHECK(sol.numDecodings(s) == 0);

    s = "0";
    CHECK(sol.numDecodings(s) == 0);

    s = "2101";
    CHECK(sol.numDecodings(s) == 1);
}
