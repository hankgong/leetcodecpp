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
    int search1(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;

        while (l <= r) {
            int m = l + (r - l) / 2;
            println5(l, m, r, nums[m], target);
            if (nums[m] == target) return m;

            if (nums[0] <= nums[m]) { //left partion in order
                if (target >= nums[0] && target < nums[m]) {
                    r = m - 1;
                } else {
                    l = m + 1;
                }
            } else { //right partion in order
                if (target > nums[m] && target <= nums[nums.size() - 1]) {
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            }
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;

        while (l + 1 < r) {
            int m = l + (r - l) / 2;
            // println5(l, m, r, nums[m], target);
            // if (nums[m] == target) return m;

            if (nums[0] < nums[m]) { //left partion in order
                if (target >= nums[0] && target < nums[m]) {
                    r = m;
                } else {
                    l = m;
                }
            } else { //right partion in order
                if (target > nums[m] && target <= nums[nums.size() - 1]) {
                    l = m;
                } else {
                    r = m;
                }
            }
        }

        println4(l, r, nums[l], nums[r]);
        if (nums[l] == target) return l;
        if (nums[r] == target) return r;
        return -1;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    vector<int> v;
    v = {4, 5, 6, 7, 0, 1, 2};
    println(s.search(v, 0));
    println(s.search(v, 1));
    println(s.search(v, 2));
    println(s.search(v, 4));
    println(s.search(v, 8));
    println(s.search(v, 3));

    v = {3, 1};
    println(s.search(v, 1));
    return 0;
}
