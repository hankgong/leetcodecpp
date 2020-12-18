#include <iostream>
#include <iomanip>
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
#include <climits>
#include "hutility.hpp"

using namespace std;

#define DEBUG
#ifdef DEBUG
void LOG() {cout << endl;}
template<typename Head, typename... Args>
void LOG(const Head& head, const Args&... args )
{
    cout << head << " ";
    LOG(args...);
}

#define LLOG(...) cout<<"L"<<left<<setw(4)<<__LINE__;LOG(__VA_ARGS__)
#else
#define LOG(...) do {} while(0)
#define LLOG(...) do {} while(0)
#endif

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

int main(int argc, char const *argv[])
{
    Solution s;

    // LOG(s.isPalindrome("a"));
    // LOG(s.isPalindrome("ab"));
    // LOG(s.isPalindrome("aba"));
    // LOG(s.isPalindrome("ab a"));
    // LOG(s.isPalindrome("a, b a"));
    LOG(s.isPalindrome("A man, a plan, a canal: Panama"));
    LOG(s.isPalindrome("race a car"));
    // LOG(s.isPalindrome(""));
    // LOG(s.isPalindrome(" "));
    // LOG(s.isPalindrome(" "));
    LOG(s.isPalindrome(".,"));

    return 0;
}
