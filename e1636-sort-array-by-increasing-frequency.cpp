#define DEBUG
#include "hutility.hpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using namespace std;

/**
https://leetcode.cn/problems/sort-array-by-increasing-frequency/
*/

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> data;

        for (int i = 0; i < nums.size(); ++i) {
            if (data.count(nums[i])) {
                data[nums[i]] += 1;
            } else {
                data[nums[i]] = 1;
            }
        }

        map<int, vector<int>> d;
        for (auto p : data) {
            d[p.second].push_back(p.first);
        }

        vector<int> ret;
        for (auto e : d) {
            sort(e.second.begin(), e.second.end(), greater<int>());

            for (int j = 0; j < e.second.size(); ++j) {
                for (int i = 0; i < e.first; ++i) {
                    ret.push_back(e.second[j]);
                }
            }
        }

        LOG(ret);
        return ret;
    }
};

TEST_CASE("Doctest cases")
{
    Solution sol;

    vector<int> nums;

    nums = {1,1,2,2,2,3};
    CHECK(sol.frequencySort(nums) == vector<int>{3,1,1,2,2,2});

    nums = {2,3,1,3,2};
    CHECK(sol.frequencySort(nums) == vector<int>{1,3,3,2,2});

    nums = {-1,1,-6,4,5,-6,1,4,1};
    CHECK(sol.frequencySort(nums) == vector<int>{5,-1,4,4,-6,-6,1,1,1});
}
