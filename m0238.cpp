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
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        vector<int> left = vector<int> (len, 1), right = vector<int> (len, 1);

        for (int i = 1; i < len; ++i) {
            left[i] = nums[i - 1] * left[i - 1];
            right[len - 1 - i] = nums[len - i] * right[len - i];
        }
        println2(left, right);

        for (int i = 0; i < len; ++i) {
            left[i] = left[i] * right[i];
        }
        return left;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> v;
    v = {1, 2, 3, 4, 5};
    println(s.productExceptSelf(v));

    return 0;
}
