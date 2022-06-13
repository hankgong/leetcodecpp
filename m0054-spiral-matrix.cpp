#define DEBUG
#include "hutility.hpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using namespace std;

/**
https://leetcode.cn/problems/spiral-matrix/
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

TEST_CASE("Doctest cases")
{
    Solution sol;

    vector<vector<int>> matrix;

    matrix = {{1,2,3},{4,5,6},{7,8,9}};
    CHECK(sol.spiralOrder(matrix) == vector<int>{1,2,3,6,9,8,7,4,5});

    matrix = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    CHECK(sol.spiralOrder(matrix) == vector<int>{1,2,3,4,8,12,11,10,9,5,6,7});

    matrix = {{1, 2, 3}};
    CHECK(sol.spiralOrder(matrix) == vector<int>{1, 2, 3});

    matrix = {{1}, {5}, {9}};
    CHECK(sol.spiralOrder(matrix) == vector<int>{1, 5, 9});

    matrix = {};
    CHECK(sol.spiralOrder(matrix) == vector<int>{});
}
