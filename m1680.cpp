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

*/

class Solution {
public:
    int concatenatedBinary(int n) {
        long ret = 0;
        int mod = 1e9+7;
        int shift=0;

        for(int i=1; i<=n; ++i) {
            if((i&(i-1))==0) shift++;
            // LLOG(i, int(log2(i)), ret*pow(2, int(log2(i)+1)), i);
            ret = (ret<<shift) + i;
            LLOG(i, shift, ret);
            ret %= mod;
        }
        return ret;
    }
    int concatenatedBinary_myown(int n) {
        long ret = 0;
        int mod = 1000000007;

        for(int i=1; i<=n; ++i) {
            LLOG(i, int(log2(i)), ret*pow(2, int(log2(i)+1)), i);
            ret = ret*pow(2, int(log2(i)+1)) + i;
            ret %= mod;
        }
        return ret;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    LOG(s.concatenatedBinary(10000));


    return 0;
}
