#define DEBUG
#include "hutility.hpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using namespace std;

/**
https://leetcode.com/problems/reverse-string-ii/
*/

class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.size();
        LLOG(n);
        int b = 0;

        for(int i=1; i<=n; ++i) {
            if (i % (2*k) == 0) {
                reverse(s.begin()+b, s.begin()+b+k);
                b=i;
                LLOG(b);
            }
        }
        LLOG(b);
        if(b+k<n) {
            reverse(s.begin()+b, s.begin()+b+k);
        } else {
            LLOG("test here");
            reverse(s.begin()+b, s.end());
        }

        return s;
    }
};

TEST_CASE("Doctest cases")
{
    Solution sol;

    string s;
    int k;

    s = "abcdefg";
    k = 2;
    CHECK(sol.reverseStr(s, k) == "bacdfeg");

    s = "abcd";
    k = 2;
    CHECK(sol.reverseStr(s, k) == "bacd");

    s = "krmyfshbspcgtesxnnljhfursyissjnsocgdhgfxubewllxzqhpasguvlrxtkgatzfybprfmmfithphckksnvjkcvnsqgsgosfxc";
    k = 20;
    CHECK(sol.reverseStr(s, k) == "jlnnxsetgcpsbhsfymrkhfursyissjnsocgdhgfxtxrlvugsaphqzxllwebukgatzfybprfmmfithphccxfsogsgqsnvckjvnskk");
}
