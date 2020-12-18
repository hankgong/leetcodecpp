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
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) {
            return "";
        }

        println(strs);

        string ret = "";
        for (int i = 0; i < strs[0].size(); i++) {
            for (int j = 1; j < strs.size(); j++) {
                if (strs[j][i] != strs[0][i]) {
                    return ret;
                }
                // if (strs[j].substr(0, i+1) != strs[0].substr(0, i+1)) {
                //     // return strs[0].substr(0, i);
                //     return ret;
                // }
            }
            ret = strs[0].substr(0, i + 1);
        }

        return ret;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    vector<string> v;
    v = {"flower", "flow", "flight"};
    println(s.longestCommonPrefix(v));

    v = {"flower", "flower", "flower"};
    println(s.longestCommonPrefix(v));

    v = {"", "flower", "flower"};
    println(s.longestCommonPrefix(v));

    v =  {"dog", "racecar", "car"};
    println(s.longestCommonPrefix(v));

    return 0;
}
