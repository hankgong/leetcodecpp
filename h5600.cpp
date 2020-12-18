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


    string kthSmallestPath(vector<int>& destination, int k) {
        return getallpaths(destination[0], destination[1])[k];
        // println("checking");
        // println(allpath);
    }


    vector<string> getallpaths(int row, int col) {
        // println2(row, col);
        if (row == 0 && col == 0) {
            return {};
        } else if (row == 0) {
            return {string(col, 'H')};
        } else if (col == 0) {
            return {string(row, 'V')};
        }

        vector<string> allpath;
        allpath.push_back(string(col, 'H') + string(row, 'V'));

        for (int i = 1; i <= col; ++i) {
            string prefix = string(col - i, 'H') + string(1, 'V');
            vector<string> tocat = getallpaths(row - 1, i);

            for (int j = 0; j < tocat.size(); ++j) {
                allpath.push_back(prefix + tocat[j]);
            }
        }

        // println(allpath);
        return allpath;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> d;
    d = {15, 15};
    println(s.kthSmallestPath(d, 1));

    return 0;
}
