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
#include <unordered_set>
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
https://leetcode-cn.com/problems/remove-duplicate-letters/
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

int main(int argc, char const *argv[])
{
    Solution s;

    LOG(s.removeDuplicateLetters("bcabc"));
    LOG(s.removeDuplicateLetters("cbacdcbc"));
    LOG(s.removeDuplicateLetters("bbcaac"));
    LOG(s.removeDuplicateLetters("abacb"));


    return 0;
}
