#define DEBUG
#include "hutility.hpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using namespace std;

/**
https://leetcode.cn/problems/maximum-units-on-a-truck/
*/

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int ans = 0;

        sort(boxTypes.begin(), boxTypes.end(), [](const auto& u, const auto& v) {
            return u[1] > v[1];
        });

        int usedBox = 0;
        for(int i = 0; i<boxTypes.size(); ++i) {
            int n = boxTypes[i][0];
            int v = boxTypes[i][1];
            if (usedBox + n <= truckSize) {
                ans += v*n;
                usedBox += n;
            } else {
                ans += v*(truckSize-usedBox);
                return ans;
            }
            LLOG(ans);
        }

        LLOG(boxTypes);

        return ans;
    }
};

TEST_CASE("Doctest cases")
{
    Solution sol;

    vector<vector<int>> boxTypes;
    int truckSize;

    boxTypes = {{1,3},{2,2},{3,1}};
    truckSize = 4;
    CHECK(sol.maximumUnits(boxTypes, truckSize) == 8);

    boxTypes = {{5,10},{2,5},{4,7},{3,9}};
    truckSize = 10;
    CHECK(sol.maximumUnits(boxTypes, truckSize) == 91);
}
