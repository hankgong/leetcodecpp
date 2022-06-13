#define DEBUG
#include "hutility.hpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using namespace std;

/**
https://leetcode.cn/problems/create-maximum-number/
*/

class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> ans=vector<int>(k, 0);
        function<vector<int>(vector<int>&, int)> mono = [&](vector<int>& nums, int m) {
            if(m>nums.size()) return nums;
            vector<int> ret;
            int count=nums.size()-m;
            for (int i = 0; i < nums.size(); ++i) {
                while(!ret.empty() && ret.back()<nums[i] && count>0) {
                    ret.pop_back();
                    count--;
                }
                ret.push_back(nums[i]);
            }

            while(ret.size() > m) ret.pop_back();
            return ret;
        };

        vector<int> n1, n2;
        // n1 = mono(nums1, 5);
        // n2 = mono(nums2, 3);
        // LLOG(n1, n2);
        for(int l=0; l<=k; l++) {
            if (l>nums1.size() || (k-l)>nums2.size()) continue;
            n1 = mono(nums1, l);
            n2 = mono(nums2, k-l);
            LLOG(n1, n2);

            //merge
            vector<int> merge;
            int s1=n1.size(), s2=n2.size();
            int i=0, j=0;
            while(i<s1 && j<s2) {
                LLOG(n1[i], n2[j]);
                if (n1[i] > n2[j]) {
                    merge.push_back(n1[i++]);
                } else if (n1[i] < n2[j]) {
                    merge.push_back(n2[j++]);
                } else { //n1[i] == n2[j]
                    int ii=i;
                    int jj=j;

                    while(ii<s1 && jj<s2 && n1[ii] == n2[jj]) {
                        ii++;
                        jj++;
                    }
                    if (ii==s1) merge.push_back(n2[j++]);
                    else if (jj==s2) merge.push_back(n1[i++]);
                    else{
                        if (n1[ii] > n2[jj]) {
                            merge.push_back(n1[i++]);
                        } else {
                            merge.push_back(n2[j++]);
                        }
                    }
                }
            }

            while(i<s1) merge.push_back(n1[i++]);
            while(j<s2) merge.push_back(n2[j++]);

            //compare
            LLOG(merge, ans);
            for(int t=0; t<k; ++t) {
                if(merge[t]==ans[t]) continue;
                if(merge[t]<ans[t]) break;
                if(merge[t]>ans[t]) {
                    ans=merge;
                    break;
                }
            }

        }

        return ans;
    }
};

TEST_CASE("Doctest cases")
{
    Solution sol;

    vector<int> nums1;
    vector<int> nums2;
    int k;

    nums1 = {3,4,6,5};
    nums2 = {9,1,2,5,8,3};
    k = 5;
    CHECK(sol.maxNumber(nums1, nums2, k) == vector<int>{9,8,6,5,3});

    nums1 = {6,7};
    nums2 = {6,0,4};
    k = 5;
    CHECK(sol.maxNumber(nums1, nums2, k) == vector<int>{6,7,6,0,4});

    nums1 = {3,9};
    nums2 = {8,9};
    k = 3;
    CHECK(sol.maxNumber(nums1, nums2, k) == vector<int>{9,8,9});
}
