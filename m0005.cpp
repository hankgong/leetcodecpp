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
    string longestPalindrome(string s) {
        int n = s.size();
        int start = 0;
        int end = 0;
        int maxl = 1;

        vector<vector<bool>> dp(n, vector<bool>(n, false));

        for(int r=1; r<n; r++) {
            for(int l=0; l<r; l++) {
                LLOG(l, r);
                if(s[l] == s[r] && (r-l<=2 || dp[l+1][r-1])) {
                    dp[l][r] = true;
                    if (r-l+1>maxl) {
                        maxl = r-l+1;
                        start = l;
                        end = r;
                    }
                }
            }
        }

        LLOG(start, end, maxl);
        return s.substr(start, maxl);
    }

    string longestPalindrome_expand(string s) {
        int start = 0, end = 0;

        function<pair<int, int>(int, int)> expandatloc = [&](int l, int r) {
            int b = l, e=l;
            while(l>=0 && r<s.size() && s[l] == s[r]) {
                b = l;
                e = r;
                l--;
                r++;
            }
            return make_pair(b, e);
        };

        for(int i=0; i<s.size()-1; ++i) {
            int b, e;
            tie(b, e) = expandatloc(i, i);
            if(e-b>end-start) {
                start = b;
                end = e;
            }

            tie(b, e) = expandatloc(i, i+1);
            if (e-b>end-start) {
                start = b;
                end = e;
            }
        }

        LLOG(start, end);
        return s.substr(start, end-start+1);
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    println(s.longestPalindrome("abbbbac"));

    return 0;
}
