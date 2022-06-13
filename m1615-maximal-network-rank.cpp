#define DEBUG
#include "hutility.hpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using namespace std;

/**
https://leetcode.com/problems/maximal-network-rank/
*/

class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> cnt(n, 0);
        map<vector<int>, bool> net;

        for (int i = 0; i < roads.size(); ++i)
        {
            cnt[roads[i][0]]++;
            cnt[roads[i][1]]++;
            if (roads[i][1] < roads[i][0]){
                roads[i] = {roads[i][1], roads[i][0]};
            }
            net.insert(make_pair(roads[i], true));
        }

        int ret = 0;

        for (int i = 0; i < cnt.size(); ++i)
        {
            for (int j = i+1; j < cnt.size(); ++j)
            {
                int t = cnt[i] + cnt[j];
                if (net.find({i, j}) != net.end())
                {
                    t--;
                }
                ret = max(ret, t);
            }
        }

        return ret;
    }
};

TEST_CASE("Doctest cases")
{
    Solution sol;

    int n;
    vector<vector<int>> roads;

    n = 4;
    roads = {{0,1},{0,3},{1,2},{1,3}};
    CHECK(sol.maximalNetworkRank(n, roads) == 4);

    n = 5;
    roads = {{0,1},{0,3},{1,2},{1,3},{2,3},{2,4}};
    CHECK(sol.maximalNetworkRank(n, roads) == 5);

    n = 8;
    roads = {{0,1},{1,2},{2,3},{2,4},{5,6},{5,7}};
    CHECK(sol.maximalNetworkRank(n, roads) == 5);
}
