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
https://leetcode-cn.com/problems/maximize-grid-happiness/
*/

class Solution {
public:
    int getMaxGridHappiness(int m, int n, int a, int b) {
        //0 no placement 1 invert 3 extravert
        int cases = pow(3, n);
        int case_1 = pow(3, n-1);

        int offset[3][3] = {0, 0, 0, 0, -60, -10, 0, -10, 40};

        int M = cases -1;
        int dp[m*n+1][a+1][b+1][cases];
        memset(dp, 0, sizeof(dp));

        for(int coor=m*n-1; coor >=0; --coor) {
            int i = coor/n, j = coor%n;
            for(int x=0; x<=a; ++x) {
                for(int y=0; y<=b; ++y) {
                    for(int pre=0; pre<cases; ++pre) {
                        int nem = (pre*3)%cases;
                        if(x>0) {
                            int diff = 120 + (j!=0)*offset[1][pre%3] + offset[1][pre/case_1];
                            dp[coor][x][y][pre] = max(dp[coor][x][y][pre], diff + dp[coor+1][x-1][y][nem+1]);
                        }
                        if(y>0) {
                            int diff = 40 + (j!=0)*offset[2][pre%3] + offset[2][pre/case_1];
                            dp[coor][x][y][pre] = max(dp[coor][x][y][pre], diff + dp[coor+1][x][y-1][nem+2]);
                        }
                        dp[coor][x][y][pre] = max(dp[coor][x][y][pre], dp[coor+1][x][y][nem]);
                    }
                }
            }
        }
        return dp[0][a][b][0];
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    LOG(s.getMaxGridHappiness(3, 2, 2, 2));


    return 0;
}
