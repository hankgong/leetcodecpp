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

int main(int argc, char const *argv[])
{
    Solution s;
    println(s.countAndSay(1));
    println(s.countAndSay(2));
    println(s.countAndSay(3));
    println(s.countAndSay(4));
    println(s.countAndSay(5));
    println(s.countAndSay(6));
    println(s.countAndSay(30));

    return 0;
}
