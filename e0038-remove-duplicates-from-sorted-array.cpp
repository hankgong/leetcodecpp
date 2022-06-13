#define DEBUG
#include "hutility.hpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using namespace std;

/**
https://leetcode.com/problems/remove-duplicates-from-sorted-array/
*/

class Solution {
public:
    string countAndSay(int n) {
        string s, ret;
        s = "1";
        for (int i = 1; i < n; i++) {
            string say = "";
            int cnt = 0;
            char chr = s[0];
            for (auto c : s) {
                if (c == chr) {
                    cnt++;
                } else {
                    say += (to_string(cnt) + chr);
                    chr = c;
                    cnt = 1;
                }
            }
            say += (to_string(cnt) + chr);
            s = say;
        }

        return s;
    }
};

TEST_CASE("test results")
{
    Solution s;

    CHECK(s.countAndSay(1) == "1");
    CHECK(s.countAndSay(2) == "11");
    CHECK(s.countAndSay(3) == "21");
    CHECK(s.countAndSay(4) == "1211");
    CHECK(s.countAndSay(5) == "111221");
    CHECK(s.countAndSay(6) == "312211");
    CHECK(s.countAndSay(10) == "13211311123113112211");
}
