#define DEBUG
#include "hutility.hpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using namespace std;

/**
https://leetcode.cn/problems/check-if-two-string-arrays-are-equivalent/
*/

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        // string s1, s2;
        // s1 = accumulate(word1.begin(), word1.end(), s1);
        // s2 = accumulate(word2.begin(), word2.end(), s2);

        return accumulate(word1.begin(), word1.end(), string("")) == accumulate(word2.begin(), word2.end(), string(""));
    }
};

TEST_CASE("Doctest cases")
{
    Solution sol;

    vector<string> word1;
    vector<string> word2;

    word1 = {"ab","c"};
    word2 = {"a","bc"};
    CHECK(sol.arrayStringsAreEqual(word1, word2) == true);

    word1 = {"a","cb"};
    word2 = {"ab","c"};
    CHECK(sol.arrayStringsAreEqual(word1, word2) == false);

    word1 = {"abc","d","defg"};
    word2 = {"abcddefg"};
    CHECK(sol.arrayStringsAreEqual(word1, word2) == true);
}
