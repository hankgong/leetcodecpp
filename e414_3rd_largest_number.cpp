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

/**

*/

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long x = LONG_MIN;
        long y = LONG_MIN;
        long z = LONG_MIN;
        int uniqc = 0;

        for (int i=0; i<nums.size(); i++) {
            if (nums[i] > x && nums[i] >y && nums[i] > z) {
                z = y;
                y = x;
                x = nums[i];
            } else if (nums[i] < x && nums[i] >y && nums[i] > z) {
                z = y;
                y = nums[i];
            } else if (nums[i] < x && nums[i] < y && nums[i] > z) {
                z = nums[i];
            }

        }

        if (z != LONG_MIN) {
            return z;
        } else {
            return x;
        }
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    vector<int> v = {1, 2, 2, 5, 3, 5};
    cout << s.thirdMax(v) << endl;

    v = {1,2,-2147483648};
    cout << s.thirdMax(v) << endl;

    return 0;
}
