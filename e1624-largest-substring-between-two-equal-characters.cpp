#define DEBUG
#include "hutility.hpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using namespace std;

/**
https://leetcode.cn/problems/largest-substring-between-two-equal-characters/
*/

class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int ret = -1;
        map<char, int> cmap;

        for (int i=0; i<s.size(); i++) {
            if (cmap.find(s[i]) == cmap.end()) {
                cmap[s[i]] = i;
            } else {
                ret = max(ret, i-cmap[s[i]]-1);
            }
        }
        return ret;
    }
};


TEST_CASE("Doctest cases")
{
    Solution sol;

    string s;

    s = "aa";
    CHECK(sol.maxLengthBetweenEqualCharacters(s) == 0);

    s = "abca";
    CHECK(sol.maxLengthBetweenEqualCharacters(s) == 2);

    s = "cbzxy";
    CHECK(sol.maxLengthBetweenEqualCharacters(s) == -1);
}
