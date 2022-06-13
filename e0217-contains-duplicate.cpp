#define DEBUG
#include "hutility.hpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using namespace std;

/**
https://leetcode.com/problems/contains-duplicate/
*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int, bool> tmp;

        for(auto const &n : nums) {
            if(tmp.find(n) == tmp.end()){
                // println2("add", n);
                tmp[n] = true;
            } else {
                return true;
            }
            // println(tmp);
        }

        return false;
    }
};

TEST_CASE("Doctest cases")
{
    Solution sol;

    vector<int> nums;

    nums = {1,2,3,1};
    CHECK(sol.containsDuplicate(nums) == true);

    nums = {1,2,3,4};
    CHECK(sol.containsDuplicate(nums) == false);

    nums = {1,1,1,3,3,4,3,2,4,2};
    CHECK(sol.containsDuplicate(nums) == true);
}

