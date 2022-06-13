#define DEBUG
#include "hutility.hpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using namespace std;

/**
https://leetcode.cn/problems/reverse-words-in-a-string-iii/
*/

class Solution {
public:
    string reverseWords(string s) {
        s = s + " ";
        auto b = s.begin();
        for(auto i=s.begin();i!=s.end(); i++) {
            if (*i == ' ') {
                reverse(b, i);
                b = i+1;
            }
        }
        return s.substr(0, s.size()-1);
    }

    string reverseWords1(string s) {
        auto b = s.begin();
        for(auto i=s.begin();i!=s.end(); i++) {
            if (*i == ' ') {
                reverse(b, i);
                b = i+1;
            }
        }
        reverse(b, s.end());

        return s;
    }
};

TEST_CASE("Doctest cases")
{
    Solution sol;

    string s;

    s = "Let's take LeetCode contest";
    CHECK(sol.reverseWords(s) == "s'teL ekat edoCteeL tsetnoc");

    s = "God Ding";
    CHECK(sol.reverseWords(s) == "doG gniD");
}
