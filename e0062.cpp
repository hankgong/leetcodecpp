#include <iostream>
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

#define println(msg) cout << (msg) << endl
#define println2(m1, m2) cout << (m1) << " " << (m2) << endl
#define println3(m1, m2, m3) cout << (m1) << " " << (m2) << " " << (m3) << endl
#define println4(m1, m2, m3, m4) cout << (m1) << " " << (m2) << " " << (m3) << " " << (m4) << endl
#define println5(m1, m2, m3, m4, m5) cout << (m1) << " " << (m2) << " " << (m3) << " " << (m4) << " " << (m5)<< endl


/**

*/

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp;

        for (int i = 0; i < n; ++i) {
            dp.push_back(vector<int>(m, 0));
        }

        for (int i = 0; i < n; ++i) {
            dp[i][0] = 1;
        }

        for (int j = 0; j < m; ++j) {
            dp[0][j] = 1;
        }

        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < m; ++j) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        return dp[n - 1][m - 1];
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    println(s.uniquePaths(3, 2));
    println(s.uniquePaths(3, 1));
    println(s.uniquePaths(1, 10));

    return 0;
}
