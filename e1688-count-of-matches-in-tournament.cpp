#define DEBUG
#include "hutility.hpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using namespace std;

/**
https://leetcode.cn/problems/count-of-matches-in-tournament/
*/

class Solution {
public:
    int numberOfMatches(int n) {
        return n-1;
    }

    int numberOfMatches_mine(int n) {
        int ret=0;
        while(n>1) {
            int isOdd = (n%2==1);
            n/=2;
            ret+=n;
            if (isOdd) n++;
        }

        return ret;
    }
};

TEST_CASE("Doctest cases")
{
    Solution sol;

    int n;

    n = 7;
    CHECK(sol.numberOfMatches(n) == 6);

    n = 14;
    CHECK(sol.numberOfMatches(n) == 13);
}
