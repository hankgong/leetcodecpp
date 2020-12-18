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
https://leetcode-cn.com/problems/count-substrings-that-differ-by-one-character/
*/

class Solution {
public:
    bool onedff(string &s, string &d) {
        int cnt = 0;
        if (s.size() != d.size()) return false;

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != d[i]) cnt++;
            if (cnt > 1) return false;
        }

        println(cnt);
        return (cnt == 1);
    }

    int countSubstrings(string s, string t) {
        int ls = s.size();
        int lt = t.size();
        int ret = 0;

        for (int i = 0; i < ls; ++i) {
            for (int j = i; j < ls; ++j) {

                for (int k = 0; k < lt - (j - i); ++k) {
                    string s1 = s.substr(i, j - i + 1);
                    string s2 = t.substr(k, j - i + 1);

                    println5(i, j, k, s1, s2);
                    if (onedff(s1, s2)) ret++;
                }
            }
        }
        return ret;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    println(s.countSubstrings("aba", "baba"));
    // println(s.countSubstrings("ab", "bb"));
    // println(s.countSubstrings("a", "a"));
    // println(s.countSubstrings("abe", "bbc"));

    return 0;
}
