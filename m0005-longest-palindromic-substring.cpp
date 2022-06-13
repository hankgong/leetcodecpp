#define DEBUG
#include "hutility.hpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using namespace std;

/**
https://leetcode.cn/problems/longest-palindromic-substring/
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

TEST_CASE("Doctest cases")
{
    Solution sol;

    string s;

    s = "babad";
    CHECK(sol.longestPalindrome(s) == "bab");

    s = "cbbd";
    CHECK(sol.longestPalindrome(s) == "bb");
}
