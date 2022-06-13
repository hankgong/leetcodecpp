#define DEBUG
#include "hutility.hpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using namespace std;

/**
https://leetcode.com/problems/game-of-life/
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

TEST_CASE("Doctest cases")
{
    Solution sol;

    vector<vector<int>> board;

    board = {{0,1,0},{0,0,1},{1,1,1},{0,0,0}};
    sol.gameOfLife(board);
    CHECK(board == vector<vector<int>>{{0,0,0},{1,0,1},{0,1,1},{0,1,0}});

    board = {{1,1},{1,0}};
    sol.gameOfLife(board);
    CHECK(board == vector<vector<int>>{{1,1},{1,1}});
}
