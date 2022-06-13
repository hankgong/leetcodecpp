#define DEBUG
#include "hutility.hpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using namespace std;

/**
https://leetcode.com/problems/powx-n/
*/

class Solution {
public:
    double myPow(double x, int n) {
        if (n==0) return 1;

        if (n%2 == 0) {
            return myPow(x, n/2)*myPow(x, n/2);
        } else {
            return myPow(x, n/2)*myPow(x, n/2)*(n>0?x:1.0/x);
        }
    }

};


TEST_CASE("Doctest cases")
{
    Solution sol;

    double x;
    int n;

    x = 2.00000;
    n = 10;
    CHECK(sol.myPow(x, n) == doctest::Approx(1024.00000));

    x = 2.10000;
    n = 3;
    CHECK(sol.myPow(x, n) == doctest::Approx(9.261));

    x = 2.00000;
    n = -2;
    CHECK(sol.myPow(x, n) == doctest::Approx(0.25000));
}
