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
    int removeDuplicates(vector<int>& nums) {
        // if (nums.size() == 0) return {};
        int ret = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i > 0 && nums[i] != nums[i - 1]) {
                nums[++ret] = nums[i];
            }
        }
        return ret + 1;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> v;
    v = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    println(s.removeDuplicates(v));
    println(v);

    v = {0};
    println(s.removeDuplicates(v));
    println(v);

    v = {};
    println(s.removeDuplicates(v));
    println(v);

    v = {1, 2, 3};
    println(s.removeDuplicates(v));
    println(v);

    return 0;
}
