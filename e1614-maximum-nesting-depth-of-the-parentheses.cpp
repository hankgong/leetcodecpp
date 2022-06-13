#define DEBUG
#include "hutility.hpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using namespace std;

/**
https://leetcode.cn/problems/maximum-nesting-depth-of-the-parentheses/
*/

class Solution {
public:
    int maxDepth(string s) {
        int ret = 0;
        int level = 0;

        for (int i=0; i<s.size(); i++) {
            if (s[i] == '(') {
                level++;
                if (level > ret) {
                    ret = level;
                }
            } else if (s[i] == ')') {
                level--;
            }
        }
        return ret;
    }
};

TEST_CASE("Doctest cases")
{
    Solution sol;

    string s;

    s = "(1+(2*3)+((8)/4))+1";
    CHECK(sol.maxDepth(s) == 3);

    s = "(1)+((2))+(((3)))";
    CHECK(sol.maxDepth(s) == 3);
}
