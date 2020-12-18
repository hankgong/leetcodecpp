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
https://leetcode-cn.com/problems/reverse-bits/
*/

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int ret= 0;
        for (int i = 0; i < 32; ++i) {
            ret <<= 1;
            ret |= n & 1;
            n >>= 1;
            LOG(ret, n);
        }
        return ret;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    LOG(s.reverseBits(43261596));


    return 0;
}
