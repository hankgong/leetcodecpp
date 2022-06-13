#define DEBUG
#include "hutility.hpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using namespace std;

/**
https://leetcode.com/problems/set-matrix-zeroes/
*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool willColReset = false;
        int m = matrix.size();
        int n = matrix[0].size();

        for (int i=0; i<m; ++i) {
            //check if col 0 needs to reset
            if (matrix[i][0] == 0) {
                willColReset = true;
            }
        }

        //check and record
        for (int i = 0; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        LLOG(matrix);

        //process all data except first row and first column
        for (int i = 1; i < m; ++i) {
            for(int j=1; j< n; ++j) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        //process first row
        if(matrix[0][0] == 0) {
            for (int j = 0; j < n; ++j) {
                matrix[0][j] = 0;
            }
        }

        //process first column
        if (willColReset == true) {
            for (int i = 0; i < m; ++i) {
                matrix[i][0] = 0;
            }
        }
    }
};

TEST_CASE("Doctest cases")
{
    Solution sol;

    vector<vector<int>> matrix;

    matrix = {{1,1,1},{1,0,1},{1,1,1}};
    sol.setZeroes(matrix);
    CHECK(matrix == vector<vector<int>>{{1,0,1},{0,0,0},{1,0,1}});

    matrix = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    sol.setZeroes(matrix);
    CHECK(matrix == vector<vector<int>>{{0,0,0,0},{0,4,5,0},{0,3,1,0}});
}
