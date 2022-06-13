#define DEBUG
#include "hutility.hpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using namespace std;

/**
https://leetcode-cn.com/problems/reverse-bits/
*/

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int ret= 0;
        for (int i = 0; i < 32; ++i) {
            ret <<= 1;
            ret |= n & 1;
            n >>= 1;
            LOG(ret, n);
        }
        return ret;
    }
};

TEST_CASE("Doctest cases")
{
    Solution sol;

    uint32_t n;

    n = 0b00000010100101000001111010011100;
    CHECK(sol.reverseBits(n) == 964176192);

    n = 0b11111111111111111111111111111101;
    CHECK(sol.reverseBits(n) == 3221225471);
}
