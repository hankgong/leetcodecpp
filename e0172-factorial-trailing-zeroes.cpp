#define DEBUG
#include "hutility.hpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using namespace std;

/**
https://leetcode-cn.com/problems/factorial-trailing-zeroes/
*/

class Solution {
public:
    int trailingZeroes(int n) {
        int ret = 0;

        while (n > 0) {
           n /= 5; 
           ret += n;
        }

        return ret;
    }
};

TEST_CASE("Doctest cases")
{
    Solution sol;

    int n;

    n = 3;
    CHECK(sol.trailingZeroes(n) == 0);

    n = 5;
    CHECK(sol.trailingZeroes(n) == 1);

    n = 0;
    CHECK(sol.trailingZeroes(n) == 0);
}
