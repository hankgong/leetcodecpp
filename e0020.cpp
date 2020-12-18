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
https://leetcode-cn.com/problems/valid-parentheses/submissions/
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

int main(int argc, char const *argv[])
{
    Solution s;
    println(s.isValid("()"));
    println(s.isValid("()[]{}"));
    println(s.isValid("(]"));
    println(s.isValid("([)]"));
    println(s.isValid("{[]}"));
    println(s.isValid("]"));

    return 0;
}
