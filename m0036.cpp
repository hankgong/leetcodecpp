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
https://leetcode-cn.com/problems/valid-sudoku/
*/

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int N = 9;
        vector<char> tochk;
        for (int i = 0; i < N; i++) {
            tochk.clear();
            tochk = board[i];
            if (!isOK(tochk)) return false;
        }

        for (int i = 0; i < N; i++) {
            tochk.clear();
            for (int j = 0; j < N; j++) {
                tochk.push_back(board[j][i]);
            }
            if (!isOK(tochk)) return false;
        }

        for (int g = 0; g < N; g++) {
            tochk.clear();
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    tochk.push_back(board[(g / 3) * 3 + i][(g % 3) * 3 + j]);
                }
            }
            if (!isOK(tochk)) return false;
        }

        return true;
    }

    bool isOK(vector<char> nums) {
        unordered_map<char, int> m;
        for (auto &n : nums) {
            if (n != '.') {
                ++m[n];
                if (m[n] > 1) return false;
            }
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<vector<char>> board;

    board = {{'8', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };
    LOG(s.isValidSudoku(board));


    return 0;
}
