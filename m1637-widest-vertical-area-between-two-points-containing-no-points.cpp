#define DEBUG
#include "hutility.hpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using namespace std;

/**
https://leetcode.com/problems/widest-vertical-area-between-two-points-containing-no-points/
*/

class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        vector<int> xs;
        for (int i = 0; i < points.size(); ++i) {
            xs.push_back(points[i][0]);
        }

        sort(xs.begin(), xs.end());

        int ret = 0;
        for (int i = 0; i < xs.size() - 1; ++i) {
            ret = max(ret, xs[i + 1] - xs[i]);
        }

        return ret;
    }
};

TEST_CASE("Doctest cases")
{
    Solution sol;

    vector<vector<int>> points;

    points = {{8,7},{9,9},{7,4},{9,7}};
    CHECK(sol.maxWidthOfVerticalArea(points) == 1);

    points = {{3,1},{9,0},{1,0},{1,4},{5,3},{8,8}};
    CHECK(sol.maxWidthOfVerticalArea(points) == 3);
}
