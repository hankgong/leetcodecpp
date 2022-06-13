#define DEBUG
#include "hutility.hpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using namespace std;

/**
https://leetcode.cn/problems/ways-to-split-array-into-three-subarrays/
*/

class Solution {
public:
    int waysToSplit(vector<int>& nums) {
        vector<int> psum;
        int n = nums.size();

        int tsum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            tsum += nums[i];
            psum.push_back(tsum);
        }

        long long ans = 0;
        for(int i=0; i<nums.size(); ++i) {
            if (psum[i]*3>tsum) break;

            //binary search from here
            int left = i+1, right = n-1;

            //right boundary
            while(left<right){
                int mid = left + (right-left+1)/2;

                if (psum[mid]-psum[i] > psum[n-1]-psum[mid]) {
                    right = mid-1;
                } else {
                    left = mid;
                }
            }

            //left boundary
            int ll = i+1, rr = n-1;
            while(ll<rr) {
                int mid = ll + (rr-ll)/2;

                if (psum[mid]-psum[i] < psum[i]) {
                    ll = mid+1;
                } else {
                    rr = mid;
                }
            }

            LLOG(i, ll, left);
            if (left>=ll) ans += (left-ll+1);
        }
        return ans % (int)(1e9+7);
    }
};

TEST_CASE("Doctest cases")
{
    Solution sol;

    vector<int> nums;

    nums = {1,1,1};
    CHECK(sol.waysToSplit(nums) == 1);

    nums = {1,2,2,2,5,0};
    CHECK(sol.waysToSplit(nums) == 3);

    nums = {3,2,1};
    CHECK(sol.waysToSplit(nums) == 0);
}
