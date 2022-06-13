#define DEBUG
#include "hutility.hpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using namespace std;

/**
https://leetcode.com/problems/gray-code/
*/

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ret = {0};

        for (int i = 0; i < n; ++i) {
            int l = ret.size();
            // println3(ret, i, 1 << i);
            for (int j = 0; j < l; ++j) {
                ret.push_back((1 << i) + ret[l - 1 - j]);
            }
        }
        return ret;
    }
};

TEST_CASE("test results")
{
    Solution sol;
    int n;
    
    CHECK(sol.grayCode(1) == vector<int>{0, 1});
    CHECK(sol.grayCode(2) == vector<int>{0, 1, 3, 2});

    n = 2;
    CHECK(sol.grayCode(n) == vector<int>{0,1,3,2});

    n = 1;
    CHECK(sol.grayCode(n) == vector<int>{0,1});
}
