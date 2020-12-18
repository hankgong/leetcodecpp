#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

using namespace std;

/**
You are given two strings a and b of the same length. Choose an index and split both strings at the same index, splitting a into two strings: aprefix and asuffix where a = aprefix + asuffix, and splitting b into two strings: bprefix and bsuffix where b = bprefix + bsuffix. Check if aprefix + bsuffix or bprefix + asuffix forms a palindrome.

When you split a string s into sprefix and ssuffix, either ssuffix or sprefix is allowed to be empty. For example, if s = "abc", then "" + "abc", "a" + "bc", "ab" + "c" , and "abc" + "" are valid splits.

Return true if it is possible to form a palindrome string, otherwise return false.

Notice that x + y denotes the concatenation of strings x and y.

 

Example 1:

Input: a = "x", b = "y"
Output: true
Explaination: If either a or b are palindromes the answer is true since you can split in the following way:
aprefix = "", asuffix = "x"
bprefix = "", bsuffix = "y"
Then, aprefix + bsuffix = "" + "y" = "y", which is a palindrome.
Example 2:

Input: a = "abdef", b = "fecab"
Output: true
Example 3:

Input: a = "ulacfd", b = "jizalu"
Output: true
Explaination: Split them at index 3:
aprefix = "ula", asuffix = "cfd"
bprefix = "jiz", bsuffix = "alu"
Then, aprefix + bsuffix = "ula" + "alu" = "ulaalu", which is a palindrome.
Example 4:

Input: a = "xbdef", b = "xecab"
Output: false
 

Constraints:

1 <= a.length, b.length <= 105
a.length == b.length
a and b consist of lowercase English letters
*/

class Solution {
public:
    bool checkPalindromeFormation(string a, string b) {
        for (int i = 0; i <= a.size(); ++i)
        {
            string t1 = a.substr(0, i) + b.substr(i, a.size()-i);
            string t2 = b.substr(0, i) + a.substr(i, a.size()-i);
            println(t1, t2);

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

int main(int argc, char const *argv[])
{
    Solution s;

    cout << s.checkPalindromeFormation("x", "y") << endl;
    cout << s.checkPalindromeFormation("ulacfd", "jizalu") << endl;
    cout << s.checkPalindromeFormation("abdef", "fecab") << endl;
    return 0;
}
