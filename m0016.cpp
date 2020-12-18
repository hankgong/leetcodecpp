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
    int threeSumClosest(vector<int>& nums, int target) {
        int len = nums.size();
        int ret = nums[0] + nums[1] + nums[2];
        sort(nums.begin(), nums.end());

        for (int i = 0; i < len - 2; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int t = target - nums[i];
            int l = i + 1, r = len - 1;

            while (l < r) {
                int s = nums[l] + nums[r];
                // int d = ;
                println4(i, nums[l], nums[r], ret);

                if (abs(t - s) < abs(ret - target)) {
                    ret = nums[i] + nums[l] + nums[r];
                }
                if ( s == t) {
                    return target;
                } else if (s < t) {
                    ++l;
                } else {
                    --r;
                }
            }
        }
        return ret;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> v;

    // v = { -1, 2, 1, -4};
    // println(s.threeSumClosest(v, 1));

    v = {1, 1, -1, -1, 3};
    println(s.threeSumClosest(v, -1));
    return 0;
}
