#define DEBUG
#include "hutility.hpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using namespace std;

/**
https://leetcode.com/problems/a-number-after-a-double-reversal/
*/

class Solution {
public:
    bool isSameAfterReversals(int num) {
        return num % 10 != 0 || num == 0;
    }
};

TEST_CASE("test results")
{
    Solution sol;

    int num;

    num = 526;
    CHECK(sol.isSameAfterReversals(num) == true);

    num = 1800;
    CHECK(sol.isSameAfterReversals(num) == false);

    num = 0;
    CHECK(sol.isSameAfterReversals(num) == true);
}
