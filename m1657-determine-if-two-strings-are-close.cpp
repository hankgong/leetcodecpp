#define DEBUG
#include "hutility.hpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using namespace std;

/**
https://leetcode.com/problems/determine-if-two-strings-are-close/
*/

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.size() != word2.size()) return false;
        vector<int> v1(26, 0);
        vector<int> v2(26, 0);

        for (int i = 0; i < word1.size(); ++i) {
            v1[word1[i]-'a']++;
            v2[word2[i]-'a']++;
        }

        for (int i = 0; i < 26; ++i) {
            if ((v1[i] == 0) ^ (v2[i] == 0)) return false;
        }

        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());

        return v1==v2;
        
    }

    bool closeStrings_fullstl(string word1, string word2) {
        if (word1.size() != word2.size()) return false;
        unordered_map<char, int> m1, m2;

        for (int i = 0; i < word1.size(); ++i) {
            m1[word1[i]]++;
            m2[word2[i]]++;
        }

        unordered_set<char> s1, s2;
        vector<int> v1, v2;
        for (auto &[k, v] : m1) {
            s1.insert(k);
            v1.push_back(v);
        }

        for (auto &[k, v] : m2) {
            s2.insert(k);
            v2.push_back(v);
        }

        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());

        return (s1==s2) && (v1 == v2);
    }
};


TEST_CASE("Doctest cases")
{
    Solution sol;

    string word1;
    string word2;

    word1 = "abc";
    word2 = "bca";
    CHECK(sol.closeStrings(word1, word2) == true);

    word1 = "a";
    word2 = "aa";
    CHECK(sol.closeStrings(word1, word2) == false);

    word1 = "cabbba";
    word2 = "abbccc";
    CHECK(sol.closeStrings(word1, word2) == true);
}
