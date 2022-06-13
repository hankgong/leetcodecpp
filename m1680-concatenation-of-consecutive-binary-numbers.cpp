#define DEBUG
#include "hutility.hpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using namespace std;

/**
https://leetcode.com/problems/concatenation-of-consecutive-binary-numbers/
*/

class Solution {
public:
    int concatenatedBinary(int n) {
        long ret = 0;
        int mod = 1e9+7;
        int shift=0;

        for(int i=1; i<=n; ++i) {
            if((i&(i-1))==0) shift++;
            // LLOG(i, int(log2(i)), ret*pow(2, int(log2(i)+1)), i);
            ret = (ret<<shift) + i;
            LLOG(i, shift, ret);
            ret %= mod;
        }
        return ret;
    }
    int concatenatedBinary_myown(int n) {
        long ret = 0;
        int mod = 1000000007;

        for(int i=1; i<=n; ++i) {
            LLOG(i, int(log2(i)), ret*pow(2, int(log2(i)+1)), i);
            ret = ret*pow(2, int(log2(i)+1)) + i;
            ret %= mod;
        }
        return ret;
    }
};

TEST_CASE("Doctest cases")
{
    Solution sol;

    int n;

    n = 1;
    CHECK(sol.concatenatedBinary(n) == 1);

    n = 3;
    CHECK(sol.concatenatedBinary(n) == 27);

    n = 12;
    CHECK(sol.concatenatedBinary(n) == 505379714);
}
