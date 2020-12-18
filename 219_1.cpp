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
    int numberOfMatches_mine(int n) {
        int ret=0;
        while(n>1) {
            int isOdd = (n%2==1);
            n/=2;
            ret+=n;
            if (isOdd) n++;
        }

        return ret;
    }

    int numberOfMatches(int n) {
        return n-1;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    LOG(s.numberOfMatches(1));
    LOG(s.numberOfMatches(2));
    LOG(s.numberOfMatches(3));
    LOG(s.numberOfMatches(4));
    LOG(s.numberOfMatches(5));
    LOG(s.numberOfMatches(6));
    LOG(s.numberOfMatches(7));
    LOG(s.numberOfMatches(14));


    return 0;
}
