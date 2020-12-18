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
https://leetcode-cn.com/problems/set-matrix-zeroes/
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

int main(int argc, char const *argv[])
{
    Solution s;

    vector<vector<int>> matrix;

    matrix={
  {0,1,2,0},
  {3,4,5,2},
  {1,3,1,5}
};
    s.setZeroes(matrix);
    LOG(matrix);

    matrix={
  {1,1,1},
  {1,0,1},
  {1,1,1}
};
    s.setZeroes(matrix);
    LOG(matrix);


    return 0;
}
