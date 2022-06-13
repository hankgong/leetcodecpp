#define DEBUG
#include "hutility.hpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using namespace std;

/**
https://leetcode.com/problems/coordinate-with-maximum-network-quality/
*/

class Solution {
public:
    vector<int> bestCoordinate(vector<vector<int>>& towers, int radius) {
        vector<int> ret = {51, 51};
        vector<int> dot = {0, 0};
        int curMax=0;

        int xMin = 50, xMax = 0;
        int yMin = 50, yMax = 0;

        for (int t=0; t<towers.size(); t++) {
            xMin = min(xMin, towers[t][0]);
            xMax = max(xMax, towers[t][0]);
            yMin = min(yMin, towers[t][1]);
            yMax = max(yMax, towers[t][1]);
        }
 
        for (int i=xMin; i<=xMax; i++) {
            for (int j=yMin; j<=yMax; j++) {
                int ss = 0;
                for (int t=0; t<towers.size(); t++) {
                    dot[0] = i;
                    dot[1] = j;
                    double d = dist(dot, towers[t]);
                    if ( d <= radius) {
                        ss += floor(towers[t][2]/(1+d));
                    }
                }

                // cout << ss << "[" << i << "," << j << "]" << endl;
                if (ss > curMax) {
                    ret = dot;
                    curMax = ss;
                }
            }
        }

        return ret;
    }

    double dist(vector<int> &c1, vector<int> &c2) {
        return sqrt(pow(c1[0]-c2[0], 2) + pow(c1[1]-c2[1], 2));
    }
};

TEST_CASE("Doctest cases")
{
    Solution sol;

    vector<vector<int>> towers;
    int radius;

    towers = {{1,2,5},{2,1,7},{3,1,9}};
    radius = 2;
    CHECK(sol.bestCoordinate(towers, radius) == vector<int>{2,1});

    towers = {{23,11,21}};
    radius = 9;
    CHECK(sol.bestCoordinate(towers, radius) == vector<int>{23,11});

    towers = {{1,2,13},{2,1,7},{0,1,9}};
    radius = 2;
    CHECK(sol.bestCoordinate(towers, radius) == vector<int>{1,2});
}
