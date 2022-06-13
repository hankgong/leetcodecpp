#define DEBUG
#include "hutility.hpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using namespace std;

/**
https://leetcode-cn.com/problems/number-of-1-bits/
*/

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ret = 0;

        while (n != 0) {
            ret += n & 1;
            n >>= 1;
        }

        return ret;
    }
};

TEST_CASE("Doctest cases")
{
    Solution sol;

    uint32_t n;

    n = 0b00000000000000000000000000001011;
    CHECK(sol.hammingWeight(n) == 3);

    n = 0b00000000000000000000000010000000;
    CHECK(sol.hammingWeight(n) == 1);

    n = 0b11111111111111111111111111111101;
    CHECK(sol.hammingWeight(n) == 31);
}
