#define DEBUG
#include "hutility.hpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using namespace std;

/**
https://leetcode.com/problems/valid-sudoku/
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

TEST_CASE("Doctest cases")
{
    Solution sol;

    vector<vector<char>> board;

    board = {{'8', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    CHECK(sol.isValidSudoku(board) == false);
}
