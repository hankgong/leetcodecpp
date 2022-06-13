#define DEBUG
#include "hutility.hpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using namespace std;

/**
https://leetcode-cn.com/problems/furthest-building-you-can-reach/
*/

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int ans = 0;

        function<void(int, int, int)> dfs = [&](int cur, int b, int l) {
            if (ans == heights.size()-1) return;
            if (cur == heights.size()-1 || (heights[cur+1]-heights[cur] > b && l==0)) {
                ans = max(ans, cur);
                return;
            }

            int diff = heights[cur+1]-heights[cur];
            LLOG(cur, ans, diff, b, l);
            if (diff<=0) dfs(cur+1, b, l);
            else {
                if (b >= diff) dfs(cur+1, b-diff, l);
                if (l>0) dfs(cur+1, b, l-1);
            }
        };

        dfs(0, bricks, ladders);
        return ans;

    }

    int furthestBuilding_pq(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int> pq;
        int ans = 0;

        for (int i = 1; i < heights.size(); ++i) {
            
            int diff = heights[i] - heights[i-1];

            if (diff > 0) pq.push(-diff);

            if(pq.size() > ladders) {
                bricks += pq.top();
                pq.pop();
            }

            LLOG(i, diff, bricks);
            printpq(pq);

            if (bricks<0) return i-1;
        }

        return heights.size()-1;
    }

    int furthestBuilding_binarysearch(vector<int>& heights, int bricks, int ladders) {
        int left=0, right = heights.size()-1;

        function<bool(int)> isOK = [&](int tgt) {
            int b = bricks;
            vector<int> diff;
            for(int i=1; i<=tgt; ++i){
                if (heights[i]-heights[i-1]>0) diff.push_back(heights[i]-heights[i-1]);
            }

            LLOG(diff);
            sort(diff.begin(), diff.end());

            if (diff.size()<=ladders) return true;
            for (int i = 0; i < diff.size() - ladders; ++i) {
                LLOG(i, diff.size()-ladders, ladders);
                if (b >=diff[i] ) b-=diff[i];
                else return false;
            }
            return true;
        };

        while(left<right){
            int mid = left + (right-left+1)/2;
            LLOG(left, right, mid);
            if (isOK(mid)) {
                left = mid;
            } else {
                right = mid-1;
            }
        }
        return left;
    }
};

TEST_CASE("testing the factorial function")
{
    Solution sol;

    vector<int> heights;

    heights={4,12,2,7,3,18,20,3,19};
    CHECK(sol.furthestBuilding(heights, 10, 2) == 7);

    heights={14,3,19,3};
    CHECK(sol.furthestBuilding(heights, 17, 0) == 3);

    heights={17,16,5,10,10,14,7};
    CHECK(sol.furthestBuilding(heights, 74, 6) == 6);

    heights={2,7,9,12};
    CHECK(sol.furthestBuilding(heights, 5, 1) == 3);
}
