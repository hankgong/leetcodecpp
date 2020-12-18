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
https://leetcode-cn.com/problems/plus-one/
*/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int c = 1;
        vector<int> ret;

        for(int i=digits.size()-1; i>=0; --i) {
            digits[i] += c;
            c = digits[i]/10;
            ret.insert(ret.begin(), digits[i]%10);
        }

        if (c) ret.insert(ret.begin(), c);
        return ret;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> digits;

    digits= {1, 2, 3};
    LOG(s.plusOne(digits));

    digits= {9, 9, 9};
    LOG(s.plusOne(digits));

    digits={4,3,2,1};
    LOG(s.plusOne(digits));
    return 0;
}
