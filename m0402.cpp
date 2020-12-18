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
https://leetcode-cn.com/problems/remove-k-digits/
*/

class Solution {
public:
    string removeKdigits(string num, int k) {
        string ret="";
        int count = 0;
        for(int i=0; i<num.size(); ++i) {
            while(ret.size()>0 && num[i]<ret.back() && count<k) {
                ret.pop_back();
                count++;
            }

            ret.push_back(num[i]);
        }

        while(count < k) {
            // LLOG(ret, count);
            ret.pop_back();
            count++;
        }

        // LLOG(ret.size(), ret);
        int i=0;
        while(ret[i]=='0') {i++;}
        ret.erase(ret.begin(), ret.begin()+i);
        if(ret.size()==0) {return "0";}
        return ret;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    LOG(s.removeKdigits("1432219", 3));
    LOG(s.removeKdigits("10200", 1));
    LOG(s.removeKdigits("10", 2));
    LOG(s.removeKdigits("10", 1));
    LOG(s.removeKdigits("1111111", 3));
    LOG(s.removeKdigits("1234567890", 9));


    return 0;
}
