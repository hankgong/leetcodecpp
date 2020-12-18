#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <climits>
#include "hutility.hpp"

using namespace std;

#define println(msg) cout << (msg) << endl
#define println2(m1, m2) cout << (m1) << " " << (m2) << endl
#define println3(m1, m2, m3) cout << (m1) << " " << (m2) << " " << (m3) << endl
#define println4(m1, m2, m3, m4) cout << (m1) << " " << (m2) << " " << (m3) << " " << (m4) << endl
#define println5(m1, m2, m3, m4, m5) cout << (m1) << " " << (m2) << " " << (m3) << " " << (m4) << " " << (m5)<< endl


/**

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

int main(int argc, char const *argv[])
{
    Solution s;
    println(s.myAtoi("  123ab "));
    println(s.myAtoi("  -123 "));
    println(s.myAtoi(" a -123 "));

    return 0;
}
