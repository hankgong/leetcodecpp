#define DEBUG
#include "hutility.hpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using namespace std;

/**
https://leetcode-cn.com/problems/excel-sheet-column-number/
*/

class Solution {
public:
    int titleToNumber(string columnTitle) {
        int ret = 0;
        for (int i = 0; i < columnTitle.size(); ++i) {
            ret = ret * 26 + (columnTitle[i] - 'A' + 1);
        }
        return ret;
    }
};


TEST_CASE("Doctest cases")
{
    Solution sol;

    string columnTitle;

    columnTitle = "A";
    CHECK(sol.titleToNumber(columnTitle) == 1);

    columnTitle = "AB";
    CHECK(sol.titleToNumber(columnTitle) == 28);

    columnTitle = "ZY";
    CHECK(sol.titleToNumber(columnTitle) == 701);    
}
