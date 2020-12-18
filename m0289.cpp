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
https://leetcode-cn.com/problems/game-of-life/
*/

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        if (m==0) return;
        int n = board[0].size();

        //-1 means 0 to 1 and 2 means 1->0
        for(int i =0; i<m; ++i) {
            for(int j = 0; j<n; ++j) {
                int s = 0;
                if (i-1>=0 && j-1>=0 && board[i-1][j-1]>0) s++;
                if (i-1>=0 && j>=0 && board[i-1][j]>0) s++;
                if (i-1>=0 && j+1<n && board[i-1][j+1]>0) s++;
                if (i>=0 && j-1>=0 && board[i][j-1]>0) s++;
                if (i>=0 && j+1<n && board[i][j+1]>0) s++;
                if (i+1<m && j-1>=0 && board[i+1][j-1]>0) s++;
                if (i+1<m && j>=0 && board[i+1][j]>0) s++;
                if (i+1<m && j+1<n && board[i+1][j+1]>0) s++;

                if (board[i][j] == 1 && s < 2) {
                    board[i][j] = 2;
                }

                if (board[i][j] == 1 && s > 3) {
                    board[i][j] = 2;
                }

                if (board[i][j] == 0 && s == 3) {
                    board[i][j] = -1;
                }
            }
        }


        for(int i =0; i<m; ++i) {
            for(int j = 0; j<n; ++j) {
                if (board[i][j] == 2) board[i][j] = 0;
                if (board[i][j] == -1) board[i][j] = 1;
            }
        }

    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    vector<vector<int>> board;

    board={
  {0,1,0},
  {0,0,1},
  {1,1,1},
  {0,0,0}
};
    s.gameOfLife(board);
    LLOG(board);


    return 0;
}
