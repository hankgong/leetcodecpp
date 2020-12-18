#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <unordered_set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <climits>
#include "hutility.hpp"

using namespace std;

#define DEBUG
#ifdef DEBUG
void LOG() {cout << endl;}
template<typename Head, typename... Args>
void LOG(const Head& head, const Args&... args )
{
    cout << head << " ";
    LOG(args...);
}

#define LLOG(...) cout<<"L"<<left<<setw(4)<<__LINE__;LOG(__VA_ARGS__)
#else
#define LOG(...) do {} while(0)
#define LLOG(...) do {} while(0)
#endif

/**
https://leetcode-cn.com/contest/weekly-contest-217/problems/find-the-most-competitive-subsequence/
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

int main(int argc, char const *argv[])
{
    Solution s;

    vector<int> nums;

    nums={2,4,3,3,5,4,9,6};
    LOG(s.mostCompetitive(nums, 4));

    nums={3,5,2,6};
    LOG(s.mostCompetitive(nums, 3));


    return 0;
}
