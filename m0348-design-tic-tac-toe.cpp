#define DEBUG
#include "hutility.hpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using namespace std;

/**
https://leetcode.com/problems/design-tic-tac-toe/
*/

class TicTacToe {
public:
    /** Initialize your data structure here. */
    vector<vector<int>> cnt;
    int N;
    TicTacToe(int n) {
        cnt = vector<vector<int>>(2*n+2, {0, 0});
        N = n;
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        cnt[row][player-1]++;
        if (cnt[row][player-1] == N) return player;
        
        cnt[N+col][player-1]++;
        if (cnt[N+col][player-1] == N) return player;

        if (row == col) {
            cnt[2*N][player-1]++;
            if (cnt[2*N][player-1] == N) return player;
        }

        if (row + col == N-1) {
            cnt[2*N+1][player-1]++;
            if (cnt[2*N+1][player-1] == N) return player;
        }

        LLOG(cnt);

        return 0;
    }
};

TEST_CASE("Doctest cases")
{
    TicTacToe* obj = new TicTacToe(2);
    int res;
    res = obj->move(0,1,1);
    LLOG(res);

    res = obj->move(1,1,2);
    LLOG(res);

    res = obj->move(1,0,1);
    LLOG(res);
}

