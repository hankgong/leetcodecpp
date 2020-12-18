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
https://leetcode-cn.com/problems/power-of-three/
*/

class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) return false;
        while (n > 1) {
            if (n%3 != 0) return false;
            n /= 3;
        }

        return true;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    LOG(s.isPowerOfThree(-1));
    LOG(s.isPowerOfThree(0));
    LOG(s.isPowerOfThree(1));
    LOG(s.isPowerOfThree(2));
    LOG(s.isPowerOfThree(3));
    LOG(s.isPowerOfThree(4));
    LOG(s.isPowerOfThree(6));
    LOG(s.isPowerOfThree(9));


    return 0;
}
