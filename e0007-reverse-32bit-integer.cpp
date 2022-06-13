#define DEBUG
#include "hutility.hpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using namespace std;

/**
https://leetcode.com/problems/reverse-integer/
*/

class Solution {
public:
    int reverse(int x) {
        long ret = 0;

        while (x!=0) {
            int n = x%10;
            x=x/10;

            if (ret<INT_MIN/10 || (ret==INT_MIN/10 && n<-8)) return 0;
            if (ret>INT_MAX/10 || (ret==INT_MAX/10 && n> 7)) return 0;

            ret = ret*10+n;
        }

        return ret;
    }

    int reverse_mine(int x) {
        if (x == INT_MIN) return 0;
        bool neg = (x<0)? true:false;
        x = (neg == true)? -x:x;

        cout << INT_MIN << " " << INT_MAX << endl;

        long ret = 0;
        while (x != 0) {
            int d = x % 10;
            x = x/10;
            
            ret = 10*ret + d;
        }

        if ((neg == true && -ret < -pow(2, 31)) || (neg == false && ret > pow(2, 31) -1)) {
            return 0;
        } else {
            return (neg == true)?-ret:ret;
        }
    }
};

TEST_CASE("Doctest cases")
{
    Solution sol;

    int x;

    x = 123;
    CHECK(sol.reverse(x) == 321);

    x = -123;
    CHECK(sol.reverse(x) == -321);

    x = 120;
    CHECK(sol.reverse(x) == 21);

    x = 1534236469;
    CHECK(sol.reverse(x) == 0);

    x = -2147483648;
    CHECK(sol.reverse(x) == 0);
}
