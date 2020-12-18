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
https://leetcode-cn.com/problems/reverse-string-ii/
*/

class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.size();
        LLOG(n);
        int b = 0;

        for(int i=1; i<=n; ++i) {
            if (i % (2*k) == 0) {
                reverse(s.begin()+b, s.begin()+b+k);
                b=i;
                LLOG(b);
            }
        }
        LLOG(b);
        if(b+k<n) {
            reverse(s.begin()+b, s.begin()+b+k);
        } else {
            LLOG("test here");
            reverse(s.begin()+b, s.end());
        }

        return s;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    LOG(s.reverseStr("abcdefg", 2));
    LOG(s.reverseStr("krmyfshbspcgtesxnnljhfursyissjnsocgdhgfxubewllxzqhpasguvlrxtkgatzfybprfmmfithphckksnvjkcvnsqgsgosfxc", 20));


    return 0;
}
