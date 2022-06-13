#define DEBUG
#include "hutility.hpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using namespace std;

/**
https://leetcode.com/problems/longest-common-prefix/
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) {
            return "";
        }

        // LOG(strs);

        string ret = "";
        for (int i = 0; i < strs[0].size(); i++) {
            for (int j = 1; j < strs.size(); j++) {
                if (strs[j][i] != strs[0][i]) {
                    return ret;
                }
                // if (strs[j].substr(0, i+1) != strs[0].substr(0, i+1)) {
                //     // return strs[0].substr(0, i);
                //     return ret;
                // }
            }
            ret = strs[0].substr(0, i + 1);
        }

        return ret;
    }
};

TEST_CASE("Doctest cases")
{
    Solution sol;

    vector<string> v;
    v = {"flower", "flow", "flight"};
    CHECK(sol.longestCommonPrefix(v) == "fl");

    v = {"flower", "flower", "flower"};
    CHECK(sol.longestCommonPrefix(v) == "flower");

    v = {"", "flower", "flower"};
    CHECK(sol.longestCommonPrefix(v) == "");

    v =  {"dog", "racecar", "car"};
    CHECK(sol.longestCommonPrefix(v) == "");
}
