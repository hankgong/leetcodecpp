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
https://leetcode-cn.com/contest/weekly-contest-212/problems/slowest-key/
*/

class Solution {
public:
    char slowestKey(vector<int>& R, string K) {
        R.insert(R.begin(), 0);

        println(R);
        int curMax = -1;
        int curChr = 0;
        for (int i = 1; i < R.size(); ++i) {
            println2(R[i] - R[i - 1], K[i - 1]);
            if (R[i] - R[i - 1] > curMax) {
                curChr = K[i - 1];
                curMax = R[i] -  R[i - 1];
            } else if (R[i] - R[i - 1] == curMax && K[i - 1] > curChr ) {
                curChr = K[i - 1];
                curMax = R[i] -  R[i - 1];
            }
        }
        return curChr;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> v;

    v = {9, 29, 49, 50};
    println(s.slowestKey(v, "cbcd"));

    v = {12, 23, 36, 46, 62};
    println(s.slowestKey(v, "spuda"));
    return 0;
}
