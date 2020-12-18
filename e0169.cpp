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
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }

    int majorityElement1(vector<int>& nums) {
        int halfSize = nums.size() / 2;
        map<int, int> cntm;

        int ret = nums[0];
        for (auto n : nums) {
            if (cntm.find(n) != cntm.end()) {
                cntm[n] += 1;
                if (cntm[n] >= halfSize) {
                    ret = n;
                }
            } else {
                cntm[n] == 1;
            }
        }
        return ret;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    vector<int> v;
    v = {2, 2, 1, 1, 1, 2, 2};
    println(s.majorityElement1(v));

    return 0;
}
