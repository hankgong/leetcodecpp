#define DEBUG
#include "hutility.hpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using namespace std;

/**
https://leetcode-cn.com/problems/sliding-window-maximum/
*/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> tmp;
        vector<int> ans;

        for (int i = 0; i < nums.size(); ++i) {
            tmp.push(make_pair(nums[i], i));
            if(i<k-1) continue;

            while(tmp.top().second <= i-k) {
                tmp.pop();
            }
            // printpq(tmp);

            ans.push_back(tmp.top().first);
        }

        return ans;
    }
};

TEST_CASE("testing the factorial function")
{
    Solution sol;

    vector<int> nums;

    nums={1,3,-1,-3,5,3,6,7};
    CHECK(sol.maxSlidingWindow(nums, 3) == std::vector<int>{3, 3, 5, 5, 6, 7} );

    nums={1};
    CHECK(sol.maxSlidingWindow(nums, 1) == std::vector<int>{1});

    nums={1,-1};
    CHECK(sol.maxSlidingWindow(nums, 1) == std::vector<int>{1, -1});

    nums={9,11};
    CHECK(sol.maxSlidingWindow(nums, 2) == std::vector<int>{11});

    nums={4,-2};
    CHECK(sol.maxSlidingWindow(nums, 2) == std::vector<int>{4});

}
