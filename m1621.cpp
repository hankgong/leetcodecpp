#define DEBUG
#include "hutility.hpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using namespace std;

/**
https://leetcode.com/problems/number-of-sets-of-k-non-overlapping-line-segments/
*/

class Solution {
public:
    int f(int n, int k) {
        if (k == 1)
            return n-1;
        if (n-k == 1)
            return 1;
        else
            return f(n-1, k-1) + f(n-1, k);
    }


    int numberOfSets(int n, int k) {
        return f(n, k);
    }
};

TEST_CASE("Doctest cases")
{
    Solution sol;

    int n;
    int k;

    n = 4;
    k = 2;
    CHECK(sol.f(n, k) == 5);

    n = 3;
    k = 1;
    CHECK(sol.f(n, k) == 3);

    n = 30;
    k = 7;
    CHECK(sol.f(n, k) == 796297179);
}
