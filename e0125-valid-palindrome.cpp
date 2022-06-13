#define DEBUG
#include "hutility.hpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using namespace std;

/**
https://leetcode-cn.com/problems/valid-palindrome/
*/

class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0, r = s.size() - 1;

        while (l < r) {
            if (!isalnum(s[l])) {
                ++l;
            } else if (!isalnum(s[r])) {
                --r;
            } else {
                if (tolower(s[l++]) != tolower(s[r--])) {
                    return false;
                }    
            }
        }

        return true;
    }
};

TEST_CASE("Doctest cases")
{
    Solution sol;

    string s;

    s = "race a car";
    CHECK(sol.isPalindrome(s) == false);

    s = " ";
    CHECK(sol.isPalindrome(s) == true);

    s = "A man, a plan, a canal: Panama";
    CHECK(sol.isPalindrome(s) == true);
}




