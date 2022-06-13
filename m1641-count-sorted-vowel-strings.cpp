#define DEBUG
#include "hutility.hpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using namespace std;

/**
https://leetcode.com/problems/count-sorted-vowel-strings/
*/

class Solution {
public:
    int countVowelStrings(int n) {
        vector<int> dp(5, 1);

        for(int i=0; i<n; ++i) {
            dp[0]=dp[0]+dp[1]+dp[2]+dp[3]+dp[4];
            dp[1]=dp[1]+dp[2]+dp[3]+dp[4];
            dp[2]=dp[2]+dp[3]+dp[4];
            dp[3]=dp[3]+dp[4];
            dp[4]=dp[4];            
        }
        
        return dp[0];
    }

    int countVowelStrings1(int n) {
        vector<int> ret = {5, 4, 3, 2, 1};

        for (int i = 1; i < n; i++) {
            ret[3] += ret[4];
            ret[2] += ret[3];
            ret[1] += ret[2];
            ret[0] += ret[1];
            LOG(ret);
        }
        return ret[0];
    }
};

TEST_CASE("Doctest cases")
{
    Solution sol;

    int n;

    n = 1;
    CHECK(sol.countVowelStrings(n) == 5);

    n = 2;
    CHECK(sol.countVowelStrings(n) == 15);

    n = 33;
    CHECK(sol.countVowelStrings(n) == 66045);
}
