#define DEBUG
#include "hutility.hpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using namespace std;

/**
https://leetcode-cn.com/problems/plus-one/
*/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int c = 1;
        vector<int> ret;

        for(int i=digits.size()-1; i>=0; --i) {
            digits[i] += c;
            c = digits[i]/10;
            ret.insert(ret.begin(), digits[i]%10);
        }

        if (c) ret.insert(ret.begin(), c);
        return ret;
    }
};

TEST_CASE("Doctest cases")
{
    Solution sol;
    vector<int> digits;

    digits= {1, 2, 3};
    CHECK(sol.plusOne(digits) == vector<int>{1, 2, 4});

    digits= {9, 9, 9};
    CHECK(sol.plusOne(digits) == vector<int>{1, 0, 0, 0});

    digits={4,3,2,1};
    CHECK(sol.plusOne(digits) == vector<int>{4, 3, 2, 2});

    digits = {1,2,3};
    CHECK(sol.plusOne(digits) == vector<int>{1,2,4});

    digits = {4,3,2,1};
    CHECK(sol.plusOne(digits) == vector<int>{4,3,2,2});

    digits = {9};
    CHECK(sol.plusOne(digits) == vector<int>{1,0});
}
