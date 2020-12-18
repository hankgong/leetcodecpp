#include <iostream>
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

#define println(msg) cout << (msg) << endl
#define println2(m1, m2) cout << (m1) << " " << (m2) << endl
#define println3(m1, m2, m3) cout << (m1) << " " << (m2) << " " << (m3) << endl
#define println4(m1, m2, m3, m4) cout << (m1) << " " << (m2) << " " << (m3) << " " << (m4) << endl
#define println5(m1, m2, m3, m4, m5) cout << (m1) << " " << (m2) << " " << (m3) << " " << (m4) << " " << (m5)<< endl


/**

*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        vector<vector<int>> ret;

        for(int i=0; i<n-2; ++i){
            if (i>0 && nums[i] == nums[i-1]) continue;
            int l = i+1, r = n-1;
            int t = -nums[i];
            while (l < r) {
                int c = nums[l] + nums[r];
                if (c<t) {
                    l++;  
                } else if (c>t) {
                    r--;
                } else { //c == t
                    ret.push_back({nums[i], nums[l], nums[r]});
                    while (l<r && nums[l] == nums[++l]);
                    while (l<r && nums[r] == nums[--r]);
                }
            }
        }
        return ret;
    }
    
    vector<vector<int>> threeSum1(vector<int>& nums) {
        int len = nums.size();
        vector<vector<int>> ret;
        if (len < 3) return {};
        sort(nums.begin(), nums.end());

        for (int i = 0; i < len - 2; ++i) {
            if (nums[i] > 0) break;
            if (i > 0 && nums[i] == nums[i - 1]) continue; // remove the repeating ones

            int target = -nums[i];
            int l = i + 1, r = len - 1;
            while (l < r) {
                if (nums[l] + nums[r] == target) {
                    ret.push_back({nums[i], nums[l], nums[r]});

                    ++l;
                    --r;
                    while (l < r && nums[l] == nums[l - 1]) ++l;
                    while (l < r && nums[r] == nums[r + 1]) --r;
                } else if (nums[l] + nums[r] < target) {
                    ++l;
                } else {
                    --r;
                }
            }
        }
        return ret;
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        int l = nums.size();
        vector<vector<int>> ret;
        if ( l < 3) return {};
        sort(nums.begin(), nums.end());

        for (int i = 0; i < l - 2; ++i ) {
            if (i > 0 && nums[i - 1] ==  nums[i]) {
                println2("skip ", i);
                continue;
            }
            int target = -nums[i];
            unordered_map<int, int> smap;
            for (int j = i + 1; j < l; ++j) {
                if (0 == smap.count(target - nums[j])) {
                    smap[nums[j]] = 0;
                } else {
                    if (smap[target - nums[j]] == 0) {
                        ret.push_back({nums[i], nums[j], -nums[i] - nums[j]});
                        smap[target - nums[j]] = 1;
                    }
                }
                println(smap);
            }
            println(ret);
        }
        return ret;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> v;
    // v = { -1, 0, 1, 2, -1, -4};
    println(s.threeSum(v));

    v = {0, 0, 0, 0};
    println(s.threeSum(v));

    return 0;
}
