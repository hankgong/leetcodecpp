#define DEBUG
#include "hutility.hpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using namespace std;

/**
https://leetcode.cn/problems/get-maximum-in-generated-array/
*/

class Solution {
public:
    int getMaximumGenerated(int n) {
        vector<int> v(101, 0);

        if (n==0) return 0;
        if (n==1) return 1;

        int ret = 1;

        v[0] = 0;
        v[1] = 1;

        for (int i = 2; i<= n; ++i) {
            if (i % 2 == 0) {
                v[i] = v[i/2];
            } else {
                v[i] = v[i/2] + v[i/2+1];
            }
            ret = max(v[i], ret);
        }

        LOG(v);

        return ret;
    }
};

TEST_CASE("Doctest cases")
{
    Solution sol;

    int n;

    n = 7;
    CHECK(sol.getMaximumGenerated(n) == 3);

    n = 2;
    CHECK(sol.getMaximumGenerated(n) == 1);

    n = 3;
    CHECK(sol.getMaximumGenerated(n) == 2);
}
