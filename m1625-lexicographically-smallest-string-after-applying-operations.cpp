#define DEBUG
#include "hutility.hpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using namespace std;

/**
https://leetcode.com/problems/lexicographically-smallest-string-after-applying-operations/
*/

class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        string ret = s;
        int n = s.size();

        //rotate is even number
        if (b%2 == 0) {
            for (int i=1; i<=10; i++){
                for (int j=1; j<=n; j++) {
                    string tmps = s;

                    //add
                    for (int k=1; k<n; k+=2) {
                        tmps[k] = '0' + (tmps[k] -'0' + i*a) % 10;
                    }
                    //rotate
                    int m = j*b%n;
                    tmps = tmps.substr(m, n-m) + tmps.substr(0, m);

                    ret = min(ret, tmps);
                }
            }
        } else {
            for (int i=1; i<=10; i++) {
                for (int l=1; l<=10; l++) {
                    for (int j=1; j<=n; j++) {
                        string tmps = s;

                        //add
                        for (int k=1; k<n; k+=2) {
                            tmps[k] = '0' + (tmps[k] -'0' + i*a) % 10;
                            tmps[k-1] = '0' + (tmps[k-1] -'0' + l*a) % 10;
                        }

                        //rotate
                        int m = j*b%n;
                        tmps = tmps.substr(m, n-m) + tmps.substr(0, m);

                        ret = min(ret, tmps);
                    }
                }
            }
        }

        return ret;
    }
};

TEST_CASE("Doctest cases")
{
    Solution sol;

    string s;
    int a;
    int b;

    s = "5525";
    a = 9;
    b = 2;
    CHECK(sol.findLexSmallestString(s, a, b) == "2050");

    s = "74";
    a = 5;
    b = 1;
    CHECK(sol.findLexSmallestString(s, a, b) == "24");

    s = "0011";
    a = 4;
    b = 2;
    CHECK(sol.findLexSmallestString(s, a, b) == "0011");
}
