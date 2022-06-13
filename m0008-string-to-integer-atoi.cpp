#define DEBUG
#include "hutility.hpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using namespace std;

/**
https://leetcode.cn/problems/string-to-integer-atoi/
*/

class Automaton {
    string state = "start";
    unordered_map <string, vector<string>> table = {
        {"start", {"signed", "start", "number", "end"}},
        {"signed", {"end", "end", "number", "end"}},
        {"number", {"end", "end", "number", "end"}},
        {"end", {"end", "end", "end", "end"}}
    };

    int getchar(char c) {
        if (c == '+' or c == '-') return 0;
        else if (isspace(c)) return 1;
        else if (isdigit(c)) return 2;
        else return 3;
    }
public:
    int sign = 1;
    long long ans = 0;

    void get(char c) {
        state = table[state][getchar(c)];
        if (state == "number") {
            ans = ans * 10 + c - '0';
            ans = sign == 1 ? min(ans, (long long)INT_MAX) : min(ans, -(long long)INT_MIN);
        }
        else if (state == "signed") {
            sign = c == '+' ? 1 : -1;
        }
    }

};

class Solution {

public:
    int myAtoi(string s) {
        Automaton automaton;

        for (char c : s)
            automaton.get(c);

        return automaton.sign * automaton.ans;
    }
};

TEST_CASE("Doctest cases")
{
    Solution sol;

    string s;

    s = "42";
    CHECK(sol.myAtoi(s) == 42);

    s = "   -42 ";
    CHECK(sol.myAtoi(s) == -42);

    s = "4193 with words";
    CHECK(sol.myAtoi(s) == 4193);
}
