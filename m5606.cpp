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
https://leetcode-cn.com/contest/weekly-contest-216/problems/smallest-string-with-a-given-numeric-value/
*/

class Solution {
public:
    string getSmallestString(int n, int k) {
        string ret(n, 'a');
        int l = k-n;            //left amount after using all "a....a" as a start 

        int pos = n-1;          //greedy from back to forth
        while (l > 25) {
            ret[pos--] = 'z';   //if can use z, use z
            l -= 25;
        }
        ret[pos] = 'a' + l;     //use up left over
        return ret;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    LOG(s.getSmallestString(3, 27));
    LOG(s.getSmallestString(5, 73));


    return 0;
}
