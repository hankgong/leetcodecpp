#define DEBUG
#include "hutility.hpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using namespace std;

/**
https://leetcode-cn.com/problems/path-with-maximum-minimum-value/
*/

class Solution {
public:
    vector<vector<int>> dir = {{1, 0}, { -1, 0}, {0, 1}, {0, -1}};
    int maximumMinimumPath_bfs(vector<vector<int>>& A) {
        int nRow = A.size();
        int nCol = A[0].size();
        int l = 0;
        int r = min(int(1e9), A[0][0]);

        while (l < r) {
            int m = l + (r - l + 1) / 2;
            LOG(l, m, r);

            queue<pair<int, int>> q;
            q.push(make_pair(0, 0));

            vector<vector<bool>> vis(nRow, vector<bool>(nCol, false));

            while (!q.empty()) {
                int i, j;
                tie(i, j) = q.front();
                q.pop();

                for ( auto &d : dir) {
                    int ni = i + d[0];
                    int nj = j + d[1];

                    if (ni >= 0 && ni < nRow && nj >= 0 && nj < nCol && !vis[ni][nj] && A[ni][nj] >= m) {
                        q.push(make_pair(ni, nj));
                        vis[ni][nj] = true;
                    }
                }
            }

            if (vis[nRow - 1][nCol - 1]) {
                l = m;
            } else {
                r = m - 1;
            }
        }

        LOG(l, r);
        return l;
    }


    int maximumMinimumPath(vector<vector<int>>& A) {

    }

    bool dfs(int i, int j, int m, vector<vector<int>>& A, vector<vector<bool>>& vis) {
        if (i == A.size() - 1 && j == A[0].size() - 1) {
            return true;
        }

        vis[i][j] = true;

        for (auto &d : dir) {
            int ni = i + d[0];
            int nj = j + d[1];

            if (ni >= 0 && ni < nRow && nj >= 0 && nj < nCol && !vis[ni][nj] && A[ni][nj] >= m) {
                return dfs (ni, nj, m, A, vis);
            }
        }

        return false;
    }
};

TEST_CASE("Doctest cases")
{
    Solution sol;
}




int main(int argc, char const *argv[])
{
    Solution s;
    vector<vector<int>> A;

    // A = {{5, 4, 5}, {1, 2, 6}, {7, 4, 6}};
    // LOG(s.maximumMinimumPath(A));

    // A = {{2, 2, 1, 2, 2, 2}, {1, 2, 2, 2, 1, 2}};
    // LOG(s.maximumMinimumPath(A));

    // A = {{3, 4, 6, 3, 4}, {0, 2, 1, 1, 7}, {8, 8, 3, 2, 7}, {3, 2, 4, 9, 8}, {4, 1, 2, 0, 0}, {4, 6, 5, 4, 3}};
    // LOG(s.maximumMinimumPath(A));

    A = {{0, 1, 0, 0, 0, 1}, {0, 1, 1, 0, 0, 0}, {0, 0, 1, 1, 0, 1}, {0, 1, 1, 1, 1, 0}, {1, 1, 1, 1, 1, 1}};
    LOG(s.maximumMinimumPath(A));
    return 0;
}
