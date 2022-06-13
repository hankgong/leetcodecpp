#define DEBUG
#include "hutility.hpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using namespace std;

/**
https://leetcode.cn/problems/largest-rectangle-in-histogram/
*/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        heights.insert(heights.begin(), 0);
        vector<int> ss;
        int ret=0;

        ss.push_back(0);

        for(int i=0; i<heights.size(); ++i) {
            int t = ss.back();
            LLOG(ss, heights[t], heights[i]);
            while (heights[i]<heights[ss.back()]) {
                //pop out and calculate
                int h = ss.back();
                ss.pop_back();
                ret = max(ret, heights[h]*(i-ss.back()-1));
                LLOG(ret, heights[h]*(i-ss.back()-1), h);
            } 
            ss.push_back(i);
        }

        return ret;
    }
};

TEST_CASE("Doctest cases")
{
    Solution sol;

    vector<int> heights;

    heights = {2,1,5,6,2,3};
    CHECK(sol.largestRectangleArea(heights) == 10);

    heights = {2,4};
    CHECK(sol.largestRectangleArea(heights) == 4);
}

