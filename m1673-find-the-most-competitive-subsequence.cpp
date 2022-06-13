#define DEBUG
#include "hutility.hpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using namespace std;

/**
https://leetcode.com/problems/find-the-most-competitive-subsequence/
*/

class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        vector<int> ss;
        int count=0;

        for (int i = 0; i < nums.size(); ++i) {
            while (!ss.empty() && ss.back()>nums[i] && count<nums.size()-k) {
                ss.pop_back();
                count++;
            }

            ss.push_back(nums[i]);
        }

        return vector<int>(ss.begin(), ss.begin()+k);
    }

    vector<int> mostCompetitive_stack1(vector<int>& nums, int k) {
        vector<int> ret;
        int n=nums.size(), count=n-k;

        for (int i = 0; i < n; ++i) {
            while(ret.size()>0 && nums[i]<ret.back() && count>0) {
                ret.pop_back();
                count--;
            }
            ret.push_back(nums[i]);
        }

        while(ret.size()>k) ret.pop_back();
        return ret;
    }

    vector<int> mostCompetitive_stack(vector<int>& nums, int k) {
        stack<int> ss;

        int n=nums.size(), cnt=n-k;
        for (int i = 0; i < n; ++i) {
            //current element is smaller than end of stack element, pop out
            //check if the leftover array length is enough to fill the stack, otherwise length<k
            while(ss.size()>0 && nums[i]<ss.top() && cnt>0) {
                ss.pop();
                cnt--;
            }

            if (ss.size()<k) {
                ss.push(nums[i]);
            }

            printpq(ss);
        }

        vector<int> ret;

        while(k--) {
            int t = ss.top();
            ss.pop();
            ret.insert(ret.begin(), t);
        }

        return ret;
    }

    vector<int> mostCompetitive_myown(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ret;
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for(int i=0;i<n;++i) {
            dp[i][i]=nums[i];
        }
        // LLOG(dp);
        for(int i=1;i<n;++i) {
            for(int j=i-1;j>=0;j--) {
                dp[j][i] = min(dp[j+1][i], dp[j][i-1]);
            }
        }
        LLOG(dp);
        int sp=0;
        for(int i=k; i>0; --i) {
            int e = dp[sp][n-i];
            LLOG(e, sp, n-i);
            ret.push_back(e);
            while(nums[sp]!=e) sp++;
            sp++;
        }
        return ret;
    }
};

TEST_CASE("Doctest cases")
{
    Solution sol;

    vector<int> nums;
    int k;

    nums = {3,5,2,6};
    k = 2;
    CHECK(sol.mostCompetitive(nums, k) == vector<int>{2,6});

    nums = {2,4,3,3,5,4,9,6};
    k = 4;
    CHECK(sol.mostCompetitive(nums, k) == vector<int>{2,3,3,4});
}
