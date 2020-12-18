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
https://leetcode-cn.com/problems/design-tic-tac-toe/
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

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */

int main(int argc, char const *argv[])
{
    // TicTacToe* obj = new TicTacToe(3);
    // int res;
    // res = obj->move(0,0,1);
    // LLOG(res);

    // res = obj->move(0,2,2);
    // LLOG(res);

    // res = obj->move(2,2,1);
    // LLOG(res);

    // res = obj->move(1,1,2);
    // LLOG(res);

    // res = obj->move(2,0,1);
    // LLOG(res);

    // res = obj->move(1,0,2);
    // LLOG(res);

    // res = obj->move(2,1,1);
    // LLOG(res);

    TicTacToe* obj = new TicTacToe(2);
    int res;
    res = obj->move(0,1,1);
    LLOG(res);

    res = obj->move(1,1,2);
    LLOG(res);

    res = obj->move(1,0,1);
    LLOG(res);
    return 0;
}
