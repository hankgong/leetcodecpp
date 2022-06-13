#define DEBUG
#include "hutility.hpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using namespace std;

/**
https://leetcode.com/problems/smallest-string-with-a-given-numeric-value/
*/

class Solution {
public:
    string getSmallestString(int n, int k) {
        string ret(n, 'a');
        int l = k-n;            //left amount after using all "a....a" as a start 

        int pos = n-1;          //greedy from back to forth
        while (l > 25) {
            ret[pos--] = 'z';   //if can use z, use z
            l -= 25;
        }
        ret[pos] = 'a' + l;     //use up left over
        return ret;
    }
};

TEST_CASE("Doctest cases")
{
    Solution sol;

    int n;
    int k;

    n = 3;
    k = 27;
    CHECK(sol.getSmallestString(n, k) == "aay");

    n = 5;
    k = 73;
    CHECK(sol.getSmallestString(n, k) == "aaszz");
}
