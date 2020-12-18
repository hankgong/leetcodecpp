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
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ret;
        for (int i = 0; i < n; ++i) {
            ret.push_back(vector<int>(n, 0));
        }

        vector<vector<int>> ops = {{0, 1}, {1, 0}, {0, -1}, { -1, 0}};
        int curOps = 0;

        int cnt = 0;
        int i = 0, j = 0;
        while (cnt < n * n) {
            // println5(i, j, curOps, ops[curOps % 4][0], ops[curOps % 4][1]);
            ret[i][j] = cnt + 1;
            cnt++;
            int ti = i + ops[curOps % 4][0];
            int tj = j + ops[curOps % 4][1];
            if (ti < 0 || ti >= n || tj < 0 || tj >= n || ret[ti][tj] != 0 ) {
                curOps++;
            }
            i += ops[curOps % 4][0];
            j += ops[curOps % 4][1];
        }
        return ret;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    println(s.generateMatrix(1));
    println(s.generateMatrix(2));
    println(s.generateMatrix(3));
    println(s.generateMatrix(5));

    return 0;
}
