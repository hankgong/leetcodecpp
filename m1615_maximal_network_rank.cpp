using namespace std;

#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include <iterator>
#include "hutility.hpp"

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

int main(int argc, char const *argv[])
{
    Solution s;

    vector<vector<int>> vec;
    vec = {{0,1},{0,3},{1,2},{1,3}};
    cout << s.maximalNetworkRank(4, vec) << endl;

    vec = {{0,1},{0,3},{1,2},{1,3},{2,3},{2,4}};
    cout << s.maximalNetworkRank(5, vec) << endl;

    vec = {{0,1},{1,2},{2,3},{2,4},{5,6},{5,7}};
    cout << s.maximalNetworkRank(8, vec) << endl;
    return 0;
}