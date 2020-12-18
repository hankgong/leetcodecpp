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
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<int> ret;
        int m = matrix.size();
        int n = matrix[0].size();

        int cnt = 0, i = 0, j = 0, op=0;
        int l=0, r=n-1, t=0, b=m-1;
        while (cnt < m*n){
            ret.push_back(matrix[i][j]);
            int ni=i+dir[op%4][0];
            int nj=j+dir[op%4][1];
            cnt++;
            if(ni>=t&&ni<=b&&nj>=l&&nj<=r) {
                i = ni;
                j = nj;
            } else {
                if (op%4 == 0){
                    t++;
                } else if (op%4==1) {
                    r--;
                } else if (op%4==2) {
                    b--;
                } else {
                    l++;
                }
                op++;
                i=i+dir[op%4][0];
                j=j+dir[op%4][1];
            }
        }
        return ret;
    }

    vector<int> spiralOrder_old(vector<vector<int>>& matrix) {
        if (matrix.empty()) return {};
        int numRow = matrix.size(), numCol = matrix[0].size();

        int rowMin = 0, rowMax = numRow - 1;
        int colMin = 0, colMax = numCol - 1;

        int curOp = 0;
        int i = 0, j = 0;

        int cnt = 0;

        vector<int> ret;
        while (cnt < numRow * numCol) {
            //get one element
            // println(matrix[i][j]);
            ret.push_back(matrix[i][j]);
            cnt++;

            if (curOp % 4 == 0) {
                if (j < colMax) {
                    j++;
                } else {
                    i++;
                    curOp++;
                    rowMin++;
                }
            } else if (curOp % 4 == 1) {
                if (i < rowMax) {
                    i++;
                } else {
                    j--;
                    curOp++;
                    colMax--;
                }
            } else if (curOp % 4 == 2) {
                if (j > colMin) {
                    j--;
                } else {
                    i--;
                    curOp++;
                    rowMax--;
                }
            } else {
                if (i > rowMin) {
                    i--;
                } else {
                    j++;
                    curOp++;
                    colMin++;
                }
            }
        }

        return ret;
    }
};


int main(int argc, char const *argv[])
{
    Solution s;
    vector<vector<int>> v;
    v = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    println(s.spiralOrder(v));

    v = {{1, 2, 3}};
    println(s.spiralOrder(v));

    v = {{1, 2, 3, 4},  {5, 6, 7, 8}, {9, 10, 11, 12}};
    println(s.spiralOrder(v));

    v = {{1},  {5}, {9}};
    println(s.spiralOrder(v));

    v = {};
    println(s.spiralOrder(v));
    return 0;
}
