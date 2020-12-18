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
https://leetcode-cn.com/problems/find-the-duplicate-number/
*/

class Solution {
public:
    int findDuplicate1(vector<int>& nums) {

        int l = 1, r = nums.size() - 1;

        while (l < r) {
            int m = l + (r - l) / 2;
            println3(l, m, r);
            int cnt = 0;

            for (int i = 0; i < nums.size(); ++i) {
                if (nums[i] <= m) {
                    cnt++;
                }
            }

            if (cnt > m) {
                r = m;
            } else {
                l = m + 1;
            }
        }

        return l;
    }

    int findDuplicate(vector<int>& nums) {

        int l = 1, r = nums.size() - 1;

        while (l + 1 < r) {
            int m = l + (r - l) / 2;
            println3(l, m, r);
            int cnt = 0;

            for (int i = 0; i < nums.size(); ++i) {
                if (nums[i] <= m) {
                    cnt++;
                }
            }

            if (cnt > m) {
                r = m;
            } else {
                l = m;
            }
        }

        int c = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == l) c++;
        }
        println2(l, r);

        if (c > 1)
            return l;
        else
            return r;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    vector<int> v;
    v = {1, 3, 4, 2, 2};
    println(s.findDuplicate(v));

    v = {3, 1, 3, 4, 2};
    println(s.findDuplicate(v));

    v = {1, 3, 4, 2, 2};
    println(s.findDuplicate(v));

    return 0;
}
