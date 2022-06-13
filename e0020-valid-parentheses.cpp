#define DEBUG
#include "hutility.hpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using namespace std;

/**
https://leetcode-cn.com/problems/valid-parentheses/
*/

class Solution {
public:
    bool isValid(string s) {
        stack<char> ss;

        for (auto &c : s) {
            if (c == '[' || c== '{' || c=='(') {
                ss.push(c);
            } else {
                if (ss.empty()) return false;
                if (c == ']' && ss.top() != '[') return false; 
                if (c == '}' && ss.top() != '{') return false; 
                if (c == ')' && ss.top() != '(') return false; 
                ss.pop();
            }

        }

        return ss.empty();
    }
};

TEST_CASE("Doctest cases")
{
    Solution sol;
    string s;

    CHECK(sol.isValid("()") == true);
    CHECK(sol.isValid("()[]{}") == true);
    CHECK(sol.isValid("(]") == false);
    CHECK(sol.isValid("([)]") == false);
    CHECK(sol.isValid("{[]}") == true);
    CHECK(sol.isValid("]") == false);
    CHECK(sol.isValid("[][]()") == true);

    s = "()";
    CHECK(sol.isValid(s) == true);

    s = "()[]{}";
    CHECK(sol.isValid(s) == true);

    s = "(]";
    CHECK(sol.isValid(s) == false);
}
