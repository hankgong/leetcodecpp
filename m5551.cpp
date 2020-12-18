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
https://leetcode-cn.com/contest/biweekly-contest-39/problems/minimum-deletions-to-make-string-balanced/
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

int main(int argc, char const *argv[])
{
    Solution s;

    LOG(s.minimumDeletions("aababbab"));


    return 0;
}
