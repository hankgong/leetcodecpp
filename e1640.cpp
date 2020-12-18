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
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        bool start = true;
        int idx = -1;
        int pos = -1;
        for (int i = 0; i < arr.size(); ++i) {
            if (idx == -1) {
                for (int j = 0; j < pieces.size(); ++j) {
                    if (pieces[j][0] == arr[i]) {
                        idx = j;
                        pos = 0;
                        break;
                    }
                }
                if (idx == -1) {
                    return false;
                }
            }

            // compare idx vector in pieces
            if (arr[i] != pieces[idx][pos])
                return false;
            else
                pos++;

            if (pos == pieces[idx].size()) {
                idx = -1;
                pos = -1;
            }
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<vector<int>> v;
    vector<int> a;

    a = {85};
    v = {{85}};
    println(s.canFormArray(a, v));

    a = {15, 88};
    v = {{88}, {15}};
    println(s.canFormArray(a, v));

    a = {49, 18, 16};
    v = {{16, 18, 49}};
    println(s.canFormArray(a, v));

    a = {91, 4, 64, 78};
    v = {{78}, {4, 64}, {91}};
    println(s.canFormArray(a, v));

    return 0;
}
