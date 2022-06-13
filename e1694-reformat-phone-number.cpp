#define DEBUG
#include "hutility.hpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using namespace std;

/**
https://leetcode.cn/problems/reformat-phone-number/
*/

class Solution {
public:
    string reformatNumber(string number) {
        string ans = "";

        string n = "";
        for (auto const& c : number) {
            if (c != '-' && c != ' ') {
                n.push_back(c);
            }
        }

        int l = n.size();
        int i;
        for (i = 0; i < l; ++i) {
            // if (i < n.size()-4) {
            if (i !=0 && i%3==0) {
                ans.push_back('-');
            }
            if (i%3==0 && i>=l-4) break;
            ans.push_back(n[i]);
        }
        LLOG(i, ans);
        if (l-i<4) {
            ans += n.substr(i, l-i);
        } else {
            ans += n.substr(i, 2);
            ans += "-";
            ans += n.substr(i+2, 2);
        }

        LLOG(ans);
        return ans;
    }
};

TEST_CASE("Doctest cases")
{
    Solution sol;

    string number;

    number = "1-23-45 6";
    CHECK(sol.reformatNumber(number) == "123-456");

    number = "123 4-567";
    CHECK(sol.reformatNumber(number) == "123-45-67");

    number = "123 4-5678";
    CHECK(sol.reformatNumber(number) == "123-456-78");

    number = "12";
    CHECK(sol.reformatNumber(number) == "12");

    number = "175-229-353-94-75";
    CHECK(sol.reformatNumber(number) == "175-229-353-94-75");

    number = "9964-";
    CHECK(sol.reformatNumber(number) == "99-64");
}
