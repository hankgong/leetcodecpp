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
https://leetcode-cn.com/problems/factorial-trailing-zeroes/
*/

class Solution {
public:
    int trailingZeroes(int n) {
        int ret = 0;

        while (n > 0) {
           n /= 5; 
           ret += n;
        }

        return ret;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    LOG(s.trailingZeroes(5));
    LOG(s.trailingZeroes(3));
    LOG(s.trailingZeroes(10));


    return 0;
}
