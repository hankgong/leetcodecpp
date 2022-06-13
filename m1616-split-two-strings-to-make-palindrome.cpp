#define DEBUG
#include "hutility.hpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using namespace std;

/**
https://leetcode.com/problems/split-two-strings-to-make-palindrome/
*/

class Solution {
public:
    bool checkPalindromeFormation(string a, string b) {
        for (int i = 0; i <= a.size(); ++i)
        {
            string t1 = a.substr(0, i) + b.substr(i, a.size()-i);
            string t2 = b.substr(0, i) + a.substr(i, a.size()-i);
            LOG(t1, t2);

            if (isPalindrome(t1) || isPalindrome(t2)){
                return true;
            }
        }

        return false;
    }

    bool isPalindrome(string a) {
        int i = 0;
        int j = a.size()-1;
        while (i < j) {
            if (a[i] == a[j]) {
                i++;
                j--;    
            } else {
                return false;
            }
            
        }
        return true;
    }
};

TEST_CASE("Doctest cases")
{
    Solution sol;

    string a;
    string b;

    a = "x";
    b = "y";
    CHECK(sol.checkPalindromeFormation(a, b) == true);

    a = "xbdef";
    b = "xecab";
    CHECK(sol.checkPalindromeFormation(a, b) == false);

    a = "ulacfd";
    b = "jizalu";
    CHECK(sol.checkPalindromeFormation(a, b) == true);
}
