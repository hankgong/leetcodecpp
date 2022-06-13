#define DEBUG
#include "hutility.hpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using namespace std;

/**
https://leetcode.com/problems/count-substrings-that-differ-by-one-character/
*/

class Solution {
public:
    int countSubstrings(string s, string t) {
        int ls = s.size();
        int lt = t.size();
        int ret = 0;

        for (int i = 0; i < ls; ++i) {
            for (int j = i; j < ls; ++j) {

                for (int k = 0; k < lt - (j - i); ++k) {
                    string s1 = s.substr(i, j - i + 1);
                    string s2 = t.substr(k, j - i + 1);

                    LOG(i, j, k, s1, s2);
                    if (onedff(s1, s2)) ret++;
                }
            }
        }
        return ret;
    }

    bool onedff(string &s, string &d) {
        int cnt = 0;
        if (s.size() != d.size()) return false;

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != d[i]) cnt++;
            if (cnt > 1) return false;
        }

        LOG(cnt);
        return (cnt == 1);
    }
};

TEST_CASE("Doctest cases")
{
    Solution sol;

    string s;
    string t;

    s = "aba";
    t = "baba";
    CHECK(sol.countSubstrings(s, t) == 6);

    s = "ab";
    t = "bb";
    CHECK(sol.countSubstrings(s, t) == 3);
}
