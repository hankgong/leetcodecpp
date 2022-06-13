#define DEBUG
#include "hutility.hpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using namespace std;

/**
https://leetcode.com/problems/remove-duplicate-letters/
*/

class Solution {
public:
    string removeDuplicateLetters(string s) {
        int cnt[26];
        int used[26];
        memset(cnt, 0, sizeof(cnt));
        memset(used, 0, sizeof(used));

        for (int i = 0; i < s.size(); ++i) {
            cnt[s[i]-'a']++;
        }

        string ret="";
        for (int i = 0; i < s.size(); ++i) {
            cnt[s[i]-'a']--;
            if (used[s[i]-'a']) continue;
            
            while(!ret.empty() && ret.back()>s[i] && cnt[ret.back()-'a']>0) {
                used[ret.back()-'a'] = 0;
                ret.pop_back();

            }

            // LLOG(ret.empty(), ret.back(), s[i], cnt[ret.back()-'a']);
            ret.push_back(s[i]);
            used[s[i]-'a']=1;
        }

        return ret;
    }
};

TEST_CASE("Doctest cases")
{
    Solution sol;

    string s;

    s = "bcabc";
    CHECK(sol.removeDuplicateLetters(s) == "abc");

    s = "cbacdcbc";
    CHECK(sol.removeDuplicateLetters(s) == "acdb");
}
