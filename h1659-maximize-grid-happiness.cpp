#define DEBUG
#include "hutility.hpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using namespace std;

/**
https://leetcode.cn/problems/maximize-grid-happiness/
*/

class Solution {
public:
    int getMaxGridHappiness(int m, int n, int introvertsCount, int extrovertsCount) {
        //0 no placement 1 invert 3 extravert
        int cases = pow(3, n);
        int case_1 = pow(3, n-1);

        int offset[3][3] = {0, 0, 0, 0, -60, -10, 0, -10, 40};

        int M = cases -1;
        int dp[m*n+1][introvertsCount+1][extrovertsCount+1][cases];
        memset(dp, 0, sizeof(dp));

        for(int coor=m*n-1; coor >=0; --coor) {
            int i = coor/n, j = coor%n;
            for(int x=0; x<=introvertsCount; ++x) {
                for(int y=0; y<=extrovertsCount; ++y) {
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
        return dp[0][introvertsCount][extrovertsCount][0];
    }
};

TEST_CASE("Doctest cases")
{
    Solution sol;

    int m;
    int n;
    int introvertsCount;
    int extrovertsCount;

    m = 2;
    n = 3;
    introvertsCount = 1;
    extrovertsCount = 2;
    CHECK(sol.getMaxGridHappiness(m, n, introvertsCount, extrovertsCount) == 240);

    m = 3;
    n = 1;
    introvertsCount = 2;
    extrovertsCount = 1;
    CHECK(sol.getMaxGridHappiness(m, n, introvertsCount, extrovertsCount) == 260);

    m = 2;
    n = 2;
    introvertsCount = 4;
    extrovertsCount = 0;
    CHECK(sol.getMaxGridHappiness(m, n, introvertsCount, extrovertsCount) == 240);
}
