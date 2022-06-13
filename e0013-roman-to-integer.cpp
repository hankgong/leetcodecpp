#define DEBUG
#include "hutility.hpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using namespace std;

/**
https://leetcode.com/problems/roman-to-integer/
*/

class Solution {
public:
    int romanToInt(string s) {
        map<char, int> roman = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
            {'C', 100}, {'D', 500}, {'M', 1000}
        };

        int ret = 0;
        int i = 0;
        while (i < s.size() - 1) {
            if (roman[s[i]] < roman[s[i + 1]]) {
                ret += roman[s[i + 1]] - roman[s[i]];
                i = i + 2;
            } else {
                ret += roman[s[i]];
                i++;
                LOG(ret, i, s[i]);
            }
        }

        if (i == s.size() - 1) {
            ret += roman[s[i]];
        }

        return ret;
    }
};

TEST_CASE("Doctest cases")
{
    Solution sol;

    string s;

    s = "III";
    CHECK(sol.romanToInt(s) == 3);

    s = "LVIII";
    CHECK(sol.romanToInt(s) == 58);

    s = "MCMXCIV";
    CHECK(sol.romanToInt(s) == 1994);

}
