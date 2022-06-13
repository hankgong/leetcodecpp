#define DEBUG
#include "hutility.hpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using namespace std;

/**
https://leetcode.com/problems/minimum-deletions-to-make-string-balanced/
*/

class Solution {
public:
    int minimumDeletions(string s) {
        stack<char> char_stack;
        int cnt=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='b')
                char_stack.push(s[i]);
            else
            {
                if(!char_stack.empty())
                {
                    cnt++;
                    char_stack.pop();
                }
            }
            LLOG(s[i], char_stack.size());
        }
        return cnt;
    }
};

TEST_CASE("Doctest cases")
{
    Solution sol;

    string s;

    s = "aababbab";
    CHECK(sol.minimumDeletions(s) == 2);

    s = "bbaaaaabb";
    CHECK(sol.minimumDeletions(s) == 2);
}
