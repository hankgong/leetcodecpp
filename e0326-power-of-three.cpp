#define DEBUG
#include "hutility.hpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using namespace std;

/**
https://leetcode.com/problems/power-of-three/
*/

class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) return false;
        while (n > 1) {
            if (n%3 != 0) return false;
            n /= 3;
        }

        return true;
    }
};

TEST_CASE("Doctest cases")
{
    Solution sol;

    int n;

    n = 27;
    CHECK(sol.isPowerOfThree(n) == true);

    n = 0;
    CHECK(sol.isPowerOfThree(n) == false);

    n = 9;
    CHECK(sol.isPowerOfThree(n) == true);
}
