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
https://leetcode-cn.com/problems/excel-sheet-column-number/
*/

class Solution {
public:
    int titleToNumber(string s) {
        int ret = 0;
        for (int i = 0; i < s.size(); ++i) {
            ret = ret * 26 + (s[i] - 'A' + 1);
        }
        return ret;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    LOG(s.titleToNumber("A"));
    LOG(s.titleToNumber("A"));
    LOG(s.titleToNumber("ZY"));


    return 0;
}
