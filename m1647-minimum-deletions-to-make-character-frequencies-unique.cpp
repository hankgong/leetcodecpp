#define DEBUG
#include "hutility.hpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using namespace std;

/**
https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/
*/

class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char, int>m;
        for (int i = 0; i < s.size(); ++i) {
            ++m[s[i]];
        }

        set<int> cset;
        int ret = 0;
        for(auto f:m) {
            if (f.second !=0) {
                while(cset.count(f.second)) {
                    f.second--;
                    ret++;
                }

                if (f.second!=0) cset.insert(f.second);
            }
        }

        LOG(cset);

        return ret;

    }

    int minDeletions_(string s) {
        unordered_map<char, int> m;

        for (int i = 0; i < s.size(); ++i) {
            ++m[s[i]];
        }

        vector<int> nums;
        for(auto f:m) {
            nums.push_back(f.second);
        }

        sort(nums.rbegin(), nums.rend());
        LOG(nums);

        int ret = 0;
        int l = nums.size();
        int curf = nums.back();
        for (int i = 1; i < l; ++i) {
            if (nums[l-1-i] >= curf) {
                if (curf > 0) --curf;
                ret += (nums[l-1-i] - curf);
            } else {
                curf = nums[l-1-i];
            }
        }

        return ret;
    }
};

TEST_CASE("Doctest cases")
{
    Solution sol;

    string s;

    s = "aab";
    CHECK(sol.minDeletions(s) == 0);

    s = "aaabbbcc";
    CHECK(sol.minDeletions(s) == 2);

    s = "ceabaacb";
    CHECK(sol.minDeletions(s) == 2);
}
