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
                println3(ret, i, s[i]);
            }
        }

        if (i == s.size() - 1) {
            ret += roman[s[i]];
        }

        return ret;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    println(s.romanToInt("III"));
    println(s.romanToInt("IV"));
    println(s.romanToInt("IX"));
    println(s.romanToInt("LVIII"));
    println(s.romanToInt("MCMXCIV"));

    return 0;
}
