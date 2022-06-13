#define DEBUG
#include "hutility.hpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using namespace std;

/**
https://leetcode.cn/problems/partitioning-into-minimum-number-of-deci-binary-numbers/
*/

class Solution {
public:
    int minPartitions(string n) {
        char maxC='0';

        for (int i = 0; i < n.size(); ++i) {
            maxC=max(n[i], maxC);
        }

        return maxC-'0';
    }
};

TEST_CASE("Doctest cases")
{
    Solution sol;

    string n;

    n = "32";
    CHECK(sol.minPartitions(n) == 3);

    n = "82734";
    CHECK(sol.minPartitions(n) == 8);

    n = "27346209830709182346";
    CHECK(sol.minPartitions(n) == 9);
}
