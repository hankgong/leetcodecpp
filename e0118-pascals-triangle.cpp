#define DEBUG
#include "hutility.hpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using namespace std;

/**
https://leetcode-cn.com/problems/pascals-triangle/
*/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows == 0) return {};
        if (numRows == 1) return {{1}};

        vector<vector<int>> ret = {{1}};

        for (int i = 1; i < numRows; ++i) {
            vector<int> lastRow = ret.back();
            lastRow.insert(lastRow.begin(), 0);
            lastRow.push_back(0);

            vector<int> toadd;
            for (int i = 0; i < lastRow.size()-1; ++i) {
                toadd.push_back(lastRow[i]+lastRow[i+1]);
            }
            ret.push_back(toadd);
        }

        return ret;
    }
};

TEST_CASE("test results")
{
    Solution sol;

    int numRows;
    CHECK(sol.generate(1) == vector<vector<int>>{{1}});
    CHECK(sol.generate(2) == vector<vector<int>>{{1}, {1, 1}});
    CHECK(sol.generate(3) == vector<vector<int>>{{1}, {1, 1}, {1, 2, 1}});
    CHECK(sol.generate(4) == vector<vector<int>>{{1}, {1, 1}, {1, 2, 1}, {1, 3, 3, 1}});

    numRows = 5;
    CHECK(sol.generate(numRows) == vector<vector<int>>{{1},{1,1},{1,2,1},{1,3,3,1},{1,4,6,4,1}});

    numRows = 1;
    CHECK(sol.generate(numRows) == vector<vector<int>>{{1}});
}
