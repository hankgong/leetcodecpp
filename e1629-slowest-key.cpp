#define DEBUG
#include "hutility.hpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using namespace std;

/**
https://leetcode.com/problems/slowest-key/
*/

class Solution {
public:
    char slowestKey(vector<int>& R, string K) {
        R.insert(R.begin(), 0);

        int curMax = -1;
        int curChr = 0;
        for (int i = 1; i < R.size(); ++i) {
            LLOG(R[i] - R[i - 1], K[i - 1]);
            if (R[i] - R[i - 1] > curMax) {
                curChr = K[i - 1];
                curMax = R[i] -  R[i - 1];
            } else if (R[i] - R[i - 1] == curMax && K[i - 1] > curChr ) {
                curChr = K[i - 1];
                curMax = R[i] -  R[i - 1];
            }
        }
        return curChr;
    }
};

TEST_CASE("testing the factorial function")
{
    Solution s;
    vector<int> v;

    v = {9, 29, 49, 50};
    CHECK(s.slowestKey(v, "cbcd"));

    v = {12, 23, 36, 46, 62};
    CHECK(s.slowestKey(v, "spuda"));
}


TEST_CASE("another test")
{
    Solution s;
    vector<int> v;

    v = {9, 29, 49, 50};
    CHECK(s.slowestKey(v, "cbcd"));

    v = {12, 23, 36, 46, 62};
    CHECK(s.slowestKey(v, "spuda"));
}